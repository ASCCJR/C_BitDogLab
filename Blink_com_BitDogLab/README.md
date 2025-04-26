# Código Original 
## Exercício:
Faça uma adaptação neste código em C de forma que o programa pisque o LED na cor vermelha e também na cor verde. Comece pelo fluxograma, depois modifique o pseudocódigo, e por fim implemente e depure seu código em C. Faça um vídeo, de no máximo 15 segundos, mostrando seu funcionamento e carregue no Moodle.

Foi fornecido o código:
```c
/**
 * Embarcatech 
 * Exemplo Blink com a BitDogLab
 */

#include "pico/stdlib.h"

int main() {
    // Define o pino do LED e o configura como saída
    const uint LED_PIN = 12;  // Substitua com o número do GPIO desejado
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        // Liga o LED
        gpio_put(LED_PIN, true);
        sleep_ms(250);  // Espera 250ms

        // Desliga o LED
        gpio_put(LED_PIN, false);
        sleep_ms(250);  // Espera 250ms
    }
}
```
Disponivel em: https://github.com/BitDogLab/BitDogLab-C/tree/main/blink
