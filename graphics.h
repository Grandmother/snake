#include <ncurses.h>

/*
	This library contain functions to work with graphics
*/

/*Function may init graphics with default settings. Maximum available screen
  size will be choosed as default.
*/
void graph_init();

/*Function may init graphics with specified parameters. 
*/
//void graph_init(int x_size, int y_size);

/*Function return the current console (field) size via parameters. Game will
  use this  function to set field array size.
*/
void get_screen_size (unsigned char *x_size, unsigned char *y_size);


/*If user want to set his own field size programm will do it with this
  function. Function get new field size in parameters and try to change
  field size. Procedure will return error code if maximum screen size is
  less than user want.
*/
int set_screen_size (unsigned char x_size, unsigned char y_size);



/* This function have single parameter as pointer to first element of
   field array. Function get field size from screen size and use it as
   field size.

 */
void draw_field (unsigned char *field);

/* This function will show message*/
void show_message(char*);

/* This function end courses mode*/
void graph_close();
