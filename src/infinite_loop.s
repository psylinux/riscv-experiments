.section .text               # code section
.globl _start                # export the entry symbol
_start:                      # program entry point
    j _start                 # infinite loop
