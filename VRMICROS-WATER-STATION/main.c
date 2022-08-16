#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include "stm32f1xx.h"
#include "systemClockConfig.h"
#include "sysTick.h"
#include "usart.h"
#include "GSMCommand.h"
#include "ECDO.h"

int count = 0, distance = 0, num = 0, digit1 = 0, digit2 = 0, digit3 = 0, digit4 = 0;
unsigned byte1,byte2,byte3,byte4,sum,decimal;
char DOBuff[15];
char ECBuff[17];
char DOCommand[8] = {0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x85, 0xDB};
char ECCommand[8] = {0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0xC5, 0xDA};
__IO uint32_t tmpreg;

int main(void){
	
	/*Configure System Clock To 36MHz*/
	system_clock_config();
	
	/*Wait For Complete Configuring System Clock*/
	sysTickDelayMs(500);
	
	/*Initial USART1 With Baudrate 9600*/
	usart1_Init(0xEA6);
	
	/*Initial USART2 With Baudrate 9600*/
	usart2_Init(0xEA6);
	
	/*Initial USART3 With Baudrate 9600*/
	usart3_Init(0xEA6);
	
	/*Initial UART4 With Baudrate 9600*/
	uart4_Init(0xEA6);
	
	/*Set GPIOA Pin 4&5 As HIGH For Enable DI Pin of MAX485 Module*/
	EC_Enable();
	
	/*Enable DMA1 Channel 3 To Recieve Incomming Data*/
	DMA1_channel3_init((uint32_t) ECBuff, (uint32_t) &USART3->DR, 17);
	
	/*Enable DMA1 Channel 4 To Transmit Request Packet*/
	DMA1_channel4_init((uint32_t) ECCommand, (uint32_t) &USART1->DR, 8);
	
	/*Waiting For 10ms*/
	sysTickDelayMs(10);
	
	/*Disable DI Pin of MAX485 Module*/
	EC_Disable();
	
	/*Waiting For 1000ms*/
	sysTickDelayMs(1000);
	
	/*Set GPIOA Pin 4&6 As HIGH For Enable DI Pin of MAX485 Module*/
	DO_Enable();
	
	/*Enable DMA2 Channel 3 To Recieve Incomming Data*/
	DMA2_channel3_init((uint32_t) DOBuff, (uint32_t) &UART4->DR, 15);
	
	/*Enable DMA1 Channel 4 To Transmit Request Packet*/
	DMA1_channel4_init((uint32_t) DOCommand, (uint32_t) &USART1->DR, 8);
	
	/*Waiting For 10ms*/
	sysTickDelayMs(10);
	
	/*Disable DI Pin of MAX485 Module*/
	DO_Disable();
	
	/*Wait For SIM800L Ready*/
	sysTickDelayMs(5000);
	sysTickDelayMs(5000);
	sysTickDelayMs(5000);

	/*Enable DMA1 Channel 5 To Recieve Incomming Data*/
	DMA1_channel5_init((uint32_t) RES_CMD, (uint32_t) &USART1->DR, 50);
	
	/*Enable DMA1 Channel 4 To Transmit First GSM Command*/
	DMA1_channel4_init((uint32_t) AT_CMD, (uint32_t) &USART1->DR, 4);
	while(1){
		
	}
}

