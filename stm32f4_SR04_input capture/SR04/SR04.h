//SR04.h
#ifndef __SR04_H
#define __SR04_H
#include "main.h"
#include "tim.h"
#include "stdio.h"

#define Trig_GPIO_Port GPIOA
#define Trig_Pin GPIO_PIN_1

#define TRIG_H  HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_SET)
#define TRIG_L  HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_RESET)

#define TIM_sr04 TIM2
#define htim_sr04 htim2
extern float distant;
extern uint32_t high_time;

void delay_us(uint16_t nus);
void SR04_GetData(void);

#endif
