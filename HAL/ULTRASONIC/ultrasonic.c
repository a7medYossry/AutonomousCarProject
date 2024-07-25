#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "util/delay.h"

#include "../../MCAL/TIMERS/TIMER_init.h"
#include "../../MCAL/TIMERS/TIMER_confg.h"
#include "../../MCAL/TIMERS/TIMER_praivat.h"

#include "ultrasonic.h"                   // Include custom ultrasonic sensor header
#include "../../MCAL/DIO/DIO_Interface.h" // Include the DIO interface header

#define TIMER0_TICK_TIME 4

volatile u16 g_timer_count = 0;

void timer_overflow_callback(void)
{
    g_timer_count++;
}
void ultrasonic_init()
{
    vSet_Pin_Direction(PORT_C, PIN_2, OUTPUT);
    vSet_Pin_Direction(TRIG_PORT, TRIG_PIN, OUTPUT);
    vSet_Pin_Direction(ECHO_PORT, ECHO_PIN, INPUT);

    vTIMER0_INIT();
    vTIMER0_OF_CallBack(timer_overflow_callback);
}

void send_trigger_pulse()
{
    vSet_Pin_OUTPUTvalue(TRIG_PORT, TRIG_PIN, LOW);
    _delay_us(2);

    vSet_Pin_OUTPUTvalue(TRIG_PORT, TRIG_PIN, HIGH);
    _delay_us(10);

    vSet_Pin_OUTPUTvalue(TRIG_PORT, TRIG_PIN, LOW);
}

u16 read_echo_pulse()
{
    u32 timeout = 0;
    u32 pulse_duration = 0;

    // Wait for the echo pin to go high (start of pulse)
    while (vGIT_PIN(ECHO_PORT, ECHO_PIN) == LOW)
    {
        timeout++;
        if (timeout > 30000) // Timeout after about 30ms
        {

            return 0; // Return 0 if no echo is received
        }
    }
    vSet_Pin_OUTPUTvalue(PORT_C, PIN_2, HIGH);

    // Reset and start timer
    g_timer_count = 0;
    vTIMER0_preload(0);
    vTIMER0_START();

    // Wait for the echo pin to go low (end of pulse)
    timeout = 0;
    //    _delay_ms(1000);
    while (vGIT_PIN(ECHO_PORT, ECHO_PIN) == HIGH)
    {

        timeout++;
        if (timeout > 30000)
        { // Timeout after about 30ms
            _delay_ms(1000);
            vSet_Pin_OUTPUTvalue(PORT_C, PIN_2, LOW);
            _delay_ms(1000);
            break;
        }
    }

    vTIMER0_STOP();
    pulse_duration = (g_timer_count * 256 + TCNT0) * TIMER0_TICK_TIME;

    // Calculate pulse duration

    // Calculate distance in cm
    // Sound travels at 343m/s, so it takes 58µs to travel 1cm (round trip)
    return TCNT0;
}
