#include <stdint.h>
#include "GPIO.h"
#include "LED.h"
#include "LED_Cfg.h"


#define High    0xFF
#define Low     0x00


void LED_Init(void)
{
    uint8_t LoopIndex;
    for(LoopIndex = 0; LoopIndex < LED_NUMBER; LoopIndex++)
    {
        if(LED_ConfigParam[LoopIndex].ConnectionType == ACTIVE_HIGH)
        {
            GPIO_Write(LED_ConfigParam[LoopIndex].PinID, Low);
        }
        else
        {
            GPIO_Write(LED_ConfigParam[LoopIndex].PinID, High);
        }
    }
}

LED_Chktype LED_On(uint8_t GroupID)
{
    LED_Chktype RetVar;
    if(GroupID < LED_NUMBER)
    {
        if(LED_ConfigParam[GroupID].ConnectionType == ACTIVE_HIGH)
        {
            GPIO_Write(LED_ConfigParam[GroupID].PinID, High);
        }
        else
        {
            GPIO_Write(LED_ConfigParam[GroupID].PinID, Low);
        }
        RetVar = LED_OK;
    }
    else
    {
        RetVar = LED_NOK;
    }
    return RetVar;
}

LED_Chktype LED_Off(uint8_t GroupID)
{
    LED_Chktype RetVar;
    if(GroupID < LED_NUMBER)
    {
        if(LED_ConfigParam[GroupID].ConnectionType == ACTIVE_HIGH)
        {
            GPIO_Write(LED_ConfigParam[GroupID].PinID, Low);
        }
        else
        {
            GPIO_Write(LED_ConfigParam[GroupID].PinID, High);
        }
        RetVar = LED_OK;
    }
    else
    {
        RetVar = LED_NOK;
    }
    return RetVar;
}

LED_Chktype LED_Blink(uint8_t GroupID, uint16_t BlinkTimes)
{
	LED_Chktype RetVar;
    static uint32_t Count[LED_NUMBER] = {0};
    static uint16_t Blink[LED_NUMBER] = {0};
    static uint8_t State[LED_NUMBER] = {0x00};
	if(GroupID < LED_NUMBER)
	{
	    if(Blink[GroupID] < (2 * BlinkTimes))
	    {
	        if(Count[GroupID] == 0)
	        {
	            Count[GroupID]++;
	            Blink[GroupID]++;
                State[GroupID] = ~State[GroupID];
                if(LED_ConfigParam[GroupID].ConnectionType == ACTIVE_HIGH)
                {
                    GPIO_Write(LED_ConfigParam[GroupID].PinID, State[GroupID]);
                }
                else
                {
                    GPIO_Write(LED_ConfigParam[GroupID].PinID, ~State[GroupID]);
                }
	        }
	        else if(Count[GroupID] < LED_ConfigParam[GroupID].Frequency)
	        {
                Count[GroupID]++;
	        }
	        else
	        {
	            Count[GroupID] = 0;
	        }
        }
	    else
	    {
	        /* Do nothing */
	    }
        RetVar = LED_OK;
	}
	else
	{
		RetVar = LED_NOK;
	}
	return RetVar;
}
