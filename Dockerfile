FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    gcc-riscv64-unknown-elf \
    binutils-riscv64-unknown-elf \
    binutils \
    bsdextrautils \
    gdb-multiarch \
    qemu-system-riscv32 \
    git \
    ca-certificates \
    curl \
    python3 \
    python3-pip \
    python3-venv \
    xxd \
  && rm -rf /var/lib/apt/lists/*

# Install dz6 (hex editor) via rustup/cargo (needs a recent Rust for edition 2024).
ENV CARGO_HOME=/opt/cargo
ENV RUSTUP_HOME=/opt/rustup
ENV PATH="/opt/cargo/bin:${PATH}"
RUN curl -sSf https://sh.rustup.rs | sh -s -- -y --profile minimal \
  && cargo install dz6

# Install pwndbg under /opt/pwndbg so the Makefile's gdbinit path works.
RUN git clone https://github.com/pwndbg/pwndbg /opt/pwndbg \
  && cd /opt/pwndbg \
  && ./setup.sh

WORKDIR /work

# Default to a shell so you can run make commands interactively.
CMD ["/bin/bash"]
