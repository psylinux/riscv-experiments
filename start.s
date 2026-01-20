.section .text.start
.globl _start

_start:
  la sp, _stack_top
  la gp, __global_pointer$

  # Zero .bss so C globals start as zero.
  la t0, _bss_start
  la t1, _bss_end
  beq t0, t1, 2f
1:
  sw zero, 0(t0)
  addi t0, t0, 4
  blt t0, t1, 1b
2:
  call main

3:
  wfi
  j 3b
