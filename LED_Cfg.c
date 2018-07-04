#include "LED.h"
#include "LED_Cfg.h"


const LED_ConfigType LED_ConfigParam[LED_NUMBER] =
{
	{0x00, ACTIVE_HIGH, 100000}
	,
	{0x01, ACTIVE_LOW, 200000}
	,
	{0x02, ACTIVE_HIGH, 1000000}
    ,
    {0x03, ACTIVE_LOW, 1000000}
    ,
    {0x04, ACTIVE_HIGH, 1000000}
};
