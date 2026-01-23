#include "types.h"
#include "uart.h"

#define OFFSETOF(type, member) ((u32)(usize)&(((type *)0)->member))

static void show_type(const char *name, u32 size, u32 align) {
  uart_puts(name);
  uart_puts(" size=");
  uart_putdec(size);
  uart_puts(" align=");
  uart_putdec(align);
  uart_puts("\n");
}

#define SHOW(T) show_type(#T, (u32)sizeof(T), (u32)_Alignof(T))

struct A {
  u8  a;
  u32 b;
  u16 c;
};

struct B {
  u32 b;
  u16 c;
  u8  a;
};

int main(void) {
  SHOW(char);
  SHOW(short);
  SHOW(int);
  SHOW(long);
  SHOW(long long);
  SHOW(void *);
  SHOW(float);
  SHOW(double);

  uart_puts("\nstruct A size=");
  uart_putdec((u32)sizeof(struct A));
  uart_puts(" off(a)=");
  uart_putdec(OFFSETOF(struct A, a));
  uart_puts(" off(b)=");
  uart_putdec(OFFSETOF(struct A, b));
  uart_puts(" off(c)=");
  uart_putdec(OFFSETOF(struct A, c));
  uart_puts("\n");

  uart_puts("\nstruct B size=");
  uart_putdec((u32)sizeof(struct B));
  uart_puts(" off(b)=");
  uart_putdec(OFFSETOF(struct B, b));
  uart_puts(" off(c)=");
  uart_putdec(OFFSETOF(struct B, c));
  uart_puts(" off(a)=");
  uart_putdec(OFFSETOF(struct B, a));
  uart_puts("\n");

  return 0;
}
