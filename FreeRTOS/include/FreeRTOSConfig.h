/*
 * FreeRTOS V202212.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/
/*置1：RTOS使用抢占式调度器
  置0：RTOS使用协作式调度器*/
#define configUSE_PREEMPTION		          1

/* 系统有两种选择下一个执行任务的方法，一种是通用方法（0），
另一种是特定的一直方法（1）*/
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0

/*
置0：保持滴答中断始终运行
置1：使用低功耗无滴答模式
*/
#define configUSE_TICKLESS_IDLE           0
/*
置0：忽略空闲钩子
置1：使用空闲钩子
*/
#define configUSE_IDLE_HOOK			          0

/*滴答中断的外设所用的内部时钟的执行频率*/
#define configCPU_CLOCK_HZ			          ( ( unsigned long ) 108000000 )

/*若与MCU相同频率运行systick 则不需要此设置*/
//#define configSYSTICK_CLOCK_HZ  1000000

/*滴答中断的频率*/
#define configTICK_RATE_HZ		            ( ( TickType_t ) 1000 )

/*应用程序任务可用的优先级数量*/
#define configMAX_PRIORITIES		           ( 5 )

/*空闲任务使用的堆栈大小*/
#define configMINIMAL_STACK_SIZE	( ( unsigned short ) 128 )

/*创建任务时，任务描述性名称最大允许长度*/
#define configMAX_TASK_NAME_LEN		        ( 16 )

/*
置0：滴答Type_t为无符号的32位类型
置1：滴答Type_t为无符号的16位类型
*/
#define configUSE_16_BIT_TICKS		          0

/*
置1：使用抢占式调度器
置2：应用程序创建运行在空闲优先级的任务
*/
#define configIDLE_SHOULD_YIELD		          1

/*
置0：构建中将不包括直达任务通知功能及其相关API
置1：构建中将包括直达任务通知功能及其相关API
*/
#define configUSE_TASK_NOTIFICATIONS        1

/*每个RTOS任务都有一个任务置数组*/
#define configTASK_NOTIFICATION_ARRAY_ENTRIES 3

/*
置0：在构建中忽脑略互斥功能
置1：构建中包含互斥功能
*/
#define configUSE_MUTEXES                   1

/*
置0：在构建中忽略递归互斥功能
置1：在构建中包含递归互斥功能
*/
#define configUSE_RECURSIVE_MUTEXES         1

/*
置0：在构建中忽略递计数信号量功能
置1：在构建中包含计数信号量功能
*/
#define configUSE_COUNTING_SEMAPHORES       0

/*
置0：在构建中忽略替代队列函数
置1：在构建中包含替代队列函数
*/
#define configUSE_ALTERNATIVE_API           0

/*队列注册表大小，可以关联文本名称和队列，便于在调试GUI中识别队列
包含调试器定位每个已注册队列和信号量所需的信息*/
#define configQUEUE_REGISTRY_SIZE          10

/*
置0：忽略队列集合功能
置1：包含队列集合功能
*/
#define configUSE_QUEUE_SETS 1

/*默认情况下使用带时间片的抢占式优先级调度
置0：调度器仍将运行优先级最高且处于就绪状态的任务，但不会因为发生滴答
中断而在具有相同优先级的任务之间切换*/
#define configUSE_TIME_SLICING 0

/*
置1：将为每个创建的任务分配一个newlib重入结构体
*/ 
#define configUSE_NEWLIB_REENTRANT              0

/*
设置0：将在构建中忽略宏（FreeRTOS.h头文件包含的一组#define宏）
*/ 
//#define configENABLE_BACKWARD_COMPATIBILITY 0

/*设置每个任务的线程本地存储数组值*/
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 5

/*
fREErtos列表中的开始和结束标记节点
置0：与listitem_t 保持一致为4个字段
置1：Minilistitem_t 包含的字段比与listitem_t少3个
*/
#define configUSE_MINI_LIST_ITEM 0

/*设置调用 xTaskCreate() 时用于指定堆栈深度的类型，以及许多其他 使用堆栈大小的地方*/
#define configSTACK_DEPTH_TYPE                  uint16_t

