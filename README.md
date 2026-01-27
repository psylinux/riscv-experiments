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
- Docker (optional, for a containerized toolchain)

## Documentation

## PoC builds

- From repo root: `make compile m-001`

## Docker (optional)

If you prefer a containerized toolchain, this repo includes a Dockerfile based on Ubuntu 24.04
with the RISC-V cross-compiler, QEMU, GDB, and Pwndbg installed.

Build the image:

```bash
docker build -t riscv-experiments .
```

Run a shell with the repo mounted at `/work`:

```bash
docker run --rm -it -v "$PWD":/work -w /work riscv-experiments
```

Then run the usual targets inside the container:

```bash
make compile m-001
make run m-001
```

If you want to debug with GDB from the host, expose QEMU's GDB port:

```bash
docker run --rm -it -v "$PWD":/work -w /work -p 1234:1234 riscv-experiments
```
