#include "main.h"

int main()
{
    stdio_init_all();
    init_pins_gpio();

    gpio_set_irq_enabled_with_callback(bot_A, GPIO_IRQ_EDGE_FALL, true, botoes_callback); //Interrupção SDK

    while (true)
    {
        printf("Aperte o botao A\n");
        sleep_ms(10000);
    }
    
}
