// src/opt.c
#include "types.h"
#include "uart.h"

volatile u32 sink;

u32 f(u32 x) {
  u32 a = x * 3u;
  u32 b = x * 3u;      // same expression as a
  u32 c = a + b;

  if ((c & 1u) == 0u) {
    // looks like it matters...
    c += 10u;
  }

  // store result somewhere observable
  sink = c;
  return c;
}

int main(void) {
  u32 r = f(7u);
  uart_puts("f(7)=");
  uart_puthex32(r);
  uart_putc('\n');
  return 0;
}
