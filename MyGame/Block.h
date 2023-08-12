#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;

class Block {
private:
	int x;
	int y;

public:
	Block(int x, int y);
	int getX();
	int getY();
	void down();
};

#endif