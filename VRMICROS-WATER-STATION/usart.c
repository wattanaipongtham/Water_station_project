#include <stdio.h>
#include "stm32f10x.h"
#include "usart.h"

void usart1_Init(uint32_t baudrate)
{
	/*Enable Alternate Function For Peripheral Pin*/
	RCC->APB2ENR	|=	(1U<<0);
	
	/*Enable Clock To Port A*/
	RCC->APB2ENR	|=	(1U<<2);
	
	/*Enable Clock To UART1*/
	RCC->APB2ENR |= 	(1U<<14);
	
	/*Configure Port A Pin9 As Alternate Function Output PP 50MHz*/
	GPIOA->CRH		|=	(1U<<7);
	GPIOA->CRH		&=	~(1U<<6);
	GPIOA->CRH		|=	(1U<<5);
	GPIOA->CRH		|=	(1U<<4);
	
	/*Configure Port A Pin10 As Input Pull-up Pull-down*/
	GPIOA->CRH		|=	(1U<<11);
	GPIOA->CRH		&=	~(1U<<10);
	GPIOA->CRH		&=	~(1U<<9);
	GPIOA->CRH		&=	~(1U<<8);
	
	/*Configure Buad Rate*/
	USART1->BRR		|=	baudrate;
	
	/*Enable Transmitter*/
	USART1->CR1		|=	(1U<<3);
	
	/*Enable Receiver*/
	USART1->CR1		|=	(1U<<2);
	
	/*Enable IDLE Line*/
	USART1->CR1	|=	(1U<<4);
	
	/*Enable UART*/
	USART1->CR1		|=	(1U<<13);
	
	/*Enable Interupt When IDLE Line Occur */
	NVIC_EnableIRQ(USART1_IRQn);
}

void usart2_Init(uint32_t baudrate)
{
	/*Enable Alternate Function For Peripheral Pin*/
	RCC->APB2ENR	|=	(1U<<0);
	
	/*Enable Clock To Port A*/
	RCC->APB2ENR	|=	(1U<<2);
	
	/*Enable Clock To UART2*/
	RCC->APB1ENR |= 	(1U<<17);
	
	
	/*Configure Port A Pin2 As Alternate Function Output PP 50MHz*/
	GPIOA->CRL		|=	(1U<<11);
	GPIOA->CRL		&=	~(1U<<10);
	GPIOA->CRL		|=	(1U<<9);
	GPIOA->CRL		|=	(1U<<8);
	
	/*Configure Port A Pin3 As Input Pull-up Pull-down*/
	GPIOA->CRL		|=	(1U<<15);
	GPIOA->CRL		&=	~(1U<<14);
	GPIOA->CRL		&=	~(1U<<13);
	GPIOA->CRL		&=	~(1U<<12);
	
	/*Configure Buad Rate*/
	USART2->BRR		|=	baudrate;
	
	/*Enable Transmitter*/
	USART2->CR1		|=	(1U<<3);
	
	/*Enable Receiver*/
	USART2->CR1		|=	(1U<<2);
	
	/*Enable IDLE Line*/
	USART2->CR1	|=	(1U<<4);
	
	/*Enable UART*/
	USART2->CR1		|=	(1U<<13);
	
	/*Enable Interupt When IDLE Line Occur */
	NVIC_EnableIRQ(USART2_IRQn);
}

void usart3_Init(uint32_t baudrate)
{
	/*Enable Alternate Function For Peripheral Pin*/
	RCC->APB2ENR	|=	(1U<<0);
	
	/*Enable Clock To Port B*/
	RCC->APB2ENR	|=	(1U<<3);
	
	/*Enable Clock To UART3*/
	RCC->APB1ENR |= 	(1U<<18);
	
	
	/*Configure Port B Pin10 As Alternate Function Output PP 50MHz*/
	GPIOB->CRH		|=	(1U<<11);
	GPIOB->CRH		&=	~(1U<<10);
	GPIOB->CRH		|=	(1U<<9);
	GPIOB->CRH		|=	(1U<<8);
	
	/*Configure Port B Pin11 As Input Pull-up Pull-down*/
	GPIOB->CRH		|=	(1U<<15);
	GPIOB->CRH		&=	~(1U<<14);
	GPIOB->CRH		&=	~(1U<<13);
	GPIOB->CRH		&=	~(1U<<12);
	
	/*Configure Buad Rate*/
	USART3->BRR		|=	baudrate;
	
	/*Enable Transmitter*/
	USART3->CR1		|=	(1U<<3);
	
	/*Enable Receiver*/
	USART3->CR1		|=	(1U<<2);
	
	/*Enable IDLE Line*/
	USART3->CR1	|=	(1U<<4);
	
	/*Enable USART3*/
	USART3->CR1		|=	(1U<<13);
	
	/*Enable Interupt When IDLE Line Occur */
	NVIC_EnableIRQ(USART3_IRQn);
}

