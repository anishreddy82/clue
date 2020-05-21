#include "Game.hpp"
#include <iostream>
#include <string>
#include <vector>


Game::Game() {
	turn_number = 0;
	//colors begin at index 0
	deck.emplace(deck.begin(), Card("w", 'c'));
	deck.emplace_back(Card("v", 'c'));
	deck.emplace_back(Card("y", 'c'));
	deck.emplace_back(Card("g", 'c'));
	deck.emplace_back(Card("r", 'c'));
	deck.emplace_back(Card("b", 'c'));

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

	name.push_back("w");
	name.push_back("v");
	name.push_back("y");
	name.push_back("g");
	name.push_back("r");
	name.push_back("b");
	weapon.push_back("candlestick");
	weapon.push_back("revolver");
	weapon.push_back("rope");
	weapon.push_back("wrench");
	weapon.push_back("lead pipe");
	weapon.push_back("knife");
	room.push_back("study");
	room.push_back("library");
	room.push_back("conservatory");
	room.push_back("hall");
	room.push_back("kitchen");
	room.push_back("ballroom");
	room.push_back("lounge");
	room.push_back("billiard room");
}

void Game::givePlayerCard(vector<Card>& v) {
	int idx = rand() % deck.size();
	v.push_back(deck.at(idx));
	deck.erase(deck.begin() + idx);
}

void Game::giveBoardCards(vector<Card>& v) {
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
	giveBoardCards(murderCards);

	int i = 0;
	//deal the rest of the cards to the players hands
	while (static_cast<int>(deck.size() > 0)) {
		//mod the number of players for even distribution
		givePlayerCard(players.at(i % (players.size())).hand);
		i++;
	}
}

void Game::movePlayer(std::vector<Player>& players) {
	int choice;
	int move;
	int player_id = turn_number % static_cast<int>(players.size());

	std::cout << "Would you like to make a move?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	std::cin >> choice;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	if (choice == 1) {
		srand(time(NULL));
		int randDie = rand() % 3 + 1;
		std::cout << "You rolled " << randDie << std::endl;
		std::vector<int> playerPosX;
		std::vector<int> playerPosY;
		//for (int i = 0; i < players.size(); i++) {
		//	playerPosX.push_back(players[i].getPositionX());
		//	playerPosY.push_back(players[i].getPositionY());
		//}
		while (randDie > 0) {
			std::cout << "You have " << randDie << " move(s) left" << std::endl;
			std::cout << "Would you like to move up, down, left or right?" << std::endl;
			std::cout << "1. Up" << std::endl;
			std::cout << "2. Down" << std::endl;
			std::cout << "3. Left" << std::endl;
			std::cout << "4. Right" << std::endl;
			std::cin >> move;
			//clear the buffer after cin
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			bool playerThere = false;
			if (move == 1) {
				playerThere = playerInSpot(players[player_id].getPositionX(), players[player_id].getPositionY() - 1);
				if (players[player_id].getPositionY() != 0 && playerThere == false) {
					players[player_id].setPositionY(players[player_id].getPositionY() - 1);
				}
				else {
					std::cout << "Not a valid spot!" << std::endl;
					randDie++;
				}
			}
			else if (move == 2) {
				playerThere = playerInSpot(players[player_id].getPositionX(), players[player_id].getPositionY() + 1);
				if (players[player_id].getPositionY() != 6 && playerThere == false) {
					players[player_id].setPositionY(players[player_id].getPositionY() + 1);
				}
				else {
					std::cout << "Not a valid spot!" << std::endl;
					randDie++;
				}
			}
			else if (move == 3) {
				playerThere = playerInSpot(players[player_id].getPositionX() - 1, players[player_id].getPositionY());
				if (players[player_id].getPositionX() != 0 && playerThere == false) {
					players[player_id].setPositionX(players[player_id].getPositionX() - 1);
				}
				else {
					std::cout << "Not a valid spot!" << std::endl;
					randDie++;
				}
			}
			else if (move == 4) {
				playerThere = playerInSpot(players[player_id].getPositionX() + 1, players[player_id].getPositionY());
				if (players[player_id].getPositionX() != 4 && playerThere == false) {
					players[player_id].setPositionX(players[player_id].getPositionX() + 1);
				}
				else {
					std::cout << "Not a valid spot!" << std::endl;
					randDie++;
				}
			}

			//display board
			gameBoard.dif(players);
			randDie--;
		}
	}
}


