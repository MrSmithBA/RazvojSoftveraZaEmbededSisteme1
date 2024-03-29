
#include "command_draw.h"
#include "file_parser.h"
#include <stdio.h>
#include <stdlib.h>

int color_matrix[480][640];

static void draw_cmd(int x1, int y1, int x2, int y2,color_id_t clr_id){
    int i;
    int color_to_write=0; 
    int k;
    switch (clr_id){
        case RED_CLR:
            color_to_write=RGB_RED;
        break;
        case GREEN_CLR:
            color_to_write=RGB_GREEN;
        break;
        case BLUE_CLR:
            color_to_write=RGB_BLUE;
        break;
        case YELLOW_CLR:
            color_to_write=RGB_YELLOW;
        break; 
        case WHITE_CLR:
            color_to_write=RGB_WHITE;
        break;
        case BLACK_CLR:
            color_to_write=RGB_BLACK;
        break;
        default:
        break;
    }
    if (y1==y2){//linija horizontalna
        for (i =x1; i<x2; i++)
            color_matrix[y1][i]=color_to_write;
    }else if (x1==x2){//linija vertikalna
        for (i =y1; i<y2; i++)
            color_matrix[i][x1]=color_to_write;
    }else {
        for (i=y1;i<y2;i++)
            for (k=x1;k<x2;k++)
                color_matrix[i][k]=color_to_write;
    }
}
        
void copy_image_matrix(){
    int x,y;
	// If memory map is defined send image directly via mmap
	int fd;
	int *p;
	fd = open("/dev/vga_dma", O_RDWR|O_NDELAY);
	if (fd < 0)
	{
		printf("Cannot open /dev/vga for write\n");
		return ;
	}
	p=(int*)mmap(0,640*480*4, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	memcpy(p, color_matrix, MAX_PKT_SIZE);
	munmap(p, MAX_PKT_SIZE);
	close(fd);
	if (fd < 0)
	{
		printf("Cannot close /dev/vga for write\n");
		return ;
	}
} 

void draw_all(command_buffer_t* p_cmd_buffer){
    int i=0;
    for (i=0;i<p_cmd_buffer->size;i++)
        draw_cmd(p_cmd_buffer->commands[i].x1,p_cmd_buffer->commands[i].y1,p_cmd_buffer->commands[i].x2,p_cmd_buffer->commands[i].y2,p_cmd_buffer->commands[i].clr_id);
    copy_image_matrix();
}
