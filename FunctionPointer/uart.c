#include "uart.h"
#include <unistd.h>

//Khai bao con tro ham pt
uart_data_hander_t pt;

void uart_recv(char *data, int length)
{
    pt(data, length);//them tham so cho con tro ham
}


void uart_set_callback(uart_data_hander_t cb)
{
    pt = cb; //gan con tro ham bang dia chi cua ham cb
}

void uart_start(void)
{
    while(1)
    {
        uart_recv("ON", 2);
        sleep(1);
    }
}
