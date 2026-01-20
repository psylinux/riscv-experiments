#include "types.h"
#include "uart.h"

__attribute__((noinline))
u32 victim(u32 x) {
  volatile u32 canary = 0xCAFEBABEu;
  volatile u8 buf[16];

  // BUG: writes 17 bytes into a 16-byte buffer
  for (int i = 0; i <= 16; i++) {
    buf[i] = (u8)i;
  }

  // return depends on whether canary got corrupted
  return (canary ^ x);
}

int main(void) {
  uart_puthex32(victim(0x12345678u));
  uart_putc('\n');
  return 0;
}
