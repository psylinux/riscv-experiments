#include "types.h"
#include "uart.h"

static u32 read_u32(const u8 *p) {
  return (u32)p[0] | ((u32)p[1] << 8) | ((u32)p[2] << 16) | ((u32)p[3] << 24);
}

int main(void) {
  u8 buf[8] = {0x44, 0x33, 0x22, 0x11, 0x88, 0x77, 0x66, 0x55};
  u32 v = read_u32(&buf[1]);
  uart_puthex32(v);
  uart_putc('\n');
  return 0;
}
