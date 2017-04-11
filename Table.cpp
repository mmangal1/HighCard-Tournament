#include "Table.h"
#include <iostream>
using namespace std;
Table::Table(int num_seats, int ante){
	seat_available = num_seats;
	bet = ante;
	winner = Player();
	deck = Deck();
}

bool Table::emptySeat(){
	if(seat_available == 0)
		return false;
	return true;
}

std::vector<Player> Table::playRound(){
	deck = Deck();
	deck.shuffle();
	winner = Player();
	//each player given a card
      	for(int x = 0; x < players.size(); x++){
		players.at(x).hand = deck.draw();
	}
	
	//find highest value card -> hence find winner
	winner = players.at(0);
	for(int x = 1; x < players.size(); x++){
		if(winner.hand.getValue() < players.at(x).hand.getValue()){
			winner = players.at(x);
		}
		else if(winner.hand.getValue() ==  players.at(x).hand.getValue()){
			if(winner.hand.getSuit() < players.at(x).hand.getSuit()){
				winner = players.at(x);
			}
		}
	}

	//remove bet money from losers and add winner money to winner
	//create vector of losers
	std::vector<Player> losers;
	for(int x = 0; x < players.size(); x++){
		if(!(players.at(x)==winner)){
			players.at(x).bet(bet);
			losers.push_back(players.at(x));

			//empty seats now that losers are removed
			seat_available++;
		}
		else{
			players.at(x).collectWinnings(bet);
		}
	}

	//remove players	
	while(players.size() != 0){
		players.erase(players.begin());
	}
	
	//keep winner for next round
	players.push_back(winner);

	return losers;
}

void Table::addPlayer(Player p){
	players.push_back(p);
	seat_available--;
}

void Table::printWinner(){
	cout << "Winner is : " << winner.getName() << endl;
}
