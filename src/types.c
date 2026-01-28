#include "types.h"
#include "uart.h"

// Compute the byte offset of a member inside a struct type.
// This does not access memory; it just uses the member's address from a null base.
#define OFFSETOF(type, member) ((u32)(usize)&(((type *)0)->member))

static void show_type(const char *name, u32 size, u32 align) {
  // Print a "name size=... align=..." line for one type.
  uart_puts(name);
  uart_puts(" size=");
  uart_putdec(size);
  uart_puts(" align=");
  uart_putdec(align);
  uart_puts("\n");
}

// Convenience macro: stringize the type name and show its size and alignment.
#define SHOW(T) show_type(#T, (u32)sizeof(T), (u32)_Alignof(T))

struct A {
  // Likely introduces padding between fields due to alignment.
  u8  a;
  u32 b;
  u16 c;
};

struct B {
  // Same fields as A but reordered to reduce padding.
  u32 b;
  u16 c;
  u8  a;
};

int main(void) {
  // Show basic scalar sizes/alignments for this target/compiler.
  SHOW(char);
  SHOW(short);
  SHOW(int);
  SHOW(long);
  SHOW(long long);
  SHOW(void *);
  SHOW(float);
  SHOW(double);

  // Compare layout of two structs with the same fields in different orders.
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
