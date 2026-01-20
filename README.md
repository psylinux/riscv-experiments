# RISC-V Notes and Experiments

This repository is a structured notes with executable code, focused on RV32 bare-metal in QEMU.

**URL:** [https://psylinux.github.io/riscv-experiments/](https://psylinux.github.io/riscv-experiments/)

## Features

- C/ASM: real code in `src/`
- Make: reproducible build
- QEMU (Quick Emulator, emulator/virtualizer): execution on `virt`
- Bare-metal only: no libc, UART via MMIO

## Requirements

- riscv64-unknown-elf-gcc (GCC + binutils)
- qemu-system-riscv32

## Documentation

## PoC builds

- From repo root: `make compile m-001`
