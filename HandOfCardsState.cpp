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
			(SCREEN_HEIGHT / 2) - (this->returnButton.getGlobalBounds().height / 2));

	}

	void HandOfCardsState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}

			if (this->data->input.isSpriteClicked(this->returnButton, sf::Mouse::Left,
				this->data->window)) {
				this->data->machine.addState(stateRef(new GameState(data)), true); //replacing this state but want to go back to the old one
			}

		}
	}

	void HandOfCardsState::update(float dt) {

	}

	void HandOfCardsState::draw(float dt) {
		this->data->window.clear(sf::Color::Black);
		this->data->window.draw(this->background);
		this->data->window.draw(this->returnButton);
		this->data->window.display();
	}

	void HandOfCardsState::loadPlayerCards() {

	}
}