/*FreeRTOS 消息缓冲区使用 configMESSAGE_BUFFER_LENGTH_TYPE 类型的变量存储 每个消息的长度*/
#define configMESSAGE_BUFFER_LENGTH_TYPE        size_t

/*
置0：默认为0
置1：则使用 pvPortMalloc()分配的内存块将在通过 vPortFree() 释放时清除
*/
#define configHEAP_CLEAR_MEMORY_ON_FREE         1

/* Memory allocation related definitions. */
/*
置0：默认，RTOS 对象可以 使用应用程序编写者提供的 RAM 创建
置1：RTOS 对象只能 使用从 RAM 堆中分配的 FreeRTOS 创建。
*/
#define configSUPPORT_STATIC_ALLOCATION             1

/*
置0：RTOS 对象只能使用应用程序编写者提供的 RAM 创建
置1：默认，那么 RTOS 对象可以 使用从 RAM 堆中自动分配的 FreeRTOS 创建。
*/
#define configSUPPORT_DYNAMIC_ALLOCATION            1

/*RAM 堆中可用的 FreeRTOS 总量。*/
#define configTOTAL_HEAP_SIZE                       10240

/*
置0：默认情况下，FreeRTOS 堆由 FreeRTOS 声明 并由链接器放置在存储器中
置1：允许应用程序编写者声明堆，这使得 应用程序编写者可以将堆放置在内存的任意位置。
*/
//#define configAPPLICATION_ALLOCATED_HEAP            0

/*
设置为 1，那么对于任何 使用 xTaskCreate 或 xTaskCreateRestricted API 创建的任务，其堆栈 使用 pvPortMallocStack 函数分配并使用 vPortFreeStack 函数释放。用户需要 实现线程安全的 pvPortMallocStack 和 vPortFreeStack 函数
默认为 0
*/
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP   0

/* Hook function related definitions. */

/*
设置为 1，使用空闲钩子， 
设置为 0，忽略空闲钩子。
*/
#define configUSE_IDLE_HOOK                     0

/*
设置为 1，使用 滴答 钩子，
设置为 0，忽略 滴答 钩子
*/
#define configUSE_TICK_HOOK                     0

/*堆栈溢出检测*/
#define configCHECK_FOR_STACK_OVERFLOW          0

/*
设置为 1，应用程序必须定义 malloc() 失败的钩子函数， 
设置为 0，那么 malloc() 失败的钩子函数将不会被调用。
*/
#define configUSE_MALLOC_FAILED_HOOK            0

/*
如果 configUSE_TIMERS 和 configUSE_DAEMON_TASK_STARTUP_HOOK 都设置为 1， 那么应用程序必须定义钩子函数，而且它必须和如下的函数具有相同的名称和原型 
*/
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0

/*
设置 configUSE_SB_COMPLETED_CALLBACK() 时需要设置构建中的 xStreamBufferCreateWithCallback() 和 xStreamBufferCreateStaticWithCallback() （及其消息缓冲区等效函数）。 使用这些函数创建的流缓冲区和消息缓冲区可以有自己 唯一的发送完成回调和接收完成回调，其中通过 xStreamBufferCreate() 和 xStreamBufferCreateStatic ()（及其消息缓冲区等效函数） 创建的流缓冲区和消息缓冲区都共享 sbSEND_COMPLETED() 和 sbRECEVE_COMPLETED() 宏定义的回调。 configUSE_SB_COMPLETED_CALLBACK 默认为 0 ，以便向后兼容
*/
#define configUSE_SB_COMPLETED_CALLBACK         0


/* Run time and task stats gathering related definitions. */

/*运行时间统计页面说明了此参数的使用*/
#define configGENERATE_RUN_TIME_STATS           0

/*如果想包含其他结构成员和函数来辅助执行可视化和跟踪，将其设置为 1*/
#define configUSE_TRACE_FACILITY                0

/*将 configUSE_TRACE_FACILITY 和 configUSE_STATS_FORMATTING_FUNCTIONS 设置为 1， 包含 vTaskList() 和 vTaskGetRunTimeStats() 函数中的功能。 设置任意一个为 0，会在构建时忽略 vTaskList() 和 vTaskGetRunTimeStates()。
*/
#define configUSE_STATS_FORMATTING_FUNCTIONS    0



