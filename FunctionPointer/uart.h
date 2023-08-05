#ifndef UART_H
#define UART_H

//Khai bao function pointer
typedef (*uart_data_hander_t) (char *data, int length);

//Tat ca cac function co trong file uart.h
void uart_start(void);
void uart_set_callback(uart_data_hander_t cb);

#endif // UART_H
