#include "kernel.h"
#include "../graphics/vga.h"

void kernel_main() {
    set_video_mode(0x13);  // VGA 320x200 mode

    draw_box(40, 40, 240, 120, 4);   // Red outer box
    draw_box(45, 45, 230, 110, 1);   // Blue inner box

    // Simple mock-up window title bar
    draw_box(45, 45, 230, 15, 15);   // White title bar
    draw_box(50, 48, 5, 5, 12);      // "X" button in red

    while (1) { __asm__ volatile("hlt"); }
}
