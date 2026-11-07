#include <stdint.h>

#include "estados.h"
#include "driver.h"

typedef enum
{
   VERDE,
   AMARILLO,
   AMARILLO2,
   ROJO,
   APAGADO
}estado_t;

static estado_t estado = APAGADO; //Con static solo estados.c puede acceder a estado
static uint8_t segundos = 0;

static uint8_t comenzar = 0;
static uint8_t finalizar = 0;

void estados_init(void)
{
   estado = APAGADO;
   comenzar = 0;
   finalizar = 0;
   segundos = 0;

   leds_apagados();
}

void control_SW (uint8_t pulsador_activo())
{
   if (pulsador_activo() == 1)
   {
      comenzar = 1;
   } else if (pulsador_activo() == 0)
   {
      comenzar = 0;
   }
   
   
}
void estados_update()
{
   
   segundos++;
   switch (estado)
         {
         case ROJO:
            if( segundos >= ROJO_T )
            {
               
               segundos = 0;
               if ( comenzar == 1 )
               {
                  estado = AMARILLO;
                  led_rojo();
               }
               else
               {
                  estado = APAGADO;
                  leds_apagados();
               }
               
            }
            break;
         case APAGADO:
            if ( comenzar == 0 )
            {
               estado = ROJO;
               segundos = 0;
               leds_apagados();
            }
            break;
         case AMARILLO:
            if ( segundos >= AMARILLO_T )
            {
               estado = VERDE;
               segundos = 0;
               led_amarillo();
               
               }
            break;
         case VERDE:
            if ( segundos >= VERDE_T )
            {
               estado = AMARILLO2;
               segundos = 0;
               led_verde();
               
            }
            break;
            
         case AMARILLO2:
            if ( segundos >= AMARILLO_T )
            {
               estado = ROJO;
               segundos = 0;
               led_amarillo();
               
            }
            break;
            
      }
   
}
