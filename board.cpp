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
			boardArray[i][j].name = "";
		}
	}
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			createBoard(i, j);
			/*if (i == 0 && j == 0) {
				boardArray[i][j].name = "   kitchen   ";
			}
			else if (i == 0 && j == 2) {
				boardArray[i][j].name = "  Ball Room  ";
			}
			else if (i == 0 && j == 4) {
				boardArray[i][j].name = "Conservatory ";
			}
			else if (i == 2 && j == 4) {
				boardArray[i][j].name = "Billiard Room";
			}
			else if (i == 3 && j == 0) {
				boardArray[i][j].name = "Dining Room  ";
			}
			else if (i == 3 && j == 2) {
				boardArray[i][j].name = "    Clue     ";
			}
			else if (i == 4 && j == 4) {
				boardArray[i][j].name = "Library      ";
			}
			else if (i == 6 && j == 0) {
				boardArray[i][j].name = "    Lounge   ";
			}
			else if (i == 6 && j == 2) {
				boardArray[i][j].name = "    Hall     ";
			}
			else if (i == 6 && j == 4) {
				boardArray[i][j].name = "    Study    ";
			}
			else {
				boardArray[i][j].name = "    space    ";
			}*/
		}
	}

}

void Board::createBoard(int i, int j) {
	if (i == 0 && j == 0) {
		boardArray[i][j].name = "   kitchen   ";
	}
	else if (i == 0 && j == 2) {
		boardArray[i][j].name = "  Ball Room  ";
	}
	else if (i == 0 && j == 4) {
		boardArray[i][j].name = "Conservatory ";
	}
	else if (i == 2 && j == 4) {
		boardArray[i][j].name = "Billiard Room";
	}
	else if (i == 3 && j == 0) {
		boardArray[i][j].name = "Dining Room  ";
	}
	else if (i == 3 && j == 2) {
		boardArray[i][j].name = "    Clue     ";
	}
	else if (i == 4 && j == 4) {
		boardArray[i][j].name = "Library      ";
	}
	else if (i == 6 && j == 0) {
		boardArray[i][j].name = "    Lounge   ";
	}
	else if (i == 6 && j == 2) {
		boardArray[i][j].name = "    Hall     ";
	}
	else if (i == 6 && j == 4) {
		boardArray[i][j].name = "    Study    ";
	}
	else {
		boardArray[i][j].name = "    space    ";
	}
}

void Board::updateBoard(std::vector<Player> players){
	
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