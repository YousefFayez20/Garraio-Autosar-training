#include "Dio_LCfg.h"
#include "Port_LCfg.h"
#include "tm4c123gh6pm.h"


int i =0;
int main(void) {
 Port_Init(&PortPin[0]);

   
    Dio_WriteChannel(1, STD_HIGH); 

  
  
    while (1) {
		   
    Dio_WriteChannel(0, STD_HIGH); 
     for(i =0 ;i<50000000; i++);
    Dio_WriteChannel(0, STD_LOW);
    for(i =0 ;i<50000000; i++);
		
		}

    


    return 0;
}
