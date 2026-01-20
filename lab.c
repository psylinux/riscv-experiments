#include "types.h"
#include "uart.h"

static volatile u32 mmio_fake = 0u;

static u32 add_u32(u32 a, u32 b) {
  return a + b;
}

int main(void) {
  u32 x = 0x11223344u;
  u32 y = 0x55667788u;
  u32 z = add_u32(x, y);

  mmio_fake = z;
  u32 r = mmio_fake;

  uart_puts("x=");
  uart_puthex32(x);
  uart_puts(" y=");
  uart_puthex32(y);
  uart_puts(" z=");
  uart_puthex32(z);
  uart_puts(" r=");
  uart_puthex32(r);
  uart_putc('\n');

  return (int)(r & 0xffu);
}
