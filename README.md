# RISC-V Notes and Experiments

This repository is a structured notes with executable code, focused on RV32 bare-metal in QEMU.

**URL:** [https://psylinux.github.io/series/experimenting-with-risc-v/](https://psylinux.github.io/series/experimenting-with-risc-v/)

## Features

- C/ASM: real code in the repo root (`*.c`, `*.s`)
- Make: reproducible build
- QEMU (Quick Emulator, emulator/virtualizer): execution on `virt`
- Bare-metal only: no libc, UART via MMIO

## Requirements

- riscv64-unknown-elf-gcc (GCC + binutils)
- qemu-system-riscv32

## Documentation

## PoC builds

- From repo root: `make compile m-001`
