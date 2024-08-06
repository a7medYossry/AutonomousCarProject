#include "main.h"


void check_distances(u16 *right_distance, u16 *left_distance) {
    servo_set_angle(90);
    vLCD_Clear();
    vLCD_Send_String("Calculating Right distance");
    _delay_ms(SERVO_DELAY);
    send_trigger_pulse();
    *right_distance = read_echo_pulse();

    servo_set_angle(-90);
    vLCD_Clear();
    vLCD_Send_String("Calculating Left distance");
    _delay_ms(SERVO_DELAY);
    send_trigger_pulse();
    *left_distance = read_echo_pulse();

    servo_set_angle(0);
    _delay_ms(MOVE_DELAY);
}

void handle_obstacle(u16 right_distance, u16 left_distance) {
    vLCD_Clear();
    if (left_distance > right_distance && left_distance > OBSTACLE_THRESHOLD) {
        vLCD_Send_String("Turn Left");
        Turn_Left();
    } else if (right_distance > left_distance && right_distance > OBSTACLE_THRESHOLD) {
        vLCD_Send_String("Turn Right");
        Turn_Right();
    } else {
        vLCD_Send_String("Turn Back");
        Backward_Move();
    }
    _delay_ms(TURN_DELAY);
}

int main() {
    vGlobal_interrupt_Enable();
    servo_init();
    vLCD_init();
    ultrasonic_init();

    u16 forward_distance = 0;
    u16 right_distance = 0;
    u16 left_distance = 0;

    while (1) {
        send_trigger_pulse();
        forward_distance = read_echo_pulse();
        _delay_ms(MOVE_DELAY);

        if (forward_distance < OBSTACLE_THRESHOLD) {
            Stop_Move();
            vLCD_Clear();
            vLCD_Send_String("Stop Move");
            _delay_ms(MOVE_DELAY);

            check_distances(&right_distance, &left_distance);
            handle_obstacle(right_distance, left_distance);
        } else {
            vLCD_Clear();
            vLCD_Send_String("Forward Move");
            Forward_Move();
            _delay_ms(MOVE_DELAY);
        }
    }
}
