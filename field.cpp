#include "field.h"

field::field(	unsigned char new_x_size,
		unsigned char new_y_size){
	borders         = true;
    food            = false;
	snakes_count    = 0;
//	for (int i = 0; i < 4;i++){
		snakes = NULL;
//	}
	x_size = new_x_size;
	y_size = new_y_size;
	field_array = (unsigned char*) calloc (x_size*y_size, sizeof(unsigned char));
	for (int i=0; i < x_size*y_size; i++)
		field_array[i] = 0;
	set_borders(1);
	return;
}

int field::add_snake(){
//	if (snakes_count == 4){		// if number of snakes is too big
//		return -1;
//	}
	snakes_count = 0;
	snakes = new snake(x_size/2, y_size/2, 3, field_array, x_size);
//	snakes_count++;
}

void field::game_paused(){
	char message[]="Pause. To continue the game press \"Any key\".";
	show_message(message);
}

int field::game_step(){
	char obstacle;
    if (!food){
        food_add(field_array,x_size,y_size);
    }
//	for (int i=0; i < snakes_count; i++){
		obstacle = snakes->snake_have_obstacle(field_array,x_size);
		// snake die and if it's last snake game will be ended
		if ((obstacle == 1) || (obstacle == 5) || (obstacle == 8)){
			snakes->kill(field_array, x_size, y_size);
//			if ( !--snakes_count){
				game_over();
				return 1;
//			}
		}
		if ((obstacle != 6) && (obstacle != 7)){	// tail have not moved
			snakes->tail_move(field_array,x_size);
		}
        else{
            food = false;
        }
//	}
//	for (int i = 0; i < snakes_count; i++){
		snakes->head_move(field_array,x_size);
//	}
	draw_field(field_array);
	return 0;
}

void field::set_borders(char bor){ 
	char border	= bor ? 8 : 0;
	borders		= bor ? true : false;
	int index;
	for (int i = 0; i < x_size; i++){
		index = i;
		field_array[index]	= border;
		index = (y_size-1)*x_size + i;
		field_array[index]	= border;
	}
	for (int i = 0; i < y_size; i++ ){
		index = i*x_size;
		field_array[index]	= border;
		index = i*x_size + x_size-1;
		field_array[index]	= border;
	}
}

void field::game_over(){
	char message[] = "GAME OVER!\nPress \"Any key\" to exit.";
	draw_field(field_array);
	show_message(message);
	getch();
	graph_close();
}

void field::game_event(char event_numbeer){
	if (event_numbeer == 0){	// pause
		game_paused();
		return;
	}
	if (event_numbeer == 5){	// exit
//		for (int i = 0; i < snakes_count; i++){
			if (snakes){
				snakes->kill(field_array, x_size, y_size);
			}
//		}
		game_over();
		return;
	}
	switch (event_numbeer){
	case 1:
		snakes->change_direction( 1);
		break;
	case 2:
		snakes->change_direction(-1);
		break;
	case 3:
		snakes->change_direction( 3);
		break;
	case 4:
		snakes->change_direction(-3);
		break;
	}
	return;
}

void field::food_add(unsigned char *field_array, unsigned char x_size, unsigned char y_size){
    int food_coordinates = random()%(x_size*y_size);
    while (field_array[food_coordinates]){
        food_coordinates = random()%(x_size*y_size);
    }
    field_array[food_coordinates] = 6;
    food = true;
    return;
}
