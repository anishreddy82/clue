#include <iostream>
#include "room.hpp"
#include "Player.hpp"

Room::Room() {
	player1 = new Player;
	weapon = 0;
	name = "";
}
