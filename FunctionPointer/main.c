#include <stdio.h>
#include <stdlib.h>
#include "uart.h"

void main_uart_callback(char *data, int length) //cai ham nay chay o dau, luc nao
{
    if(strstr(data, "ON"))//strstr(data, "ON") != Null => In "ON LED\n"
    {
        printf("ON LED\n");
    }
}

void main()
{
    uart_set_callback(main_uart_callback); // cho con tro ham pt = dia chi cua ham cb
    uart_start(); //nap gia tri cho con tro ham pt => goi ham cb voi tham so nap vao cua pt
}
