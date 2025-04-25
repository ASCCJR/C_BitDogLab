#include <stdio.h>
#include "pico/stdlib.h"

#define LEDR 13  // Vermelho (GPIO13)
#define LEDG 11  // Verde (GPIO11)
#define LEDB 12  // Azul (GPIO12)

void led_rgb(bool r, bool g, bool b) {
    gpio_put(LEDR, r);
    gpio_put(LEDG, g);
    gpio_put(LEDB, b);
}

int main() {
    stdio_init_all();
    
    // Configura os LEDs como saída
    gpio_init(LEDR);
    gpio_init(LEDG);
    gpio_init(LEDB);
    gpio_set_dir(LEDR, GPIO_OUT);
    gpio_set_dir(LEDG, GPIO_OUT);
    gpio_set_dir(LEDB, GPIO_OUT);

//A parte  gpio_set_slew_rate foi removida. --> Configuração é desnecessária para LEDs, pois é útil apenas em comunicações de alta velocidade (ex: SPI)

    while (true) {
        // Sequência: Vermelho -> Verde -> Azul -> Branco -> Repete
        led_rgb(1, 0, 0);  // Vermelho
        sleep_ms(500);
        led_rgb(0, 1, 0);  // Verde (Resistor 220Ω)
        sleep_ms(500);
        led_rgb(0, 0, 1);  // Azul (Resistor de 150Ω)
        sleep_ms(500);
        led_rgb(1, 1, 1);  // Branco (todas as cores)
        sleep_ms(500);
    }
}

//(Github BitDogLab) Um LED RGB, cátodo comum, tem o eletrodo do vermelho lidado no GPIO 13 através de um resistor de 220 ohm, 
//o pino de verde está ligado no GPIO 11 também através de um resistor de 220 ohm e o pino do azul no 
// GPIO 12 através de um resistor de 150 ohm. (Github BitDogLab)