# MyOS - A Minimal Operating System with GUI


**MyOS** is a simple, bootable operating system developed using C with a touch of Assembly to create the bootloader. This project is designed to demonstrate low-level systems programming, VGA graphics handling, and minimal GUI capability in a 32-bit protected mode environment. It runs from boot using BIOS, sets up a basic VGA graphics mode, and displays a basic GUI layout.

---

##  File Structure

```
myos_gui/
├── boot/                   # Bootloader code (written in Assembly)
│   └── bootloader.asm
├── kernel/                 # Kernel code (written in C)
│   ├── kernel.c
│   └── kernel.h
├── graphics/               # Graphics utilities for VGA mode
│   ├── vga.c
│   └── vga.h
├── iso/                    # Temporary directory used to generate bootable ISO
├── linker.ld               # Linker script to load kernel at proper address
├── Makefile                # Build instructions
├── build.sh                # Easy build and run script
└── README.md               # This file
```

---

##  What This OS Does

- Bootloader sets CPU into 32-bit Protected Mode.
- Switches to **320x200 256-color VGA graphics mode** using BIOS interrupt.
- C-based kernel draws:
  - A colored background.
  - A GUI-style window (title bar, body).
  - A red "X" button (not interactive yet).
- Infinite loop with `hlt` instruction after rendering.

---

##  How to Run

Make sure you have the following installed:

- `nasm`
- `gcc` (32-bit support)
- `ld`
- `qemu`
- `grub-mkrescue`
- `xorriso`

###  Build and Run

```bash
chmod +x build.sh
./build.sh
```

This builds the OS and launches it using QEMU.

---

## Tech Stack

- **Language:** C (Kernel, VGA interface), Assembly (Bootloader)
- **Graphics Mode:** VGA 320x200 (Mode 13h)
- **Platform:** x86 (BIOS boot)
- **Toolchain:** NASM, GCC, GRUB, QEMU

---

## Bootloader (Assembly)

Initial 512 bytes contain:
- CPU setup
- GDT initialization
- Switch to protected mode
- Jump to kernel (C code)

---

##  Kernel & GUI (C)

- Initializes VGA mode using `int 0x10`.
- Draws pixels and rectangles by writing directly to video memory `0xA0000`.
- Modular design (`vga.h`, `vga.c`) for future GUI extensions (mouse, buttons, text).

---

##  Future Improvements

- Add mouse cursor using PS/2.
- Add text rendering using bitmap fonts.
- Implement simple window management.
- Add filesystem reading and basic apps.


