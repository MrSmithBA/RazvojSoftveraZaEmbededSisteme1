
#ifndef COMMAND_DRAW_H
#define COMMAND_DRAW_H
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "file_parser.h"

#define MAX_PKT_SIZE (640*480*4)


#define X_MAX 640
#define Y_MAX 480
#define SIZE_OF_IMAGE X_MAX*Y_MAX


#define RGB_RED     0xF800
#define RGB_BLACK   0x0000
#define RGB_WHITE   0xFFFF
#define RGB_GREEN   0x07E0
#define RGB_YELLOW  (RGB_RED | RGB_GREEN)
#define RGB_BLUE    0x001F

void draw_all(command_buffer_t* p_cmd_buffer);

#endif