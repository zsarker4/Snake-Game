#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>

#include "Snake.h"
#include "Food.h"

#define WIDTH 50
#define HEIGHT 25

using namespace std;

Snake snake({ WIDTH/2, HEIGHT/2 }, 1);
Food food;
int score = 0;

void background() {
	COORD snakePos = snake.getPos();
	COORD foodPos = food.getPos();
	vector <COORD> snakeBody = snake.getBody();
	cout << "SCORE: " << score << "\n";
	for (int i = 0; i < HEIGHT; i++) {
		cout << "\t\t#";
		for (int j = 0; j < WIDTH - 2; j++) {
			if (i == 0 || i == HEIGHT - 1) {
				cout << "#";
			}
			else if (i == snakePos.Y && j+1 == snakePos.X) {
				cout << "O";
			}
			else if (i == foodPos.Y && j+1 == foodPos.X) {
				cout << "*";
			}
			else {
				bool isBodyPart = false;
				for (int k = 0; k < snakeBody.size() - 1; k++) {
					if (i == snakeBody[k].Y && j + 1 == snakeBody[k].X) {
						cout << "O";
						isBodyPart = true;
						break;
					}
				}
				if (!isBodyPart) {
					cout << " ";
				}
			}
		}
		cout << "#\n";
	}
}

int main() {
	score = 0;
	srand(time(NULL));
	food.genFood();
	bool gameOver = false;
	while (!gameOver) {
		background();
		if (_kbhit()) {
			switch (_getch()) {
			case 72:
				snake.changeDirection('u'); break;
			case 75:
				snake.changeDirection('l'); break;
			case 80:
				snake.changeDirection('d'); break;
			case 77:
				snake.changeDirection('r'); break;
			}
		}
		if (snake.collided()) {
			gameOver = true;
		}
		if (snake.eaten(food.getPos())) {
			food.genFood();
			snake.grow();
			score++;
		}
		snake.moveSnake();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	}	
}