OUTPUT_ARCH(riscv)
ENTRY(_start)

MEMORY {
  RAM (rwx) : ORIGIN = 0x80000000, LENGTH = 16M
}

SECTIONS {
  .text : {
    *(.text .text.*)
  } > RAM

  .rodata : {
    *(.rodata .rodata.*)
  } > RAM

  .data : {
    *(.data .data.*)
  } > RAM

  .sdata : {
    __global_pointer$ = . + 0x800;
    *(.sdata .sdata.*)
  } > RAM

  .sbss (NOLOAD) : {
    *(.sbss .sbss.*)
  } > RAM

  .bss (NOLOAD) : {
    _bss_start = .;
    *(.bss .bss.* COMMON)
    _bss_end = .;
  } > RAM

  . = ALIGN(16);
  _stack_top = ORIGIN(RAM) + LENGTH(RAM);
}