void USART1_IRQHandler(void)
{
	if(USART1->SR & (1U<<4) && USART1->CR1 & (1U<<4)){
		switch(count){
			case 0:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(RES_CMD[2] == 'O' && RES_CMD[3] == 'K')
				{
					count = count + 1;
					DMA1_channel5_init((uint32_t) RES_CIPSHUT, (uint32_t) &USART1->DR, 50);
					DMA1_channel4_init((uint32_t) AT_CIPSHUT, (uint32_t) &USART1->DR, 12);
				}else
				{
					//DMA1_channel5_init((uint32_t) RES_CMD, (uint32_t) &USART1->DR, 50);
					//DMA1_channel4_init((uint32_t) AT_CMD, (uint32_t) &USART1->DR, 4);
					NVIC_SystemReset();
				}
				break;
			case 1:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(RES_CIPSHUT[2] == 'S' && RES_CIPSHUT[3] == 'H' && RES_CIPSHUT[4] == 'U' && RES_CIPSHUT[5] == 'T' && RES_CIPSHUT[7] == 'O' && RES_CIPSHUT[8] == 'K')
				{
					count = count + 1;
					DMA1_channel5_init((uint32_t) RES_CGATT, (uint32_t) &USART1->DR, 50);
					DMA1_channel4_init((uint32_t) AT_CGATT, (uint32_t) &USART1->DR, 12);
				}else
				{
					//DMA1_channel5_init((uint32_t) RES_CIPSHUT, (uint32_t) &USART1->DR, 50);
					//DMA1_channel4_init((uint32_t) AT_CIPSHUT, (uint32_t) &USART1->DR, 12);
					NVIC_SystemReset();
				}
				break;
			case 2:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(RES_CGATT[2] == 'O' && RES_CGATT[3] == 'K')
				{
					count = count + 1;
					DMA1_channel5_init((uint32_t) RES_CFUN, (uint32_t) &USART1->DR, 50);
					DMA1_channel4_init((uint32_t) AT_CFUN, (uint32_t) &USART1->DR, 11);
				}else
				{
					//DMA1_channel5_init((uint32_t) RES_CGATT, (uint32_t) &USART1->DR, 50);
					//DMA1_channel4_init((uint32_t) AT_CGATT, (uint32_t) &USART1->DR, 12);
					NVIC_SystemReset();
				}
				break;
			case 3:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(RES_CFUN[2] == 'O' && RES_CFUN[3] == 'K')
				{
					count = count + 1;
					DMA1_channel5_init((uint32_t) RES_CPIN, (uint32_t) &USART1->DR, 50);
					DMA1_channel4_init((uint32_t) AT_CPIN, (uint32_t) &USART1->DR, 10);
				}else
				{
					//DMA1_channel5_init((uint32_t) RES_CFUN, (uint32_t) &USART1->DR, 50);
					//DMA1_channel4_init((uint32_t) AT_CFUN, (uint32_t) &USART1->DR, 11);
					NVIC_SystemReset();
				}
				break;
			case 4:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(RES_CPIN[9] == 'R' && RES_CPIN[10] == 'E' && RES_CPIN[11] == 'A' && RES_CPIN[12] == 'D' && RES_CPIN[13] == 'Y' && RES_CPIN[18] == 'O' && RES_CPIN[19] == 'K' )
				{
					count = count + 1;
					DMA1_channel5_init((uint32_t) RES_CSTT, (uint32_t) &USART1->DR, 50);
					DMA1_channel4_init((uint32_t) AT_CSTT, (uint32_t) &USART1->DR, 34);
				}else
				{
					//DMA1_channel5_init((uint32_t) RES_CPIN, (uint32_t) &USART1->DR, 50);
					//DMA1_channel4_init((uint32_t) AT_CPIN, (uint32_t) &USART1->DR, 10);
					NVIC_SystemReset();
				}
				break;
			case 5:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(1)
				{
					count = count + 1;
					DMA1_channel5_init((uint32_t) RES_CIICR, (uint32_t) &USART1->DR, 50);
					DMA1_channel4_init((uint32_t) AT_CIICR, (uint32_t) &USART1->DR, 10);
				}else
				{
					//DMA1_channel5_init((uint32_t) RES_CSTT, (uint32_t) &USART1->DR, 50);
					//DMA1_channel4_init((uint32_t) AT_CSTT, (uint32_t) &USART1->DR, 34);
					NVIC_SystemReset();
				}
				break;
			case 6:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(RES_CIICR[2] == 'O' && RES_CIICR[3] == 'K')
				{
					count = count + 1;
					DMA1_channel5_init((uint32_t) RES_CIFSR, (uint32_t) &USART1->DR, 50);
					DMA1_channel4_init((uint32_t) AT_CIFSR, (uint32_t) &USART1->DR, 10);
				}else
				{
					//DMA1_channel5_init((uint32_t) RES_CIICR, (uint32_t) &USART1->DR, 50);
					//DMA1_channel4_init((uint32_t) AT_CIICR, (uint32_t) &USART1->DR, 10);
					NVIC_SystemReset();
				}
				break;
			case 7:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(isdigit(RES_CIFSR[2]) && isdigit(RES_CIFSR[3]))
				{
					count = count + 1;
					DMA1_channel5_init((uint32_t) RES_CIPSTART, (uint32_t) &USART1->DR, 150);
					DMA1_channel4_init((uint32_t) AT_CIPSTART, (uint32_t) &USART1->DR, 43);
				}else
				{
					//DMA1_channel5_init((uint32_t) RES_CIFSR, (uint32_t) &USART1->DR, 50);
					//DMA1_channel4_init((uint32_t) AT_CIFSR, (uint32_t) &USART1->DR, 10);
					NVIC_SystemReset();
				}
				break;
			case 8:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(RES_CIPSTART[2] == 'O' && RES_CIPSTART[3] == 'K')
				{
					count = count + 1;
					DMA1_channel5_init((uint32_t) RES_CIPSTART2, (uint32_t) &USART1->DR, 50);
				}else
				{
					//DMA1_channel5_init((uint32_t) RES_CIPSTART, (uint32_t) &USART1->DR, 50);
					//DMA1_channel4_init((uint32_t) AT_CIPSTART, (uint32_t) &USART1->DR, 43);
					NVIC_SystemReset();
				}
				break;
			case 9:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(RES_CIPSTART2[10] == 'O' && RES_CIPSTART2[11] == 'K')
				{
						count = count + 1;
						DMA1_channel5_init((uint32_t) RES_CIPSEND, (uint32_t) &USART1->DR, 50);
						DMA1_channel4_init((uint32_t) AT_CIPSEND, (uint32_t) &USART1->DR, 15);
				}else
				{
						NVIC_SystemReset();
				}
				break;
			case 10:
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				if(RES_CIPSEND[2] == '>')
				{
						count = count + 1;
						DMA1_channel5_init((uint32_t) RES_SERVER, (uint32_t) &USART1->DR, 50);
						DMA1_channel4_init((uint32_t) DATA, (uint32_t) &USART1->DR, 68);
				}else
				{
						NVIC_SystemReset();
				}
				break;
			default :
				tmpreg = USART1->SR;
				(void) tmpreg;
				tmpreg = USART1->DR;
				(void) tmpreg;
				NVIC_SystemReset();
				break;
		}
	}
}

