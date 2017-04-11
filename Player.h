#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <cstdlib>
#include "Card.h"

class Player{

	private:

	public:
		Player();
		Player(std::string name, int budget);
		std::string getName();
		int getBudget();
		bool bet(int amount);
		void collectWinnings(int amount);
		Card hand;
		std::string player_name;
		int player_budget;
		bool operator == (Player x);
};

#endif
