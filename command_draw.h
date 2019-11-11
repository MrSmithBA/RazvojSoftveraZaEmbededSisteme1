/*
 * autor: Milos Kovac 
 * */
#ifndef COMMAND_DRAW_H
#define COMMAND_DRAW_H
/*#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>*/
#include "file_parser.h"

#define MAX_PKT_SIZE (640*480*4)

//comment to send pixels as commands via regular write function of char driver
//leave uncommented to write directly to memory (faster)
#define MMAP

#define X_MAX 640
#define Y_MAX 480
#define SIZE_OF_IMAGE X_MAX*Y_MAX
/*
 * U SLUCAJU STATICKE ALOKACIJE NEOPHODNO JE DEFINISATI MAKSIMALNU VELICINU LINIJE IZ FAJLA 
 * KAO I MAKSIMALAN BROJ LINIJA KOJE PROGRAM MOZE PROCESIRATI U FAJLU
 * ZASTITA NIJE REALIZOVANA U SLUCAJU DA SE OVAJ BROJ PREMASI
 * U TOM SLUCAJU NASTUPA PISANJE PO NULL POINTERU ILI JOS GORE, PISANJE PO NAREDNOM ALOCIRANOM PROSTORU STO MOZE DOVESTI DO NEKONZISTENTNOSTI PODATAKA ! 
 * */

#define RGB_RED     0x1F00
#define RGB_BLACK   0x0000
#define RGB_WHITE   0xFFFF
#define RGB_GREEN   0x03F0
#define RGB_YELLOW  (RGB_RED | RGB_GREEN)
#define RGB_BLUE    0x001F

void draw_all(command_buffer_t* p_cmd_buffer);

#endif