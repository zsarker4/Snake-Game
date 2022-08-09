#ifndef SNAKE_H
#define SNAKE_H

#include <windows.h>
#include <vector>

class Snake {
private:
	COORD pos;
	int len;
	int vel;
	char direction;
	std::vector<COORD> body;

public:
	Snake(COORD position, int velocity);
	void changeDirection(char dir);
	std::vector <COORD> getBody();
	void moveSnake();
	COORD getPos();
	bool eaten(COORD foodPos);
	void grow();
	bool collided();
};
#endif