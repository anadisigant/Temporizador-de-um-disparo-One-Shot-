# Clock e Temporizadores
Repositório criado a fim de armazenar uma aplicação prática da função add_alarm_in_ms().<br>
__Autora:__ Ana Karolina Disigant Reis

## Temporizador de um disparo (One Shot)
A função _add_alarm_in_ms()_ tem sua aplicação evidenciada em um sistema de temporização para o acionamento de LEDs, que atua a partir do clique em um
botão (pushbutton).<br>

__Componentes necessários:__
1) Microcontrolador Raspberry Pi Pico W;
2) 03 LEDs (azul, vermelho e verde);
3) 03 Resistores de 330 Ω;
4) Botão (Pushbutton).

__Requisitos de desenvolvimento:__
1) Caso o usuário clique no botão (pushbutton), os três LEDs serão ligados (todos em nível alto). A partir da primeira rotina de atraso, ocorrerá uma mudança de estado para dois LEDs ligados e, em seguida, apenas um;
2) O temporizador do alarme deve ser ajustado para um atraso de 3 segundos (3.000ms), entre os estados de acionamento dos LEDs;
3) A mudança de estado dos LEDs deve ser implementa em funções de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - turn_off_callback();
4) O botão só pode alterar o estado dos LEDs quando o último LED for desligado. Deste modo, durante a execução das rotinas de temporização, o botão não pode iniciar uma nova chamada da função call-back;
5) Com o emprego da Ferramenta Educacional BitDogLab, faça um experimento com o código deste exercício utilizando o LED RGB – GPIOs 11, 12 e 13 e o Botão A, GPIO 05;
6) _Opcional:_ Implementar uma rotina em software para atenuação do efeito bouncing no botão (software debounce).

__Configuração e Compilação:__

1. Clone o repositório:
   ```sh
   git clone https://github.com/anadisigant/Temporizador-de-um-disparo-One-Shot-.git
   cd Temporizador-de-um-disparo-One-Shot-
   ```
2. Configure o ambiente:
   ```sh
   export PICO_SDK_PATH=</caminho/para/o/pico-sdk>
   ```
3. Crie e entre no diretório de build:
   ```sh
   mkdir build && cd build
   ```
4. Execute o CMake:
   ```sh
   cmake ..
   ```
5. Compile o projeto:
   ```sh
   make
   ```
6. Após a compilação, conecte o Raspberry Pi Pico no modo BOOTSEL e arraste o arquivo `.uf2` gerado para o dispositivo.

__Uso__

1. Após carregar o firmware no Raspberry Pi Pico, o temporizador será inicializado.
2. O código está configurado para acionar eventos em intervalos regulares.
3. Para modificar o tempo do temporizador, ajuste os parâmetros no código-fonte.
