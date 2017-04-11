#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 15;
const int MAX_SNAKE_SIZE = 10;
int size = 2; // Start snake size
int scores = 0;

enum state{live, die};
state cur_state = live;
enum direction{s_right, s_left, s_up, s_down};
direction cur_direction = s_right;
bool food_exist = false;


class Snake
{
public:
	Snake();
	~Snake(){return;};
	char field[WIDTH][HEIGHT]; // GAmeplay
	int coordinates[MAX_SNAKE_SIZE][2]; //Array with the snake head and sigmets coordinates
	
	void check_collide(int i, int j); //Check collision with itself & with a food
	void def_snake(); //Add snake symbols to gameplay(field) array
	void new_food(); //create new food coordinates
	void def_food(); //Add food symbols to gameplay
	void def_frame(); //Add frame symbols to gameplay
	void display_all(); //cout all gameplay
	void change_size(); //increase the snake size after eating the food
	void clear_display();//reset all symbols to ' '
	void move();//check direction and move the snake
	int food_x, food_y;
};

Snake :: Snake()
{
	register int i, j, p, k;
	for (j = 0; j<HEIGHT; j++){
		for (i = 0; i<WIDTH; i++){
			field[i][j] = ' ';
		}
	}
	for (p = 0; p < 2; p++){
		for (k = 0; k < MAX_SNAKE_SIZE -1; k++){
			coordinates[k][p] = -10;}
	}
	coordinates[0][0] = 5;
	coordinates[0][1] = 5;
	coordinates[1][0] = 4;
	coordinates[1][1] = 5;
}

void Snake :: def_frame()
{
	int i, j;
	for (j = 0; j<HEIGHT; j++){
					for (i = 0; i<WIDTH; i++){
						if ((i == 0 || i == (WIDTH - 1)) || ((j == 0) || (j == HEIGHT - 1))) field[i][j] = '#';
						} 
				}
}


void Snake :: def_snake()
{
	register int i, j;

	for (j = 0; j<HEIGHT; j++){
		for (i = 0; i<WIDTH; i++){

			for (int e = 0; e < MAX_SNAKE_SIZE -1; e++){
				if (coordinates[e][0] != -10){
					if (e == 0){
						if ((i == coordinates[e][0]) && (j == coordinates[e][1])){
							check_collide(i, j);
							field[i][j] = 'o';
						}
					}
					else{
						if ((i == coordinates[e][0]) && (j == coordinates[e][1])){
										field[i][j] = '+';
						}
					}					
				}
		}
													
		}
	}
}

void Snake :: check_collide(int i, int j)
{
	if (field[i][j] == '@'){
		change_size();
		food_exist = false;
		scores += 10;
	} 
	for (int e = 1; e < MAX_SNAKE_SIZE -1; e++){
		if (i == coordinates[e][0] && j == coordinates[e][1]){
			cur_state = die;
		}
		
	}
}

void Snake :: clear_display()
{
	register int i, j;
	for (j = 0; j<HEIGHT; j++){
		for (i = 0; i<WIDTH; i++){
			field[i][j] = ' ';
		}
	}
}

void Snake :: new_food()
{
	static long int start;
	int s_rand;
	s_rand = rand();
	start = clock();
	food_x = (start) % (WIDTH - 2);
	food_y = (start) % (HEIGHT - 2);
	if (food_x == 0) food_x++;
	if (food_y == 0) food_y++;
	food_exist = true;	
}

void Snake :: def_food()
{
	field[food_x][food_y] = '@';
}

void Snake :: display_all()
{
	register int i, j;
	for (j = 0; j<HEIGHT; j++){
		for (i = 0; i<WIDTH; i++){
			cout << field[i][j];
		}
		cout << '\n';
	}
}

void Snake :: change_size()
{
	coordinates[size][0] = -5;
	coordinates[size][1] = -5;
	if (size < MAX_SNAKE_SIZE) size++;
	else return;
}

void Snake :: move()
{		
		int delay;
		delay = 1;
		for (int e = MAX_SNAKE_SIZE -1; e > 0; e--){
			if (coordinates[e][0] != -10){
				coordinates[e][0] = coordinates[e-1][0];
				coordinates[e][1] = coordinates[e-1][1];
			}
		}
		switch (cur_direction){
			case s_right:
				coordinates[0][0] += 1;
				if (coordinates[0][0] == (WIDTH -1)) coordinates[0][0] = 1;
				break;
			case s_left:
				coordinates[0][0] -= 1;
				if (coordinates[0][0] == -1) coordinates[0][0] = WIDTH - 2;
				break;
			case s_up:
				coordinates[0][1] -= 1;
				if (coordinates[0][1] == -1) coordinates[0][1] = HEIGHT - 2;
				break;
			case s_down:
				coordinates[0][1] += 1;
				if (coordinates[0][1] == (HEIGHT -1)) coordinates[0][1] = 1;
				break;
		}
		system("cls");
		if (!food_exist) this -> new_food();
		this -> def_food();
		this -> def_snake();
		this -> def_food();
		this -> def_frame();
		this -> display_all();
		clock_t start;
		start = clock();
		while (clock()/CLOCKS_PER_SEC - start/CLOCKS_PER_SEC < delay);
		this -> clear_display();
}

class Game
{
public:
	Game(){};
	~Game(){};
	void play(Snake &object);
};

void Game :: play(Snake &object)
{
	char user_command;
	user_command = 'd';
	while(cur_state == live){
	
		if (kbhit()) user_command = getch();
		
		switch (user_command){
			case 'a':
				cur_direction = s_left;
				break;
			case 'd':
				cur_direction = s_right;
				break;
			case 'w':
				cur_direction = s_up;
				break;
			case 's':
				cur_direction = s_down;
			default:
				break;
		}
		object.move();
	}
	cout << "GAME OVER!\n";
	cout << "YOUR SCORES: " << scores;

}


int main(int argc, char const *argv[])
{
	Snake hero;
	Game new_game;
	new_game.play(hero);
	return 0;
}