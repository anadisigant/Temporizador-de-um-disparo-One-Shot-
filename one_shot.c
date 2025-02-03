#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"

#define LED1 11
#define LED2 12
#define LED3 13
#define BUTTON 5

volatile bool timer_active = false;
volatile int led_state = 0;
struct repeating_timer timer;  // Variável global para manter o timer ativo

bool debounce_button() {
    static uint32_t last_press_time = 0;
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if (current_time - last_press_time < 200) {
        return false;
    }
    last_press_time = current_time;
    return true;
}

bool turn_off_callback(struct repeating_timer *t) {
    if (led_state == 3) {
        gpio_put(LED2, 0);
    } else if (led_state == 2) {
        gpio_put(LED3, 0);
    } else if (led_state == 1) {
        gpio_put(LED1, 0);
        timer_active = false;
        return false; // Para o timer
    }
    led_state--;
    return true;
}

void button_callback(uint gpio, uint32_t events) {
    if (!timer_active && debounce_button()) {
        gpio_put(LED1, 1);
        gpio_put(LED2, 1);
        gpio_put(LED3, 1);
        led_state = 3;
        timer_active = true;
        add_repeating_timer_ms(-3000, turn_off_callback, NULL, &timer);
    }
}

int main() {
    stdio_init_all();

    // Inicializar LEDs como saída
    gpio_init(LED1);
    gpio_init(LED2);
    gpio_init(LED3);
    gpio_set_dir(LED1, GPIO_OUT);
    gpio_set_dir(LED2, GPIO_OUT);
    gpio_set_dir(LED3, GPIO_OUT);

    // Inicializar botão como entrada com pull-up interno
    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

    // Configurar interrupção para borda de descida (quando o botão for pressionado)
    gpio_set_irq_enabled_with_callback(BUTTON, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    while (1) {
        tight_loop_contents();
    }
}