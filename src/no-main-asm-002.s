# This assembly file does not define a main function and is related to no-main-001.c
# To compile and link this file, use `make psylinux`.
#
# Note that the order of the files during linking is important, the .c file comes after the .s file,
# so that the symbol psylinux is defined before being referenced.
# spacer before code section
.section .text                # code section
.globl _start                 # export entry symbol
_start:                       # program entry point
    li sp, 0x80002000         # set a valid stack pointer
    jal psylinux              # jump and link to psylinux
j .                            # infinite loop to avoid falling through
