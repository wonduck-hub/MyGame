#include "Stage.h"

int startBlockCount = 0;
int blockCount = 0;

Stage::Stage(int x, int y) {
	this->xSize = x;
	this->ySize = y;

	for (int i = 0; i < y; ++i) {
		for (int j = 0; j < x; ++j) {
			if (j == 0 || j == (x - 1))
				table[i][j] = 2;
			else
				table[i][j] = 0;
		}
	}

	table[p->getY()][p->getX()] = 1;
}
bool Stage::getPlay() {
	return play;
}
void Stage::setPlay(bool play) {
	this->play = play;
}
void Stage::showTable() {
	for (int i = 0; i < ySize; ++i) {
		for (int j = 0; j < xSize; ++j) {
			if (j == 0 || j == (xSize - 1))
				table[i][j] = 2;
			else
				table[i][j] = 0;
		}
	}

	table[p->getY()][p->getX()] = 1;

	for (int i = startBlockCount; i < blockCount; ++i) {
		table[blocks[i]->getX()][blocks[i]->getY()] = 3;
	}

	for (int i = 0; i < ySize; ++i) {
		for (int j = 0; j < xSize; ++j) {
			printChar(table[i][j]);
		}
		cout << endl;
	}

	//충돌 검사
	if (table[p->getY()][p->getX()] != 1)
		play = false;
}
void Stage::playerRMove() {
	if (table[p->getY()][p->getX() + 1] == 3)
		play = false;
	p->rightMove();
}
void Stage::playerLMove() {
	if (table[p->getY()][p->getX() - 1] == 3)
		play = false;
	p->leftMove();
}
void Stage::blockDown() {
	for (int i = startBlockCount; i < blockCount; ++i) {
		if (blocks[i]->getX() > 28) {
			++startBlockCount;
			free(blocks[i]);
		}
		else {
			blocks[i]->down();
		}
	}
}
void Stage::addBlock() {
	srand(static_cast<unsigned int>(time(NULL)));
	int r = (rand() * rand()) % 48;
	++r;

	blocks[blockCount++] = new Block(0, r);
}
void Stage::printChar(int t) {
	// 는 빈칸 : 0
		//T는 플레이어 : 1
		//@는 벽 : 2
		//#은 장애물 : 3

	if (t == 0)
		cout << " ";
	else if (t == 2)
		cout << "@";
	else if (t == 3)
		cout << "#";
	else if (t == 1)
		cout << "T";
}