void uart4_Init(uint32_t baudrate)
{
	/*Enable Alternate Function For Peripheral Pin*/
	RCC->APB2ENR	|=	(1U<<0);
	
	/*Enable Clock To Port C*/
	RCC->APB2ENR	|=	(1U<<4);
	
	/*Enable Clock To UART4*/
	RCC->APB1ENR |= 	(1U<<19);
	
	
	/*Configure Port C Pin10 As Alternate Function Output PP 50MHz*/
	GPIOC->CRH		|=	(1U<<11);
	GPIOC->CRH		&=	~(1U<<10);
	GPIOC->CRH		|=	(1U<<9);
	GPIOC->CRH		|=	(1U<<8);
	
	/*Configure Port C Pin11 As Input Pull-up Pull-down*/
	GPIOC->CRH		|=	(1U<<15);
	GPIOC->CRH		&=	~(1U<<14);
	GPIOC->CRH		&=	~(1U<<13);
	GPIOC->CRH		&=	~(1U<<12);
	
	/*Configure Buad Rate*/
	UART4->BRR		|=	baudrate;
	
	/*Enable Transmitter*/
	UART4->CR1		|=	(1U<<3);
	
	/*Enable Receiver*/
	UART4->CR1		|=	(1U<<2);
	
	/*Enable IDLE Line*/
	UART4->CR1	|=	(1U<<4);
	
	/*Enable UART4*/
	UART4->CR1		|=	(1U<<13);
	
	/*Enable Interupt When IDLE Line Occur */
	NVIC_EnableIRQ(UART4_IRQn);
}

void DMA1_channel2_init(uint32_t src, uint32_t dst, uint32_t len)
{
	/*Enable Clock Access To DMA1*/
	RCC->AHBENR		|=	(1U<<0);
	
	/*Disable DMA1 Channel2*/
	DMA1_Channel2->CCR	&= ~(1U<<0);
	
	/*Wait For DMA1 Channel2 is Disable*/
	while(DMA1_Channel2->CCR & (1U<<0)){}
		
	/*Clear All Interrupt Flags of Channel2*/
	DMA1->IFCR	|=	(1U<<4);
	DMA1->IFCR	|=	(1U<<5);
	DMA1->IFCR	|=	(1U<<6);
	DMA1->IFCR	|=	(1U<<7);
	
	/*Set the Destination Buffer*/
	DMA1_Channel2->CPAR		=	dst;
	
	/*Set the Source Buffer*/
	DMA1_Channel2->CMAR		=	src;
	
	/*Set Length*/
	DMA1_Channel2->CNDTR	=	len;
	
	/*Enable Memory Increment*/
	DMA1_Channel2->CCR	|=	(1U<<7);
	
	/*Configure Transfer Direction*/
	DMA1_Channel2->CCR	|=	(1U<<4);
	
	/*Enable DMA Transfer Complete Interrupt*/
	DMA1_Channel2->CCR	|=	(1U<<1);
	
	/*Enable DMA1 Channel2*/
	DMA1_Channel2->CCR	|=	(1U<<0);
	
	/*Enable UART3 Transmitter DMA*/
	USART3->CR3	|=	(1U<<7);
	
}

