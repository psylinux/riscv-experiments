#include "types.h"
#include "uart.h"

volatile u32 g_state = 0u;

static void step(u32 x) {
  g_state ^= (x + 0x1234u);
}

int main(void) {
  for (u32 i = 0u; i < 5u; i++) {
    step(i);
  }
  uart_puts("state=");
  uart_puthex32(g_state);
  uart_putc('\n');
  return 0;
}
