/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */
uint8_t dem = 0;
uint8_t var[4] = {17,17,17,17};
uint8_t password[4] = {1,1,1,1};
uint8_t Nhapsai = 0;
uint8_t last_key = 17; // Lưu phím vừa nhấn (ban đầu là không nhấn gì)
uint32_t last_key_time = 0;  // Thời gian của lần nhấn phím trước đó

uint8_t key_count = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void quetbanphim()
{

	 uint32_t current_time = HAL_GetTick(); // Lấy thời gian hiện tại (ms)

	    // Quét cột thứ nhất
	    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0); // Kéo cột 1 xuống mức thấp
	    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0) // Nhấn phím "1"
	    {
	        while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0) {} // Chờ thả phím

	        if (last_key == 1) // Nếu phím trước đó cũng là "1"
	        {
	            // Kiểm tra thời gian giữa hai lần nhấn
	            if ((current_time - last_key_time) <= 500) // Nếu trong vòng 5s
	            {
	                var[dem-1] = 10; // Gán "A" vào var[0]
//	                dem++;     // Đặt vị trí tiếp theo là var[1]
	            }
	            else // Nếu cách nhau > 5s
	            {
	                if (dem < 4)
	                {
	                    var[dem] = 1; // Gán giá trị "1"
	                    dem++;
	                }
	            }
	        }
	        else // Nếu đây là lần nhấn đầu tiên
	        {
	            if (dem < 4)
	            {
	                var[dem] = 1; // Gán giá trị "1"
	                dem++;
	            }
	        }

	        last_key = 1;           // Cập nhật phím vừa nhấn
	        last_key_time = current_time; // Cập nhật thời gian nhấn
	    }
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==0)                // nhan phim 4
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==0){}
		    if (last_key == 4)
					        {
					            if ((current_time - last_key_time) <= 500)
					            {
					                var[dem-1] = 13;
				//	                dem++;     // Đặt vị trí tiếp theo là var[1]
					            }
					            else
					            {
					                if (dem < 4)
					                {
					                    var[dem] = 4;
					                    dem++;
					                }
					            }
					        }
					        else
					        {
					            if (dem < 4)
					            {
					                var[dem] = 4;
					                dem++;
					            }
					        }

					        last_key = 4;
					        last_key_time = current_time;
					    }


	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)==0)                // nhan phim 7
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)==0){}
			if(dem<4)
			{
				var[dem] = 7;
				dem++;
			}
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0)                // nhan phim * hay phim xoa
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0){}
			if(dem>0)
			{
					dem--;
					var[dem]=17;
			}
		}
  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);
	// nhan cot thu hai
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0);
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0)                // nhan phim 2
		{
		 {
			        while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) == 0) {}

			        if (last_key == 2)
			        {
			            if ((current_time - last_key_time) <= 500)
			            {
			                var[dem-1] = 11;
		//	                dem++;     // Đặt vị trí tiếp theo là var[1]
			            }
			            else
			            {
			                if (dem < 4)
			                {
			                    var[dem] = 2;
			                    dem++;
			                }
			            }
			        }
			        else
			        {
			            if (dem < 4)
			            {
			                var[dem] = 2;
			                dem++;
			            }
			        }

			        last_key = 2;
			        last_key_time = current_time;
			    }
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==0)                // nhan phim 5
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==0){}
		    if (last_key == 5)
					        {
					            if ((current_time - last_key_time) <= 500)
					            {
					                var[dem-1] = 14;
				//	                dem++;     // Đặt vị trí tiếp theo là var[1]
					            }
					            else
					            {
					                if (dem < 4)
					                {
					                    var[dem] = 5;
					                    dem++;
					                }
					            }
					        }
					        else
					        {
					            if (dem < 4)
					            {
					                var[dem] = 5;
					                dem++;
					            }
					        }

					        last_key = 5;
					        last_key_time = current_time;
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)==0)                // nhan phim 8
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)==0){}
			if(dem<4)
			{
				var[dem] = 8;
				dem++;
			}
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0)                // nhan phim 0
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0){}
			if(dem<4)
			{
				var[dem] = 0;
				dem++;
			}
		}
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,1);
	// nhan cot thu ba
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0);
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0)                // nhan phim 3
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3)==0){}
		    if (last_key == 3)
					        {
					            if ((current_time - last_key_time) <= 500)
					            {
					                var[dem-1] = 12;
				//	                dem++;     // Đặt vị trí tiếp theo là var[1]
					            }
					            else
					            {
					                if (dem < 4)
					                {
					                    var[dem] = 3;
					                    dem++;
					                }
					            }
					        }
					        else
					        {
					            if (dem < 4)
					            {
					                var[dem] = 3;
					                dem++;
					            }
					        }

					        last_key = 3;
					        last_key_time = current_time;
					    }

	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==0)                // nhan phim 6
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4)==0){}
		    if (last_key == 6)
					        {
					            if ((current_time - last_key_time) <= 500)
					            {
					                var[dem-1] = 15;
				//	                dem++;     // Đặt vị trí tiếp theo là var[1]
					            }
					            else
					            {
					                if (dem < 4)
					                {
					                    var[dem] = 6;
					                    dem++;
					                }
					            }
					        }
					        else
					        {
					            if (dem < 4)
					            {
					                var[dem] = 6;
					                dem++;
					            }
					        }

					        last_key = 6;
					        last_key_time = current_time;
					    }

	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)==0)                // nhan phim 9
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5)==0){}
			if(dem<4)
			{
				var[dem] = 9;
				dem++;
			}
		}
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0)                // nhan phim # hay phim Enter
		{
			while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_6)==0){}
			CheckPass();                                         // kiem tra mat khau
		}
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);
}

