#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include <stdint.h> // Biblioteca para tipos de dados como uint

// Prototipos das funções
void init_led(uint pin);      // Inicializa o pino do LED
void turn_on_led(uint pin);   // Liga o LED
void turn_off_led(uint pin);  // Desliga o LED

#endif // LED_CONTROL_H
