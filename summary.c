
//this is for gd32  arm gcc none eabi
#include "gd32f403.h"
#include <stdio.h> // be careful this must us <>,rather than " "

int main()
{
}

int _write (int fd, char *pBuffer, int size)
{
	for (int i = 0; i < size; i++)
	{
		while(RESET == usart_flag_get(USART1, USART_FLAG_TBE));
		usart_data_transmit(USART1, (uint8_t)pBuffer[i]);
	}
	return size;
}


// this is for stm32 hal arm gcc none eabi
#include "stm32f4xx_hal.h"
#include <stdio.h>

int main()
{
}

int _write(int fd, unsigned char *pBuffer, int size)
{
    HAL_UART_Transmit(&huart2, pBuffer, size, 0xff);
    return size;
}