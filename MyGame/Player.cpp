#include "Player.h"

Player::Player(int x, int y) {
	this->x = x;
	this->y = y;
}
int Player::getX() {
	return x;
}
int Player::getY() {
	return y;
}
void Player::rightMove() {
	++x;
	if (x >= 48)
		x = 48;
}
void Player::leftMove() {
	--x;
	if (x <= 1)
		x = 1;
}