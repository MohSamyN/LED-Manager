#include "GPIO.h"
#include "LED.h"


int main(void)
{
	GPIO_Init();
	LED_Init();
    while(1)
	{
        LED_Blink(0, 6);
        LED_Blink(1, 3);
	}
    return 0;
}
