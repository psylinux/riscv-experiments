#include "types.h"
#include "uart.h"

u32 nv_reg;
volatile u32 v_reg;

u32 demo(u32 x) {
  nv_reg = x;
  nv_reg = x;     // might be merged

  v_reg = x;
  v_reg = x;      // must not be merged

  return nv_reg + v_reg;
}

int main(void) {
  u32 r = demo(0x1234u);
  uart_puts("demo=");
  uart_puthex32(r);
  uart_putc('\n');
  return 0;
}
