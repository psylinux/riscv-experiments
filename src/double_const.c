#include "types.h"
#include "uart.h"

static const double g = 1234.676;

__attribute__((noinline))
double f(void) {
  return g;
}

int main(void) {
  union {
    double d;
    u32 w[2];
  } u;

  u.d = f();
  uart_puts("lo=");
  uart_puthex32(u.w[0]);
  uart_puts(" hi=");
  uart_puthex32(u.w[1]);
  uart_putc('\n');
  return 0;
}