void USART2_IRQHandler(void)
{
	tmpreg = USART3->SR;
	(void) tmpreg;
	tmpreg = USART3->DR;
	(void) tmpreg;
	if(num < 100){
	num = num + 1;
	distance += ((int)RES_MX7383[1] - 48)*1000;
	distance += ((int)RES_MX7383[2] - 48)*100;
	distance += ((int)RES_MX7383[3] - 48)*10;
	distance += ((int)RES_MX7383[4] - 48)*1;
	DMA1_channel6_init((uint32_t) RES_MX7383, (uint32_t) &USART2->DR, 6);
	}else
	{
		/*Disable Receiver*/
		USART2->CR1		&=	~(1U<<2);
	
		/*Disable UART2*/
		USART2->CR1		&=	~(1U<<13);

		distance = distance/100;
		digit1 = distance/1000;
		digit2 = (distance/100)%10;
		digit3 = (distance%100)/10;
		digit4 = distance%10;
		if(digit1 == 0)
		{
			DATA[37] = 0x20;
		}else{
			DATA[37] = digit1+48;
		}
		DATA[38] = digit2+48;
		DATA[39] = digit3+48;
		DATA[40] = digit4+48;
	
		/*Enable DMA1 Channel 5 To Recieve Incomming Data*/
		DMA1_channel5_init((uint32_t) RES_CMD, (uint32_t) &USART1->DR, 50);
	
		/*Enable DMA1 Channel 4 To Transmit First GSM Command*/
		DMA1_channel4_init((uint32_t) AT_CMD, (uint32_t) &USART1->DR, 4);
	}
}

void USART3_IRQHandler(void)
{
	tmpreg = USART3->SR;
	(void) tmpreg;
	tmpreg = USART3->DR;
	(void) tmpreg;
	byte1 = ECBuff[11];
	byte2 = ECBuff[12];
	byte3 = ECBuff[13];
	byte4 = ECBuff[14];
	byte1 = byte1<<24;
	byte2 = byte2<<16;
	byte3 = byte3<<8;
	sum = byte1+byte2+byte3+byte4;
	decimal = sum%100;
	sum = sum/100;
	if(sum <=9){
		DATA[47] = ' ';
		DATA[48] = ' ';
		DATA[49] = ' ';
		DATA[50] = ' ';
		DATA[51] = (sum%10)+48;
		DATA[53] = (decimal/10)+48;
		DATA[54] = (decimal%10)+48;
	}else if(sum <= 99 && sum >= 10){
		DATA[47] = ' ';
		DATA[48] = ' ';
		DATA[49] = ' ';
		DATA[50] = ((sum%100)/10)+48;
		DATA[51] = (sum%10)+48;
		DATA[53] = (decimal/10)+48;
		DATA[54] = (decimal%10)+48;
	}else if(sum <= 999 && sum >= 100){
		DATA[47] = ' ';
		DATA[48] = ' ';
		DATA[49] = ((sum%1000)/10)+48;
		DATA[50] = ((sum%100)/10)+48;
		DATA[51] = (sum%10)+48;
		DATA[53] = (decimal/10)+48;
		DATA[54] = (decimal%10)+48;
	}else if(sum <= 9999 && sum >= 1000){
		DATA[47] = ' ';
		DATA[48] = ((sum%10000)/10)+48;
		DATA[49] = ((sum%1000)/10)+48;
		DATA[50] = ((sum%100)/10)+48;
		DATA[51] = (sum%10)+48;
		DATA[53] = (decimal/10)+48;
		DATA[54] = (decimal%10)+48;
	}else if(sum <= 99999 && sum >= 10000){
		DATA[47] = (sum/10)+48;
		DATA[48] = ((sum%10000)/10)+48;
		DATA[49] = ((sum%1000)/10)+48;
		DATA[50] = ((sum%100)/10)+48;
		DATA[51] = (sum%10)+48;
		DATA[53] = (decimal/10)+48;
		DATA[54] = (decimal%10)+48;
	}
}

void UART4_IRQHandler(void){
	tmpreg = UART4->SR;
	(void) tmpreg;
	tmpreg = UART4->DR;
	(void) tmpreg;
	byte1 = DOBuff[11];
	byte2 = DOBuff[12];
	byte1 = byte1<<8;
	byte1 = byte1+byte2;
	if((byte1/1000) == 0){
		DATA[61] = ' ';
	}else{
		DATA[61] = (byte1/1000)+48;
	}
	DATA[62] = ((byte1/100)%10)+48;
	DATA[64] = ((byte1%100)/10)+48;
	DATA[65] = (byte1%10)+48;
}
