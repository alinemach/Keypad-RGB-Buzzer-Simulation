        #include <stdio.h>
        #include "pico/stdlib.h"
        #include "hardware/pwm.h"

        // Define os pinos GPIO para as linhas e para as colunas
        #define L1 2
        #define L2 3
        #define L3 4
        #define L4 5
        #define C1 6
        #define C2 7
        #define C3 8
        #define C4 9

        int rowPins[4] = {L1, L2, L3, L4};    // Pinos GPIO para as linhas
        int colPins[4] = {C1, C2, C3, C4};    // Pinos GPIO para as colunas

        // Define os pinos do LED RGB
        #define LED_GREEN 11
        #define LED_BLUE 12
        #define LED_RED 13

        // Define o pino do buzzer
        #define BUZZER 21

        // Delay LEDs
        #define DELAY_LED 250

        // Mapeamento das teclas em uma matriz 4x4
        char teclas[4][4] = {
            {'1', '2', '3', 'A'},
            {'4', '5', '6', 'B'},
            {'7', '8', '9', 'C'},
            {'*', '0', '#', 'D'}
        };

        // Declaração das funções
        void init_keypad();
        char read_keypad();
        void init_led(uint pin);
        void turn_on_led(uint pin);
        void turn_off_led(uint pin);

        void BUZZER_CONFIG (uint gpio, float frequencia, float duty_cycle){
    gpio_set_function(gpio, GPIO_FUNC_PWM); //DEFINE O PINO COMO SAÍDA PWM
    uint slice_num = pwm_gpio_to_slice_num(gpio); //OBTEM O NUMERO DA SLICE ASSOCIADA AO PINO
    uint channel = pwm_gpio_to_channel(gpio); //OBETEM O NÚMERO DO CANAL

    float clk_div = 4.0f;  // DIVISOR DE CLOCK
    uint32_t wrap = (uint32_t)((125e6 / (frequencia * clk_div)) - 1);
   
    // CONFIGURAÇÃO PWM
    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, clk_div);
    pwm_config_set_wrap(&config, wrap);
    pwm_init(slice_num, &config, true);
    
    // CONFIGURAÇÃO DUTY_CICLE
     uint32_t level = (uint32_t)(wrap * duty_cycle);
    pwm_set_chan_level(slice_num, channel, level);
    pwm_set_enabled(slice_num, true);
}
    
    void CONTROLE_BUZZER(){

    BUZZER_CONFIG(BUZZER, 880.0f, 0.5f); //CONFIGURA FREQUENCIA E DUTY_CYCLE
        sleep_ms(500);
        
        uint slice_num = pwm_gpio_to_slice_num(BUZZER);
        uint channel = pwm_gpio_to_channel(BUZZER);
        pwm_set_chan_level(slice_num, channel, 0);  //DESLIGAR BUZZER

}

        int main() {
            stdio_init_all();
            init_keypad();
            init_led(LED_RED);  // Inicializa o LED vermelho
            init_led(LED_BLUE);
            init_led(LED_GREEN);

            while (true) {
                char caracter = read_keypad();  // Escaneia o teclado matricial
                if (caracter != '\0') {  // Se uma tecla foi pressionada
                    printf("Tecla pressionada: %c\n", caracter);
                    switch (caracter) {
                        case 'A':  // Verifica se a tecla pressionada foi a letra A
                            turn_on_led(LED_RED);  // Acende o LED vermelho
                            turn_off_led(LED_BLUE);
                            turn_off_led(LED_GREEN);
                            break;
                        case 'B':
                            turn_on_led(LED_BLUE);
                            turn_off_led(LED_RED);
                            turn_off_led(LED_GREEN);
                            break;
                        case 'C':
                            turn_on_led(LED_GREEN);
                            turn_off_led(LED_BLUE);
                            turn_off_led(LED_RED);
                            break;
                        case '#': //VERIFICA TECLA PRESSIONADA #
                            CONTROLE_BUZZER();
                            break;
                        default:
                            turn_off_led(LED_RED);  // Desliga o LED se nenhuma tecla relevante for pressionada
                            turn_off_led(LED_BLUE);
                            break;
                    }
                } else {
                    turn_off_led(LED_RED);  // Garante que o LED esteja desligado
                    turn_off_led(LED_BLUE);
                    turn_off_led(LED_GREEN);
                }

                sleep_ms(200);  // Pausa de 200ms para evitar leituras repetidas
            }

            return 0;
        }

        // Função para inicializar o teclado matricial
        void init_keypad() {
            // Configura os pinos das linhas como saída (para enviar sinal)
            for (int i = 0; i < 4; i++) {
                gpio_init(rowPins[i]);
                gpio_set_dir(rowPins[i], GPIO_OUT);
            }

            // Configura os pinos das colunas como entrada (para ler o sinal)
            for (int i = 0; i < 4; i++) {
                gpio_init(colPins[i]);
                gpio_set_dir(colPins[i], GPIO_IN);
                gpio_pull_up(colPins[i]); // Configura as colunas com resistor de pull-up
            }
        }

        // Função para realizar a varredura do teclado matricial
        char read_keypad() {
            for (int row = 0; row < 4; row++) {
                // Desativa todas as linhas antes de ativar a linha atual
                for (int i = 0; i < 4; i++) {
                    gpio_put(rowPins[i], 1); // Coloca todas as linhas em nível alto
                }

                // Ativa a linha atual (colocando-a em nível baixo)
                gpio_put(rowPins[row], 0);

                // Verifica se houve alteração nas colunas
                for (int col = 0; col < 4; col++) {
                    if (gpio_get(colPins[col]) == 0) {  // Verifica se a tecla foi pressionada
                        // Debounce: espera um pouco para garantir que o botão foi pressionado
                        sleep_ms(50);
                        return teclas[row][col];  // Retorna o valor da tecla pressionada
                    }
                }

                // Coloca a linha de volta para o nível alto
                gpio_put(rowPins[row], 1);
            }

            return '\0'; // Nenhuma tecla foi pressionada
        }

        // Função para inicializar um LED
        void init_led(uint pin) {
            gpio_init(pin);
            gpio_set_dir(pin, GPIO_OUT);
        }

        // Função para acender um LED
        void turn_on_led(uint pin) {
            gpio_put(pin, 1);
        }

        // Função para apagar um LED
        void turn_off_led(uint pin) {
            gpio_put(pin, 0);
        }