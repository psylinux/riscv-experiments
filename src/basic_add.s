.section .text               # code section
.globl _start                # export the entry symbol
# spacer between directives and label
_start:                      # program entry point
  li t0, 40                  # load 40 into t0
  li t1, 2                   # load 2 into t1
  add t2, t0, t1             # add t0 and t1 into t2
# spacer between compute and store
  la t3, g_result            # load address of g_result into t3
  sw t2, 0(t3)               # store result to memory
# spacer before loop
1:                           # local label for infinite loop
  j 1b                       # jump back to label 1
# spacer before data section
.section .bss                # zero-initialized data section
.align 4                     # align to 16-byte boundary
g_result:                    # label for result storage
  .word 0                    # reserve one word initialized to 0
