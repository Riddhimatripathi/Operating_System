#include "vga.h"
#include <stdint.h>

#define VIDEO_MEMORY 0xA0000
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

void set_video_mode(uint8_t mode) {
    __asm__ volatile (
        "int $0x10"
        :
        : "a"(0x0000 | mode)
    );
}

void put_pixel(int x, int y, uint8_t color) {
    uint8_t* video = (uint8_t*) VIDEO_MEMORY;
    video[y * SCREEN_WIDTH + x] = color;
}

void draw_box(int x, int y, int width, int height, uint8_t color) {
    for (int i = y; i < y + height; i++) {
        for (int j = x; j < x + width; j++) {
            put_pixel(j, i, color);
        }
    }
}
