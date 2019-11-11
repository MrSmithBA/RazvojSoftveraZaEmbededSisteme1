/*
 * autor: Milos Kovac 
 * */
#include "file_parser.h"
#include "command_draw.h"

int main(int argc, char **argv)
{
	if(argc!=2)
		return;
	process_file(argv[1]);
    //process_file("C:\\Users\\HP\\Documents\\test.txt");
    print_commands();
    command_buffer_t*cmd_buffer=get_cmd_buffer();
    draw_all(cmd_buffer);
}
