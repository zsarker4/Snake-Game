#ifndef food_h
#define food_h

#include <windows.h>
#include <cstdlib>

#define WIDTH 50
#define HEIGHT 25

class Food {
private:
	COORD pos;

public:
	void genFood();
	COORD getPos();
};
#endif;
