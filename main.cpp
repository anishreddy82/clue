#include <iostream>
#include "Player.hpp"

int main() {

	Player newPlayer = Player(1);
	newPlayer.setPassword("123");

	if (newPlayer.checkPassword("123")) {
		std::cout << "success" << std::endl;
		std::cout << newPlayer.getId();
	}

	else {
		std::cout << "fail" << std::endl;
	}
	return 0;
}