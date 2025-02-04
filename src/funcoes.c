#include "main.h"

uint8_t controle_leds = 0; //Variavel de controle de LEDs
volatile bool flag_leds = 0;
volatile uint32_t passado = 0; //Usada para implementar o debouncing
struct repeating_timer timer; //Crie estrutura do tipo timer

/**
 * @brief inicia os pinos de GPIO
 */
void init_pins_gpio()
{
    //Configuração do buzzer B
    gpio_init(buz_B);
    gpio_set_dir(buz_B, GPIO_OUT);

    //Configuração do LED vermelho
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);

    //Configuração do Led Amarelo
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);

    //Configuração do LED verde
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);

}

/**
 * @brief Controla os leds a intervalos regulares definido na função add_repeating_timer_ms
 * @param t recebe ponteiro para a estrutura de dados do temporizador que chamou a função
 * @return retorna true para continuar com o timer ou false para parar
 */
bool apaga_leds(struct repeating_timer *t)
{
    if(controle_leds < 2)
        controle_leds++;
    else
    {
        gpio_put(LED_R, 0);
        printf("Apagaou led3 aos %d ms\n", to_ms_since_boot(get_absolute_time()));
        controle_leds = 0;
        flag_leds = 0;
        printf("Botao Liberado aos %d ms\n", to_ms_since_boot(get_absolute_time()));
        return false;
    }

    printf("%d\n", controle_leds);

    switch (controle_leds)
    {
        case 1:
            gpio_put(LED_G, 0);
            printf("Apagaou led1 aos %d ms\n", to_ms_since_boot(get_absolute_time()));
            break;
        case 2:
            gpio_put(LED_B, 0);
            printf("Apagaou led2 aos %d ms\n", to_ms_since_boot(get_absolute_time()));
            break;
        default:
            break;
    }
    return true;
}

/**
 * @brief trata a interrupção gerada pelo botão A da BitDog
 * @param gpio recebe o pino que gerou a interrupção
 * @param events recebe o evento que causou a interrupção
 */
void botoes_callback(uint gpio, uint32_t events)
{
    // Obtém o tempo atual em microssegundos
    uint32_t agora = to_us_since_boot(get_absolute_time());

    // Verifica se passou tempo suficiente desde o último evento
    if (agora - passado > 200000) // 200 ms de debouncing
    {
        if(!flag_leds)
        {
            flag_leds = 1;
            gpio_put(LED_R, 1);
            gpio_put(LED_G, 1);
            gpio_put(LED_B, 1);
            add_repeating_timer_ms(temp_led, apaga_leds, NULL, &timer); //Cria um temporizador (SDK)
            printf("Disparado aos %d ms\n", to_ms_since_boot(get_absolute_time()));
        }
    }

}

/**
 * @brief reproduz um tom puro
 * @param freq é a frequência do sinal
 * @param duration_ms é a duração do sinal em milisegundos
 */
void som_buz(uint16_t freq, uint16_t duration_ms)
{
    uint period = 1000000 / freq;  // Período do sinal em microssegundos
    uint cycles = (duration_ms * 1000) / period;  // Número de ciclos a gerar

    for (uint i = 0; i < cycles; i++) 
    {
        gpio_put(buz_B, 1);  // Liga o buzzer
        sleep_us(period / 2);  // Espera metade do período
        gpio_put(buz_B, 0);  // Desliga o buzzer
        sleep_us(period / 2);  // Espera metade do período
    }

}

/**
 * @brief coloca o PICO no modo de gravação
 */
void entrar_modo_gravacao() 
{
    printf("Entrando no modo de gravação...\n");
    reset_usb_boot(0, 0); 
}