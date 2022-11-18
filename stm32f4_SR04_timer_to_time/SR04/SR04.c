//SR04.c
#include "SR04.h"

float distant;      //测量距离
uint32_t high_time;   //超声波模块返回的高电平时间


void for_delay_us(uint16_t us)//微秒级延时（循环）
{
		uint8_t system_clock = 168;//主频
		uint16_t nus = us * system_clock;
		do
		{
			__NOP();
		}
		while(nus--);
}


void  Start(void) //启动超声波模块
{
    HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_SET); //拉高
    for_delay_us(15);          //15us延时
    HAL_GPIO_WritePin(Trig_GPIO_Port,Trig_Pin,GPIO_PIN_RESET);  //拉低
}


int Get(void)
{
    return HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0); //获得Echo的电平高低

}

void start(void)//开始计时
{
    __HAL_TIM_SetCounter(&htim_sr04,0);   //清0开始计数
    HAL_TIM_Base_Start_IT(&htim_sr04);   // 开启定时器更新中断
}

unsigned int get_stop(void)//获取停止之后的数据
{
    unsigned int  dta;
    HAL_TIM_Base_Stop_IT (&htim_sr04);       //关闭定时器更新中断
    high_time = __HAL_TIM_GetCounter(&htim_sr04);  //获得计数值
    dta = high_time*340;                     //high_time为时间，单位us  假设当前声波速度为340m/s
    return dta;
}

void SR04_GetData(void)
{
		Start();               //启动超声波模块
		while(!Get());        //当Echo返回0，等待,变为1继续
		start();//开始计时
		while(Get());		  //当Echo为1计数并等待  ,变为0继续
		distant = (float)get_stop()/20000.0;//单位为cm
}
