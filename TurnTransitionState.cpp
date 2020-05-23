#include <sstream>
#include "TurnTransitionState.hpp"
#include <iostream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

namespace gui {
	TurnTransitionState::TurnTransitionState(GameDataRef data) : data(data) {}

	void TurnTransitionState::init() {
		this->data->assets.loadTexture("Transition Turn State Background",
			TRANSITION_BACKGROUND_FILEPATH);
		this->data->assets.loadTexture("Ready Button", READY_BUTTON_FILEPATH);

		background.setTexture(this->data->assets.getTexture("Transition Turn State Background"));
		readyButton.setTexture(this->data->assets.getTexture("Ready Button"));

		this->readyButton.setPosition((SCREEN_WIDTH / 2) -
			(this->readyButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2 ) + (this->readyButton.getGlobalBounds().height * 1));
	}

	void TurnTransitionState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}

			//AND IF PASSWORD IN FIELD IS CORRECT??????????????????????????????????????
			if (this->data->input.isSpriteClicked(this->readyButton, sf::Mouse::Left,
				this->data->window)) {
				this->data->machine.removeState();
			}
		}
	}

	void TurnTransitionState::update(float dt) {

	}

	void TurnTransitionState::draw(float dt) {
		this->data->window.clear(sf::Color::Black);
		this->data->window.draw(this->background);
		this->data->window.draw(this->readyButton);
		this->data->window.display();
	}
}
