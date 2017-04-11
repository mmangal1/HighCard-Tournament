#include "Deck.h"
#include <algorithm>

Deck::Deck(){
	for(int x = 1; x <= 4; x++){
		for(int y = 2; y <= 14; y++){
			Card* card = new Card(x, y);
			deck.push_back(card);
		}
	}
}

Card Deck::draw(){
	Card* temp =  deck.front();
	Card retVal = *temp;
	deck.erase(deck.begin());
	delete temp;
	return retVal;

}

bool Deck::empty(){
	return deck.empty();
}

void Deck::shuffle(){
	std::random_shuffle(deck.begin(), deck.end());
}
