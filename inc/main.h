#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/bootrom.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

/********************* Defines *********************/
#define bot_A   5

#define buz_B   10

#define LED_G   11
#define LED_B   12
#define LED_R   13

#define temp_led 3000

/********************* Variaveis Globais *********************/


/********************* Prototipo de Funções *********************/

void init_pins_gpio();
void led_amarelo();
bool apaga_leds(struct repeating_timer *t);
void botoes_callback(uint gpio, uint32_t events);
void som_buz(uint16_t freq, uint16_t duration_ms);
void entrar_modo_gravacao();

#endif //MAIN_H