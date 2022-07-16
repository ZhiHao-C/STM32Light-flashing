#include "stm32f10x.h"                  // Device header

void delay_ms(int n)//延时函数
{
	int i;
	while (n--)
	{
		for(i=0;i<115;i++);
	}
}



int main()
{
	//打开GPIO端口的时钟
	*(unsigned int*)0x40021018|=1<<3;
	//配置IO口为输出
//	*(unsigned int*)0x40010c00|=1;
//	*(unsigned int*)0x40010c00|=1<<4;
//	*(unsigned int*)0x40010c00|=1<<20;
	while (1)
	{
		//清零
		*(unsigned int*)0x40010c0c=0;
		*(unsigned int*)0x40010c00=0;
		//配置IO口为输出
		*(unsigned int*)0x40010c00|=1;
		//控制ODR寄存器PB0
		*(unsigned int*)0x40010c0c&=~1;
		
		
		
		delay_ms(2000);
		*(unsigned int*)0x40010c00=0;
		*(unsigned int*)0x40010c0c=0;
		//配置IO口为输出
		*(unsigned int*)0x40010c00|=1<<4;
		//控制ODR寄存器PB1
		*(unsigned int*)0x40010c0c&=~(1<<1);
		delay_ms(2000);
		
		*(unsigned int*)0x40010c00=0;
		*(unsigned int*)0x40010c0c=0;
		//配置IO口为输出
		*(unsigned int*)0x40010c00|=1<<20;
		//控制ODR寄存器PB1
		*(unsigned int*)0x40010c0c&=~(1<<5);
		delay_ms(2000);
		
		
		
		
		

	}
	
}




void SystemInit()
{
	
}
