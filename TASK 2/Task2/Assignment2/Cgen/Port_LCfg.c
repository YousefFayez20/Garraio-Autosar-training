

/******************************************************************************************
****************************************Port Module****************************************
*********************************Link-Time Configurations*********************************
******************************************************************************************/





#include "Port_LCfg.h"



/******************************************************************************************
********************************** Linker Configurations **********************************
******************************************************************************************/




/******************************************************************************************
***************************** Port Containers Configurations  *****************************
******************************************************************************************/






/******************************************************************************************
**********************************PortConfigSet Container**********************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_PortConfigSet_size = PORT_CONFIG_SET_SIZE;

/* Array Of Structures Linking Configurations*/
PortConfigSet_s PortConfigSet[PORT_CONFIG_SET_SIZE] =
{
	{	/*Instance_0*/
		.PortContainer_startingIndex = PORT_CONTAINER_0_STARTING_INDEX,
		.PortContainer_numberOfInstances = PORT_CONTAINER_0_NUMBER_INSTANCES
	}
};



/******************************************************************************************
**********************************PortContainer Container**********************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_PortContainer_size = PORT_CONTAINER_SIZE;

/* Array Of Structures Linking Configurations*/
PortContainer_s PortContainer[PORT_CONTAINER_SIZE] =
{
	{	/*Instance_0*/
		.PortNumberOfPortPins = 4,
		.PortPin_startingIndex = PORT_PIN_0_STARTING_INDEX,
		.PortPin_numberOfInstances = PORT_PIN_0_NUMBER_INSTANCES
	}
};



/******************************************************************************************
*************************************PortPin Container*************************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_PortPin_size = PORT_PIN_SIZE;

/* Array Of Structures Linking Configurations*/
PortPin_s PortPin[PORT_PIN_SIZE] =
{
	{	/*Instance_0*/
		.PortPinDirection = PORT_PIN_OUT,
		.PortPinDirectionChangeable = FALSE,
		.PortPinId = 1,
		.PortPinInitialMode = PORT_PIN_MODE_DIO,
		.PortPinLevelValue = PORT_PIN_LEVEL_LOW,
		.PortPinMode = PORT_PIN_MODE_DIO,
		.PortPinModeChangeable = FALSE,
		.PortPinInputPullResistor = PORT_PIN_IN_NO_PULL
	},
	{	/*Instance_1*/
		.PortPinDirection = PORT_PIN_IN,
		.PortPinDirectionChangeable = FALSE,
		.PortPinId = 2,
		.PortPinInitialMode = PORT_PIN_MODE_DIO,
		.PortPinLevelValue = PORT_PIN_LEVEL_HIGH,
		.PortPinMode = PORT_PIN_MODE_DIO,
		.PortPinModeChangeable = FALSE,
		.PortPinInputPullResistor = PORT_PIN_IN_PULL_DOWN
	},
	{	/*Instance_2*/
		.PortPinDirection = PORT_PIN_IN,
		.PortPinDirectionChangeable = FALSE,
		.PortPinId = 3,
		.PortPinInitialMode = PORT_PIN_MODE_DIO,
		.PortPinLevelValue = PORT_PIN_LEVEL_HIGH,
		.PortPinMode = PORT_PIN_MODE_DIO,
		.PortPinModeChangeable = FALSE,
		.PortPinInputPullResistor = PORT_PIN_IN_PULL_UP
	},
	{	/*Instance_3*/
		.PortPinDirection = PORT_PIN_IN,
		.PortPinDirectionChangeable = FALSE,
		.PortPinId = 4,
		.PortPinInitialMode = PORT_PIN_MODE_DIO,
		.PortPinLevelValue = PORT_PIN_LEVEL_HIGH,
		.PortPinMode = PORT_PIN_MODE_DIO,
		.PortPinModeChangeable = FALSE,
		.PortPinInputPullResistor = PORT_PIN_IN_NO_PULL
	}
};

 void Port_Init(const Port_ConfigType* ConfigPtr) {
    // 
   // Enable clock for Port F
    SYSCTL_RCGCGPIO_R |= (1U << 5);
   
    for (uint8 i = 0; i < lcfg_PortPin_size; i++) {
        
        const PortPin_s* pinConfig = &PortPin[i];
        SYSCTL_RCGCGPIO_R  |= (pinConfig->PortPinId - 1);
         while ((SYSCTL_PRGPIO_R & (pinConfig->PortPinId - 1)) == 0) {};  // Wait until Port F is ready

   
          GPIO_PORTF_LOCK_R = 0x4C4F434B;
        if (pinConfig->PortPinDirection == PORT_PIN_OUT) {
            GPIO_PORTF_DIR_R |= (1 << (pinConfig->PortPinId - 1));  
        } else {
            GPIO_PORTF_DIR_R &= ~(1 << (pinConfig->PortPinId - 1));  
        }

        
        if (pinConfig->PortPinInputPullResistor == PORT_PIN_IN_PULL_DOWN) {
            GPIO_PORTF_PDR_R |= (1 << (pinConfig->PortPinId - 1));  
        } else {
            GPIO_PORTF_PDR_R &= ~(1 << (pinConfig->PortPinId - 1));  
        }

        
        if (pinConfig->PortPinLevelValue == PORT_PIN_LEVEL_HIGH) {
            GPIO_PORTF_DATA_R |= (1 << (pinConfig->PortPinId - 1));  
        } else {
            GPIO_PORTF_DATA_R &= ~(1 << (pinConfig->PortPinId - 1));  
        }

        GPIO_PORTF_DEN_R |= (1 << (pinConfig->PortPinId - 1));  
    }
}
