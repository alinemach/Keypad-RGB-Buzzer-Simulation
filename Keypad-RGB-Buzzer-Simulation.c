#include <stdio.h>
#include "pico/stdlib.h"

// Define os pinos GPIO para as linhas e para as colunas
#define L1 2
#define L2 3
#define L3 4
#define L4 5
#define C1 6
#define C2 7
#define C3 8
#define C4 9

// Define os pinos do LED RGB
#define LED_RED 13
#define LED_BLUE 12
#define LED_GREEN 11

// Define o pino do buzzer
#define BUZZER 21

// Delay Leds
#define DELAY_LED 250

// Mapeamento das teclas em uma matriz 4x4
char teclas[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

int main() {

    return 0;
}