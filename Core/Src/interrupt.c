/*funzione per la gestione dell'interrupt corrispondente, in questo caso al pin 0.
 * I nomi della funzione sono contenuti nel file startup della cartella startup.
 */
/*
 * interrupt.c
 *
 *  Created on: 2 ago 2022
 *      Author: Mattia
 */




#include "stm32f429xx.h"
#include "cmsis_os.h"
#include "led.h"
#include "main.h"

extern volatile int a,time,bpm;
extern volatile TickType_t start,stop;
extern volatile uint8_t state;
void EXTI0_IRQHandler(void)
{
	a++;
	state = !state;
    led();

    stop = HAL_GetTick();

    if(stop-start>1500)
    {
    	start=stop;

    }
    else
    {   time=(stop-start);
    	start=HAL_GetTick();
    	bpm=60000/(time);

    }


	//per controllare con esattezza il bit 0, in questo caso, si usa il pending register*/
   if ((EXTI->PR & (1U<<0)) !=0)
   {

	EXTI->PR |= (1U<<0);



   }

}

