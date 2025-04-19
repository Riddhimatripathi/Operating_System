C_SOURCES = kernel/kernel.c graphics/vga.c
OBJ = ${C_SOURCES:.c=.o}

all: os-image

os-image: boot/bootloader.bin kernel.bin
	mkdir -p iso/boot
	cp boot/bootloader.bin iso/boot/
	cp kernel.bin iso/boot/
	grub-mkrescue -o myos.iso iso

boot/bootloader.bin: boot/bootloader.asm
	nasm -f bin boot/bootloader.asm -o boot/bootloader.bin

kernel.bin: $(OBJ) linker.ld
	ld -T linker.ld -o kernel.bin $(OBJ)

%.o: %.c
	gcc -m32 -ffreestanding -c $< -o $@

clean:
	rm -f kernel/*.o graphics/*.o *.iso boot/*.bin kernel.bin
	rm -rf iso

run: os-image
	qemu-system-i386 -cdrom myos.iso
