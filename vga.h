#ifndef VGA_H
#define VGA_H

#include <stdint.h>

void set_video_mode(uint8_t mode);
void put_pixel(int x, int y, uint8_t color);
void draw_box(int x, int y, int width, int height, uint8_t color);

#endif
