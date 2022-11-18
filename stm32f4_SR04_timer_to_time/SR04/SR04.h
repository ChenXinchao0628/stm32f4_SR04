//SR04.h
#ifndef __SR04_H
#define __SR04_H
#include "main.h"
#include "tim.h"
#include "stdio.h"

#define htim_sr04 htim6//定义使用的定时器

#define Trig_GPIO_Port GPIOA
#define Trig_Pin GPIO_PIN_1

#define TRIG_H  HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_SET)
#define TRIG_L  HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_RESET)


extern float distant;
extern uint32_t high_time;

void for_delay_us(uint16_t us); //注意根据主频修改参数
void  Start(void);
int Get(void);
void start(void);
unsigned int get_stop(void);
void SR04_GetData(void);

#endif
