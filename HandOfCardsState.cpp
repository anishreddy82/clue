#include <sstream>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "HandOfCardsState.hpp"
#include "GameState.hpp"

namespace gui {
	HandOfCardsState::HandOfCardsState(GameDataRef data) : data(data) {}

	void HandOfCardsState::init() {
		this->data->assets.loadTexture("Background", CARDS_BACKGROUND_FILEPATH);
		this->data->assets.loadTexture("Return Button", RETURN_BUTTON_FILEPATH);
		//this->data->assets.loadTexture("Hand of Cards Title", CARDS_TITLE_FILEPATH);
		this->background.setTexture(this->data->assets.getTexture("Background"));
		this->returnButton.setTexture(this->data->assets.getTexture("Return Button"));

		//positioning

		this->background.setPosition((SCREEN_WIDTH / 2) -
			(this->background.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));

		this->returnButton.setScale(0.5f, 0.5f);
		this->returnButton.setPosition((SCREEN_WIDTH / 2) -
			(this->returnButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT) - (this->returnButton.getGlobalBounds().height));

		loadPlayerCards();

		float offset = this->playerCards.at(0).getGlobalBounds().width;
		//set positions of player cards in grid
		for (int i = 0; i < this->playerCards.size(); i++) {
			if (i % 2 == 0) {
				this->playerCards.at(i).setPosition(
					((i * this->playerCards.at(i).getGlobalBounds().width*1.1) + (SCREEN_WIDTH/10)), //X
					(0 + (SCREEN_HEIGHT / 5))); //Y
			}
			else {
				this->playerCards.at(i).setPosition(
					((i * this->playerCards.at(i).getGlobalBounds().width*1.1) + (SCREEN_WIDTH / 10)), //X
					(SCREEN_HEIGHT - (this->playerCards.at(i).getGlobalBounds().height * 1.4))); //Y
			}
			offset *= offset*(i*.1);
			
		}

	}

