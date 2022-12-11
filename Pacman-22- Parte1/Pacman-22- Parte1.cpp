#include <iostream>
#include <conio.h>
#include <cstdlib>
#define MAP_VERTICAL 29
#define MAP_HORIZONTAL 120
#define PERSONAJE '0'
enum TILES {EMPTY = ' ', WALL = '#', POINT = '.' };
TILES map[MAP_VERTICAL][MAP_HORIZONTAL];
bool run = true; 

enum INPUT {QUIT, UP, DOWN, LEFT, RIGHT, UNKNOWN };
INPUT currentInput = INPUT::UNKNOWN; 

int personaje_x;
int personaje_y;
int puntuacion_actual = 0;
int puntuacion_total;



void Setup() {
	personaje_x = MAP_HORIZONTAL / 2;
	personaje_y = MAP_VERTICAL / 2;
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == 0 || j == 0 || i == MAP_VERTICAL - 1 || j == MAP_HORIZONTAL - 1) {
				map[i][j] = TILES::WALL;
			}
			else {
				map[i][j] = TILES::EMPTY;
			}
		}
	}

	map[12][18] = TILES::POINT;
	map[12][19] = TILES::POINT;
	map[12][20] = TILES::POINT;
	map[12][58] = TILES::POINT;
	map[12][59] = TILES::POINT;
	map[12][60] = TILES::POINT;
	map[12][98] = TILES::POINT;
	map[12][99] = TILES::POINT;
	map[12][100] = TILES::POINT;
	
	map[11][1] = TILES::POINT;
	map[12][1] = TILES::POINT;
	map[13][1] = TILES::POINT;
	map[14][1] = TILES::POINT;
	map[10][MAP_HORIZONTAL - 2] = TILES::POINT;
	map[11][MAP_HORIZONTAL - 2] = TILES::POINT;
	map[12][MAP_HORIZONTAL - 2] = TILES::POINT;
	map[13][MAP_HORIZONTAL - 2] = TILES::POINT;
	map[1][56] = TILES::POINT;
	map[1][57] = TILES::POINT;
	map[1][58] = TILES::POINT;
	map[1][59] = TILES::POINT;
	map[1][60] = TILES::POINT;
	map[1][61] = TILES::POINT;
	map[1][62] = TILES::POINT;
	map[1][63] = TILES::POINT;
	map[MAP_VERTICAL - 2][56] = TILES::POINT;
	map[MAP_VERTICAL - 2][57] = TILES::POINT;
	map[MAP_VERTICAL - 2][58] = TILES::POINT;
	map[MAP_VERTICAL - 2][59] = TILES::POINT;
	map[MAP_VERTICAL - 2][60] = TILES::POINT;
	map[MAP_VERTICAL - 2][61] = TILES::POINT;
	map[MAP_VERTICAL - 2][62] = TILES::POINT;
	map[MAP_VERTICAL - 2][63] = TILES::POINT;

	map[11][7] = TILES::WALL;
	map[12][7] = TILES::WALL;
	map[13][7] = TILES::WALL;
	map[14][7] = TILES::WALL;
	map[10][MAP_HORIZONTAL - 8] = TILES::WALL;
	map[11][MAP_HORIZONTAL - 8] = TILES::WALL;
	map[12][MAP_HORIZONTAL - 8] = TILES::WALL;
	map[13][MAP_HORIZONTAL - 8] = TILES::WALL;
	map[3][56] = TILES::WALL;
	map[3][57] = TILES::WALL;
	map[3][58] = TILES::WALL;
	map[3][59] = TILES::WALL;
	map[3][60] = TILES::WALL;
	map[3][61] = TILES::WALL;
	map[3][62] = TILES::WALL;
	map[3][63] = TILES::WALL;
	map[MAP_VERTICAL - 4][56] = TILES::WALL;
	map[MAP_VERTICAL - 4][57] = TILES::WALL;
	map[MAP_VERTICAL - 4][58] = TILES::WALL;
	map[MAP_VERTICAL - 4][59] = TILES::WALL;
	map[MAP_VERTICAL - 4][60] = TILES::WALL;
	map[MAP_VERTICAL - 4][61] = TILES::WALL;
	map[MAP_VERTICAL - 4][62] = TILES::WALL;
	map[MAP_VERTICAL - 4][63] = TILES::WALL;

	map[13][30] = TILES::WALL;
	map[13][31] = TILES::WALL;
	map[13][32] = TILES::WALL;
	map[13][33] = TILES::WALL;
	map[13][34] = TILES::WALL;
	map[13][35] = TILES::WALL;
	map[13][36] = TILES::WALL;
	map[13][37] = TILES::WALL;
	map[14][34] = TILES::WALL;
	map[15][34] = TILES::WALL;
	map[16][34] = TILES::WALL;
	map[17][34] = TILES::WALL;

	map[13][80] = TILES::WALL;
	map[13][81] = TILES::WALL;
	map[13][82] = TILES::WALL;
	map[13][83] = TILES::WALL;
	map[13][84] = TILES::WALL;
	map[13][85] = TILES::WALL;
	map[13][86] = TILES::WALL;
	map[13][87] = TILES::WALL;
	map[12][84] = TILES::WALL;
	map[11][84] = TILES::WALL;
	map[10][84] = TILES::WALL;
	map[9][84] = TILES::WALL;


	map[11][0] = TILES::EMPTY;
	map[12][0] = TILES::EMPTY;
	map[13][0] = TILES::EMPTY;
	map[14][0] = TILES::EMPTY;
	map[0][56] = TILES::EMPTY;
	map[0][57] = TILES::EMPTY;
	map[0][58] = TILES::EMPTY;
	map[0][59] = TILES::EMPTY;
	map[0][60] = TILES::EMPTY;
	map[0][61] = TILES::EMPTY;
	map[0][62] = TILES::EMPTY;
	map[0][63] = TILES::EMPTY;

	map[10][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[11][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[12][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[13][MAP_HORIZONTAL - 1] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][56] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][57] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][58] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][59] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][60] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][61] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][62] = TILES::EMPTY;
	map[MAP_VERTICAL - 1][63] = TILES::EMPTY;



	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (map[i][j] == TILES::POINT) {
				puntuacion_total++;
			}
		}
	}
}


