
#include "main.h"

/**
 * Checks distances on the right and left sides
 * @param right_distance Pointer to store right side distance
 * @param left_distance Pointer to store left side distance
 */
void check_distances(u16 *right_distance, u16 *left_distance) {
    // Check right distance
    servo_set_angle(90);
    vLCD_Clear();
    vLCD_Send_String("Calculating Right distance");
    _delay_ms(SERVO_DELAY);
    send_trigger_pulse();
    *right_distance = read_echo_pulse();

    // Check left distance
    servo_set_angle(-90);
    vLCD_Clear();
    vLCD_Send_String("Calculating Left distance");
    _delay_ms(SERVO_DELAY);
    send_trigger_pulse();
    *left_distance = read_echo_pulse();

    // Reset servo position
    servo_set_angle(0);
    _delay_ms(MOVE_DELAY);
}

/**
 * Handles obstacle avoidance based on measured distances
 * @param right_distance Distance to obstacle on the right
 * @param left_distance Distance to obstacle on the left
 */
void handle_obstacle(u16 right_distance, u16 left_distance) {
    vLCD_Clear();
    if (left_distance >= right_distance && left_distance > OBSTACLE_THRESHOLD) {
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
    // Initialize system components
    vGlobal_interrupt_Enable();
    servo_init();
    vLCD_init();
    ultrasonic_init();

    // Declare variables to store distance measurements
    u16 forward_distance = 0;
    u16 right_distance = 0;
    u16 left_distance = 0;

    // Main control loop
    while (1) {
        // Measure forward distance
        send_trigger_pulse();
        forward_distance = read_echo_pulse();
        _delay_ms(MOVE_DELAY);

        // Check if obstacle is detected in front
        if (forward_distance < OBSTACLE_THRESHOLD) {
            // Stop and inform about the obstacle
            Stop_Move();
            vLCD_Clear();
            vLCD_Send_String("Stop Move");
            _delay_ms(MOVE_DELAY);

            // Check surrounding distances and handle obstacle
            check_distances(&right_distance, &left_distance);
            handle_obstacle(right_distance, left_distance);
        } else {
            // No obstacle, continue moving forward
            vLCD_Clear();
            vLCD_Send_String("Forward Move");
            Forward_Move();
            _delay_ms(MOVE_DELAY);
        }
    }
}
