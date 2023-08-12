#include <iostream>
#include <ctime>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>

#include "Stage.h"

using namespace std;

const int RIGHT_ARROW = 77;
const int LEFT_ARROW = 75;

// 는 빈칸 : 0
//T는 플레이어 : 1
//@는 벽 : 2
//#은 장애물 : 3

//커서 위치 변경 함수
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

//커서 깜빡임 숨기는 함수
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

int main() {
	
    ShowConsoleCursor(false);
    
    clock_t startT, finishT;

    Stage* s = new Stage(50, 29);        

    startT = clock();
    int input;
    
    while (s->getPlay()) {

        if (_kbhit()) {
            input = _getch();
            
            switch (input) {
            case RIGHT_ARROW:
                s->playerRMove();
                break;
            case LEFT_ARROW:
                s->playerLMove();
                break;
            default:
                break;
            }
        }

        setCursorPosition(0, 0);

        finishT = clock();
        if ((double)(finishT - startT) > 1000) {
            startT = finishT;
            s->addBlock();
            s->blockDown();
        }

        s->showTable();
    }

    _getch();

	return 0;
}