/*
 *	Author 			: Wattanai Pongtham
 *	Create On 	:	13 Apr 2022
 *	Description	:	Header File For STM32F103C8 UART1 Driver
*/

#ifndef UART_H_

#define	UART_H_
#include <stdint.h>
void usart1_Init(uint32_t);
void usart2_Init(uint32_t);
void usart3_Init(uint32_t);
void uart4_Init(uint32_t);

void DMA1_channel2_init(uint32_t src, uint32_t dst, uint32_t len);//USART3_TX
void DMA1_channel3_init(uint32_t src, uint32_t dst, uint32_t len);//USART3_RX
void DMA1_channel4_init(uint32_t src, uint32_t dst, uint32_t len);//USART1_TX
void DMA1_channel5_init(uint32_t src, uint32_t dst, uint32_t len);//USART1_RX
void DMA1_channel6_init(uint32_t src, uint32_t dst, uint32_t len);//USART2_RX
void DMA1_channel7_init(uint32_t src, uint32_t dst, uint32_t len);//USART2_TX

void DMA2_channel3_init(uint32_t src, uint32_t dst, uint32_t len);//UART4_RX
void DMA2_channel5_init(uint32_t src, uint32_t dst, uint32_t len);//UART4_TX

#endif
