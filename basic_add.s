.section .text
.globl _start

_start:
  li t0, 40
  li t1, 2
  add t2, t0, t1

  la t3, g_result
  sw t2, 0(t3)

1:
  j 1b

.section .bss
.align 4
g_result:
  .word 0
