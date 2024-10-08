

/******************************************************************************************
****************************************Dio Module****************************************
*********************************Link-Time Configurations*********************************
******************************************************************************************/





#include "Dio_LCfg.h"
#include "Dio_Types.h"


/******************************************************************************************
*************************************DioPort Container*************************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_DioPort_size = DIO_PORT_SIZE;

/* Array Of Structures Linking Configurations*/
DioPort_s DioPort[DIO_PORT_SIZE] =
{
	{	/*Instance_0*/
		.DioPortId = 1,
		.DioChannel_startingIndex = DIO_CHANNEL_0_STARTING_INDEX,
		.DioChannel_numberOfInstances = DIO_CHANNEL_0_NUMBER_INSTANCES,
		.DioChannelGroup_startingIndex = DIO_CHANNEL_GROUP_0_STARTING_INDEX,
		.DioChannelGroup_numberOfInstances = DIO_CHANNEL_GROUP_0_NUMBER_INSTANCES
	}
};
/******************************************************************************************
************************************DioConfig Container************************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_DioConfig_size = DIO_CONFIG_SIZE;

/* Array Of Structures Linking Configurations*/
DioConfig_s DioConfig[DIO_CONFIG_SIZE] =
{
	{	/*Instance_0*/
		.DioPort_startingIndex = DIO_PORT_0_STARTING_INDEX,
		.DioPort_numberOfInstances = DIO_PORT_0_NUMBER_INSTANCES
	}
};
/******************************************************************************************
***********************************DioChannel Container***********************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_DioChannel_size = DIO_CHANNEL_SIZE;

/* Array Of Structures Linking Configurations*/
DioChannel_s DioChannel[DIO_CHANNEL_SIZE] =
{
	{	/*Instance_0*/
		.DioChannelId = 0
	},
	{	/*Instance_1*/
		.DioChannelId = 1
	},
	{	/*Instance_2*/
		.DioChannelId = 2
	},
	{	/*Instance_3*/
		.DioChannelId = 3
	}
};
/******************************************************************************************
*********************************DioChannelGroup Container*********************************
*******************************Size And Array Of Structures*******************************
**********************************Linking Configurations **********************************
******************************************************************************************/

/* Size Variable Linking Configuration*/
uint8 lcfg_DioChannelGroup_size = DIO_CHANNEL_GROUP_SIZE;

/* Array Of Structures Linking Configurations*/
DioChannelGroup_s DioChannelGroup[DIO_CHANNEL_GROUP_SIZE] =
{
	{	/*Instance_0*/
		.DioPortMask = 1,
		.DioPortOffset = 1,
		.DioPortId = 1
	}
};





// Function to write to a specific DIO channel
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
    if (ChannelId == 0) {
        if (Level == STD_HIGH) {
            DIO_CHANNEL_0_PORT |= DIO_CHANNEL_0_PIN;
        } else {
            DIO_CHANNEL_0_PORT &= ~DIO_CHANNEL_0_PIN;
        }
    } else if (ChannelId == 1) {
        if (Level == STD_HIGH) {
            DIO_CHANNEL_1_PORT |= DIO_CHANNEL_1_PIN;
        } else {
            DIO_CHANNEL_1_PORT &= ~DIO_CHANNEL_1_PIN;
        }
    } else if (ChannelId == 2) {
        if (Level == STD_HIGH) {
            DIO_CHANNEL_2_PORT |= DIO_CHANNEL_2_PIN;
        } else {
            DIO_CHANNEL_2_PORT &= ~DIO_CHANNEL_2_PIN;
        }
    } else if (ChannelId == 3) {
        if (Level == STD_HIGH) {
            DIO_CHANNEL_3_PORT |= DIO_CHANNEL_3_PIN;
        } else {
            DIO_CHANNEL_3_PORT &= ~DIO_CHANNEL_3_PIN;
        }
    } else {
        
    }
}

// Function to read the current level of a specific DIO channel
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) {
    if (ChannelId == 0) {
        if (DIO_CHANNEL_0_PORT & DIO_CHANNEL_0_PIN) {
            return STD_HIGH;
        } else {
            return STD_LOW;
        }
    } else if (ChannelId == 1) {
        if (DIO_CHANNEL_1_PORT & DIO_CHANNEL_1_PIN) {
            return STD_HIGH;
        } else {
            return STD_LOW;
        }
    } else if (ChannelId == 2) {
        if (DIO_CHANNEL_2_PORT & DIO_CHANNEL_2_PIN) {
            return STD_HIGH;
        } else {
            return STD_LOW;
        }
    } else if (ChannelId == 3) {
        if (DIO_CHANNEL_3_PORT & DIO_CHANNEL_3_PIN) {
            return STD_HIGH;
        } else {
            return STD_LOW;
        }
    } else {
       
        return STD_LOW;
    }
}
