ENTRY(_start)

SECTIONS
{
  . = 0x80000000;
  .bss : { *(.bss .bss.* COMMON) }
  .rodata : { *(.rodata .rodata.*) }
  .text : { *(.text .text.*) }
  .data : { *(.data .data.*) }
}
