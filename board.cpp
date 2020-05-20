#include "board.hpp"
#include "room.hpp"
#include <iostream>
#include <string>

Board::Board() {
	w = 7;
	h = 5;
	//initialize player coords CHANGE THIS FROM HARD CODED
	for (int i = 0; i < 7; i++) {
		std::pair<int, int> player;
		player.first = 0;
		player.second = 0;
		player_coords.push_back(player);
	}
	boardArray = new Room*[w];
	for (int i = 0; i < w; i++) {
		boardArray[i] = new Room[h];
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			boardArray[i][j].name = "    space    ";
		}
	}

	boardArray[0][0].name = "   kitchen   ";
	boardArray[0][2].name = "  Ball Room  ";
	boardArray[0][4].name = "Conservatory ";
	boardArray[2][4].name = "Billiard Room";
	boardArray[3][0].name = "Dining Room  ";
	boardArray[3][2].name = "    Clue     ";
	boardArray[4][4].name = "Library      ";
	boardArray[6][0].name = "    Lounge   ";
	boardArray[6][2].name = "    Hall     ";
	boardArray[6][4].name = "    Study    ";
}


void Board::dif(std::vector<Player> players){
	
	for (int i = 0; i < static_cast<int>(players.size()); i++) {
		player_coords.at(i).first = players.at(i).getPositionY();
		player_coords.at(i).second = players.at(i).getPositionX();
	}

	std::cout << "__________________________________________________________________________________" << std::endl;

	bool match = false;
	//printing the board
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
			match = false;
			//if a player coord matches i and j, add token to the name
			for (int k = 0; k < static_cast<int>(players.size()); k++) {
				if (i == player_coords.at(k).first && j == player_coords.at(k).second) {
					std::cout << boardArray[i][j].name << players[k].getColor() << "|";
					match = true;
				}
			}
			if (!match) {
				std::cout << boardArray[i][j].name << "|";
			}
        }
        std::cout << std::endl;
    }
	std::cout << "__________________________________________________________________________________" << std::endl;
	std::cout << std::endl;
}