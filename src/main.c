/*
 * main.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Ahmedyossry
 */
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Initialize Port C, Pin 2 as an output
    DDRC |= (1 << PC2); // Set PC2 as output

    while (1) {
        // Toggle the LED
        PORTC ^= (1 << PC2); // Toggle PC2

        // Delay for 1 second
        _delay_ms(1000);

    }

    return 0;
}
