#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Player {
private:
	int x;
	int y;

public:
	Player(int x, int y);
	int getX();
	int getY();
	void rightMove();
	void leftMove();
};

#endif