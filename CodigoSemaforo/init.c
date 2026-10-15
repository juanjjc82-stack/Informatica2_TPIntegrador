#include "conf.h"

void init(void){
   LED_DIR = 0xFF;  //PORTA Como salida
   LED_PORT = 0x00;  //Al iniciar los LEDs estan apagados
   SW_DIR = 0x00;    //PORTD Como entrada
   PORTD |= (1<<0);  //Boton a GND
   
}