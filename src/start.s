.section .text.start          # startup code section
.globl _start                 # export entry symbol
# spacer between directives and label
_start:                       # program entry point
  la sp, _stack_top           # initialize stack pointer
  la gp, __global_pointer$    # initialize global pointer
# spacer before .bss clear
  # Zero .bss so C globals start as zero.
  la t0, _bss_start           # start of .bss
  la t1, _bss_end             # end of .bss
  beq t0, t1, 2f              # skip zeroing if empty
1:                            # loop label for clearing .bss
  sw zero, 0(t0)              # store zero word
  addi t0, t0, 4              # advance pointer
  blt t0, t1, 1b              # loop until end
2:                            # label after .bss clear
  call main                   # call C main
# spacer before idle loop
3:                            # idle loop label
  wfi                          # wait for interrupt
  j 3b                        # stay in idle loop
