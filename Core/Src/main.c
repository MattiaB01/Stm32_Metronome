
#include "main.h"
#include "cmsis_os.h"
#include "led.h"
#include "exti.h"
#include "configurations.h"
#include <string.h>




volatile uint8_t state=0;
volatile int time=1000;
volatile TickType_t start=0;
volatile TickType_t stop=0;
volatile uint8_t p=0;
volatile int bpm=0;
volatile int a=0;


int id;


const TickType_t xDelay = 500 / portTICK_PERIOD_MS;
int main(void)
{
  /* USER CODE BEGIN 1 */
  HAL_Init();

  pa0_inter_init();
  SystemClock_Config();

  init_led();

  id=HAL_GetDEVID();


  while (1)
  {

	  //led acceso per 50ms
	  GPIOG->ODR |= (1<<13);
	  HAL_Delay(50);
	  //led spento
	  GPIOG->ODR &=~(1<<13);
	  HAL_Delay(time-50);


  }




}