/* Co-routine related definitions. */
/*
设置为 1，将在构建中包含协程功能
设置为 0，将在构建中忽略协程功能。 
要包含协程功能，项目必须包含 croutine.c 文件
*/
#define configUSE_CO_ROUTINES                   0

/*
应用程序协程可用的优先级数量 。 任意数量的协程可共用相同的优先级。 任务单独分配优先级，请参阅 configMAX_PRIORITIES。
*/
#define configMAX_CO_ROUTINE_PRIORITIES         1



/* Software timer related definitions. */

/*
设置为 1，将包含软件定时器功能
设置为 0，将忽略软件定时器功能。 
请参阅 FreeRTOS 软件定时器页面，获取完整说明
*/
#define configUSE_TIMERS                        1

/*设置软件定时器服务/守护任务的优先级*/
#define configTIMER_TASK_PRIORITY               3

/*设置软件定时器命令队列的长度*/
#define configTIMER_QUEUE_LENGTH                10

/*设置分配给软件定时器服务/守护任务的堆栈深度*/
#define configTIMER_TASK_STACK_DEPTH            configMINIMAL_STACK_SIZE


/* Interrupt nesting behaviour configuration. */
//#define configKERNEL_INTERRUPT_PRIORITY         [dependent of processor]
//#define configMAX_SYSCALL_INTERRUPT_PRIORITY    [dependent on processor and application]
//#define configMAX_API_CALL_INTERRUPT_PRIORITY   [dependent on processor and application]



/* Define to trap errors during development. */
//#define configASSERT( ( x ) ) if( ( x ) == 0 ) vAssertCalled( __FILE__, __LINE__ )


/* FreeRTOS MPU specific definitions. */

/*如果 configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS 设置为 1，
那么 应用程序编写者必须提 "application_defined_privileged_functions.h" 头文件*/
/*
#define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS 0
#define configTOTAL_MPU_REGIONS                                8 
#define configTEX_S_C_B_FLASH                                  0x07UL 
#define configTEX_S_C_B_SRAM                                   0x07UL 
#define configENFORCE_SYSTEM_CALLS_FROM_KERNEL_ONLY            1
#define configALLOW_UNPRIVILEGED_CRITICAL_SECTIONS             1
#define configENABLE_ERRATA_837070_WORKAROUND   1
*/
/*仅用于 ARMv8-M 安全端移植,则默认为 8。*/
//#define secureconfigMAX_SECURE_CONTEXTS         8

/* Optional functions - most linkers will remove unused functions anyway. */
/*要包含某个 API 函数，请将对应宏设置为 1， 或设置为 0，排除该函数。例如，要包含 vTaskDelete() API 函数，请使用*/
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_xResumeFromISR                  1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskGetSchedulerState          1
#define INCLUDE_xTaskGetCurrentTaskHandle       1
#define INCLUDE_uxTaskGetStackHighWaterMark     0
#define INCLUDE_uxTaskGetStackHighWaterMark2    0
#define INCLUDE_xTaskGetIdleTaskHandle          0
#define INCLUDE_eTaskGetState                   0
#define INCLUDE_xEventGroupSetBitFromISR        1
#define INCLUDE_xTimerPendFunctionCall          0
#define INCLUDE_xTaskAbortDelay                 0
#define INCLUDE_xTaskGetHandle                  0
#define INCLUDE_xTaskResumeFromISR              1
#define INCLUDE_vTaskCleanUpResources	          0

/* This is the raw value as per the Cortex-M3 NVIC.  Values can be 255
(lowest) to 0 (1?) (highest). */
#define configKERNEL_INTERRUPT_PRIORITY 		255
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 	191 /* equivalent to 0xb0, or priority 11. */


/*
将FreeRTOS端口中断处理程序映射到CMSIS标准名称的定义
*/
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler


/* This is the value being used as per the ST library which permits 16
priority values, 0 to 15.  This must correspond to the
configKERNEL_INTERRUPT_PRIORITY setting.  Here 15 corresponds to the lowest
NVIC value of 255. */
#define configLIBRARY_KERNEL_INTERRUPT_PRIORITY	15

#endif /* FREERTOS_CONFIG_H */

