	.file	"return-3.c"                   # source file name
	.option nopic                     # disable position-independent code
	.attribute arch, "rv32i2p1"        # target architecture
	.attribute unaligned_access, 0     # no unaligned memory access
	.attribute stack_align, 16         # stack alignment requirement
	.text                              # code section
	.align	2                         # align to 4-byte boundary
	.globl	psylinux                   # export symbol
	.type	psylinux, @function         # mark as function
psylinux:                               # function entry
	addi	sp,sp,-16                 # allocate stack frame
	sw	s0,12(sp)                 # save s0
	addi	s0,sp,16                 # set frame pointer
	li	a5,3                       # load return value
	mv	a0,a5                      # move return value to a0
	lw	s0,12(sp)                 # restore s0
	addi	sp,sp,16                 # deallocate stack frame
	jr	ra                         # return to caller
	.size	psylinux, .-psylinux       # set function size
	.ident	"GCC: (13.2.0-11ubuntu1+12) 13.2.0" # compiler ident
