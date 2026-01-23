# This assembly file does not define a main function and is related to no-main-001.c
# To compile and link this file, use `make psylinux`.
#
# Note that the order of the files during linking is important, the .c file comes after the .s file,
# so that the symbol psylinux is defined before being referenced.

.section .text
.globl _start
_start:
    j psylinux
j .

# The correct form would be:
#
## We need to set up a valid stack pointer before calling psylinux, otherwise the prologue
## will attempt to store to an invalid RAM location, like 0xfffffff0.
#
# .globl _start
# _start:
#     la sp, _stack_top     # set a valid stack pointer
#     call psylinux         # now prologue stores to valid RAM
# 1:  j 1b                  # don’t fall off
# .section .bss
# .align 12
# _stack_top:
