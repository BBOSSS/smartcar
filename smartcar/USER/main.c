#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "pwm.h"
#include "bsp_sccb.h"

u8 adr1 = 0x12;
u8 val1 = 0;
int main(void)
{ 
//	u16 led0pwmval=0;    
//	u8 dir=1;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	uart_init(115200);//��ʼ�����ڲ�����Ϊ115200
 	TIM14_PWM_Init(500-1,84-1);	//84M/84=1Mhz�ļ���Ƶ��,��װ��ֵ500������PWMƵ��Ϊ 1M/500=2Khz.  
  SCCB_GPIO_Config();
	printf("Test\n\n");
	while(1)
	{
		SCCB_ReadByte( &val1, 1, adr1);
		printf("reg_adr = 0x%x\n\n",adr1);
		printf("reg_val = 0x%x\n\n",val1);
		delay_ms(1000);
	}
	
	
	
	
	
	
//   while(1) //ʵ�ֱȽ�ֵ��0-300��������300���300-0�ݼ���ѭ��
//	{
// 		delay_ms(10);	 
//		if(dir)led0pwmval++;//dir==1 led0pwmval����
//		else led0pwmval--;	//dir==0 led0pwmval�ݼ� 
// 		if(led0pwmval>300)dir=0;//led0pwmval����300�󣬷���Ϊ�ݼ�
//		if(led0pwmval==0)dir=1;	//led0pwmval�ݼ���0�󣬷����Ϊ����
// 
//		TIM_SetCompare1(TIM14,led0pwmval);	//�޸ıȽ�ֵ���޸�ռ�ձ�
//	}
}
