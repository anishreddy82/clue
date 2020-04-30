#ifndef GAME_H
#define GAME_H

#include "Card.hpp"
#include "Player.hpp"
#include "board.hpp"
#include <vector>

using std::vector;

class Game {
	private:
		vector<Card> deck;
		vector<Player> players;
		Board gameBoard;
		
	public:
		Game();
		void givePlayerCard(vector<Card> &v);
		void giveBoardCards(vector<Card> &v);
		void dealAllCards();
		void setPlayers(std::vector<Player> setupPlayers);
		void setBoard(Board createdBoard);
		vector<Player> getPlayers();
};

#endif
