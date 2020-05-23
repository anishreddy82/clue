#include <sstream>
#include "TurnTransitionState.hpp"
#include <iostream>
#include "DEFINITIONS.hpp"
#include "MainMenuState.hpp"

namespace gui {
	TurnTransitionState::TurnTransitionState(GameDataRef data) : data(data) {}

	void TurnTransitionState::init() {
		//pwFieldClicked = false;
		int player_id = this->data->turnNumber % this->data->players.size();

		this->data->assets.loadTexture("Transition Turn State Background",
			TRANSITION_BACKGROUND_FILEPATH);
		this->data->assets.loadTexture("Ready Button", READY_BUTTON_FILEPATH);

		background.setTexture(this->data->assets.getTexture("Transition Turn State Background"));
		readyButton.setTexture(this->data->assets.getTexture("Ready Button"));

		this->readyButton.setPosition((SCREEN_WIDTH / 2) -
			(this->readyButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2 ) + (30 + this->readyButton.getGlobalBounds().height * 1));

		this->data->assets.loadFont("Roll Font", ROLL_FONT_FILEPATH);
		playerNameText.setFont(this->data->assets.getFont("Roll Font"));
		playerNameText.setCharacterSize(60);
		playerNameText.setFillColor(sf::Color::Black);
		this->playerNameText.setString(this->data->players.at(player_id).getName() + "'s Turn");
		this->playerNameText.setPosition(
			((SCREEN_WIDTH / 2) - this->playerNameText.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2 - 30));

		//password input
		this->pwBox = sf::RectangleShape(sf::Vector2f(550.0f, 50.0f));
		this->pwBox.setPosition(
			((SCREEN_WIDTH / 2) - this->pwBox.getGlobalBounds().width / 2),
			((SCREEN_HEIGHT / 2) + 50));
		this->passwordInput.setFont(this->data->assets.getFont("Roll Font"));
		this->passwordInput.setCharacterSize(40);
		this->passwordInput.setFillColor(sf::Color::Black);
		this->passwordInput.setPosition(
			((SCREEN_WIDTH / 2) - this->playerNameText.getGlobalBounds().width + 10),
			(SCREEN_HEIGHT / 2 + 45));
		this->passwordInput.setString("Password Here (if any)");
	}

	void TurnTransitionState::handleInput() {
		int player_id = this->data->turnNumber % this->data->players.size();
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}

			if (this->data->input.isRectClicked(this->pwBox, sf::Mouse::Left,
				this->data->window)) {
				pwFieldClicked = true;
				this->passwordInput.setString("");
			}


			if (sf::Event::TextEntered == event.type && pwFieldClicked) {
				if (event.text.unicode == '\b' && playerPw.getSize() > 0)
					playerPw.erase(playerPw.getSize() - 1, 1);
				else {
					playerPw += event.text.unicode;
				}
				passwordInput.setString(playerPw);
			}

			if (this->data->input.isSpriteClicked(this->readyButton, sf::Mouse::Left,
				this->data->window) && this->data->players.at(player_id).checkPassword(playerPw)) {
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
		this->data->window.draw(this->playerNameText);
		this->data->window.draw(this->pwBox);
		this->data->window.draw(this->passwordInput);
		this->data->window.display();
	}
}
