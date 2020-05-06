#include "board.hpp"
#include "room.hpp"
#include <iostream>
#include <string>


void Board::dif(std::vector<Player> players){
    int w = 7;
    int h = 5;
    boardArray = new Room*[w];
    for(int i = 0; i < w; i++){
        boardArray[i] = new Room[h];
    }
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            boardArray[i][j].name = "";
        }
    }

    boardArray[0][0].name = "   kitchen   ";
    boardArray[0][1].name = "    space    ";
    boardArray[0][2].name = "  Ball Room  ";
    boardArray[0][3].name = "    space    ";
    boardArray[0][4].name = "Conservatory ";
    boardArray[1][0].name = "    space    ";
    boardArray[1][1].name = "    space    ";
    boardArray[1][2].name = "    space    ";
    boardArray[1][3].name = "    space    ";
    boardArray[1][4].name = "    space    ";
    boardArray[2][0].name = "    space    ";
    boardArray[2][1].name = "    space    ";
    boardArray[2][2].name = "    space    ";
    boardArray[2][3].name = "    space    ";
    boardArray[2][4].name = "Billiard Room";
    boardArray[3][0].name = "Dining Room  ";
    boardArray[3][1].name = "    space    ";
    boardArray[3][2].name = "    Clue     ";
    boardArray[3][3].name = "    space    ";
    boardArray[3][4].name = "    space    ";
    boardArray[4][0].name = "    space    ";
    boardArray[4][1].name = "    space    ";
	  boardArray[4][2].name = "    space    ";
    boardArray[4][3].name = "    space    ";
    boardArray[4][4].name = "Library      ";
    boardArray[5][0].name = "    space    ";
    boardArray[5][1].name = "    space    ";
    boardArray[5][2].name = "    space    ";
    boardArray[5][3].name = "    space    ";
    boardArray[5][4].name = "    space    ";
    boardArray[6][0].name = "    Lounge   ";
    boardArray[6][1].name = "    space    ";
    boardArray[6][2].name = "    Hall     ";
    boardArray[6][3].name = "    space    ";
    boardArray[6][4].name = "    Study    ";
	
	for (int i = 0; i < players.size(); i++) {
		boardArray[players[i].getPositionX()][players[i].getPositionY()].name += players[i].getColor();
	}
	std::cout << "__________________________________________________________________________________" << std::endl;

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            std::cout << boardArray[i][j].name << "|";
        }
        std::cout << std::endl;
    }
	std::cout << "__________________________________________________________________________________" << std::endl;
	std::cout << std::endl;
}