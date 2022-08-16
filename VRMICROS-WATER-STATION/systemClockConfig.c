#include "stm32f1xx.h"
#include "systemClockConfig.h"

void system_clock_config(void)
{
	RCC->CFGR = 0x001C000A;
	RCC->CR = 0x13005A83;
}
