#include <avr/io.h>
#include <avr/interrupt.h>
#include "driver.h"

#define LED_PORT PORTA
#define LED_DIR DDRA

#define SW_PIN PIND
#define SW_DIR DDRD

#define SET_BIT(V,bit) ((V) |= (1 << (bit)))
#define CLR_BIT(V,bit) ((V) &=~ (1 << (bit)))
#define SET_BIT(V,bit) ((V) ^= (1 << (bit)))

#define D1 0
#define D2 0
#define D3 0

typedef struct
{
    unsigned char B0:1;
    unsigned char B1:1;
    unsigned char B2:1;
}bit_t;

#define REGBIT(reg,bit)	(((volatile bit_t *)&(reg))->B##bit)

#define LED_DIR_D1 REGBIT(DDRA,0)
#define LED_D1 REGBIT(PORTA,0)

#define LED_D3 REGBIT(PORTA,2)

#define SW REGBIT(PIND,0)

/*
Configuramos el timer para utilizarlo en segundos:

Fint = fclk_I/O / N . (1+OCRn) -> OCRn = (fclk_I/O / N . Fint) - 1
OCR1A = (F_CPU / (prescaler × frecuencia_deseada)) − 1

OCR1A = (16MHz / (256 × 1)) − 1
*/
volatile uint16_t tick_1s = 0;

void timer1_init(void)
{
    TCCR1A = 0; //modo CTC 
    TCCR1B = (1 << WGM12) | (1 << CS12);//TOP = OCR1A y Prescaler 256

    OCR1A = 62499;
    TCNT1 = 0;

    TIMSK |= (1 << OCIE1A); //habilita interrupción por comparación

    sei();  //habilita las interrupciones globales
}

ISR(TIMER1_COMPA_vect)
{
    tick_1s = 1;            //Avisa al main que pasó 1seg
}

void init(void)
{
    LED_DIR = 0xFF; //PORTA Como salida
    LED_PORT = 0x00; //Al iniciar los LEDs estan apagados
    SW_DIR = 0x00; //PORTD Como entrada
    PORTD |= (1 << 0); //Boton a GND
}

uint8_t timer_get_tick(void)
{
    if (tick_1s)
    {
        tick_1s = 0;
        return 1;
    }
    return 0;
}

void led_verde(void)
{
    LED_PORT = ( 1 << PA2 );
}

void led_amarillo(void)
{
    LED_PORT = ( 1 << PA1 );
}

void led_rojo(void)
{
    LED_PORT = ( 1 << PA0 );
}

void leds_apagados(void)
{
    LED_PORT = 0x00;
}

//Configuracion de pulsador

uint8_t pulsador_activo(void)
{
    return !(PIND & (1 << PD0)); //sin presionar el pulsador =0; con el pulsador presionado =1
}