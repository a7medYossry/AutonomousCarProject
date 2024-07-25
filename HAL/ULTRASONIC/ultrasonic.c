#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ultrasonic.h"  // Include custom ultrasonic sensor header
#include "DIO_Interface.h" // Include the DIO interface header

// Function to send trigger pulse to the ultrasonic sensor
void send_trigger_pulse() {
    // Set TRIG_PIN low
    vSet_Pin_OUTPUTvalue(TRIG_PORT, TRIG_PIN, LOW);
    _delay_us(2);  // Short delay to ensure a clean low pulse

    // Set TRIG_PIN high for 10 microseconds
    vSet_Pin_OUTPUTvalue(TRIG_PORT, TRIG_PIN, HIGH);
    _delay_us(10);

    // Set TRIG_PIN low again to end the trigger pulse
    vSet_Pin_OUTPUTvalue(TRIG_PORT, TRIG_PIN, LOW);
}

// Function to read the echo pulse and calculate distance
u16 read_echo_pulse() {
    // Wait for the echo pin to go high (start of pulse)
    while (vGIT_PIN(ECHO_PORT, ECHO_PIN) == LOW);

    // Reset Timer1 counter
    TCNT1 = 0;

    // Start Timer1 with prescaler 64 (CS11 and CS10 bits set)
    TCCR1B |= (1 << CS11) | (1 << CS10);

    // Wait for the echo pin to go low (end of pulse)
    while (vGIT_PIN(ECHO_PORT, ECHO_PIN) == HIGH);

    // Stop Timer1
    TCCR1B &= ~((1 << CS11) | (1 << CS10));

    // Read Timer1 value (pulse width in timer ticks)
    u16 pulse_width = TCNT1;

    // Convert pulse width to distance in centimeters
    // For 16MHz clock with 64 prescaler, one tick is 4µs
    // Sound travels at 343m/s, so it takes 58µs to travel 1cm (round trip)
    // Therefore, distance = (pulse_width * 4) / 58
    return (pulse_width * 4) / 58;
}

// Initialization function (call this in your main() before using the sensor)
void ultrasonic_init() {
    // Set TRIG_PIN as output
    vSet_Pin_Direction(TRIG_PORT, TRIG_PIN, OUTPUT);
    
    // Set ECHO_PIN as input
    vSet_Pin_Direction(ECHO_PORT, ECHO_PIN, INPUT);

    // Initialize Timer1
    TCCR1A = 0; // Set Timer1 to normal mode
    TCCR1B = 0; // Clear prescaler settings
}
