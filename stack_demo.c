#include "types.h"
#include "uart.h"

__attribute__((noinline))
u32 inner(u32 a, u32 b) {
  u32 x = a ^ 0xA5A5A5A5u;
  u32 y = b + 0x1234u;
  u32 z = x + y;
  return z;
}

__attribute__((noinline))
u32 outer(u32 v) {
  u32 local1 = v + 1u;
  u32 local2 = v + 2u;
  return inner(local1, local2);
}

int main(void) {
  uart_puts("outer=");
  uart_puthex32(outer(100u));
  uart_putc('\n');
  return 0;
}
