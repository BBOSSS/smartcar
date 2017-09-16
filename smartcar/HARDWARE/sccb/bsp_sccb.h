#ifndef __SCCB_H
#define __SCCB_H



#include "sys.h"
#include "delay.h"
#include "usart.h"

#define Delay(ms)              delay_ms(ms)
#define DCMI_TIMEOUT_MAX       10000

//IIC SCCB
#define CAMERA_I2C                          I2C1
#define CAMERA_I2C_CLK                      RCC_APB1Periph_I2C1

#define CAMERA_I2C_SCL_PIN                  GPIO_Pin_8
#define CAMERA_I2C_SCL_GPIO_PORT            GPIOB
#define CAMERA_I2C_SCL_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define CAMERA_I2C_SCL_SOURCE               GPIO_PinSource8
#define CAMERA_I2C_SCL_AF                   GPIO_AF_I2C1

#define CAMERA_I2C_SDA_PIN                  GPIO_Pin_9
#define CAMERA_I2C_SDA_GPIO_PORT            GPIOB
#define CAMERA_I2C_SDA_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define CAMERA_I2C_SDA_SOURCE               GPIO_PinSource9
#define CAMERA_I2C_SDA_AF                   GPIO_AF_I2C1


void SCCB_HW_Init(void);
uint8_t SCCB_WriteReg(uint16_t Addr, uint8_t Data);
uint8_t SCCB_ReadReg(uint16_t Addr);

#endif 
