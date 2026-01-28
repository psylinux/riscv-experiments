#include "types.h"
#include "uart.h"

static void puthex8(u8 v) {
  // Print one byte as two lowercase hex digits.
  const char *digits = "0123456789abcdef";
  uart_putc(digits[(v >> 4) & 0x0f]);
  uart_putc(digits[v & 0x0f]);
}

int main(void) {
  // Store a known 32-bit pattern and examine its byte order in memory.
  u32 x = 0x11223344u;
  u8 *p = (u8 *)&x;
  // Emit the four bytes to reveal endianness (LSB first on little-endian).
  puthex8(p[0]); uart_putc(' ');
  puthex8(p[1]); uart_putc(' ');
  puthex8(p[2]); uart_putc(' ');
  puthex8(p[3]); uart_putc('\n');
  return 0;
}
