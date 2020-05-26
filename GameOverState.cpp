#include <sstream>
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace gui {
	GameOverState::GameOverState(GameDataRef data) : data(data) {}

	void GameOverState::init() {
		/*this->data->assets.loadTexture("Background", PAUSE_BACKGROUND_FILEPATH);
		this->background.setTexture(this->data->assets.getTexture("Background"));

		this->background.setScale(2.2f, 2.2f);
		this->background.setPosition((SCREEN_WIDTH / 2) -
				(this->background.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));*/
		this->data->assets.loadFont("Conclusion Font", ROLL_FONT_FILEPATH);
		this->conclusionFont = this->data->assets.getFont("Conclusion Font");
		this->conclusionText.setFont(conclusionFont);
		this->conclusionText.setCharacterSize(60);
		this->conclusionText.setFillColor(sf::Color::White);
		this->conclusionText.setPosition(sf::Vector2f(0, 0));
		if (this->data->accusation.size() == 3) {
			this->conclusionText.setString(this->data->players.at(this->data->turnNumber)
					.getName() + " has solved the mystery!");
		}
		else {
			this->conclusionText.setString("The killer was not found!");
		}

	}

	void GameOverState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			/*if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					this->data->machine.removeState();
				}
			}*/
		}
	}

	void GameOverState::update(float dt) {

	}

	void GameOverState::draw(float dt) {
		this->data->window.clear();

		//this->data->window.draw(this->background);
		this->data->window.draw(this->conclusionText);

		this->data->window.display();
	}
}
