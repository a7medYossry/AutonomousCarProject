#include "main.h"

int main()
{
    vGlobal_interrupt_Enable();
    servo_init();
    vLCD_init();
    ultrasonic_init();

    u16 Forward_distance = 0;
    u16 Right_distance = 0;
    u16 Left_distance = 0;

    while (1)
    {
        send_trigger_pulse();
        Forward_distance = read_echo_pulse();
        _delay_ms(1000);

        if (Forward_distance < OBSTACLE_THRESHOLD)
        {
            Stop_Move();
            vLCD_Clear();
            vLCD_Send_String("Stop Move");
            _delay_ms(1000);

            servo_set_angle(0);
            send_trigger_pulse();
            Right_distance = read_echo_pulse();
            _delay_ms(1000);

            servo_set_angle(180);
            send_trigger_pulse();
            Left_distance = read_echo_pulse();
            _delay_ms(1000);

            servo_set_angle(90);
            _delay_ms(1000);

            if (Left_distance > Right_distance)
            {
                vLCD_Clear();
                vLCD_Send_String("Turn Left");
                Turn_Left();
            }
            else
            {
                vLCD_Clear();
                vLCD_Send_String("Turn Right");
                Turn_Right();
            }

            _delay_ms(1000);
            Forward_Move();
            vLCD_Clear();
            vLCD_Send_String("Forward Move");
        }
    }
}
