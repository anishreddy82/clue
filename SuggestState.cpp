#include <sstream>
#include <algorithm>
#include "SuggestState.hpp"
#include "GameState.hpp"
#include "Helper.hpp"

namespace gui {
	SuggestState::SuggestState(GameDataRef data) : data(data) {}

	void SuggestState::init() {
		suggestion.clear();
		charSelected = false;
		weaponSelected = false;
		roomSelected = false;
		player_id = this->data->turnNumber % this->data->players.size();

		this->data->assets.loadTexture("Background", CARDS_BACKGROUND_FILEPATH);
		this->data->assets.loadTexture("Return Button", RETURN_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Check Button", CHECK_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Cross Button", CROSS_BUTTON_FILEPATH);

		this->background.setTexture(this->data->assets.getTexture("Background"));
		this->cancelButton.setTexture(this->data->assets.getTexture("Return Button"));

		this->background.setPosition((SCREEN_WIDTH / 2) -
			(this->background.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));

		this->cancelButton.setScale(0.5f, 0.5f);
		this->cancelButton.setPosition(0, 0);
		/*this->cancelButton.setPosition((SCREEN_WIDTH) -
				(this->cancelButton.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT) - (this->cancelButton.getGlobalBounds().height));*/

		initPlayerSelect();
	}

	void SuggestState::initPlayerSelect() {
		float offsetX = 6.0;
		float offsetY = 4.5;
		this->redChar.setTexture(this->data->assets.getTexture("Red Color Card"));
		this->redChar.setPosition((SCREEN_WIDTH / offsetX), (SCREEN_HEIGHT / offsetY));

		this->blueChar.setTexture(this->data->assets.getTexture("Blue Color Card"));
		this->blueChar.setPosition(redChar.getPosition().x, redChar.getPosition().y);
		this->blueChar.move(sf::Vector2f(redChar.getGlobalBounds().width * 2, 0));

		this->greenChar.setTexture(this->data->assets.getTexture("Green Color Card"));
		this->greenChar.setPosition(blueChar.getPosition().x, blueChar.getPosition().y);
		this->greenChar.move(sf::Vector2f(blueChar.getGlobalBounds().width * 2, 0));

		this->brownChar.setTexture(this->data->assets.getTexture("Brown Color Card"));
		this->brownChar.setPosition(redChar.getPosition().x, redChar.getPosition().y);
		this->brownChar.move(sf::Vector2f(0, brownChar.getGlobalBounds().height * 1.25));

		this->whiteChar.setTexture(this->data->assets.getTexture("White Color Card"));
		this->whiteChar.setPosition(brownChar.getPosition().x, brownChar.getPosition().y);
		this->whiteChar.move(sf::Vector2f(brownChar.getGlobalBounds().width * 2, 0));

		this->purpleChar.setTexture(this->data->assets.getTexture("Purple Color Card"));
		this->purpleChar.setPosition(whiteChar.getPosition().x, whiteChar.getPosition().y);
		this->purpleChar.move(sf::Vector2f(whiteChar.getGlobalBounds().width * 2, 0));
	}

	void SuggestState::initWeaponSelect() {
		float offsetX = 6.0;
		float offsetY = 4.5;
		this->candlestickCard.setTexture(this->data->assets.getTexture("Candlestick Weapon Card"));
		this->candlestickCard.setPosition((SCREEN_WIDTH / offsetX), (SCREEN_HEIGHT / offsetY));

		this->gunCard.setTexture(this->data->assets.getTexture("Revolver Weapon Card"));
		this->gunCard.setPosition(candlestickCard.getPosition().x, candlestickCard.getPosition().y);
		this->gunCard.move(sf::Vector2f(gunCard.getGlobalBounds().width * 2, 0));

		this->ropeCard.setTexture(this->data->assets.getTexture("Rope Weapon Card"));
		this->ropeCard.setPosition(gunCard.getPosition().x, gunCard.getPosition().y);
		this->ropeCard.move(sf::Vector2f(ropeCard.getGlobalBounds().width * 2, 0));

		this->wrenchCard.setTexture(this->data->assets.getTexture("Wrench Weapon Card"));
		this->wrenchCard.setPosition(candlestickCard.getPosition().x,
			candlestickCard.getPosition().y);
		this->wrenchCard.move(sf::Vector2f(0, wrenchCard.getGlobalBounds().height * 1.25));

		this->pipeCard.setTexture(this->data->assets.getTexture("Lead Pipe Weapon Card"));
		this->pipeCard.setPosition(wrenchCard.getPosition().x, wrenchCard.getPosition().y);
		this->pipeCard.move(sf::Vector2f(wrenchCard.getGlobalBounds().width * 2, 0));

		this->knifeCard.setTexture(this->data->assets.getTexture("Knife Weapon Card"));
		this->knifeCard.setPosition(pipeCard.getPosition().x, pipeCard.getPosition().y);
		this->knifeCard.move(sf::Vector2f(pipeCard.getGlobalBounds().width * 2, 0));

	}

