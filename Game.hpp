#ifndef GAME_H
#define GAME_H

#include "Card.hpp"
#include "Player.hpp"
#include "board.hpp"
#include <vector>
#include "Die.hpp"

using std::vector;

class Game {
	private:
		vector<Card> deck;
		vector<Player> players;
		Board gameBoard;
		int turn_number;
		Die die;
		
	public:
		Game();
		void givePlayerCard(vector<Card> &v);
		void giveBoardCards(vector<Card> &v);
		void dealAllCards();
		void setPlayers(std::vector<Player> setupPlayers);
		void setBoard(Board createdBoard);
		void movePlayer(std::vector<Player> &players);
		vector<Player> getPlayers();

		bool playTurn();
		void clearScreen();
		void greet(std::string current_player_name, char current_player_color);
		int displaySubMenu();
		int promptForMovementMenu();
		int playerMovementDirectionMenu(int movementPointsLeft);
};

#endif
