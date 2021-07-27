#ifndef _MYIIC2_H
#define _MYIIC2_H
#include "ctiic.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32F407������
//IIC��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2017/4/13
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	
//IO��������
#define SDA2_IN()  {GPIOF->MODER&=~(3<<(13*2));GPIOF->MODER|=0<<13*2;}	//PF13����ģʽ
#define SDA2_OUT() {GPIOF->MODER&=~(3<<(13*2));GPIOF->MODER|=1<<13*2;} //PF13���ģʽ
//IO����
#define IIC2_SCL   PFout(15) //SCL
#define IIC2_SDA   PFout(13) //SDA
#define READ2_SDA  PFin(13)  //����SDA

//IIC���в�������
void IIC2_Init(void);                //��ʼ��IIC��IO��				 
void IIC2_Start(void);				//����IIC��ʼ�ź�
void IIC2_Stop(void);	  			//����IICֹͣ�ź�
void IIC2_Send_Byte(uint8_t txd);			//IIC����һ���ֽ�
uint8_t IIC2_Read_Byte(unsigned char ack);//IIC��ȡһ���ֽ�
uint8_t IIC2_Wait_Ack(void); 				//IIC�ȴ�ACK�ź�
void IIC2_Ack(void);					//IIC����ACK�ź�
void IIC2_NAck(void);				//IIC������ACK�ź�

void IIC2_Write_One_Byte(uint8_t daddr,uint8_t addr,uint8_t data);
uint8_t IIC2_Read_One_Byte(uint8_t daddr,uint8_t addr);	 
#endif

