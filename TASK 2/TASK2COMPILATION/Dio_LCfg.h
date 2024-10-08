

#ifndef DIO_LCFG_H
#define DIO_LCFG_H



/******************************************************************************************
****************************************Dio Module****************************************
*********************************Link-Time Configurations*********************************
******************************************************************************************/


/*
* Dio_LCfg_H
* 	File's Includes
*/
#include "Dio_Types.h"
#include "tm4c123gh6pm.h"

typedef unsigned int Dio_ChannelType;
typedef unsigned int Dio_LevelType;
#define DIO_CHANNEL_0_PORT GPIO_PORTA_DATA_R
#define DIO_CHANNEL_1_PORT GPIO_PORTB_DATA_R
#define DIO_CHANNEL_2_PORT GPIO_PORTC_DATA_R
#define DIO_CHANNEL_3_PORT GPIO_PORTD_DATA_R

// Corresponding pin masks
#define DIO_CHANNEL_0_PIN (1U << 0)
#define DIO_CHANNEL_1_PIN (1U << 1)
#define DIO_CHANNEL_2_PIN (1U << 2)
#define DIO_CHANNEL_3_PIN (1U << 3)

/******************************************************************************************
***************************************Dio Module's***************************************
****************************************Structures****************************************
******************************************************************************************/


/*
* DioPort Container
*  Macro Configurations
*/
#define DIO_PORT_SIZE                                 (1U)

/* Container Instance 0*/
#define DIO_PORT_ID_0                                 (0U)
#define DIO_CHANNEL_0_STARTING_INDEX                  (0U)
#define DIO_CHANNEL_0_NUMBER_INSTANCES                (4U)
#define DIO_CHANNEL_GROUP_0_STARTING_INDEX            (0U)
#define DIO_CHANNEL_GROUP_0_NUMBER_INSTANCES          (1U)


/*
* DioConfig Container
*  Macro Configurations
*/
#define DIO_CONFIG_SIZE                               (1U)

/* Container Instance 0*/
#define DIO_CONFIG_ID_0                               (0U)
#define DIO_PORT_0_STARTING_INDEX                     (0U)
#define DIO_PORT_0_NUMBER_INSTANCES                   (1U)


/*
* DioChannel Container
*  Macro Configurations
*/
#define DIO_CHANNEL_SIZE                              (4U)

/* Container Instance 0*/
#define DIO_CHANNEL_ID_0                              (0U)
/* Container Instance 1*/
#define DIO_CHANNEL_ID_1                              (1U)
/* Container Instance 2*/
#define DIO_CHANNEL_ID_2                              (2U)
/* Container Instance 3*/
#define DIO_CHANNEL_ID_3                              (3U)

/*
* DioChannelGroup Container
*  Macro Configurations
*/
#define DIO_CHANNEL_GROUP_SIZE                        (1U)

/* Container Instance 0*/
#define DIO_CHANNEL_GROUP_ID_0                        (0U)

/*DioChannelGroupIdentification: PORTC*/
#define DIO_CONF_DIO_CHANNEL_GROUP_0			((Dio_ChannelGroupType*)(&(DioChannelGroup[DIO_CHANNEL_GROUP_ID_0])))




/******************************************************************************************
**********************************User Defined Map Array**********************************
**************************************Mapping Element**************************************
******************************************************************************************/

#ifndef USER_MAP_ARRAY_ELEMENT_TYPE
#define USER_MAP_ARRAY_ELEMENT_TYPE
/* Used only in case of user defined multiple mapping*/
typedef struct
{
	uint8*	baseAddress;	/*The base address which refers to the UserMapArrayIds*/
	uint8	offset;			/*The number of mapped elements*/

}UserMapArrayElement_s;
#endif

/******************************************************************************************
***************************************Dio Module's***************************************
*************************************Structures Arrays*************************************
******************************************Extern******************************************
******************************************************************************************/


/*
* DioPort Container
* 	Extern Array Of Structures
*/
extern DioPort_s DioPort[DIO_PORT_SIZE];

/*
* DioConfig Container
* 	Extern Array Of Structures
*/
extern DioConfig_s DioConfig[DIO_CONFIG_SIZE];

/*
* DioChannel Container
* 	Extern Array Of Structures
*/
extern DioChannel_s DioChannel[DIO_CHANNEL_SIZE];

/*
* DioChannelGroup Container
* 	Extern Array Of Structures
*/
extern DioChannelGroup_s DioChannelGroup[DIO_CHANNEL_GROUP_SIZE];




/******************************************************************************************
***************************************Dio Module's***************************************
*************************************Structures Sizes*************************************
******************************************Extern******************************************
******************************************************************************************/


/*
* DioPort Container
* 	Extern Size Variable
*/
extern uint8 lcfg_DioPort_size;

/*
* DioConfig Container
* 	Extern Size Variable
*/
extern uint8 lcfg_DioConfig_size;

/*
* DioChannel Container
* 	Extern Size Variable
*/
extern uint8 lcfg_DioChannel_size;

/*
* DioChannelGroup Container
* 	Extern Size Variable
*/
extern uint8 lcfg_DioChannelGroup_size;







/******************************************************************************************
***************************************Dio Module's***************************************
**************************************Default Values**************************************
******************************************************************************************/

#define DEFAULT_PARAMETER_8BIT_VALUE            (255U)
#define DEFAULT_PARAMETER_16BIT_VALUE           (65535U)
#define DEFAULT_PARAMETER_32BIT_VALUE           (4294967295U)
#define DEFAULT_PARAMETER_64BIT_VALUE           (18446744073709551615U)
#define DEFAULT_PARAMETER_BOOLEAN_VALUE         (0U)
#define DEFAULT_PARAMETER_ENUM_VALUE            (0U)
#define DEFAULT_PARAMETER_STRING_VALUE          ("\0")
#define DEFAULT_REFERENCE_TYPE                  (0U)
#define DEFAULT_REFERENCE_NUMBER_INSTANCES      (0U)
#define DEFAULT_REFERENCE_VALUE                 ((void *)0)
#define DEFAULT_PARAMETER_FUNCTION_NAME_VALUE   ((void *)0)
#define DEFAULT_CONTAINER_TYPE                  (0U)
#define DEFAULT_CONTAINER_STARTING_VALUE        (0U)
#define DEFAULT_CONTAINER_NUMBER_INSTANCES      (0U)
#define FALSE                                   (0U)
#define TRUE                                    (1U)
#define STD_LOW                                 (0U)
#define STD_HIGH                                 (1U)

void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);


#endif