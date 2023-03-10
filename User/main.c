/*
xTaskCreateStatic静态方式创建线程，
若使用动态方式则使用xTaskCreate函数，
且不需要vApplicationGetIdleTaskMemory和
vApplicationGetTimerTaskMemory
*/

#include "FreeRTOS.h"
#include "task.h"
#include "systick.h"
#include "gd32f10x.h"

#define START_TASK_PRIO		1
#define LED1_TASK_PRIO		2
#define LED2_TASK_PRIO		2

#define START_STK_SIZE 		128  
#define TASK1_STK_SIZE 		128  
#define TASK2_STK_SIZE 		128 


static StackType_t Idle_Task_Stack[configMINIMAL_STACK_SIZE];

static StackType_t Timer_Task_Stack[configTIMER_TASK_STACK_DEPTH];

static StaticTask_t Idle_Task_TCB;	

static StaticTask_t Timer_Task_TCB;

StackType_t StartTaskStack[START_STK_SIZE];
StaticTask_t StartTaskTCB;
TaskHandle_t StartTask_Handler;
void start_task(void *pvParameters);

StackType_t Task1TaskStack[TASK1_STK_SIZE];
StaticTask_t Task1TaskTCB;
TaskHandle_t LED1Task_Handler;
void task1_task(void *pvParameters);

StackType_t Task2TaskStack[TASK1_STK_SIZE];
StaticTask_t Task2TaskTCB;
TaskHandle_t LED2Task_Handler;
void task2_task(void *pvParameters);

void led_init(){
	rcu_periph_clock_enable(RCU_GPIOC);
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
	gpio_bit_reset(GPIOC, GPIO_PIN_6);
	
	gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_7);
	gpio_bit_reset(GPIOC, GPIO_PIN_7);
}


void vApplicationGetIdleTaskMemory(StaticTask_t **ppxIdleTaskTCBBuffer, 
								   StackType_t **ppxIdleTaskStackBuffer, 
								   uint32_t *pulIdleTaskStackSize)
{
	*ppxIdleTaskTCBBuffer=&Idle_Task_TCB;
	*ppxIdleTaskStackBuffer=Idle_Task_Stack;
	*pulIdleTaskStackSize=configMINIMAL_STACK_SIZE;
}

void vApplicationGetTimerTaskMemory(StaticTask_t **ppxTimerTaskTCBBuffer, 
									StackType_t **ppxTimerTaskStackBuffer, 
									uint32_t *pulTimerTaskStackSize)
{
	*ppxTimerTaskTCBBuffer=&Timer_Task_TCB;/* ÈÎÎñ¿ØÖÆ¿éÄÚ´æ */
	*ppxTimerTaskStackBuffer=Timer_Task_Stack;/* ÈÎÎñ¶ÑÕ»ÄÚ´æ */
	*pulTimerTaskStackSize=configTIMER_TASK_STACK_DEPTH;/* ÈÎÎñ¶ÑÕ»´óÐ¡ */
}

int main(){
	systick_config();
	led_init();
	//静态创建任务
	StartTask_Handler = xTaskCreateStatic((TaskFunction_t	)start_task,		//ÈÎÎñº¯Êý
	(const char* 	)"start_task",		//任务名称
										(uint32_t 		)START_STK_SIZE,	//任务堆栈的大小
										(void* 		  	)NULL,				//传递给任务函数的参数
										(UBaseType_t 	)START_TASK_PRIO, 	//任务优先级
										(StackType_t*   )StartTaskStack,	//任务堆栈
										(StaticTask_t*  )&StartTaskTCB);	//任务控制模块             
    vTaskStartScheduler();          //开启任务调度
}

void start_task(void *pvParameters)
{
	taskENTER_CRITICAL();           //进入临界区
   
	LED1Task_Handler=xTaskCreateStatic((TaskFunction_t	)task1_task,		
										(const char* 	)"task1_task",		
										(uint32_t 		)TASK1_STK_SIZE,	
										(void* 		  	)NULL,				
										(UBaseType_t 	)LED1_TASK_PRIO, 	
										(StackType_t*   )Task1TaskStack,	
										(StaticTask_t*  )&Task1TaskTCB);	
	LED2Task_Handler=xTaskCreateStatic((TaskFunction_t	)task2_task,		
										(const char* 	)"task2_task",		
										(uint32_t 		)TASK2_STK_SIZE,	
										(void* 		  	)NULL,				
										(UBaseType_t 	)LED2_TASK_PRIO, 	
										(StackType_t*   )Task2TaskStack,	
										(StaticTask_t*  )&Task2TaskTCB);
    vTaskDelete(StartTask_Handler); //删除开始任务
		taskEXIT_CRITICAL();            //退出临界区
}


void task1_task(void *pvParameters)
{
    while(1)
    {
        gpio_bit_reset(GPIOC, GPIO_PIN_6);
        vTaskDelay(200);
        gpio_bit_set(GPIOC, GPIO_PIN_6);
        vTaskDelay(800);
    }
}


void task2_task(void *pvParameters)
{
    while(1)
    {
        gpio_bit_reset(GPIOC, GPIO_PIN_7);
        vTaskDelay(200);
        gpio_bit_set(GPIOC, GPIO_PIN_7);
        vTaskDelay(800);
    }
}
