/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "stm32f10x_it.h"

void USART1_IRQHandler(void)
{
  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
  {
	  USART_ITConfig(USART1, USART_IT_RXNE, DISABLE);

	  uint8_t dat = USART_ReceiveData(USART1);
	  USART_SendData(USART1, dat);
//	  trace_putchar(dat);

      USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
  }
}
