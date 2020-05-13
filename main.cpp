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

	std::cout << "How many players for the game? (min 4, max 6)" << std::endl;
	std::cin >> player_count;
	std::cin.clear();
	std::cin.ignore(10000, '\n');

	while (player_count > 6 || player_count < 4) {
		std::cout << "Please input a valid player count. (min 4, max 6)" << std::endl;

		std::cin >> player_count;

		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	
	std::vector<Player> game_players = main_menu.setup(player_count);
	Board difBoard;
	Game game = Game();
	game.setPlayers(game_players);
	game.setBoard(difBoard);
	game.dealAllCards();
	
	game.clearScreen();
	std::cout << "Lets start the game!" << std::endl;

	game.clearScreen();

	bool winner = false;
	while (!winner) {
		game.clearScreen();

		//print UI information (SFML possible here????)

		winner = game.playTurn();
	}

	return 0;
}
