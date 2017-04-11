#include "Player.h"

Player::Player():hand(){}
Player::Player(std::string name, int budget):hand(){
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

bool Player::operator==(Player x){
	if((this->player_name == x.player_name) && (this->player_budget == x.player_budget))
		return true;
	return false;
}
