#include "types.h"
#include "uart.h"

u32 sum_u32(const u32 *p, u32 n) {
  u32 s = 0u;
  for (u32 i = 0u; i < n; i++) {
    s += p[i];
  }
  return s;
}

int main(void) {
  u32 a[4] = {1u, 2u, 3u, 4u};
  u32 s = sum_u32(a, 4u);
  uart_puts("sum=");
  uart_puthex32(s);
  uart_putc('\n');
  return 0;
}
