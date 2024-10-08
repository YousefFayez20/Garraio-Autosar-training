#ifndef DIO_H_
#define DIO_H_


typedef unsigned char uint8;
typedef unsigned int uint32;



typedef struct{
uint8 DioPortId;
uint8 DioChannel_startingIndex;
uint8 DioChannel_numberOfInstances;
uint8 DioChannelGroup_startingIndex;
uint8 DioChannelGroup_numberOfInstances;
}DioPort_s;


typedef struct{

uint8 DioPort_startingIndex;
uint8 DioPort_numberOfInstances;

}DioConfig_s;

typedef struct{
uint8 DioChannelId;
}DioChannel_s;
typedef struct{
  uint8 DioPortMask;
  uint8 DioPortOffset;
  uint8 DioPortId;

}DioChannelGroup_s;

#endif