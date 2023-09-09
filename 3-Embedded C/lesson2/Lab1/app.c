#include "uart.h"

unsigned char string_buffer[100] = "Learn-in-depth: ALI";
void main(void)
{
/* verstile physical bord */
Uart_send_string(string_buffer);
}
