#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 15;
int size = 1;

enum state{live, die};
state cur_state;
enum direction{s_right, s_left, s_up, s_down};
direction cur_direction = s_right;


class Snake
{
public:
	Snake();
	~Snake(){};

	char field[WIDTH][HEIGHT];
	int coordinates[100][2];
	int speed;
	
	void def_snake();
	void def_frame();
	void display_all();
	void change_size();
	void move();
};

Snake :: Snake()
{
	register int i, j;
	for (j = 0; j<HEIGHT; j++){
		for (i = 0; i<WIDTH; i++){
			field[i][j] = ' ';
		}
	}
	coordinates[0][0] = 5;
	coordinates[0][1] = 5;
	
	speed = 2;
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
			int x,y;
			for (x = 0, y = 0; x < size, y < size; x++, y++){
				if ((i == coordinates[x][0]) && (j == coordinates[y][1])){
								field[i][j] = '0';
								switch(cur_direction){
										case s_right:
											field[i-size][j] = ' ';
											break;
										case s_left:
											field[i+size][j] = ' ';
											break;
										case s_up:
											field[i][j+size] = ' ';
											break;
										case s_down:
											field[i][j-size] = ' ';
											break;
								}
				}
			}
			
		}
	}
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
	for (int i = 0; i < size; i++){
    	for (int j = 0; j < 2; j++) cout << coordinates[i][j] << " ";
     cout << endl;
	}
	coordinates[size][0] = coordinates[size-1][0];
	coordinates[size][1] = coordinates[size-1][1];
	size ++;
}

void Snake :: move()
{		
		float delay;
		delay = 3/speed;

		switch (cur_direction){
			case s_right:
				coordinates[0][0] += 1;
				if (coordinates[0][0] == (WIDTH)) coordinates[0][0] = 1;
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
				if (coordinates[0][1] == (HEIGHT)) coordinates[0][1] = 1;
				break;
		}
		system("cls");
		this -> def_snake();
		this -> def_frame();
		this -> display_all();
		clock_t start;
		start = clock();
		while (clock()/CLOCKS_PER_SEC - start/CLOCKS_PER_SEC < delay);
		
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
	cout << "Game is started";
	char user_command;
	for(;;){
		
		switch (cur_state){
			case die:
				cout << "Game over!" << endl;
				return;
			default:
				break;
		}
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

}


int main(int argc, char const *argv[])
{
	Snake hero;
	hero.change_size();
	hero.change_size();

	for (int i = 0; i < size; i++){
    	for (int j = 0; j < 2; j++) cout << hero.coordinates[i][j] << " ";
     cout << endl;
	}
	
	Game new_game;
	new_game.play(hero);

	//new_game.play(hero);
	return 0;
}