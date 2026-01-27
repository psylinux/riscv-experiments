FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    gcc-riscv64-unknown-elf \
    binutils-riscv64-unknown-elf \
    gdb-multiarch \
    qemu-system-riscv32 \
    git \
    ca-certificates \
    python3 \
    python3-pip \
    python3-venv \
    xxd \
  && rm -rf /var/lib/apt/lists/*

# Install pwndbg under /opt/pwndbg so the Makefile's gdbinit path works.
RUN git clone https://github.com/pwndbg/pwndbg /opt/pwndbg \
  && /opt/pwndbg/setup.sh

WORKDIR /work

# Default to a shell so you can run make commands interactively.
CMD ["/bin/bash"]
