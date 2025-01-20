# Keypad-RGB-Buzzer-Simulation
Este repositório contém o código e os recursos para a simulação de controle de pinos GPIO utilizando um teclado matricial 4x4 com o microcontrolador RP2040 da placa Raspberry Pi Pico W. O projeto foi desenvolvido como parte de uma atividade prática para o controle de 3 LEDs RGB e de um buzzer, utilizando o simulador eletrônico Wokwi.

Link para o vídeo de explicação do código: https://drive.google.com/drive/folders/1PMzF5Q4zPEcO-9yGnC28p3UyL_OYMGJa?usp=drive_link
	

Funcionalidades
	Controle do LED RGB:
		Tecla 'A': Acende o LED vermelho.
		Tecla 'B': Acende o LED azul.
		Tecla 'C': Acende o LED verde.
	Controle do Buzzer:
		Tecla '#': Toca o buzzer com uma frequência de 880 Hz por 500 ms.
	Leitura do Teclado Matricial:
		Detecta e processa teclas pressionadas usando um teclado matricial 4x4.

Componentes Utilizados
	Microcontrolador: Raspberry Pi Pico W.
	Teclado Matricial 4x4: Utilizado para entrada de dados.
	LED RGB (Cátodo comum): Para sinalização visual.
	Buzzer: Para sinalização sonora.
	Resistores: 220 ohms para cada terminal de cor do LED RGB.

Esquema de Conexão
	Os pinos GPIO do Raspberry Pi Pico foram mapeados da seguinte maneira:

	Teclado Matricial:
		Linhas: GP2, GP3, GP4, GP5.
		Colunas: GP6, GP7, GP8, GP9.
	LED RGB:
		Verde: GP11 (via resistor de 220 ohms).
		Azul: GP12 (via resistor de 220 ohms).
		Vermelho: GP13 (via resistor de 220 ohms).
		Cátodo comum: GND.
	Buzzer:
		Positivo: GP21.
		Negativo: GND26.

Como Funciona
	Inicialização:
		O código inicializa os GPIOs para as linhas e colunas do teclado, os LEDs e o buzzer.
		Configura o PWM para controlar o buzzer.
	
	Leitura do Teclado:
		O teclado é varrido linha por linha para identificar teclas pressionadas.
		O caractere correspondente é processado.

	Ações Baseadas nas Teclas:
		Cada tecla pressionada executa uma ação específica:
		Acender LEDs (A, B, C).
		Tocar o buzzer (#).

Como Usar
	Conectar os componentes ao Raspberry Pi Pico conforme o esquema descrito.
	Compilar e carregar o código no Raspberry Pi Pico usando o SDK da Pico.
	Abra o monitor serial para visualizar as teclas pressionadas.
	Pressione as teclas no teclado matricial para interagir com o LED RGB e o buzzer.

Requisitos
	Hardware:
		Raspberry Pi Pico W.
		Periféricos descritos (teclado matricial, LED RGB, resistores, buzzer).
	Software:
		Pico SDK configurado no ambiente de desenvolvimento.
		Wokwi para simulação, se necessário.

Simulação no VS Code
	Para simular o projeto:
	Copie o conteúdo do arquivo diagram.json.
	Cole o JSON no editor do Wokwi IoT Simulator.
	Execute a simulação para visualizar o funcionamento do teclado, LED RGB e buzzer.


Notas
	Ajuste os pinos e configurações conforme necessário para atender aos requisitos específicos do projeto.