	/*
	CHANGE THIS TO ONLY THE ROOM THAT THE PLAYER IS IN
	*/
	void SuggestState::initRoomSelect() {
		float offsetX = 8.5;
		float offsetY = 4.5;
		int location = this->data->players.at(player_id).getLocation();
		
		//Kitchen
		if (location == 1) {
			this->roomCard.setTexture(this->data->assets.getTexture("Kitchen Room Card"));
		}
		//Ball Room
		else if (location == 2) {
			this->roomCard.setTexture(this->data->assets.getTexture("Ballroom Room Card"));

		}
		//Conservatory
		else if (location == 3) {
			this->roomCard.setTexture(this->data->assets.getTexture("Conservatory Room Card"));
		}
		//Billard Room
		else if (location == 4) {
			this->roomCard.setTexture(this->data->assets.getTexture("Billiard Room Card"));
		}
		//Dining Room
		else if (location == 5) {
			this->roomCard.setTexture(this->data->assets.getTexture("Dining Room Card"));
		}
		//Library
		else if (location == 6) {
			this->roomCard.setTexture(this->data->assets.getTexture("Library Room Card"));
		}
		//Hall
		else if (location == 7) {
			this->roomCard.setTexture(this->data->assets.getTexture("Hall Room Card"));

		}
		//Lounge
		else if (location == 8) {
			this->roomCard.setTexture(this->data->assets.getTexture("Lounge Room Card"));
		}
		//Study
		else if (location == 9) {
			this->roomCard.setTexture(this->data->assets.getTexture("Study Room Card"));
		}

		this->roomCard.setPosition(
			((SCREEN_WIDTH / 2) - this->roomCard.getGlobalBounds().width / 2),
			((SCREEN_HEIGHT / 2) - this->roomCard.getGlobalBounds().height / 2));
		
	}

	void SuggestState::initConfirmOrCancel() {
		this->checkButton.setTexture(this->data->assets.getTexture("Check Button"));
		this->checkButton.setPosition((SCREEN_WIDTH / 2) -
			(this->checkButton.getGlobalBounds().width * 2),
			(SCREEN_HEIGHT / 2) - (this->checkButton.getGlobalBounds().height));

		this->crossButton.setTexture(this->data->assets.getTexture("Cross Button"));
		this->crossButton.setPosition((SCREEN_WIDTH / 2) +
			(this->crossButton.getGlobalBounds().width),
			(SCREEN_HEIGHT / 2) - (this->crossButton.getGlobalBounds().height));
	}

	void SuggestState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			if (!charSelected) {
				if (this->data->input.isSpriteClicked(this->redChar, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("red");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->blueChar, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("blue");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->greenChar, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("green");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->brownChar, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("brown");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->whiteChar, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("white");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->purpleChar, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("purple");
					charSelected = true;
				}
			}
			if (!weaponSelected && charSelected) {
				if (this->data->input.isSpriteClicked(this->candlestickCard, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("candlestick");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->gunCard, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("revolver");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->ropeCard, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("rope");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->wrenchCard, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("wrench");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->pipeCard, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("lead pipe");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->knifeCard, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back("knife");
					weaponSelected = true;
				}
			}
			if (!roomSelected && weaponSelected && charSelected) {
				if (this->data->input.isSpriteClicked(this->roomCard, sf::Mouse::Left,
					this->data->window)) {
					suggestion.push_back(Helper::getRoomNameFromNumber(this->data->players.at(player_id).getLocation()));
					roomSelected = true;
				}
			}
			if (this->data->input.isSpriteClicked(this->cancelButton, sf::Mouse::Left,
				this->data->window) || (this->data->input.
					isSpriteClicked(this->crossButton, sf::Mouse::Left,
						this->data->window))) {
				suggestion.clear();
				this->data->machine.removeState();
			}
			if (this->data->input.isSpriteClicked(this->checkButton, sf::Mouse::Left,
				this->data->window)) {
				/*
				Logic for Suggestion HERE <------------------------------------------------------------------------------------------------------------------------------------------------------
				*/
				makeSuggestion();
				this->data->machine.removeState();
			}
		}
	}

	void SuggestState::update(float dt){

	}

	void SuggestState::draw(float dt) {
		this->data->window.clear();

		this->data->window.draw(this->background);
		this->data->window.draw(this->cancelButton);

		if (!charSelected) {
			this->data->window.draw(this->redChar);
			this->data->window.draw(this->blueChar);
			this->data->window.draw(this->greenChar);
			this->data->window.draw(this->brownChar);
			this->data->window.draw(this->whiteChar);
			this->data->window.draw(this->purpleChar);
		}
		if (charSelected && !weaponSelected) {
			initWeaponSelect();
			this->data->window.draw(this->candlestickCard);
			this->data->window.draw(this->gunCard);
			this->data->window.draw(this->ropeCard);
			this->data->window.draw(this->wrenchCard);
			this->data->window.draw(this->pipeCard);
			this->data->window.draw(this->knifeCard);
		}
		if (weaponSelected && !roomSelected) {
			initRoomSelect();
			this->data->window.draw(this->roomCard);
		}
		if (roomSelected) {
			initConfirmOrCancel();
			this->data->window.draw(this->checkButton);
			this->data->window.draw(this->crossButton);
		}

		this->data->window.display();
	}

	void SuggestState::makeSuggestion() {

		std::random_shuffle(suggestion.begin(), suggestion.end());
		while (suggestion.size() > 0) {
			std::string cardName = suggestion.back();
			for (int i = 0; i < this->data->players.size(); i++) {
				if (this->data->players.at(i).holdsCard(cardName)) {
					//if they have it, display, return
					std::cout << this->data->players.at(i).getName() << "has the " << cardName << std::endl;
					return;
				}
			}
			suggestion.pop_back();
		}

		//none of the 3 cards were found if other players, draw/give a crypic message, return
	}
}
