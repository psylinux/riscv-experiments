#include "types.h"
#include "uart.h"

u32 dispatch(u32 x) {
  switch (x) {
    case 0: return 0x1111u;
    case 1: return 0x2222u;
    case 2: return 0x3333u;
    case 3: return 0x4444u;
    default: return 0xdeadu;
  }
}

int main(void) {
  u32 r = dispatch(2u);
  uart_puts("dispatch=");
  uart_puthex32(r);
  uart_putc('\n');
  return 0;
}
