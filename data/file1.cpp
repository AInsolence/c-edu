#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <time.h>

using namespace std;

const int WIDTH = 10;
const int HEIGHT = 10;


class Level
{
	
public:
	char field[WIDTH][HEIGHT];

	Level();
	~Level(){return;};

	void blit();
};

Level :: Level(){
	register int i, j;
	for (j = 0; j<HEIGHT; j++){
		for (i = 0; i<WIDTH; i++){
			if ((i == 0 || i == (WIDTH - 1)) || ((j == 0) || (j == HEIGHT - 1))) field[i][j] = ' ';
			else field[i][j] = ' ';
		}
	}
}

void Level :: blit()
{
	register int i, j;
	for (j = 0; j<HEIGHT; j++){
		for (i = 0; i<WIDTH; i++){
			cout << field[i][j];
		}
		cout << '\n';
	}
}

class Snake : public Level
{
public:
	int x_pos, y_pos;
	int size;
	enum direction{right, left, up, down};
	int speed;
	enum state{live, die};

	Snake();
	~Snake(){};
	void position();
	void move();
};

Snake :: Snake()
{
	x_pos = 5;
	y_pos = 5;
	speed = 1;
	size = 1;
}

void Snake :: position()
{
	register int i, j;
	for (j = 0; j<HEIGHT; j++){
		for (i = 0; i<WIDTH; i++){
			if ((i == x_pos) && (j == y_pos)) field[i][j] = '8';
			else field[i][j] = ' ';
		}
	}
}

void Snake :: move()
{
	for(;;){
		
		int seconds = 1;
		x_pos += 1;
		if (x_pos == WIDTH) x_pos = 0;
		this -> position();
		this -> blit();
		clock_t start;
		start = clock();
		while (clock()/CLOCKS_PER_SEC - start/CLOCKS_PER_SEC < seconds);
		system("cls");
	}
}

int main(int argc, char const *argv[])
{
	Level one;
	Snake hero;
	hero.position();
	hero.blit();
	hero.move();
	return 0;
}