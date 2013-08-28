#include "snake.h"

snake::snake(	unsigned char head_x,
		unsigned char head_y,
			 char new_direction,
		unsigned char *field_array,
		unsigned char x_size){
	int index;
	array_value = 1;
	Head = new node;
	Tail = new node;
	Head->x = head_x;
	Head->y = head_y;
	
	Head->next_node = NULL;
	Head->prev_node = Tail;
	Tail->next_node = Head;
	Tail->prev_node = NULL;

	index = Head->y*x_size + Head->x;
	field_array[index] = 5;
	direction = 3;
//	direction = new_direction;
	switch (direction){
	case  1:
		Tail->x = Head->x;
		Tail->y = Head->y + 2;
		for(int i = Head->y + 1; i <= Tail->y; i++){
			index = i*x_size + Head->x;
			field_array[index] = array_value;
		}
		break;
	case -1:
		Tail->x = Head->x;
		Tail->y = Head->y - 2;
		for(int i = Tail->y; i <= Head->y-1;i++){
			index = i*x_size + Head->x;
			field_array[index] = array_value;
		}
		break;
	case  3:
		Tail->y = Head->y;
		Tail->x = Head->x - 2;
		for(int i = Tail->x; i <= Head->x - 1;i++){
			index = Tail->y*x_size + i;
			field_array[index] = array_value;
		}
		break;
	case -3:
		Tail->y = Head->y;
		Tail->x = Head->x +2;
		for(int i = Head->y + 1; i <= Tail->y;i++){
			index = Head->y*x_size + i;
			field_array[index] = array_value;
		}
		break;
	}
	return;
}

void snake::change_direction(char new_direction){
	if (direction != -new_direction){
		direction = new_direction;
		direction_changed = true;
	}
	return;
}

char snake::snake_have_obstacle(unsigned char *field, unsigned char x_size){
	char obstacle;
	int index;
	switch (direction) {
	case  1:
		index = (Head->y - 1)*x_size + Head->x;
		break;
	case -1:
		index = (Head->y + 1)*x_size + Head->x;
		break;
	case  3:
		index = Head->y*x_size + Head->x + 1;
		break;
	case -3:
		index = Head->y*x_size + Head->x - 1;
		break;
	}
	obstacle = field [index];
	return obstacle;
}

void snake::tail_move(unsigned char *field_array, unsigned char x_size){
	field_array[(Tail->y)*x_size + Tail->x] = 0;
	if (Tail->next_node->x == Tail->x){
		if (Tail->next_node->y > Tail->y) Tail->y ++;
		else Tail->y--;
	}
	else{
		if (Tail->next_node->x > Tail->x) Tail->x ++;
		else Tail->x--;
	}

	if ((Tail->next_node->x == Tail->x) && (Tail->next_node->y == Tail->y)){
		node *temp = Tail;
		Tail = Tail->next_node;
		Tail->prev_node = NULL;
		delete temp;
	}
	return;
}

void snake::head_move(unsigned char *field_array, unsigned char x_size){
	if (direction_changed){
		node *temp = new node;
		temp->x = Head->x;
		temp->y = Head->y;
		temp->prev_node = Head;
		temp->next_node = NULL;
		Head->next_node = temp;
		Head = temp;
		direction_changed = false;
	}
	field_array[(Head->y)*x_size + Head->x] = array_value;
	switch (direction) {
	case  1:
		Head->y -= 1;
		break;
	case -1:
		Head->y += 1;
		break;
	case  3:
		Head->x += 1;
		break;
	case -3:
		Head->x -= 1;
		break;
	}
	field_array[(Head->y)*x_size + Head->x] = 5;
}
void snake::kill(unsigned char *field_array,
		 unsigned char x_size,
		 unsigned char y_size){
	field_array[Head->y*x_size + Head->x] = 0;
	for (int i = 0; i < x_size; i++){
	for (int j = 0; j < y_size; j++){
		if (field_array[j*x_size + i] == array_value){
			field_array[j*x_size + i] = 0;
		}
	}
	}

	Tail = Tail->next_node;
	while (Tail) {
		delete Tail->prev_node;
		Tail = Tail->next_node;
	}
	delete Head;
	return;
}