void LED(uint8_t number)
{
    switch (number){
        case 0: // Hiển thị "0"
        	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 , 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1); // a

            break;
        case 1: // Hiển thị "1"
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10| GPIO_PIN_11, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6|GPIO_PIN_7, 0);

            break;
        case 2: // Hiển thị "2"
        	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5| GPIO_PIN_6 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_11, 0);
        	 HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10|GPIO_PIN_7, 1);

            break;
        case 3: // Hiển thị "3"
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
            break;
        case 4: // Hiển thị "4"
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
            break;
        case 5: // Hiển thị "5"
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
            break;
        case 6: // Hiển thị "6"
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
            break;
        case 7: // Hiển thị "7"
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);
            break;
        case 8: // Hiển thị "8"
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
            break;
        case 9: // Hiển thị "9"
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
            break;
        case 10: // Hiển thị "A"
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
            break;
        case 11: // Hiển thị "B"
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
               break;
           case 12: // Hiển thị "C"
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);
               break;
           case 13: // Hiển thị "D"
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
               break;
           case 14: // Hiển thị "E"
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
               break;
           case 15: // Hiển thị "F"
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, 0);
               HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 0);
               break;
        default: // Tắt LED
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 |
                                     GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 , 1);
            break;
    }

}


void quetled()
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,1);                // quet led so 1
	LED(var[0]);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,0);

	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,1);                // quet led so 2
	LED(var[1]);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,0);


	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,1);                // quet led so 3
	LED(var[2]);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,0);

	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1);                // quet led so 4
	LED(var[3]);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,0);

}

void CheckPass(void)
{
    if (Nhapsai < 3)
    {
        int match = 1; // Giả định là đúng
        for (int k = 0; k < 4; k++)
        {
            if (var[k] != password[k])
            {
                match = 0; // Nếu sai, đặt c�? báo sai
                break;
            }
        }
        if (match)
        {
            for (int i = 0; i < 4; i++)
                var[i] = 11; // Hiển thị thành công
            dem = 0;
            Nhapsai = 0; // Reset số lần nhập sai
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, SET);

            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11, RESET);

        }
        else
        {
            for (int j = 0; j < 4; j++)
                var[j] = 17; // Hiển thị thất bại
            dem = 0;
            Nhapsai++; // Tăng số lần nhập sai
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);
            HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, RESET);

        }
    }
    else
    {
HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_11);

HAL_Delay(200);}
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
quetbanphim();
quetled();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, L1_Pin|L2_Pin|L3_Pin|L4_Pin
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|Q1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, C1_Pin|C2_Pin|C3_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : L1_Pin L2_Pin L3_Pin L4_Pin
                           PA5 PA6 PA7 PA8
                           PA9 PA10 PA11 Q1_Pin */
  GPIO_InitStruct.Pin = L1_Pin|L2_Pin|L3_Pin|L4_Pin
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|Q1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : C1_Pin C2_Pin C3_Pin PB11
                           PB12 PB13 */
  GPIO_InitStruct.Pin = C1_Pin|C2_Pin|C3_Pin|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : R1_Pin R2_Pin R3_Pin R4_Pin */
  GPIO_InitStruct.Pin = R1_Pin|R2_Pin|R3_Pin|R4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
