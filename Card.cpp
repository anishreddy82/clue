#include <iostream>
#include "Card.hpp"


/*
Default Constructor
Creates an invalid Card
*/
Card::Card() {
	name = "null";
	type = 'n';
	murder = false;
}

/*
Overloaded constructor
Used for setup of all cards in the game
Initially, all cards will not be involved in the murder
Params: string name of the card, char type of card
*/
Card::Card(std::string nameIn, char typeIn) {
	name = nameIn;
	type = typeIn;
	murder = false;
}


/*
Mutator function, changes the murder member to true
Used if this card is part of the winning set
(involved in the murder)
return: none
*/
void Card::setMurder() {
	murder = true;
}

/*
Printer function for showing the information of this card
*/
void Card::displayCard() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Type: " << type << std::endl;
	std::cout << "Murder: " << murder << std::endl;
}

/*
Function that checks if this card is part of the winning set
(involved  in the murder)
returns true if involved, false if not
*/
bool Card::isMurder() {
	if (murder == true) {
		return true;
	}
	else {
		return false;
	}
}

/*
Accessor functions for type and name
return: none
*/
char Card::getType() {
	return type;
}
std::string Card::getName() {
	return name;
}
