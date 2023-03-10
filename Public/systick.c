#include "FreeRTOS.H"
#include "gd32f10x.h"
#include "task.h"
#include "systick.h"

volatile static uint32_t delay;

void systick_config(void){
	/* setup systick timer for 1000Hz interrupts */
	if(SysTick_Config(SystemCoreClock/1000u)){
		while(1){
		}
	}
	NVIC_SetPriority(SysTick_IRQn,0X00u);
}

void delay_ms(uint32_t count){
	delay = count;
	if(0U != delay){
		vTaskDelay(delay);
	}
}
