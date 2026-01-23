# ============================================================
# RISC-V Makefile (rv32im) - PoC builds
# ============================================================
# Run from repo root with:
#   make compile m-001
# ============================================================

# ---------------- Toolchain ----------------
TARGET  := riscv64-unknown-elf
CC      := $(TARGET)-gcc
OBJCOPY := $(TARGET)-objcopy
QEMU    := qemu-system-riscv32
GDB     := gdb-multiarch

# ---------------- Arch / ABI ----------------
ARCH := rv32im
ABI  := ilp32

# ---------------- Argument handling ----------------
ARG := $(word 2, $(MAKECMDGOALS))

# Source and output directories (repo root).
ROOT_DIR  := $(CURDIR)
SRC_DIR   := $(ROOT_DIR)
BUILD_DIR := $(ROOT_DIR)/build

# ---------------- Flags ----------------
CFLAGS  := -O0 -ggdb -ffreestanding -fno-builtin -nostdlib -march=$(ARCH) -mabi=$(ABI)
CFLAGS_NODEBUG := -O0 -ffreestanding -fno-builtin -nostdlib -march=$(ARCH) -mabi=$(ABI)
ASFLAGS := -O0 -ffreestanding -fno-builtin -nostdlib -march=$(ARCH) -mabi=$(ABI) -S
LDFLAGS := -Wl,-T,$(SRC_DIR)/link.ld

# Argument-derived names and extensions.
ARG_BASE := $(basename $(ARG))
ARG_EXT  := $(suffix $(ARG))

# Source file paths resolved from the argument.
SRC_C := $(SRC_DIR)/$(ARG)
SRC_S := $(SRC_DIR)/$(ARG_BASE).s

# Build output paths derived from the argument.
ASM := $(BUILD_DIR)/$(ARG_BASE).s
ELF := $(BUILD_DIR)/$(ARG_BASE).elf
BIN := $(BUILD_DIR)/$(ARG_BASE).bin

# Common runtime for C examples.
RUNTIME_SRCS := $(SRC_DIR)/start.s $(SRC_DIR)/uart.c

# Avoid errors for the extra argument target (e.g., "m-001").
.PHONY: $(ARG)
$(ARG):
	@:

# ---------------- Targets ----------------

# Generate assembly from a C file in the repo root.
.PHONY: assemble
assemble: $(BUILD_DIR)
	@test -n "$(ARG)" || (echo "Use: make assemble file.c" && exit 1)
	@test -f "$(SRC_C)" || (echo "File $(SRC_C) not found" && exit 1)
	$(CC) $(ASFLAGS) $(SRC_C) -o $(ASM)

# Compile .s or .c into an ELF, then extract a raw binary.
.PHONY: compile
compile: $(BUILD_DIR)
	@test -n "$(ARG)" || (echo "Use: make compile m-001" && exit 1)
	@if [ "$(ARG_EXT)" = ".c" ]; then \
	  $(CC) $(CFLAGS) $(LDFLAGS) $(RUNTIME_SRCS) $(SRC_C) -o $(ELF); \
	else \
	  INPUT="$(SRC_S)"; \
	  if [ -f "$(ASM)" ]; then \
	    INPUT="$(ASM)"; \
	  fi; \
	  test -f "$$INPUT" || (echo "File $$INPUT not found" && exit 1); \
	  $(CC) $(CFLAGS) $(LDFLAGS) $$INPUT -o $(ELF); \
	fi
	$(OBJCOPY) -O binary $(ELF) $(BIN)

# Dump the raw binary as 32-bit little-endian words.
.PHONY: printbinary
printbinary:
	@test -n "$(ARG)" || (echo "Use: make printbinary m-001" && exit 1)
	@test -f "$(BIN)" || (echo "File $(BIN) not found" && exit 1)
	@printf "==============================\n"
	xxd -e -c 4 -g 4 $(BIN)
	@printf "==============================\n\n"

# Build then run the ELF in QEMU (rv32 virt, no BIOS).
.PHONY: run
run: compile
	@printf "==============================\n"
	xxd -e -c 4 -g 4 $(BIN)
	@printf "==============================\n\n"
	$(QEMU) -M virt -nographic -bios none -kernel $(ELF)

# Start QEMU paused with a GDB server on tcp::1234.
.PHONY: gdbserver
gdbserver: compile
	$(QEMU) -S -M virt -nographic -bios none -kernel $(ELF) -gdb tcp::1234

# Connect GDB to the QEMU GDB server and break at _start.
# NOTE: Remove the "source /opt/pwndbg/gdbinit.py" line if you don't use pwndbg.
.PHONY: gdbconnect
gdbconnect:
	@test -n "$(ARG)" || (echo "Use: make connectgdb m-001" && exit 1)
	@if ! command -v $(GDB) >/dev/null 2>&1; then \
	  echo "GDB not found: install gdb."; \
	  exit 1; \
	fi; \
	$(GDB) $(ELF) -q \
	  -ex "source /opt/pwndbg/gdbinit.py" \
	  -ex "set arch riscv:rv32" \
	  -ex "target remote localhost:1234" \
	  -ex "break _start" \
	  -ex "continue"

# Remove build artifacts and GDB history.
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) .gdb_history

# Ensure build output directory exists.
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Example: build a combined ELF and BIN for no-main samples.
.PHONY: psylinux
psylinux: $(BUILD_DIR)
	$(CC) $(CFLAGS_NODEBUG) -S $(SRC_DIR)/no-main-001.c -o $(BUILD_DIR)/no-main-001-nogdb.s
	cat $(SRC_DIR)/no-main-asm-002.s $(BUILD_DIR)/no-main-001-nogdb.s > $(BUILD_DIR)/psylinux.s
	$(CC) $(CFLAGS) $(LDFLAGS) -S $(SRC_DIR)/no-main-001.c -o $(BUILD_DIR)/no-main-001.s
	$(CC) $(CFLAGS) $(LDFLAGS) $(SRC_DIR)/no-main-asm-002.s $(BUILD_DIR)/no-main-001.s -o $(BUILD_DIR)/psylinux.elf
	$(OBJCOPY) -O binary $(BUILD_DIR)/psylinux.elf $(BUILD_DIR)/psylinux.bin
