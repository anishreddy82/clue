#include <iostream>
#include "Player.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "room.hpp"
#include <array>
#include <string>
#include "board.hpp"

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
	
	//begin game setup
	std::vector<Player> game_players = main_menu.setup(player_count);


	/*
	PRINT PLAYER INFO FOR TESTING
	*/
	std::cout << "_______________________________________________________________" << std::endl;
	for (int i = 0; i < player_count; i++) {
		if (game_players.at(i).checkPassword("")) {
			game_players.at(i).printPlayerInfo();
		}
	}

	//create the board
	Board difBoard;
	difBoard.dif(game_players);

	//create the Game
	Game game = Game();
	//add the players
	game.setPlayers(game_players);
	//add the board
	game.setBoard(difBoard);
	//deal cards to the board and player
	game.dealAllCards();
	
	std::cout << "Lets start the game!" << std::endl;

	game.movePlayer(game_players);

	/*
	PRINT PLAYER HAND INFO FOR TESTING
	*/
	game.getPlayers().at(0).showHand();

	/*
	NOTEBOOK MANIPUlATION - TESTING PURPOSES
	*/
	game.getPlayers().at(0).viewNotebook();

	return 0;
}
