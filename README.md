# 1. RISC-V Notes and Experiments

This repository is a structured notes with executable code, focused on RV32 bare-metal in QEMU.

**Series:** https://psylinux.github.io/series/experimenting-with-risc-v/

## 1.1. Features

- C/ASM: real code in the repo root (`*.c`, `*.s`)
- Make: reproducible build
- QEMU (Quick Emulator, emulator/virtualizer): execution on `virt`
- Bare-metal only: no libc, UART via MMIO

## 1.2. Requirements

- riscv64-unknown-elf-gcc (GCC + binutils)
- qemu-system-riscv32
- Docker (optional, for a containerized toolchain)

## 1.3. Hex Editor

The image also includes the `dz6` TUI hex editor:

```bash
docker run --rm -it -v "$PWD":/work -w /work riscv-experiments dz6 /work/build/m-001.bin
```

## 1.4. PoC builds

- From repository root directory: 
```bash
cd riscv-experiments/
make compile m-001
```

## 1.5. Docker (optional)

If you prefer a containerized toolchain, this repo includes a Dockerfile based on Ubuntu 24.04
with the RISC-V cross-compiler, QEMU, GDB, and Pwndbg installed.

### 1.5.1. Build the image

> [!IMPORTANT]
> When running QEMU via `make run`, use an interactive TTY so QEMU receives the
> escape keys. Exit QEMU with `Ctrl+a`, then `x` (or `Ctrl+a`, then `c`, then
> `quit`).


```bash
docker build -t riscv-experiments .
```

### 1.5.2. Run a shell with the repo mounted at `/work`:

```bash
docker run --rm -it -v "$PWD":/work -w /work riscv-experiments
make compile m-001
make run m-001
```

### 1.5.3. Run the usual targets inside the container:

```bash
docker run --rm -it -v "$PWD":/work -w /work riscv-experiments make run m-001
```

### 1.5.4. Debugging with GDB

> [!IMPORTANT]
> If you run the GDB server and client in separate containers, publish the port
> and point GDB at `host.docker.internal` (Docker Desktop). Make sure the port
> matches on both sides.


- Terminal 1 (GDB server)
```bash
docker run --rm -it -v "$PWD":/work -w /work -p 1234:1234 riscv-experiments make gdbserver psylinux
```

- Terminal 2 (GDB client)
```bash
docker run --rm -it -v "$PWD":/work -w /work riscv-experiments make gdbconnect psylinux GDB_TARGET=host.docker.internal:1234
```

> [!WARNING]
> In GDB, use `continue` (not `run`) to start the paused QEMU target.

#### 1.5.4.1. GDB Server on Docker and GDB Client on Host

You need to remap debug paths to the host for source lookup in GDB.

- GDB server from Docker
```bash
docker run --rm -it -v "$PWD":/work -w /work -p 1234:1234 riscv-experiments make gdbserver psylinux DEBUG_PREFIX_MAP="-fdebug-prefix-map=/work=$PWD"
```

- GDB client from host (ex. MacOS)
```bash
cd riscv-experiments/
gdb build/psylinux.elf \
  -ex "set arch riscv:rv32" \
  -ex "target remote 127.0.0.1:1234" \
  -ex "break _start" \
  -ex "continue"
```

### 1.5.5. Troubleshooting

#### 1.5.5.1. Port Mapping
- If `-p 1234:1234` fails with "port is already allocated", either stop the
  process using `1234` or map a different host port.
- If GDB says "could not connect", confirm the server container is running and
  the host port matches `GDB_TARGET`.

#### 1.5.5.2. GDB can't find sources

If GDB can't find sources because paths are `/work/...`, rebuild with a debug
path remap (this rewrites paths stored in DWARF):
`DEBUG_PREFIX_MAP="-fdebug-prefix-map=/work=$PWD"`

Example:

```bash
docker run --rm -it -v "$PWD":/work -w /work riscv-experiments make psylinux DEBUG_PREFIX_MAP="-fdebug-prefix-map=/work=$PWD"
```


#### 1.5.5.3. Find Docker containers using 1234
```bash
docker ps --format "table {{.ID}}\t{{.Names}}\t{{.Ports}}"
```

#### 1.5.5.4. Or find any process using 1234
```bash
lsof -nP -iTCP:1234 -sTCP:LISTEN
```

