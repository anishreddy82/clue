#include <sstream>
#include "PauseState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace gui {
	PauseState::PauseState(GameDataRef data) : data(data) {}

	void PauseState::init() {
		gameState = STATE_PAUSED;
		
		this->data->assets.loadTexture("Background", PAUSE_BACKGROUND_FILEPATH);
		this->background.setTexture(this->data->assets.getTexture("Background"));

		this->background.setScale(2.2f, 2.2f);
		this->background.setPosition((SCREEN_WIDTH / 2) -
				(this->background.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));
	}

	void PauseState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					this->data->machine.removeState();
				}
			}
		}
	}

	void PauseState::update(float dt) {

	}

	void PauseState::draw(float dt) {
		this->data->window.clear();

		this->data->window.draw(this->background);

		this->data->window.display();
	}
}
