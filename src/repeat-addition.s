.section .text                # code section
.globl _start                 # export the entry symbol
_start:                         # program entry point
    addi x1, x0, 2              # x1 <- 2 (value to be added repeatedly)
    addi x2, x0, 5              # x2 <- 5 (loop counter)
    addi x3, x0, 0              # x3 <- 0 (result accumulator)
# spacer between setup and loop
repeat_addition:                # start of the addition loop
    add x3, x3, x1              # x3 <- x3 + x1 (accumulated sum)
    addi x2, x2, -1             # x2 <- x2 - 1 (decrement the counter)
    bne x2, x0, repeat_addition # if x2 != 0, jump back to loop start
# spacer before halt loop
j .                             # infinite loop: jumps to the current address
                                # (end of program)
