#ifndef __SCCB_H
#define __SCCB_H



#include "sys.h"
#include "delay.h"
#include "usart.h"



/************************** OV7725 连接引脚定义********************************/
#define      macOV7725_SIO_C_SCK_APBxClock_FUN              RCC_APB1PeriphClockCmd
#define      macOV7725_SIO_C_GPIO_CLK                       RCC_AHB1Periph_GPIOC
#define      macOV7725_SIO_C_GPIO_PORT                      GPIOC
#define      macOV7725_SIO_C_GPIO_PIN                       GPIO_Pin_6

#define      macOV7725_SIO_D_SCK_APBxClock_FUN              RCC_APB1PeriphClockCmd
#define      macOV7725_SIO_D_GPIO_CLK                       RCC_AHB1Periph_GPIOC
#define      macOV7725_SIO_D_GPIO_PORT                      GPIOC
#define      macOV7725_SIO_D_GPIO_PIN                       GPIO_Pin_7



#define SCL_H         GPIO_SetBits(macOV7725_SIO_C_GPIO_PORT , macOV7725_SIO_C_GPIO_PIN) 
#define SCL_L         GPIO_ResetBits(macOV7725_SIO_C_GPIO_PORT , macOV7725_SIO_C_GPIO_PIN) 
   
#define SDA_H         GPIO_SetBits(macOV7725_SIO_D_GPIO_PORT , macOV7725_SIO_D_GPIO_PIN) 
#define SDA_L         GPIO_ResetBits(macOV7725_SIO_D_GPIO_PORT , macOV7725_SIO_D_GPIO_PIN) 

#define SCL_read      GPIO_ReadInputDataBit(macOV7725_SIO_C_GPIO_PORT , macOV7725_SIO_C_GPIO_PIN) 
#define SDA_read      GPIO_ReadInputDataBit(macOV7725_SIO_D_GPIO_PORT , macOV7725_SIO_D_GPIO_PIN) 

#define ADDR_OV7725   0x42


void SCCB_GPIO_Config(void);
int SCCB_WriteByte( u16 WriteAddress , u8 SendByte);
int SCCB_ReadByte(u8* pBuffer,   u16 length,   u8 ReadAddress);



#endif 
