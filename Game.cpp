#include "Game.hpp"
#include <iostream>
#include <string>

#define MAX_DIE_COUNT 3

Game::Game() {
	die = Die(MAX_DIE_COUNT);
	turn_number = 0;
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

void Game::movePlayer(std::vector<Player> &players){
	int player_id = turn_number % static_cast<int>(players.size());
	int choice = promptForMovementMenu();
	if (choice == 1) {
		die.roll();

		std::cout << "You rolled " << die.getCurrentNumber() << std::endl;
		while (die.getCurrentNumber() > 0) {
			int move = playerMovementDirectionMenu(die.getCurrentNumber());
			//clear the buffer after cin
			if (move == 1) {
				if (players[player_id].getPositionY() != 0){
					players[player_id].setPositionY(players[player_id].getPositionY() - 1);

				}
			}
			else if (move == 2) {
				if (players[player_id].getPositionY() != 6) {
					players[player_id].setPositionY(players[player_id].getPositionY() + 1);
				}
			}
			else if (move == 3) {
				if (players[player_id].getPositionX() != 0) {
					players[player_id].setPositionX(players[player_id].getPositionX() - 1);
				}
			}
			else if (move == 4) {
				if (players[player_id].getPositionX() != 4) {
					players[player_id].setPositionX(players[player_id].getPositionX() + 1);
				}
			}
			//display board
			gameBoard.dif(players);
			die.decrement();
		}
	}
}

int Game::promptForMovementMenu() {
	std::cout << "Would you like to roll the die?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	int choice;
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	return choice;
}
int Game::playerMovementDirectionMenu(int movementPointsLeft) {
	std::cout << "You have " << movementPointsLeft << " moves left" << std::endl;
	std::cout << "Would you like to move up, down, left or right?" << std::endl;
	std::cout << "1. Up" << std::endl;
	std::cout << "2. Down" << std::endl;
	std::cout << "3. Left" << std::endl;
	std::cout << "4. Right" << std::endl;
	int direction;
	std::cin >> direction;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	return direction;
}


bool Game::playTurn() {
	Player *current_player = &players.at(turn_number % static_cast<int>(players.size()));
	greet(current_player->getName(), current_player->getColor());
	movePlayer(players); 

	/*
	TODO: ADD PLAYER UI FOR SUGGESTIONS/ACCUSATIONS
	*/
	bool accusation = false;
	int menu_choice = false;
	while (menu_choice != 5) {
		menu_choice = displaySubMenu();

		switch (menu_choice) {
		case 1: current_player->showHand();
			break;
		case 2: current_player->viewNotebook();
			break;
		case 3: break; //suggestion (TODO: implement current_player->suggest(), + IF PLAYER IS IN ROOM AND HAVE NOT ALREADY MADE A SUGGESTION)
		case 4: accusation = false; //TODO: accusation (implement current_player->accuse() IF PLAYER IS IN ROOM AND HAVE NOT ALREADY MADE AN ACCUSATION)
			break; 
		case 5: break; 
		default: std::cout << "Please enter a menu choice from 1-5 only" << std::endl;
		}
	}

	if (accusation) {
		return true;
	}
	turn_number++;
	return false;
}


void Game::clearScreen() {
	for (int i = 0; i < 5; i++) {
		std::cout << std::endl;
	}

}

void Game::greet(std::string current_player_name, char current_player_color) {
	std::cout << "It is currently " << current_player_name << "'s turn." << std::endl;
	std::cout << current_player_name << " is of color (" << current_player_color << ")" << std::endl;
	gameBoard.dif(players);

}
/*
Sub menu for player action options
*/
int Game::displaySubMenu() {
	std::cout << "What action would you like to perform?" << std::endl;
	std::cout << "1. View your hand of chards" << std::endl;
	std::cout << "2. View or use your Notebook" << std::endl;
	std::cout << "3. Make a Suggestion" << std::endl;
	std::cout << "4. Make an Accusation" << std::endl;
	std::cout << "5. End your turn" << std::endl;
	std::cout << "Option: ";
	int choice;
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout << std::endl;
	return choice;
}