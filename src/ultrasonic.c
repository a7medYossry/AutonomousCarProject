#include <avr/io.h>      // Include AVR I/O definitions
#include <util/delay.h>  // Include delay functions
#include "ultrasonic.h"  // Include custom ultrasonic sensor header

// Function to send trigger pulse to the ultrasonic sensor
void send_trigger_pulse() {
    // Set TRIG_PIN (PC0) low
    PORTC &= ~(1 << TRIG_PIN);
    _delay_us(2);  // Short delay to ensure a clean low pulse

    // Set TRIG_PIN (PC0) high for 10 microseconds
    PORTC |= (1 << TRIG_PIN);
    _delay_us(10);

    // Set TRIG_PIN (PC0) low again to end the trigger pulse
    PORTC &= ~(1 << TRIG_PIN);
}

// Function to read the echo pulse and calculate distance
uint16_t read_echo_pulse() {
    // Wait for the echo pin (PC1) to go high (start of pulse)
    while (!(PINC & (1 << ECHO_PIN)));

    // Reset Timer1 counter
    TCNT1 = 0;

    // Start Timer1 with prescaler 8 (CS11 bit set)
    TCCR1B |= (1 << CS11);

    // Wait for the echo pin (PC1) to go low (end of pulse)
    while (PINC & (1 << ECHO_PIN));

    // Stop Timer1
    TCCR1B &= ~(1 << CS11);

    // Read Timer1 value (pulse width in timer ticks)
    uint16_t pulse_width = TCNT1;

    // Convert pulse width to distance in centimeters
    // (Divide by 58 as per ultrasonic sensor specifications)
    return pulse_width / 58;
}