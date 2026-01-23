#include "uart.h"

#define UART0_BASE 0x10000000u

static volatile u8 *const uart0 = (volatile u8 *)UART0_BASE;

static void uart_puthex_nibble(u32 nibble) {
  u32 v = nibble & 0x0fu;
  char c = (v < 10u) ? (char)('0' + v) : (char)('a' + (v - 10u));
  *uart0 = (u8)c;
}

void uart_putc(char c) {
  *uart0 = (u8)c;
}

void uart_puts(const char *s) {
  while (*s) {
    uart_putc(*s++);
  }
}

void uart_puthex32(u32 value) {
  uart_puts("0x");
  for (int shift = 28; shift >= 0; shift -= 4) {
    uart_puthex_nibble(value >> (u32)shift);
  }
}

void uart_putdec(u32 value) {
  char buf[10];
  int i = 0;

  if (value == 0u) {
    uart_putc('0');
    return;
  }

  while (value > 0u && i < (int)(sizeof(buf))) {
    buf[i++] = (char)('0' + (value % 10u));
    value /= 10u;
  }

  while (i > 0) {
    uart_putc(buf[--i]);
  }
}