void Input() {
	char input;
		input = _getch();
		switch (input) {
			case 'w':
			case 'W':
				currentInput = INPUT::UP;
				break;
			case 's':
			case 'S':
				currentInput = INPUT::DOWN;
				break;
			case 'a':
			case 'A':
				currentInput = INPUT::LEFT;
				break;
			case 'd':
			case 'D':
				currentInput = INPUT::RIGHT;
				break;
			case 'q':
			case 'Q':
				currentInput = INPUT::QUIT;
				break;
			default:
				currentInput = INPUT::UNKNOWN;
				break;
			}
		}
	
void Logic() {
	int personaje_y_new = personaje_y;
	int personaje_x_new = personaje_x;
	switch (currentInput)
	{
	case QUIT:
		run = false;
		break;
	case UP:
		personaje_y_new--;
		break;
	case DOWN:
		personaje_y_new++;
		break;
	case LEFT:
		personaje_x_new--;
		break;
	case RIGHT:
		personaje_x_new++;
		break;
	}
	if (personaje_x_new < 0) {
		personaje_x_new = MAP_HORIZONTAL - 1;
	}
	personaje_x_new = personaje_x_new % MAP_HORIZONTAL;

	if (personaje_y_new < 0) {
		personaje_y_new = MAP_VERTICAL - 1;
	}
	personaje_y_new = personaje_y_new % MAP_VERTICAL;
	
	switch (map[personaje_y_new][personaje_x_new])
	{
	case TILES::WALL:
		break;
	case TILES:: POINT:
		puntuacion_actual++;
		map[personaje_y_new][personaje_x_new] = TILES::EMPTY;
	default:
		personaje_y = personaje_y_new;
		personaje_x = personaje_x_new;
		break;
	}
}
void Draw() {
	system("CLS");
	system("COLOR fd");
	system("title: PACMAN JUAN CARLOS RUIZ");
	for (size_t i = 0; i < MAP_VERTICAL; i++)
	{
		for (size_t j = 0; j < MAP_HORIZONTAL; j++)
		{
			if (i == personaje_y && j == personaje_x){
				std::cout << PERSONAJE;
            }
			else {
				std::cout << (char)map[i][j];
			}
		}
		std::cout << std::endl;
	}
	std::cout << puntuacion_actual << '/' << puntuacion_total;
	
}

int main()
{
	Setup();
	Draw();
	while (run) {
		Input();
		Logic();
		Draw();
	}
}