#ifndef DRIVER_H
#define DRIVER_H

#include <stdint.h>
#define F_CPU 16000000UL

#define VERDE_T 1
#define AMARILLO_T 1
#define ROJO_T 1

void init(void);

void timer1_init(void);

void led_verde(void);
void led_amarillo(void);
void led_rojo(void);
void leds_apagados(void);

uint8_t timer_get_tick(void);

uint8_t pulsador_activo(void);

#endif