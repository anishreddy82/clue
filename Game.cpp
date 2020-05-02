#include "Game.hpp"
#include <iostream>
#include <string>


Game::Game() {
	//colors begin at index 0
	deck.emplace(deck.begin(), Card("white", 'c'));
	deck.emplace_back(Card("blue", 'c'));
	deck.emplace_back(Card("red", 'c'));
	deck.emplace_back(Card("brown", 'c'));
	deck.emplace_back(Card("green", 'c'));
	deck.emplace_back(Card("purple", 'c'));

	//weapons begin at index 6
	deck.emplace_back(Card("candlestick", 'w'));
	deck.emplace_back(Card("revolver", 'w'));
	deck.emplace_back(Card("rope", 'w'));
	deck.emplace_back(Card("wrench", 'w'));
	deck.emplace_back(Card("lead pipe", 'w'));
	deck.emplace_back(Card("knife", 'w'));

	//rooms begin at index 12
	deck.emplace_back(Card("study", 'r'));
	deck.emplace_back(Card("library", 'r'));
	deck.emplace_back(Card("conservatory", 'r'));
	deck.emplace_back(Card("hall", 'r'));
	deck.emplace_back(Card("kitchen", 'r'));
	deck.emplace_back(Card("ballroom", 'r'));
	deck.emplace_back(Card("lounge", 'r'));
	deck.emplace_back(Card("billiard room", 'r'));
}

void Game::givePlayerCard(vector<Card> &v) {
	int idx = rand() % deck.size();
	v.push_back(deck.at(idx));
	deck.erase(deck.begin() + idx);
}

void Game::giveBoardCards(vector<Card> &v) {
	int idx = (rand() % ((deck.size() - 1) - 12 + 1) + 12);
	v.push_back(deck.at(idx));
	deck.erase(deck.begin() + idx);

	idx = (rand() % (11 - 6 + 1) + 6);
	v.push_back(deck.at(idx));
	deck.erase(deck.begin() + idx);

	idx = rand() % 6;
	v.push_back(deck.at(idx));
	deck.erase(deck.begin() + idx);
}

/*
Mutator functions that add the Players and Board to the Game object
Pre: Players in the vector have already been created
	Board has already been created
accepts: players, board
returns: none
*/
void Game::setPlayers(std::vector<Player> setupPlayers) {
	players = setupPlayers;
}
void Game::setBoard(Board createdBoard) {
	gameBoard = createdBoard;
}

/*
Accessor function for returning the players
*/
vector<Player> Game::getPlayers() {
	return players;
}


/*
Function that deals out the deck to both the board (winning cards)
and players hands.
Calls: givePlayerCard(), giveBoardCards()
params: none
returns: none
*/
void Game::dealAllCards() {
	//first deal out the murder cards
	giveBoardCards(gameBoard.murderCards);

	int i = 0;
	//deal the rest of the cards to the players hands
	while (static_cast<int>(deck.size() > 0)) {
		//mod the number of players for even distribution
		givePlayerCard(players.at(i % (players.size())).hand);
		i++;
	}
}

void Game::movePlayer(std::vector<Player> players){
	for(int i = 0; i < players.size(); i++){
		int choice;
		int move;
		std::cout << "Hello " << players[i].getName() << std::endl;
		std::cout << "It is your turn to play" << std::endl;
		std::cout << "Would you like to roll the die?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;
		std::cin >> choice;
		if (choice == 1) {
			srand(time(NULL));
			int randDie = rand() % 3 + 1;
			std::cout << "You rolled " << randDie << std::endl;
			std::cout << "Would you like to move up, down, left or right?" << std::endl;
			std::cout << "1. Up" << std::endl;
			std::cout << "2. Down" << std::endl;
			std::cout << "3. Left" << std::endl;
			std::cout << "4. Right" << std::endl;
			std::cin >> move;
			if (move == 1) {
				players[i].setPositionX(players[i].getPositionX() - randDie);
			}
			else if (move == 2) {
				players[i].setPositionY(players[i].getPositionY() - randDie);
			}
			else if (move == 3) {
				players[i].setPositionY(players[i].getPositionY() + randDie);
			}
			else if (move == 4) {
				players[i].setPositionX(players[i].getPositionX() + randDie);
			}
		}

		gameBoard.dif(players);

	}
}
