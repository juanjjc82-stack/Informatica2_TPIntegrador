#ifndef CONF_H
#define CONF_H

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define SET_BIT(V,bit) ((V) |= (1 << (bit)))
#define CLR_BIT(V,bit) ((V) &=~ (1 << (bit)))
#define SET_BIT(V,bit) ((V) ^= (1 << (bit)))

#define D1 0
#define D2 0
#define D3 0
#define D4 0
#define D5 0
#define D6 0
#define D7 0
#define D8 0

#define LED_PORT PORTA
#define LED_DIR DDRA

#define SW_PIN PIND
#define SW_DIR DDRD

typedef struct{
   unsigned char B0:1;
   unsigned char B1:1;
   unsigned char B2:1;
   unsigned char B3:1;
   unsigned char B4:1;
   unsigned char B5:1;
   unsigned char B6:1;
   unsigned char B7:1;
   }bit_t;

/*Macro para manejar registros de a un bit*/
#define REGBIT(reg,bit)	(((volatile bit_t *)&(reg))->B##bit) 

#define LED_DIR_D1 REGBIT(DDRA,0)
#define LED_D1 REGBIT(PORTA,0)
#define LED_D2 REGBIT(PORTA,1)
#define LED_D3 REGBIT(PORTA,2)
#define LED_D4 REGBIT(PORTA,3)
#define LED_D5 REGBIT(PORTA,4)
#define LED_D6 REGBIT(PORTA,5)
#define LED_D7 REGBIT(PORTA,6)
#define LED_D8 REGBIT(PORTA,7)

#define SW REGBIT(PIND,0)

/*Inicializa el micro*/

   void init(void);
   
#endif