void DMA1_channel3_init(uint32_t src, uint32_t dst, uint32_t len)
{
	/*Enable Clock Access To DMA1*/
	RCC->AHBENR		|=	(1U<<0);
	
	/*Disable DMA1 Channel3*/
	DMA1_Channel3->CCR	&= ~(1U<<0);
	
	/*Wait For DMA1 Channel3 is Disable*/
	while(DMA1_Channel3->CCR & (1U<<0)){}
		
	/*Clear All Interrupt Flags of Channel3*/
	DMA1->IFCR	|=	(1U<<8);
	DMA1->IFCR	|=	(1U<<9);
	DMA1->IFCR	|=	(1U<<10);
	DMA1->IFCR	|=	(1U<<11);
	
	/*Set the Destination Buffer*/
	DMA1_Channel3->CPAR		=	dst;
	
	/*Set the Source Buffer*/
	DMA1_Channel3->CMAR		=	src;
	
	/*Set Length*/
	DMA1_Channel3->CNDTR	=	len;
	
	/*Enable Memory Increment*/
	DMA1_Channel3->CCR	|=	(1U<<7);
	
	/*Enable Circular Mode*/
	DMA1_Channel3->CCR	&=	~(1U<<5);
	
	/*Configure Transfer Direction*/
	DMA1_Channel3->CCR	&=	~(1U<<4);
	
	/*Enable DMA Transfer Complete Interrupt*/
	DMA1_Channel3->CCR	|=	(1U<<1);
	
	/*Enable DMA1 Channel5*/
	DMA1_Channel3->CCR	|=	(1U<<0);
	
	/*Enable UART1 Receiver DMA*/
	USART3->CR3	|=	(1U<<6);
	
}

void DMA1_channel4_init(uint32_t src, uint32_t dst, uint32_t len)
{
	/*Enable Clock Access To DMA1*/
	RCC->AHBENR		|=	(1U<<0);
	
	/*Disable DMA1 Channel4*/
	DMA1_Channel4->CCR	&= ~(1U<<0);
	
	/*Wait For DMA1 Channel4 is Disable*/
	while(DMA1_Channel4->CCR & (1U<<0)){}
		
	/*Clear All Interrupt Flags of Channel4*/
	DMA1->IFCR	|=	(1U<<12);
	DMA1->IFCR	|=	(1U<<13);
	DMA1->IFCR	|=	(1U<<14);
	DMA1->IFCR	|=	(1U<<15);
	
	/*Set the Destination Buffer*/
	DMA1_Channel4->CPAR		=	dst;
	
	/*Set the Source Buffer*/
	DMA1_Channel4->CMAR		=	src;
	
	/*Set Length*/
	DMA1_Channel4->CNDTR	=	len;
	
	/*Enable Memory Increment*/
	DMA1_Channel4->CCR	|=	(1U<<7);
	
	/*Configure Transfer Direction*/
	DMA1_Channel4->CCR	|=	(1U<<4);
	
	/*Enable DMA Transfer Complete Interrupt*/
	DMA1_Channel4->CCR	|=	(1U<<1);
	
	/*Enable DMA1 Channel4*/
	DMA1_Channel4->CCR	|=	(1U<<0);
	
	/*Enable UART1 Transmitter DMA*/
	USART1->CR3	|=	(1U<<7);
	
}

void DMA1_channel5_init(uint32_t src, uint32_t dst, uint32_t len)
{
	/*Enable Clock Access To DMA1*/
	RCC->AHBENR		|=	(1U<<0);
	
	/*Disable DMA1 Channel5*/
	DMA1_Channel5->CCR	&= ~(1U<<0);
	
	/*Wait For DMA1 Channel5 is Disable*/
	while(DMA1_Channel5->CCR & (1U<<0)){}
		
	/*Clear All Interrupt Flags of Channel5*/
	DMA1->IFCR	|=	(1U<<16);
	DMA1->IFCR	|=	(1U<<17);
	DMA1->IFCR	|=	(1U<<18);
	DMA1->IFCR	|=	(1U<<19);
	
	/*Set the Destination Buffer*/
	DMA1_Channel5->CPAR		=	dst;
	
	/*Set the Source Buffer*/
	DMA1_Channel5->CMAR		=	src;
	
	/*Set Length*/
	DMA1_Channel5->CNDTR	=	len;
	
	/*Enable Memory Increment*/
	DMA1_Channel5->CCR	|=	(1U<<7);
	
	/*Disable Circular Mode*/
	DMA1_Channel5->CCR	&=	~(1U<<5);
	
	/*Configure Transfer Direction*/
	DMA1_Channel5->CCR	&=	~(1U<<4);
	
	/*Enable DMA Transfer Complete Interrupt*/
	DMA1_Channel5->CCR	|=	(1U<<1);
	
	/*Enable DMA1 Channel5*/
	DMA1_Channel5->CCR	|=	(1U<<0);
	
	/*Enable UART1 Receiver DMA*/
	USART1->CR3	|=	(1U<<6);
	
}

