#include "types.h"
#include "uart.h"

typedef struct {
  u8  flags;
  u8  mode;
  u16 len;
  u32 addr;
} header_t;

u32 read_addr(const header_t *h) {
  return h->addr;
}

void set_len(header_t *h, u16 v) {
  h->len = v;
}

int main(void) {
  header_t h = {1u, 2u, 3u, 0x80001234u};
  set_len(&h, 0x55aau);
  uart_puts("addr=");
  uart_puthex32(read_addr(&h));
  uart_putc('\n');
  return 0;
}
