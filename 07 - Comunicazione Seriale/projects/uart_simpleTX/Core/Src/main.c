/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

void myUART_init();

int main(void){
	/* MCU Configuration--------------------------------------------------------*/
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();
	/* Configure the system clock */
	SystemClock_Config();
	/* Init UART */
	myUART_init();

	const unsigned char data[] = "dataflow\n\r";

	/* Infinite loop */
	while(1){
		for (int i=0; i < sizeof(data)/sizeof(data[0]); i++){
		  // Invio singolo dato
		  USART2->DR = data[i];
		  // Attesa completamento trasmissione
		  while(!(USART2->SR & (0b1 << 6)));
		  // Pausa
		  HAL_Delay(1000);
		}
	}
}

void myUART_init(){
	// Abilitazione USART2 clock
	RCC->APB1ENR |= (0x01 << 17);

	// Abilitazione GPIOA clock
	RCC->AHB1ENR |= (0x01 << 0);

	/* Configurazione GPIO*/
	GPIOA->MODER &= ~(0x0F << 4);  // Clear MODER GPIOA2/3
	GPIOA->MODER |= (0x0A << 4);   // Set Alternate function mode
	GPIOA->OSPEEDR |= (0x0A << 4); // Set Fast Speed

	// AF7 per USART2
	GPIOA->AFR[0] |= (0b111 << 8); // AFR[0] = ARFL
	GPIOA->AFR[0] |= (0b111 << 12);// AFR[0] = ARFL

	/* Configurazione USART
	 * Word Length: bit 12 del registro USART_CR1
	 * 				0: 1 Start bit, 8 Data bits, n Stop bit
	 * 				1: 1 Start bit, 9 Data bits, n Stop bit
	 *
	 * USART2->CR1 |= (0b0 << 12); // 1 Start bit, 8 Data bits, n Stop bit (DEFAULT)
	 *
	 * Parity: bit 9 del registro USART_CR1
     *		   0: Even parity
	 * 		   1: Odd parity
	 *
	 * USART2->CR1 |= (0b0 << 9); // Even parity
	 */

	/* Transmitter enable: bit 3 del registro USART_CR1
	 *			0: Transmitter is disabled
	 *			1: Transmitter is enabled
	 *
	 */
	USART2->CR1 |= (0b1 << 3);

	/* Receiver enable: bit 2 del registro USART_CR1
	 *			0: Receiver is disabled
	 *			1: Receiveris enabled
	 *
	 */
	USART2->CR1 |= (0b1 << 2);

	/* Configuarzione baud rate:
	 * 		baud rate = fCK / (8 * (2 - OVER8) * USARTDIV)
	 *
	 *		per ottenere un baud rate di 115200
	 *		con fPCK = 42Mhz e OVER8 = 0
	 *		si ottiene USARTDIV = 42Mhz / 115200 / 16 = 22.7864583
	 *		che viene mappato sul valore 22.8125
	 *		rappresentato come:
	 *		 	Fraction : 16*0.8125 = 13
	 *			Mantissa : 22
	 *			12-bit mantissa e 4-bit fraction
	 *
	 */
	USART2->BRR |= (22 << 4); // Mantissa - Configurato come valore decimale
	USART2->BRR |= (13 << 0); // Fraction - Configurato come valore decimale

	/* USART enable: bit 13 del registro USART_CR1
	 *			0: USART prescaler and outputs disabled
	 *			1: USART enabled
	 *
	 */
	USART2->CR1 |= (0b1 << 13);
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