/*
Function for performing the main game functions
will call the other class methods to perform specific
game functions for each player
*/
bool Game::playTurn() {
	//grab the current player from the container
	Board* gameBoard = new Board;
	Player* current_player = &players.at(turn_number % static_cast<int>(players.size()));

	//print welcome message for current Player
	greet(current_player->getName(), current_player->getColor());

	//move must be performed before suggestions/accusations
	movePlayer(players);


	std::string roomName1;
	std::string emptyRoomName = "    space    ";
	/*
	TODO: ADD PLAYER UI FOR SUGGESTIONS/ACCUSATIONS
	*/
	bool accusation = false; //setup for accusation
	int menu_choice = false;
	while (menu_choice != 5) {

		menu_choice = displaySubMenu();

		switch (menu_choice) {
		case 1: current_player->showHand();
			break; //show hand
		case 2: current_player->viewNotebook();
			break; //show notebook
		case 3:
			roomName1 = gameBoard->getRoomName(current_player->getPositionY(), current_player->getPositionX());
			if (roomName1.compare(emptyRoomName) == 0)  {
				break;
			}
			else {
				int weapon_menu_choice = 0;
				std::cout << "Pick a murder weapon: " << std::endl;
				std::cout << "1. candlestick" << std::endl;
				std::cout << "2. revolver" << std::endl;
				std::cout << "3. rope" << std::endl;
				std::cout << "4. wrench" << std::endl;
				std::cout << "5. lead pipe" << std::endl;
				std::cout << "6. knife" << std::endl;
				std::cin >> weapon_menu_choice;
				std::string weapon_choice;

				for (int i = 0; i <= weapon.size(); i++) {
					if (i + 1 == weapon_menu_choice) {
						weapon_choice = weapon[i];
					}
				}

				int player_choice = 0;
				std::cout << "Pick a player: " << std::endl;
				for (int i = 0; i < name.size(); i++) {
					std::cout << i + 1 << ". " << name[i] << std::endl;
				}
				std::cin >> player_choice;	
				std::string player_string_choice = name[player_choice - 1];
	
				std::string roomName = gameBoard->getRoomName(current_player->getPositionY(), current_player->getPositionX());
				std::cout << current_player->getName() << " is suggesting " << player_string_choice << " did the murder in " << roomName << " with a " << weapon_choice << std::endl;

				int player_count = players.size();
				int player_current = current_player->getId() - 1;
				bool isWeapon = false;
				bool isName = false;
				bool isRoom = false;
				while (player_count != 0) {
					if (player_current < 0) {
						player_current += players.size();
					}
					for (int i = 0; i < players[player_current].hand.size(); i++) {
						if (weapon_choice == players[player_current].hand[i].getName()) {
							std::cout << players[player_current].getName() << " has the " << weapon_choice << " you suggested" << std::endl;
							isWeapon = true;
						}
					}
					for (int i = 0; i < players[player_current].hand.size(); i++) {
						if (player_string_choice == players[player_current].hand[i].getName()) {
							std::cout << players[player_current].getName() << " has player with color " << player_string_choice << " you suggested" << std::endl;
							isName = true;
						}
					}
					for (int i = 0; i < players[player_current].hand.size(); i++) {
						if (roomName == players[player_current].hand[i].getName()) {
							std::cout << players[player_current].getName() << " has the room with name " << roomName << " you suggested" << std::endl;
							isRoom = true;
						}
					}
					player_count--;
					player_current = player_current - 1;
				}
				if (isWeapon == true && isName == true && isRoom == true) {
					std::cout << "All the cards have been accounted for" << std::endl;
				}
				else if (isWeapon == false && isName == true && isRoom == true) {
					std::cout << "The suggest weapon: " << weapon_choice << " was not found in any of the players cards" << std::endl;
				}
				else if (isWeapon == true && isName == false && isRoom == true) {
					std::cout << "The suggested player: " << player_string_choice << " was not found in any of the players cards" << std::endl;
				}
				else if (isWeapon == true && isName == true && isRoom == false) {
					std::cout << "The suggested room: " << roomName << " was not found in any of the players cards" << std::endl;
				}
				else if (isWeapon == false && isName == false && isRoom == true) {
					std::cout << "The suggested weapon: " << weapon_choice << " and player: " << player_string_choice << " were not found in any of the players cards" << std::endl;
				}
				else if (isWeapon == false && isName == true && isRoom == false) {
					std::cout << "The suggested weapon: " << weapon_choice << " and room: " << roomName << " were not found in any of the players cards" << std::endl;
				}
				else if (isWeapon == true && isName == false && isRoom == false) {
					std::cout << "The suggested player: " << player_string_choice << " and room: " << roomName << " were not found in any of the players cards" << std::endl;
				}
				else {
					std::cout << "None of the suggested cards were found in any of the players hands" << std::endl;
				}
			}
		case 4: accusation = false;
			//check to see if they are in the clue room
			if (current_player->getPositionY() == 3 && current_player->getPositionX() == 2) {
				//call accuse function
				current_player->accuse(murderCards);
				//need to delete that person from the current game here
				//and put them in the losing person database
				break;
			}
			else {
				std::cout << "You are not in the Clue Room, so you can't make an accusation!\n" << std::endl;
				break;
			}
		case 5: break; //quit
		default: std::cout << "Please enter a menu choice from 1-5 only" << std::endl;
		}
	}
	//weapons begin at index 6


	/*
	End Game check
	*/
	//accusation by the player, a success returns true to start endgame
	if (accusation) {
		return true;
	}
	//increase turn number, move on to next player
	turn_number++;
	return false;
}


/*
Clears the command line to provide better UI experience
*/
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

bool Game::playerInSpot(int x, int y) {
	//, vector<Player> players

	for (int i = 0; i < players.size(); i++) {
		if (x == players[i].getPositionX() && y == players[i].getPositionY()) {
			return true;
		}
	}
	return false;
}