#include <sstream>
#include "GameState.hpp"
#include "PauseState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace gui {
	GameState::GameState(GameDataRef data) : data(data) {}

	void GameState::init() {
		gameState = STATE_PLAYING;
		
		this->data->assets.loadTexture("Background", GAME_BACKGROUND_FILEPATH);
		this->data->assets.loadTexture("Roll Button", GAME_ROLL_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Suggest Button", GAME_SUGGEST_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Accuse Button", GAME_ACCUSE_BUTTON_FILEPATH);
		this->data->assets.loadTexture("End Turn Button", GAME_END_TURN_BUTTON_FILEPATH);
		this->data->assets.loadTexture("My Cards Button", GAME_MY_CARDS_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Notebook Button", GAME_NOTEBOOK_BUTTON_FILEPATH);

		this->background.setTexture(this->data->assets.getTexture("Background"));
		this->rollButton.setTexture(this->data->assets.getTexture("Roll Button"));
		this->suggestButton.setTexture(this->data->assets.getTexture("Suggest Button"));
		this->accuseButton.setTexture(this->data->assets.getTexture("Accuse Button"));
		this->endTurnButton.setTexture(this->data->assets.getTexture("End Turn Button"));
		this->myCardsButton.setTexture(this->data->assets.getTexture("My Cards Button"));
		this->notebookButton.setTexture(this->data->assets.getTexture("Notebook Button"));

		this->background.setScale(.8f, .8f);
		this->background.setPosition((SCREEN_WIDTH / 2) - 
				(this->background.getGlobalBounds().width / 2), 
				(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));
		this->rollButton.setScale(.20f, .20f);
		this->suggestButton.setScale(.20f, .20f);
		this->accuseButton.setScale(.20f, .20f);
		this->endTurnButton.setScale(.20f, .20f);
		this->myCardsButton.setScale(.20f, .20f);
		this->notebookButton.setScale(.20f, .20f);
	}

	void GameState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					this->data->machine.addState(stateRef(new PauseState(data)), true);
				}
			}
		}
	}

	void GameState::update(float dt) {

	}

	void GameState::draw(float dt) {
		this->data->window.clear();

		this->data->window.draw(this->background);
		this->data->window.draw(this->rollButton);
		this->data->window.draw(this->suggestButton);
		this->data->window.draw(this->accuseButton);
		this->data->window.draw(this->endTurnButton);
		this->data->window.draw(this->myCardsButton);
		this->data->window.draw(this->notebookButton);

		this->data->window.display();
	}
}
