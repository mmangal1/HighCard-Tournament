#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "stdlib.h"
#include <vector>

class Deck{
	private:
		std::vector<Card*> deck;
	public:
		Deck();
		Card draw();
		bool empty();
		void shuffle();

};

#endif

