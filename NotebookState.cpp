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
		this->data->assets.loadTexture("Box Border", BOX_BORDER_FILEPATH);

		this->data->assets.loadFont("Label Font", ROLL_FONT_FILEPATH);

		this->background.setTexture(this->data->assets.getTexture("Background"));
		this->returnButton.setTexture(this->data->assets.getTexture("Return Button"));
		this->emptyBox.setTexture(this->data->assets.getTexture("Empty Box"));
		this->emptyBox.setScale(0.6f, 0.6f);
		this->boxBorder.setTexture(this->data->assets.getTexture("Box Border"));
		this->boxBorder.setScale(0.6f, 0.6f);
		this->checkedBox.setTexture(this->data->assets.getTexture("Check Box"));
		this->crossedBox.setTexture(this->data->assets.getTexture("Cross Box"));

		this->background.setPosition((SCREEN_WIDTH / 2) - 
				(this->background.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));

		this->returnButton.setPosition(SCREEN_WIDTH - this->returnButton.getGlobalBounds().width
				, SCREEN_HEIGHT - this->returnButton.getGlobalBounds().height);

		this->boxes->at(0).setPosition(SCREEN_WIDTH * 0.6, 60);
		this->boxBorder.setPosition(boxes->at(0).getPosition().x, boxes->at(0).getPosition().y);
		this->boxBorder.setColor(sf::Color::Red);
		this->returnButton.setTexture(this->data->assets.getTexture("Return Button"));
		initLabels();
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
			this->data->window.draw(this->boxBorder);
			updateBoxPosition(i);
		}
		for (int i = 0; i < labels.size(); i++) {
			setLabelPosition(i);
			this->data->window.draw(labels.at(i));
		}

		this->data->window.display();
	}

	void NotebookState::updateBoxPosition(int idx) {
		int next = idx + 1;
		int col;
		if (idx < NOTEBOOK_NUMBOXES - 1) {
			if ((next) % 6 != 0) {
				boxes->at(next).setPosition(boxes->at(idx).getPosition().x, 
						boxes->at(idx).getPosition().y);
				boxes->at(next).move(sf::Vector2f(emptyBox.getGlobalBounds().width + 
						(emptyBox.getGlobalBounds().width / 2), 0));
			}
			else {
				boxes->at(next).setPosition(boxes->at(idx - 5).getPosition().x,
						boxes->at(idx - 5).getPosition().y);
				if (next == 36 || next == 72) {
					boxes->at(next).move(sf::Vector2f(0, 
								(emptyBox.getGlobalBounds().height * 2.25)));
				}
				else {
					boxes->at(next).move(sf::Vector2f(0, 
							(emptyBox.getGlobalBounds().height * 1.25)));
				}
			}
			
		}

		boxBorder.setPosition(boxes->at(idx).getPosition().x,
			boxes->at(idx).getPosition().y);

		col = idx % 6;
		switch (col) {
			case 0: boxBorder.setColor(sf::Color::Red);
				break;
			case 1: boxBorder.setColor(sf::Color::White);
				break;
			case 2: boxBorder.setColor(sf::Color::Blue);
				break;
			case 3: boxBorder.setColor(sf::Color::Green);
				break;
			case 4: boxBorder.setColor(sf::Color::Yellow);
				break;
			case 5: boxBorder.setColor(sf::Color::Magenta);
				break;
			default: boxBorder.setColor(sf::Color::White);
				 break;
		};

		if (idx == 119)
			this->data->window.draw(this->boxBorder);
	}

	void NotebookState::setLabelPosition(int idx) {
		int spacing = 20;
		switch(idx) {
			case 0: labels.at(0).setPosition(boxes->at(0).getPosition().x, 
						boxes->at(0).getPosition().y);
				labels.at(0).move(-(labels.at(0).getGlobalBounds().width + spacing), 0);
				break;
			case 1: labels.at(idx).setPosition(boxes->at(6).getPosition().x,
						boxes->at(6).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 2: labels.at(idx).setPosition(boxes->at(12).getPosition().x,
						boxes->at(12).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 3: labels.at(idx).setPosition(boxes->at(18).getPosition().x,
						boxes->at(18).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 4: labels.at(idx).setPosition(boxes->at(24).getPosition().x,
						boxes->at(24).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 5: labels.at(idx).setPosition(boxes->at(30).getPosition().x,
						boxes->at(30).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 6: labels.at(idx).setPosition(boxes->at(36).getPosition().x,
						boxes->at(36).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 7: labels.at(idx).setPosition(boxes->at(42).getPosition().x,
						boxes->at(42).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 8: labels.at(idx).setPosition(boxes->at(48).getPosition().x,
						boxes->at(48).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 9: labels.at(idx).setPosition(boxes->at(54).getPosition().x,
						boxes->at(54).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 10: labels.at(idx).setPosition(boxes->at(60).getPosition().x,
						boxes->at(60).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 11: labels.at(idx).setPosition(boxes->at(66).getPosition().x,
						boxes->at(66).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 12: labels.at(idx).setPosition(boxes->at(72).getPosition().x, 
						boxes->at(72).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 13: labels.at(idx).setPosition(boxes->at(78).getPosition().x,
						boxes->at(78).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 14: labels.at(idx).setPosition(boxes->at(84).getPosition().x,
						boxes->at(84).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 15: labels.at(idx).setPosition(boxes->at(90).getPosition().x,
						boxes->at(90).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 16: labels.at(idx).setPosition(boxes->at(96).getPosition().x,
						boxes->at(96).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 17: labels.at(idx).setPosition(boxes->at(102).getPosition().x,
						boxes->at(102).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 18: labels.at(idx).setPosition(boxes->at(108).getPosition().x,
						boxes->at(108).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 19: labels.at(idx).setPosition(boxes->at(114).getPosition().x,
						boxes->at(114).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
			case 20: labels.at(idx).setPosition(boxes->at(120).getPosition().x,
						boxes->at(120).getPosition().y);
				labels.at(idx).move(-(labels.at(idx).getGlobalBounds().width + spacing), 0);
				break;
		};
	}

	void NotebookState::initLabels() {
		int spacing = 20;
		this->labelFont = this->data->assets.getFont("Label Font");
		labelText.setFont(labelFont);
		labelText.setCharacterSize(20);
		labelText.setFillColor(sf::Color::Black);

		labelText.setString("Miss Scarlet");
		labels.push_back(labelText);

		labelText.setString("Mrs. Peacock");
		labels.push_back(labelText);

		labelText.setString("Reverend Green");
		labels.push_back(labelText);

		labelText.setString("Mrs. White");
		labels.push_back(labelText);

		labelText.setString("Rusty Brown");
		labels.push_back(labelText);

		labelText.setString("Lady Lavender");
		labels.push_back(labelText);

		labelText.setString("Candlestick");
		labels.push_back(labelText);

		labelText.setString("Revolver");
		labels.push_back(labelText);

		labelText.setString("Rope");
		labels.push_back(labelText);

		labelText.setString("Wrench");
		labels.push_back(labelText);

		labelText.setString("Lead Pipe");
		labels.push_back(labelText);

		labelText.setString("Knife");
		labels.push_back(labelText);

		labelText.setString("Study");
		labels.push_back(labelText);

		labelText.setString("Library");
		labels.push_back(labelText);

		labelText.setString("Conservatory");
		labels.push_back(labelText);

		labelText.setString("Hall");
		labels.push_back(labelText);

		labelText.setString("Kitchen");
		labels.push_back(labelText);

		labelText.setString("Ballroom");
		labels.push_back(labelText);

		labelText.setString("Lounge");
		labels.push_back(labelText);

		labelText.setString("Billiard Room");
		labels.push_back(labelText);

	}
}
