#include <sstream>
#include "MainMenuState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace gui {
	MainMenuState::MainMenuState(GameDataRef data) : data(data) {}

	void MainMenuState::init() {
		this->data->assets.loadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->data->assets.loadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);
		this->data->assets.loadTexture("Game Title", MAIN_MENU_TITLE_PATH);
		this->background.setTexture(this->data->assets.getTexture("Background"));
		this->playButton.setTexture(this->data->assets.getTexture("Play Button"));
		this->title.setTexture(this->data->assets.getTexture("Game Title"));

		//positioning

		this->background.setPosition((SCREEN_WIDTH / 2) - 
				(this->background.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));

		this->playButton.setScale(0.5f, 0.5f);
		this->playButton.setPosition((SCREEN_WIDTH / 2) - 
				(this->playButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (this->playButton.getGlobalBounds().height / 2));

		this->title.setPosition((SCREEN_WIDTH / 2) - 
				(this->title.getGlobalBounds().width / 2), this->title
			.getGlobalBounds().height * 0.01);
	}

	void MainMenuState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			if (this->data->input.isSpriteClicked(this->playButton, sf::Mouse::Left, 
						this->data->window)) {
				this->data->machine.addState(stateRef(new GameState(data)), true);
			}
		}
	}

	void MainMenuState::update(float dt) {

	}

	void MainMenuState::draw(float dt) {
		this->data->window.clear();

		this->data->window.draw(this->background);
		this->data->window.draw(this->playButton);
		this->data->window.draw(this->title);

		this->data->window.display();
	}
}