	void HandOfCardsState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}

			if (this->data->input.isSpriteClicked(this->returnButton, sf::Mouse::Left,
				this->data->window)) {
				this->data->machine.removeState();
			}

			//event for if mouse hovers over a card

		}
	}

	void HandOfCardsState::update(float dt) {

	}

	void HandOfCardsState::draw(float dt) {
		this->data->window.clear(sf::Color::Black);
		this->data->window.draw(this->background);
		this->data->window.draw(this->returnButton);
		for (int i = 0; i < this->playerCards.size(); i++) {
			this->data->window.draw(this->playerCards.at(i));
		}
		this->data->window.display();
	}

	void HandOfCardsState::loadPlayerCards() {
		int player_id = this->data->turnNumber % this->data->players.size();
		for (int i = 0; i < this->data->players.at(player_id).hand.size(); i++) {
			std::string cardName = this->data->players.at(player_id).hand.at(i).getName();

			switch (this->data->players.at(player_id).hand.at(i).getType()) {
			case'r': initRoomCard(cardName);
				break;
			case'w': initWeaponCard(cardName);
				break;
			case'c': initColorCard(cardName);
				break;
			default:
				throw "Unable to load Card type";
			}
		}
	}

	void HandOfCardsState::initRoomCard(std::string roomName) {
		if (roomName == "study") {
			sf::Sprite newRoomCard; 
			newRoomCard.setTexture(this->data->assets.getTexture("Study Room Card"));
			this->playerCards.push_back(newRoomCard);
		}
		else if (roomName == "library") {
			sf::Sprite newRoomCard;
			newRoomCard.setTexture(this->data->assets.getTexture("Library Room Card"));
			this->playerCards.push_back(newRoomCard);
		}
		else if (roomName == "conservatory") {
			sf::Sprite newRoomCard;
			newRoomCard.setTexture(this->data->assets.getTexture("Conservatory Room Card"));
			this->playerCards.push_back(newRoomCard);
		}
		else if (roomName == "hall") {
			sf::Sprite newRoomCard;
			newRoomCard.setTexture(this->data->assets.getTexture("Hall Room Card"));
			this->playerCards.push_back(newRoomCard);
		}
		else if (roomName == "kitchen") {
			sf::Sprite newRoomCard;
			newRoomCard.setTexture(this->data->assets.getTexture("Kitchen Room Card"));
			this->playerCards.push_back(newRoomCard);
		}
		else if (roomName == "ballroom") {
			sf::Sprite newRoomCard;
			newRoomCard.setTexture(this->data->assets.getTexture("Ballroom Room Card"));
			this->playerCards.push_back(newRoomCard);
		}
		else if (roomName == "lounge") {
			sf::Sprite newRoomCard;
			newRoomCard.setTexture(this->data->assets.getTexture("Lounge Room Card"));
			this->playerCards.push_back(newRoomCard);
		}
		else if (roomName == "billiard room") {
			sf::Sprite newRoomCard;
			newRoomCard.setTexture(this->data->assets.getTexture("Billiard Room Card"));
			this->playerCards.push_back(newRoomCard);
		}
	}
	void HandOfCardsState::initWeaponCard(std::string weaponName) {
		if (weaponName == "candlestick") {
			sf::Sprite newWeaponCard;
			newWeaponCard.setTexture(this->data->assets.getTexture("Candlestick Weapon Card"));
			this->playerCards.push_back(newWeaponCard);
		}
		else if (weaponName == "revolver") {
			sf::Sprite newWeaponCard;
			newWeaponCard.setTexture(this->data->assets.getTexture("Revolver Weapon Card"));
			this->playerCards.push_back(newWeaponCard);
		}
		else if (weaponName == "rope") {
			sf::Sprite newWeaponCard;
			newWeaponCard.setTexture(this->data->assets.getTexture("Rope Weapon Card"));
			this->playerCards.push_back(newWeaponCard);
		}
		else if (weaponName == "wrench") {
			sf::Sprite newWeaponCard;
			newWeaponCard.setTexture(this->data->assets.getTexture("Wrench Weapon Card"));
			this->playerCards.push_back(newWeaponCard);
		}
		else if (weaponName == "lead pipe") {
			sf::Sprite newWeaponCard;
			newWeaponCard.setTexture(this->data->assets.getTexture("Lead Pipe Weapon Card"));
			this->playerCards.push_back(newWeaponCard);
		}
		else if (weaponName == "knife") {
			sf::Sprite newWeaponCard;
			newWeaponCard.setTexture(this->data->assets.getTexture("Knife Weapon Card"));
			this->playerCards.push_back(newWeaponCard);
		}
	}
	void HandOfCardsState::initColorCard(std::string colorName) {
		if (colorName == "white") {
			sf::Sprite newColorCard;
			newColorCard.setTexture(this->data->assets.getTexture("White Color Card"));
			this->playerCards.push_back(newColorCard);
		}
		else if (colorName == "blue") {
			sf::Sprite newColorCard;
			newColorCard.setTexture(this->data->assets.getTexture("Blue Color Card"));
			this->playerCards.push_back(newColorCard);
		}
		else if (colorName == "red") {
			sf::Sprite newColorCard;
			newColorCard.setTexture(this->data->assets.getTexture("Red Color Card"));
			this->playerCards.push_back(newColorCard);
		}
		else if (colorName == "brown") {
			sf::Sprite newColorCard;
			newColorCard.setTexture(this->data->assets.getTexture("Brown Color Card"));
			this->playerCards.push_back(newColorCard);
		}
		else if (colorName == "green") {
			sf::Sprite newColorCard;
			newColorCard.setTexture(this->data->assets.getTexture("Green Color Card"));
			this->playerCards.push_back(newColorCard);
		}
		else if (colorName == "purple") {
			sf::Sprite newColorCard;
			newColorCard.setTexture(this->data->assets.getTexture("Purple Color Card"));
			this->playerCards.push_back(newColorCard);
		}
	}
}