void DMA1_channel6_init(uint32_t src, uint32_t dst, uint32_t len)
{
	/*Enable Clock Access To DMA1*/
	RCC->AHBENR		|=	(1U<<0);
	
	/*Disable DMA1 Channel6*/
	DMA1_Channel6->CCR	&= ~(1U<<0);
	
	/*Wait For DMA1 Channel6 is Disable*/
	while(DMA1_Channel6->CCR & (1U<<0)){}
		
	/*Clear All Interrupt Flags of Channel5*/
	DMA1->IFCR	|=	(1U<<20);
	DMA1->IFCR	|=	(1U<<21);
	DMA1->IFCR	|=	(1U<<22);
	DMA1->IFCR	|=	(1U<<23);
	
	/*Set the Destination Buffer*/
	DMA1_Channel6->CPAR		=	dst;
	
	/*Set the Source Buffer*/
	DMA1_Channel6->CMAR		=	src;
	
	/*Set Length*/
	DMA1_Channel6->CNDTR	=	len;
	
	/*Enable Memory Increment*/
	DMA1_Channel6->CCR	|=	(1U<<7);
	
	/*Disable Circular Mode*/
	DMA1_Channel6->CCR	&=	~(1U<<5);
	
	/*Configure Transfer Direction*/
	DMA1_Channel6->CCR	&=	~(1U<<4);
	
	/*Enable DMA Transfer Complete Interrupt*/
	DMA1_Channel6->CCR	|=	(1U<<1);
	
	/*Enable DMA1 Channel6*/
	DMA1_Channel6->CCR	|=	(1U<<0);
	
	/*Enable USART2 Receiver DMA*/
	USART2->CR3	|=	(1U<<6);
	
}

void DMA2_channel3_init(uint32_t src, uint32_t dst, uint32_t len)
{
	/*Enable Clock Access To DMA2*/
	RCC->AHBENR		|=	(1U<<1);
	
	/*Disable DMA2 Channel3*/
	DMA2_Channel3->CCR	&= ~(1U<<0);
	
	/*Wait For DMA2 Channel3 is Disable*/
	while(DMA2_Channel3->CCR & (1U<<0)){}
		
	/*Clear All Interrupt Flags of Channel3*/
	DMA2->IFCR	|=	(1U<<8);
	DMA2->IFCR	|=	(1U<<9);
	DMA2->IFCR	|=	(1U<<10);
	DMA2->IFCR	|=	(1U<<11);
	
	/*Set the Destination Buffer*/
	DMA2_Channel3->CPAR		=	dst;
	
	/*Set the Source Buffer*/
	DMA2_Channel3->CMAR		=	src;
	
	/*Set Length*/
	DMA2_Channel3->CNDTR	=	len;
	
	/*Enable Memory Increment*/
	DMA2_Channel3->CCR	|=	(1U<<7);
	
	/*Disable Circular Mode*/
	DMA2_Channel3->CCR	&=	~(1U<<5);
	
	/*Configure Transfer Direction*/
	DMA2_Channel3->CCR	&=	~(1U<<4);
	
	/*Enable DMA Transfer Complete Interrupt*/
	DMA2_Channel3->CCR	|=	(1U<<1);
	
	/*Enable DMA2 Channel3*/
	DMA2_Channel3->CCR	|=	(1U<<0);
	
	/*Enable UART4 Receiver DMA*/
	UART4->CR3	|=	(1U<<6);
}
void DMA2_channel5_init(uint32_t src, uint32_t dst, uint32_t len){

}
