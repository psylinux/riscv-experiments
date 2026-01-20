#include "types.h"

volatile u32 g_counter = 0u;      // .bss or .data depending on init
volatile u32 g_init    = 0x1234u; // .data

void _start(void) {
  for (;;) {
    g_counter++;
    g_init ^= 0x1111u;
  }
}
