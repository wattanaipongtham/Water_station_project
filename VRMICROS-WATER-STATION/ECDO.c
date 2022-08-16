#include "stm32f10x.h"
#include "ECDO.h"

void EC_Enable(void){
	GPIOA->CRL &= ~(1U<<19);
	GPIOA->CRL &= ~(1U<<18);
	GPIOA->CRL |= (1U<<17);
	GPIOA->CRL |= (1U<<16);
	
	GPIOA->CRL &= ~(1U<<23);
	GPIOA->CRL &= ~(1U<<22);
	GPIOA->CRL |= (1U<<21);
	GPIOA->CRL |= (1U<<20);
	GPIOA->ODR |= (1U<<4);
	GPIOA->ODR |= (1U<<5);
}

void DO_Enable(void){
	GPIOA->CRL &= ~(1U<<19);
	GPIOA->CRL &= ~(1U<<18);
	GPIOA->CRL |= (1U<<17);
	GPIOA->CRL |= (1U<<16);
	
	GPIOA->CRL &= ~(1U<<27);
	GPIOA->CRL &= ~(1U<<26);
	GPIOA->CRL |= (1U<<25);
	GPIOA->CRL |= (1U<<24);
	GPIOA->ODR |= (1U<<4);
	GPIOA->ODR |= (1U<<6);
}

void EC_Disable(){
	GPIOA->ODR &= ~(1U<<4);
	GPIOA->ODR &= ~(1U<<5);
}

void DO_Disable(){
	GPIOA->ODR &= ~(1U<<4);
	GPIOA->ODR &= ~(1U<<6);
}
