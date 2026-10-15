#include "conf.h"

int main(void){
    
    init();
    while (1){
        
        if (!SW)
        {
            LED_D3 = 1;
            _delay_ms(500);
            LED_D3 = 0;
            
            LED_D2 = 1;
            _delay_ms(500);
            LED_D2 = 0;

            LED_D1 = 1;
            _delay_ms(500);
            LED_D1 = 0;
        }
        
    }
    
    return 0;
}
