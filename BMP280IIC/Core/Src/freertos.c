/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "fsmc.h"

#include "stdio.h"

#include "lvgl.h"
#include "lv_port_disp.h"
#include "lv_port_indev.h"

#include "touch.h"
#include "BMP280.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 128 * 4
};
/* Definitions for USARTTask */
osThreadId_t USARTTaskHandle;
const osThreadAttr_t USARTTask_attributes = {
  .name = "USARTTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 256 * 4
};
/* Definitions for LCDTask */
osThreadId_t LCDTaskHandle;
const osThreadAttr_t LCDTask_attributes = {
  .name = "LCDTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 256 * 4
};
/* Definitions for TOUCHTask */
osThreadId_t TOUCHTaskHandle;
const osThreadAttr_t TOUCHTask_attributes = {
  .name = "TOUCHTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 256 * 4
};
/* Definitions for LVGLTask */
osThreadId_t LVGLTaskHandle;
const osThreadAttr_t LVGLTask_attributes = {
  .name = "LVGLTask",
  .priority = (osPriority_t) osPriorityLow,
  .stack_size = 256 * 4
};
/* Definitions for BMPTACK */
osThreadId_t BMPTACKHandle;
const osThreadAttr_t BMPTACK_attributes = {
  .name = "BMPTACK",
  .priority = (osPriority_t) osPriorityHigh,
  .stack_size = 256 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void USARTStartTask(void *argument);
void LCDStartTask(void *argument);
void TOUCHStartTask(void *argument);
void LVGLStartTask(void *argument);
void BMPStartTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of USARTTask */
  USARTTaskHandle = osThreadNew(USARTStartTask, NULL, &USARTTask_attributes);

  /* creation of LCDTask */
  LCDTaskHandle = osThreadNew(LCDStartTask, NULL, &LCDTask_attributes);

  /* creation of TOUCHTask */
  TOUCHTaskHandle = osThreadNew(TOUCHStartTask, NULL, &TOUCHTask_attributes);

  /* creation of LVGLTask */
  LVGLTaskHandle = osThreadNew(LVGLStartTask, NULL, &LVGLTask_attributes);

  /* creation of BMPTACK */
  BMPTACKHandle = osThreadNew(BMPStartTask, NULL, &BMPTACK_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_USARTStartTask */
/**
* @brief Function implementing the USARTTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_USARTStartTask */
void USARTStartTask(void *argument)
{
  /* USER CODE BEGIN USARTStartTask */
  /* Infinite loop */
  for(;;)
  {	
		lv_task_handler();
    osDelay(5);
  }
  /* USER CODE END USARTStartTask */
}

/* USER CODE BEGIN Header_LCDStartTask */
/**
* @brief Function implementing the LCDTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LCDStartTask */
void LCDStartTask(void *argument)
{
  /* USER CODE BEGIN LCDStartTask */
  /* Infinite loop */
  for(;;)
  {
		osDelay(20);
  }
  /* USER CODE END LCDStartTask */
}

/* USER CODE BEGIN Header_TOUCHStartTask */
/**
* @brief Function implementing the TOUCHTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_TOUCHStartTask */
void TOUCHStartTask(void *argument)
{
  /* USER CODE BEGIN TOUCHStartTask */
  /* Infinite loop */
  for(;;)
  {
		osDelay(1);
  }
  /* USER CODE END TOUCHStartTask */
}

/* USER CODE BEGIN Header_LVGLStartTask */
/**
* @brief Function implementing the LVGLTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_LVGLStartTask */
void LVGLStartTask(void *argument)
{
  /* USER CODE BEGIN LVGLStartTask */
  /* Infinite loop */
  for(;;)
  {
		lv_tick_inc(5);//LVGL_TICK = 5
    osDelay(5);
  }
  /* USER CODE END LVGLStartTask */
}

/* USER CODE BEGIN Header_BMPStartTask */
/**
* @brief Function implementing the BMPTACK thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BMPStartTask */
void BMPStartTask(void *argument)
{
  /* USER CODE BEGIN BMPStartTask */
	double BMP_Pressurre;
	double BMP_Temperature;
  /* Infinite loop */
  for(;;)
  {
		while(BMP280_GetStatus(BMP280_MEASURING) != RESET);
		while(BMP280_GetStatus(BMP280_IM_UPDATE) != RESET);
    BMP_Pressurre = BMP280_Get_Pressure();
		BMP_Temperature = BMP280_Get_Temperature();
		printf("\r\nTemperature %lf C Pressure %lf",BMP_Temperature,BMP_Pressurre);
		osDelay(5);
  }
  /* USER CODE END BMPStartTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
