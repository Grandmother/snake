#include <stdlib.h>

struct node{
	int x,y;		// node coordinates
	node *prev_node;
	node *next_node;
};

class snake{
private:
	node *Head;
	node *Tail;

	bool direction_changed;
	char direction;	// snake direction
			//  1 - nord
			// -1 - south
			//  3- east
			// -3 - west
	unsigned char buttons[4];	// have codes of control-buttons
	unsigned char array_value;	// have value that will symbolize
					// this snake in field-array

public:
/* snake constructor. It's have three params: two coordinates of snake's
   head and direction of her body.*/
	snake (	unsigned char head_x,
		unsigned char head_y,
			 char new_direction,
		unsigned char *field_array,
		unsigned char x_size);


	void change_direction (char new_direction);
/* this function will return anything that snake can see in front of her snout */
	char snake_have_obstacle (unsigned char *field, unsigned char x_size);
/* delete last symbol */
	void tail_move (unsigned char *field_array, unsigned char x_size);
/* move head to new position */
	void head_move (unsigned char *field_array,unsigned char x_size);
	void kill (unsigned char *field_array,
		   unsigned char x_size,
		   unsigned char y_size);	// delete snake if she have die
};
