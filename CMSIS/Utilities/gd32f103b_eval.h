/*!
    \file  gd32f103b_eval.h
    \brief definitions for GD32f103B_EVAL's leds, keys and COM ports hardware resources
*/

/*
    Copyright (C) 2017 GigaDevice

    2014-12-26, V1.0.0, demo for GD32F10x
    2017-06-30, V2.0.0, demo for GD32F10x
*/

#ifndef GD32F103B_EVAL_H
#define GD32F103B_EVAL_H

#ifdef cplusplus
 extern "C" {
#endif

#include "gd32f10x.h"
     
/* exported types */
typedef enum 
{
    LED2 = 0,
    LED3 = 1,
    LED4 = 2,
    LED5 = 3
} led_typedef_enum;

typedef enum 
{
    KEY_WAKEUP = 0,
    KEY_TAMPER = 1,
    KEY_USER   = 2
} key_typedef_enum;

typedef enum 
{
    KEY_MODE_GPIO = 0,
    KEY_MODE_EXTI = 1
} keymode_typedef_enum;

/* eval board low layer led */
#define LEDn                             4U

#define LED2_PIN                         GPIO_PIN_6
#define LED2_GPIO_PORT                   GPIOC
#define LED2_GPIO_CLK                    RCU_GPIOC
  
#define LED3_PIN                         GPIO_PIN_7
#define LED3_GPIO_PORT                   GPIOC
#define LED3_GPIO_CLK                    RCU_GPIOC
  
#define LED4_PIN                         GPIO_PIN_8
#define LED4_GPIO_PORT                   GPIOC
#define LED4_GPIO_CLK                    RCU_GPIOC
  
#define LED5_PIN                         GPIO_PIN_9
#define LED5_GPIO_PORT                   GPIOC
#define LED5_GPIO_CLK                    RCU_GPIOC

#define COMn                             2U

#define EVAL_COM1                        USART0
#define EVAL_COM1_CLK                    RCU_USART0
#define EVAL_COM1_TX_PIN                 GPIO_PIN_9
#define EVAL_COM1_RX_PIN                 GPIO_PIN_10
#define EVAL_COM1_GPIO_PORT              GPIOA
#define EVAL_COM1_GPIO_CLK               RCU_GPIOA

#define EVAL_COM2                        USART1
#define EVAL_COM2_CLK                    RCU_USART1
#define EVAL_COM2_TX_PIN                 GPIO_PIN_5
#define EVAL_COM2_RX_PIN                 GPIO_PIN_6
#define EVAL_COM2_GPIO_PORT              GPIOD
#define EVAL_COM2_GPIO_CLK               RCU_GPIOD

#define KEYn                             3U

/* wakeup push-button */
#define WAKEUP_KEY_PIN                   GPIO_PIN_0
#define WAKEUP_KEY_GPIO_PORT             GPIOA
#define WAKEUP_KEY_GPIO_CLK              RCU_GPIOA
#define WAKEUP_KEY_EXTI_LINE             EXTI_0
#define WAKEUP_KEY_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOA
#define WAKEUP_KEY_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_0
#define WAKEUP_KEY_EXTI_IRQn             EXTI0_IRQn  

/* tamper push-button */
#define TAMPER_KEY_PIN                   GPIO_PIN_13
#define TAMPER_KEY_GPIO_PORT             GPIOC
#define TAMPER_KEY_GPIO_CLK              RCU_GPIOC
#define TAMPER_KEY_EXTI_LINE             EXTI_13
#define TAMPER_KEY_EXTI_PORT_SOURCE      GPIO_PORT_SOURCE_GPIOC
#define TAMPER_KEY_EXTI_PIN_SOURCE       GPIO_PIN_SOURCE_13
#define TAMPER_KEY_EXTI_IRQn             EXTI10_15_IRQn

/* user push-button */
#define USER_KEY_PIN                     GPIO_PIN_9
#define USER_KEY_GPIO_PORT               GPIOB
#define USER_KEY_GPIO_CLK                RCU_GPIOB
#define USER_KEY_EXTI_LINE               EXTI_9
#define USER_KEY_EXTI_PORT_SOURCE        GPIO_PORT_SOURCE_GPIOB
#define USER_KEY_EXTI_PIN_SOURCE         GPIO_PIN_SOURCE_9
#define USER_KEY_EXTI_IRQn               EXTI5_9_IRQn

/* function declarations */
/* configure led GPIO */
void gd_eval_led_init(led_typedef_enum lednum);
/* turn on selected led */
void gd_eval_led_on(led_typedef_enum lednum);
/* turn off selected led */
void gd_eval_led_off(led_typedef_enum lednum);
/* toggle the selected led */
void gd_eval_led_toggle(led_typedef_enum lednum);
/* configure key */
void gd_eval_key_init(key_typedef_enum key_num, keymode_typedef_enum key_mode);
/* return the selected key state */
uint8_t gd_eval_key_state_get(key_typedef_enum key);
/* configure COM port */
void gd_eval_com_init(uint32_t com);

#ifdef cplusplus
}
#endif

#endif /* GD32F103B_EVAL_H */
