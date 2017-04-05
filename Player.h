#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <cstdlib>
class Player{

	private:

	public:
		Player(std::string name, int budget);
		std::string getName();
		int getBudget();
		bool bet(int amount);
		void collectWinnings(int amount);
//		Card hand;
		std::string player_name;
		int player_budget;
//		bool operator==(Player obj1, Player obj2);
};

#endif
