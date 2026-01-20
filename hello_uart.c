#include "types.h"
#include "uart.h"

int main(void) {
  uart_puts("Hello from RV32 in QEMU!\n");
  return 0;
}
