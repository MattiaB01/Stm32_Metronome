/*
 * Led.c
 *
 *  Created on: 31 lug 2022
 *      Author: Mattia
 */
#include "stm32f4xx.h"

#define LEVEL_LED13  (1U<<13)

void init_led()
{
	//per inizializzare led verde su PG13

	RCC->AHB1ENR |= (1U<<6); // abilito clock porta G

	GPIOG->MODER |= (1U<<26); //output mode
	GPIOG->MODER &=~(1U<<27);

	GPIOG->ODR |= LEVEL_LED13; //livello 1 - led acceso


}

void blink_led()
{

//	GPIOG->BSRR ^= LEVEL_LED13;
//	for (int i=1; i<=1000000; i++)
//	{}
	GPIOG->ODR &= ~LEVEL_LED13;


}
void led()
{

	GPIOG->ODR &= ~LEVEL_LED13;
}
