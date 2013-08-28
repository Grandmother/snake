#include "field.h"
#include "graphics.h"
#include "unix_conio.h"




int main(){
// variables
	unsigned char   x_size = 0;
	unsigned char   y_size = 0;
    char            direction = 1;
	int             counter;
	bool            game;
	bool            pause;

	field           *my_field;
	unsigned char   event_num;


	graph_init ();				// graphic initialisation
	get_screen_size (&x_size, &y_size);	// getiing size of screen

//////////////////////////////////
//x_size = 10;			//  It's only for debug.				//////////////////////////////
//y_size = 10;			//							//////////////////////////////
//resizeterm(10,10);		//
//////////////////////////////////
	my_field = new field(x_size, y_size);	// field initialisation
	my_field->add_snake();			// adding new snake to
						// field
	my_field->set_borders(1);

	game = true;
	pause = false;
	while (game){
		changemode(1);
		counter = 0;
		while (!kbhit()){
			//sleep(1);
			usleep(100);
			counter++;
			if((counter == 410 + direction ) && (!pause)){
				if (my_field->game_step() == 1){ // game is over
				    goto game_exit;	
				}
				counter = 0;
			}
		}
		switch (my_getch()){
		case 107:		// up    "k"
			event_num = 1;
			direction = 80;
			pause = false;
			break;
		case 106:		// down  "j"
			event_num = 2;
			direction = 80;
			pause = false;
			break;
		case 108:		// right "l"
			event_num = 3;
			direction = 0;
			pause = false;
			break;
		case 104:		// left  "h"
			event_num = 4;
			direction = 0;
			pause = false;
			break;
		case 112:		// pause "p"
			event_num = 0;
			pause = pause ? false : true;
			break;
		case 105:		// exit  "i"
			event_num = 5;
			game = false;
			break;
		default:
			pause = false;
			break;
		}
		my_field->game_event(event_num);
		changemode(0);
	}
game_exit:
	changemode(0);
	graph_close();
	return 0;
}
