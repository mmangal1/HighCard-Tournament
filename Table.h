#ifndef TABLE_H
#define TABLE_H

#include <cstdlib>
#include <vector>
#include "Player.h"
#include "Deck.h"

class Table{
	private:
		int seat_available;
		int bet;	
		std::vector<Player> players;
		Deck deck;
		Player winner;
	public:
		Table(int num_seats, int ante);
		bool emptySeat();
		std::vector<Player> playRound();
		void addPlayer(Player p);
		void printWinner();

};
#endif
