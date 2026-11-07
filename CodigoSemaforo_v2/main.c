#include "driver.h"
#include "estados.h"

int main(void)
{
   init();
   timer1_init();
   estados_init();
   
   while (1)
   {
      control_SW(pulsador_activo);
      
      if (timer_get_tick())
      {
         estados_update();
      }
      
   }
   
   return 0;
}
