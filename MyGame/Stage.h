#ifndef STAGE_H
#define STAGE_H

#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>

#include "Player.h"
#include "Block.h"

using namespace std;



class Stage {
private:
	int xSize;
	int ySize;
	int table[999][999];
	bool play = true;
	Block* blocks[99999];
	Player* p = new Player(24, 28);

public:
	Stage(int x, int y);

	bool getPlay();
	void setPlay(bool play);
	void showTable();
	void playerRMove();
	void playerLMove();
	void blockDown();
	void printChar(int t);
	void addBlock();
};

#endif