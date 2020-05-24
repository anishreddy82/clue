#include "NotebookState.hpp"

namespace gui {
	NotebookState::NotebookState(GameDataRef data) : data(data) {}

	void NotebookState::init() {
		boxes = new vector<sf::Sprite>(NOTEBOOK_NUMBOXES);
		boxes = &this->data->players.at(this->data->turnNumber).notes;

		this->data->assets.loadTexture("Background", CARDS_BACKGROUND_FILEPATH);
		this->data->assets.loadTexture("Empty Box", W_PIECE_FILEPATH);
		this->data->assets.loadTexture("Return Button", RETURN_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Check Box", CHECKBOX_FILEPATH);
		this->data->assets.loadTexture("Cross Box", CROSSBOX_FILEPATH);

		this->background.setTexture(this->data->assets.getTexture("Background"));
		this->returnButton.setTexture(this->data->assets.getTexture("Return Button"));
		this->emptyBox.setTexture(this->data->assets.getTexture("Empty Box"));
		this->emptyBox.setScale(0.6f, 0.6f);
		this->checkedBox.setTexture(this->data->assets.getTexture("Check Box"));
		this->crossedBox.setTexture(this->data->assets.getTexture("Cross Box"));

		this->background.setPosition((SCREEN_WIDTH / 2) - 
				(this->background.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));

		this->returnButton.setPosition(SCREEN_WIDTH - this->returnButton.getGlobalBounds().width
				, SCREEN_HEIGHT - this->returnButton.getGlobalBounds().height);

		this->boxes->at(0).setPosition(SCREEN_WIDTH * 0.6, 100);
		this->returnButton.setTexture(this->data->assets.getTexture("Return Button"));
	}

	void NotebookState::handleInput() {
		sf::Event event;
		while(this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			for (int i = 0; i < boxes->size(); i++) {
				if (this->data->input.isSpriteClicked(this->boxes->at(i), sf::Mouse::Left,
							this->data->window)) {
					if (boxes->at(i).getColor() == sf::Color::White) {
						boxes->at(i).setTexture
							(this->data->assets.getTexture("Check Box"));
						boxes->at(i).setColor(sf::Color::Green);
					}
					else if (boxes->at(i).getColor() == sf::Color::Green) {
						boxes->at(i).setTexture
							(this->data->assets.getTexture("Cross Box"));
						boxes->at(i).setColor(sf::Color::Red);
					}
					else {
						boxes->at(i).setTexture
							(this->data->assets.getTexture("Empty Box"));
						boxes->at(i).setColor(sf::Color::White);
					}
				}
			}
			if (this->data->input.isSpriteClicked(this->returnButton, sf::Mouse::Left,
						this->data->window)) {
				this->data->machine.removeState();
			}
		}
	}

	void NotebookState::update(float dt) {

	}

	void NotebookState::draw(float dt) {
		this->data->window.clear();

		this->data->window.draw(background);
		this->data->window.draw(returnButton);
		for (int i = 0; i < NOTEBOOK_NUMBOXES; i++) {
			this->data->window.draw(this->boxes->at(i));
			updateBoxPosition(i);
		}

		this->data->window.display();
	}

	void NotebookState::updateBoxPosition(int idx) {
		if (idx < NOTEBOOK_NUMBOXES - 1) {
			if ((idx + 1) % 6 != 0) {
				boxes->at(idx + 1).setPosition(boxes->at(idx).getPosition().x, 
						boxes->at(idx).getPosition().y);
				boxes->at(idx + 1).move(sf::Vector2f(emptyBox.getGlobalBounds().width + 
						(emptyBox.getGlobalBounds().width / 2), 0));
			}
			else {
				boxes->at(idx + 1).setPosition(boxes->at(idx - 5).getPosition().x,
						boxes->at(idx - 5).getPosition().y);
				boxes->at(idx + 1).move(sf::Vector2f(0, 
							(emptyBox.getGlobalBounds().height * 1.25)));
			}
		}
	}
}
