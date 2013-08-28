#include "snake.h"
#include "graphics.h"
#include <stdlib.h>


class field{
private:
	bool borders;
    bool food;
	snake *snakes;
	char snakes_count;
	unsigned char x_size;
	unsigned char y_size;
	unsigned char *field_array;	// array values:
			// 0  - field
			// 1  - 4 - snake's body
			// 5  - snake's head
			// 6  - food
			// 7  - super food
			// 8  - border
			// 9  - dead snake's head
			// 10 - dead snake's body
public:
	field(	unsigned char new_x_size,
		unsigned char new_y_size);	// alocate memory to field array
	int     add_snake();		// adding snake to field
	void	game_paused();
	int     game_step();
	void	food_add(unsigned char *field_array, unsigned char x_size, unsigned char y_size);
	void	set_borders(char);
	void	game_over();
	void	game_event(char event_numbeer);
};
