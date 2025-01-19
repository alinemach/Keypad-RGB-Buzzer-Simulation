#include "led_control.h"
#include "pico/stdlib.h"

// Função para inicializar o pino do LED
void init_led(uint pin) {
    gpio_init(pin);          // Inicializa o pino como GPIO
    gpio_set_dir(pin, GPIO_OUT); // Configura o pino como saída
}

// Função para ligar o LED
void turn_on_led(uint pin) {
    gpio_put(pin, 1); // Define o pino como HIGH (liga o LED)
}

// Função para desligar o LED
void turn_off_led(uint pin) {
    gpio_put(pin, 0); // Define o pino como LOW (desliga o LED)
}
