#include "MM74C922.h"
#include "std_types.h"

static u8 PortId;
static u8 PinId_S;

static u8 Table[16] = {0x00, 0x01, 0x02, 0x03,
                       0x04, 0x05, 0x06, 0x07,
                       0x08, 0x09, 0x0A, 0x0B,
                       0x0C, 0x0D, 0x0E, 0x0F};

void MM74C922_Init(u8 portId, u8 pinId_S , u8 pinId_E)
{
    #if (pinId_S < pinId_E)
        #if ((pinId_E-pinId_S)!= 3)
            #error "Invalid pin configuration"
        #endif
        for (u8 i = pinId_S; i <= pinId_E; i++)
        {
            dio_setPinDirection(portId, i, INPUT);
        }
        PortId = portId;
        PinId_S = pinId_S;
    #elseif (pinId_S => pinId_E)
        #error "Invalid pin configuration"
    #endif
}

void MM74C922_Decode(u8 *data)
{
    u8 temp = 0;
    for (u8 i = PinId_S; i < 4; i++)
    {
        temp |= (dio_readChannel(PortId, PinId_S + i) << i);
    }
    *data = Table[temp];
}