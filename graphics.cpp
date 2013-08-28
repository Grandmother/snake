#include "graphics.h"

void graph_init(){
	initscr();
    start_color();
	raw();
	noecho();

//   wattron(stdscr,COLOR_PAIR(2));
    init_pair(1,COLOR_RED,COLOR_BLACK);
//  init_pair(2,COLOR_WHITE, COLOR_BLACK);
    init_pair(3,COLOR_GREEN,COLOR_BLACK);
    init_pair(4,COLOR_YELLOW,COLOR_BLACK);
    init_pair(5,COLOR_MAGENTA,COLOR_BLACK);
}

void get_screen_size (unsigned char *x_size, unsigned char *y_size){
	getmaxyx(stdscr,*y_size,*x_size);
}


int set_screen_size (unsigned char x_size, unsigned char y_size){
	return resizeterm(y_size,x_size);
}

void draw_field (unsigned char *field){
	int cols = 0;
	int rows = 0;
	int index;

	getmaxyx(stdscr,rows,cols);
	for (int i=0; i < rows; i++){
	for (int j=0; j < cols; j++){
		index = i*cols + j;
		switch (field[index]){
			case 0:			// field character
				mvprintw(i,j," ");
				break;
			case 1:
				attron(COLOR_PAIR(1) | A_BOLD);
				mvprintw(i,j,"+");
				attroff(COLOR_PAIR(1) | A_BOLD);
				break;
			case 5:
                attron(COLOR_PAIR(3) | A_BOLD);
                mvprintw(i,j,"%%");
                attroff(COLOR_PAIR(3) | A_BOLD);
				break;
			case 6:
                attron(COLOR_PAIR(5) | A_BOLD);
				mvprintw(i,j,"o");
                attroff(COLOR_PAIR(5) | A_BOLD);
				break;
			case 7:
                attron(COLOR_PAIR(4) | A_BOLD);
				mvprintw(i,j,"O");
                attroff(COLOR_PAIR(4) | A_BOLD);
				break;
			case 8:
				mvprintw(i,j,"#");
				break;
		}
	}
	}
	refresh();
}

void show_message(char *message){
	unsigned char row,col;
	getmaxyx(stdscr,row,col);
	mvprintw(row/2,(col)/2,"%s\n",message);
	refresh();
	return;
}

void graph_close(){
	echo();
	endwin();
	printf("\n");
}
