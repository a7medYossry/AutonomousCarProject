#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "ultrasonic.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../FreeRTOS.h"
#include "../../task.h"
#include "../../timers.h"

// Function to send trigger pulse to the ultrasonic sensor
void send_trigger_pulse() {
    vSet_Pin_OUTPUTvalue(TRIG_PORT, TRIG_PIN, LOW);
    vTaskDelay(pdMS_TO_TICKS(1));
    vSet_Pin_OUTPUTvalue(TRIG_PORT, TRIG_PIN, HIGH);
    vTaskDelay(pdMS_TO_TICKS(1));
    vSet_Pin_OUTPUTvalue(TRIG_PORT, TRIG_PIN, LOW);
}

// Function to read the echo pulse and calculate distance
u16 read_echo_pulse() {
    TickType_t start, end;
    
    while (vGIT_PIN(ECHO_PORT, ECHO_PIN) == LOW) {
        // Wait for rising edge
    }
    start = xTaskGetTickCount();
    
    while (vGIT_PIN(ECHO_PORT, ECHO_PIN) == HIGH) {
        // Wait for falling edge
    }
    end = xTaskGetTickCount();
    
    // Calculate duration in milliseconds
    u16 duration = (end - start) * portTICK_PERIOD_MS;
    
    // Calculate distance: duration / 58 gives distance in cm
    return duration / 58;
}

// Initialization function
void ultrasonic_init() {
    vSet_Pin_Direction(TRIG_PORT, TRIG_PIN, OUTPUT);
    vSet_Pin_Direction(ECHO_PORT, ECHO_PIN, INPUT);
}

// Task to handle ultrasonic sensor readings
void vUltrasonicTask(void *pvParameters) {
    u16 distance;
    
    ultrasonic_init();
    
    for(;;) {
        send_trigger_pulse();
        distance = read_echo_pulse();
        
        // Do something with the distance value
        
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

int main(void) {
    // Other initializations...
    
    xTaskCreate(vUltrasonicTask, "Ultrasonic", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);
    
    vTaskStartScheduler();
    
    for(;;);  // Should never get here
}
