#include "types.h"
#include "uart.h"

u32 clamp_u32(u32 x, u32 lo, u32 hi) {
  if (x < lo) return lo;
  if (x > hi) return hi;
  return x;
}

int main(void) {
  u32 v = clamp_u32(42u, 10u, 30u);
  uart_puts("clamp=");
  uart_puthex32(v);
  uart_putc('\n');
  return 0;
}
