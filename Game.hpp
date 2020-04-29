#ifndef GAME_H
#define GAME_H

#include "Card.hpp"
#include <vector>

using std::vector;

class Game {
	private:
		vector<Card> deck;
	public:
		Game();
		void givePlayerCard(vector<Card> &v);
		void giveBoardCards(vector<Card> &v);
};

#endif
