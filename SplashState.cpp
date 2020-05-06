#include <sstream>
#include "SplashState.hpp"
#include <iostream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

namespace gui {
	SplashState::SplashState(GameDataRef data) : data(data) {}

	void SplashState::init() {
		this->data->assets.loadTexture("Splash State Background", 
				SPLASH_SCENE_BACKGROUND_FILEPATH);
		background.setTexture(this->data->assets.getTexture("Splash State Background"));
	}

	void SplashState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
		}
	}

	void SplashState::update(float dt) {
		if (this->clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME) {
			//switch to the main menu
			this->data->machine.addState(stateRef(new MainMenuState(data)), true);
		}
	}

	void SplashState::draw(float dt) {
		this->data->window.clear(sf::Color::Black);
		this->data->window.draw(this->background);
		this->data->window.display();
	}
}
