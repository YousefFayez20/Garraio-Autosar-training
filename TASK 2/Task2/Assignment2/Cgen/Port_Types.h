#ifndef PORT_TYPES_H
#define PORT_TYPES_H



typedef unsigned char uint8;
#include "tm4c123gh6pm.h"



typedef struct{
    uint8 PortContainer_startingIndex;
    uint8 PortContainer_numberOfInstances;
    
}PortConfigSet_s;


typedef struct{
    uint8 PortNumberOfPortPins;
    uint8 PortPin_startingIndex;
    uint8 PortPin_numberOfInstances;
    
}PortContainer_s;


typedef struct{
    uint8 PortPinDirection;
    uint8 PortPinDirectionChangeable;
    uint8 PortPin_numberOfInstances;
    uint8 PortPinId;
    uint8  PortPinInitialMode;
    uint8 PortPinLevelValue;
    uint8 PortPinMode;
    uint8 PortPinModeChangeable;
    uint8 PortPinInputPullResistor;

}PortPin_s;


typedef struct{
    uint8 PortPinDirection;
    uint8 PortPinDirectionChangeable;
    uint8 PortPin_numberOfInstances;
    uint8 PortPinId;
    uint8  PortPinInitialMode;
    uint8 PortPinLevelValue;
    uint8 PortPinMode;
    uint8 PortPinModeChangeable;
    uint8 PortPinInputPullResistor;

}Port_ConfigType;


void Port_Init(const Port_ConfigType* ConfigPtr);

#endif