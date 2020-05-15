#include <iostream>
#include "Player.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "room.hpp"
#include <array>
#include <string>
#include "board.hpp"
#include "DEFINITIONS.hpp"

int main() {
	Menu main_menu = Menu();
	int player_count;
	//prompt to confirm game setup
	std::cout << "How many players for the game? (min 4, max 6)" << std::endl;
	std::cin >> player_count;
	std::cin.clear();
	std::cin.ignore(10000, '\n'); //skips the newline char on input

	//loop for invalid player count inputs
	while (player_count > 6 || player_count < 4) {
		//prompt to confirm game setup
		std::cout << "Please input a valid player count. (min 4, max 6)" << std::endl;

		std::cin >> player_count;

		std::cin.clear();
		std::cin.ignore(10000, '\n'); //skips the newline char on input
	}
	
	/*
	Begin Game Setup
	*/
	std::vector<Player> game_players = main_menu.setup(player_count);
	//create the board
	Board difBoard;
	//create the Game
	gui::Game game = gui::Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Virtual Clue");
	//add the players
	game.setPlayers(game_players);
	//add the board
	game.setBoard(difBoard);
	//deal cards to the board and player
	game.dealAllCards();
	
	game.clearScreen();
	std::cout << "Lets start the game!" << std::endl;

	game.clearScreen();

	//begin game loop
	bool winner = false;
	while (!winner) {
		//clear the board
		game.clearScreen();

		//print UI information (SFML possible here????)

		//let the player perform the turn
		winner = game.playTurn();
	}

	return 0;
}
