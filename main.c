#include "stm32f10x.h"                  // Device header

void delay_ms(int n)//��ʱ����
{
	int i;
	while (n--)
	{
		for(i=0;i<115;i++);
	}
}



int main()
{
	//��GPIO�˿ڵ�ʱ��
	*(unsigned int*)0x40021018|=1<<3;
	//����IO��Ϊ���
//	*(unsigned int*)0x40010c00|=1;
//	*(unsigned int*)0x40010c00|=1<<4;
//	*(unsigned int*)0x40010c00|=1<<20;
	while (1)
	{
		//����
		*(unsigned int*)0x40010c0c=0;
		*(unsigned int*)0x40010c00=0;
		//����IO��Ϊ���
		*(unsigned int*)0x40010c00|=1;
		//����ODR�Ĵ���PB0
		*(unsigned int*)0x40010c0c&=~1;
		
		
		
		delay_ms(2000);
		*(unsigned int*)0x40010c00=0;
		*(unsigned int*)0x40010c0c=0;
		//����IO��Ϊ���
		*(unsigned int*)0x40010c00|=1<<4;
		//����ODR�Ĵ���PB1
		*(unsigned int*)0x40010c0c&=~(1<<1);
		delay_ms(2000);
		
		*(unsigned int*)0x40010c00=0;
		*(unsigned int*)0x40010c0c=0;
		//����IO��Ϊ���
		*(unsigned int*)0x40010c00|=1<<20;
		//����ODR�Ĵ���PB1
		*(unsigned int*)0x40010c0c&=~(1<<5);
		delay_ms(2000);
		
		
		
		
		

	}
	
}




void SystemInit()
{
	
}
