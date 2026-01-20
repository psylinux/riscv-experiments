#ifndef UART_H
#define UART_H

#include "types.h"

void uart_putc(char c);
void uart_puts(const char *s);
void uart_puthex32(u32 value);
void uart_putdec(u32 value);

#endif
