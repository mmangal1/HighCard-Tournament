#include "Player.h"

Player::Player(std::string name, int budget){
	player_name = name;
	player_budget = budget;
}

std::string Player::getName(){
	return player_name;
}

int Player::getBudget(){
	return player_budget;
}

bool Player::bet(int amount){
	player_budget -= amount;
	return true;
}

void Player::collectWinnings(int amount){
	player_budget += amount;
}
/*
bool Player::operator==(Player obj1, Player obj2){
	if()
}*/
