#include <sstream>
#include "AccuseState.hpp"
#include "GameState.hpp"

namespace gui {
	AccuseState::AccuseState(GameDataRef data) : data(data) {}

	void AccuseState::init() {
		this->data->accusation.clear();
		charSelected = false;
		weaponSelected = false;
		roomSelected = false;

		this->data->assets.loadTexture("Background", CARDS_BACKGROUND_FILEPATH);
		this->data->assets.loadTexture("Return Button", RETURN_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Check Button", CHECK_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Cross Button", CROSS_BUTTON_FILEPATH);

		this->background.setTexture(this->data->assets.getTexture("Background"));
		this->cancelButton.setTexture(this->data->assets.getTexture("Return Button"));

		this->background.setPosition((SCREEN_WIDTH / 2) - 
				(this->background.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));

		this->cancelButton.setScale(0.5f, 0.5f);
		this->cancelButton.setPosition(0, 0);
		/*this->cancelButton.setPosition((SCREEN_WIDTH) - 
				(this->cancelButton.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT) - (this->cancelButton.getGlobalBounds().height));*/

		initPlayerSelect();
	}

	void AccuseState::initPlayerSelect() {
		float offsetX = 6.0;
		float offsetY = 4.5;
		this->redChar.setTexture(this->data->assets.getTexture("Red Color Card"));
		this->redChar.setPosition((SCREEN_WIDTH / offsetX), (SCREEN_HEIGHT / offsetY));

		this->blueChar.setTexture(this->data->assets.getTexture("Blue Color Card"));
		this->blueChar.setPosition(redChar.getPosition().x, redChar.getPosition().y);
		this->blueChar.move(sf::Vector2f(redChar.getGlobalBounds().width * 2, 0));

		this->greenChar.setTexture(this->data->assets.getTexture("Green Color Card"));
		this->greenChar.setPosition(blueChar.getPosition().x, blueChar.getPosition().y);
		this->greenChar.move(sf::Vector2f(blueChar.getGlobalBounds().width * 2, 0));

		this->brownChar.setTexture(this->data->assets.getTexture("Brown Color Card"));
		this->brownChar.setPosition(redChar.getPosition().x, redChar.getPosition().y);
		this->brownChar.move(sf::Vector2f(0, brownChar.getGlobalBounds().height * 1.25));

		this->whiteChar.setTexture(this->data->assets.getTexture("White Color Card"));
		this->whiteChar.setPosition(brownChar.getPosition().x, brownChar.getPosition().y);
		this->whiteChar.move(sf::Vector2f(brownChar.getGlobalBounds().width * 2, 0));

		this->purpleChar.setTexture(this->data->assets.getTexture("Purple Color Card"));
		this->purpleChar.setPosition(whiteChar.getPosition().x, whiteChar.getPosition().y);
		this->purpleChar.move(sf::Vector2f(whiteChar.getGlobalBounds().width * 2, 0));
	}

	void AccuseState::initWeaponSelect() {
		float offsetX = 6.0;
		float offsetY = 4.5;
		this->candlestickCard.setTexture(this->data->assets.getTexture("Candlestick Weapon Card"));
		this->candlestickCard.setPosition((SCREEN_WIDTH / offsetX), (SCREEN_HEIGHT / offsetY));

		this->gunCard.setTexture(this->data->assets.getTexture("Revolver Weapon Card"));
		this->gunCard.setPosition(candlestickCard.getPosition().x, candlestickCard.getPosition().y);
		this->gunCard.move(sf::Vector2f(gunCard.getGlobalBounds().width * 2, 0));

		this->ropeCard.setTexture(this->data->assets.getTexture("Rope Weapon Card"));
		this->ropeCard.setPosition(gunCard.getPosition().x, gunCard.getPosition().y);
		this->ropeCard.move(sf::Vector2f(ropeCard.getGlobalBounds().width * 2, 0));

		this->wrenchCard.setTexture(this->data->assets.getTexture("Wrench Weapon Card"));
		this->wrenchCard.setPosition(candlestickCard.getPosition().x, 
				candlestickCard.getPosition().y);
		this->wrenchCard.move(sf::Vector2f(0, wrenchCard.getGlobalBounds().height * 1.25));

		this->pipeCard.setTexture(this->data->assets.getTexture("Lead Pipe Weapon Card"));
		this->pipeCard.setPosition(wrenchCard.getPosition().x, wrenchCard.getPosition().y);
		this->pipeCard.move(sf::Vector2f(wrenchCard.getGlobalBounds().width * 2, 0));

		this->knifeCard.setTexture(this->data->assets.getTexture("Knife Weapon Card"));
		this->knifeCard.setPosition(pipeCard.getPosition().x, pipeCard.getPosition().y);
		this->knifeCard.move(sf::Vector2f(pipeCard.getGlobalBounds().width * 2, 0));

	}

	void AccuseState::initRoomSelect() {
		float offsetX = 8.5;
		float offsetY = 45.5;
		this->studyCard.setTexture(this->data->assets.getTexture("Study Room Card"));
		this->studyCard.setPosition((SCREEN_WIDTH / offsetX), (SCREEN_HEIGHT / offsetY));

		this->libraryCard.setTexture(this->data->assets.getTexture("Library Room Card"));
		this->libraryCard.setPosition(studyCard.getPosition().x, studyCard.getPosition().y);
		this->libraryCard.move(sf::Vector2f(studyCard.getGlobalBounds().width + 
					(studyCard.getGlobalBounds().width / 2), 0));

		this->conservatoryCard.setTexture(this->data->assets.getTexture("Conservatory Room Card"));
		this->conservatoryCard.setPosition(libraryCard.getPosition().x, libraryCard.getPosition().y);
		this->conservatoryCard.move(sf::Vector2f(libraryCard.getGlobalBounds().width +
					(libraryCard.getGlobalBounds().width / 2), 0));

		this->hallCard.setTexture(this->data->assets.getTexture("Hall Room Card"));
		this->hallCard.setPosition(conservatoryCard.getPosition().x, 
				conservatoryCard.getPosition().y);
		this->hallCard.move(sf::Vector2f(conservatoryCard.getGlobalBounds().width + 
					(conservatoryCard.getGlobalBounds().width / 2), 0));

		this->kitchenCard.setTexture(this->data->assets.getTexture("Kitchen Room Card"));
		this->kitchenCard.setPosition(studyCard.getPosition().x, studyCard.getPosition().y);
		this->kitchenCard.move(sf::Vector2f(0, kitchenCard.getGlobalBounds().height * 1.1));

		this->ballroomCard.setTexture(this->data->assets.getTexture("Ballroom Room Card"));
		this->ballroomCard.setPosition(kitchenCard.getPosition().x, kitchenCard.getPosition().y);
		this->ballroomCard.move(sf::Vector2f(kitchenCard.getGlobalBounds().width + 
					(kitchenCard.getGlobalBounds().width / 2), 0));

		this->loungeCard.setTexture(this->data->assets.getTexture("Lounge Room Card"));
		this->loungeCard.setPosition(ballroomCard.getPosition().x, ballroomCard.getPosition().y);
		this->loungeCard.move(sf::Vector2f(ballroomCard.getGlobalBounds().width + 
				(ballroomCard.getGlobalBounds().width / 2), 0));

		this->billiardCard.setTexture(this->data->assets.getTexture("Billiard Room Card"));
		this->billiardCard.setPosition(loungeCard.getPosition().x, loungeCard.getPosition().y);
		this->billiardCard.move(sf::Vector2f(loungeCard.getGlobalBounds().width + 
					(loungeCard.getGlobalBounds().width / 2), 0));

		this->diningCard.setTexture(this->data->assets.getTexture("Dining Room Card"));
		this->diningCard.setPosition(ballroomCard.getPosition().x, ballroomCard.getPosition().y);
		this->diningCard.move(sf::Vector2f(diningCard.getGlobalBounds().width * 0.75, 
					diningCard.getGlobalBounds().height * 1.1));
	}

	void AccuseState::initConfirmOrCancel() {
		this->checkButton.setTexture(this->data->assets.getTexture("Check Button"));
		this->checkButton.setPosition((SCREEN_WIDTH / 2) -
				(this->checkButton.getGlobalBounds().width * 2),
				(SCREEN_HEIGHT / 2) - (this->checkButton.getGlobalBounds().height));

		this->crossButton.setTexture(this->data->assets.getTexture("Cross Button"));
		this->crossButton.setPosition((SCREEN_WIDTH / 2) + 
				(this->crossButton.getGlobalBounds().width),
				(SCREEN_HEIGHT / 2) - (this->crossButton.getGlobalBounds().height));
	}

	void AccuseState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			if (!charSelected) {
				if (this->data->input.isSpriteClicked(this->redChar, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("red");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->blueChar, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("blue");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->greenChar, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("green");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->brownChar, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("brown");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->whiteChar, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("white");
					charSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->purpleChar, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("purple");
					charSelected = true;
				}
			}
			if (!weaponSelected && charSelected) {
				if (this->data->input.isSpriteClicked(this->candlestickCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("candlestick");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->gunCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("revolver");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->ropeCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("rope");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->wrenchCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("wrench");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->pipeCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("lead pipe");
					weaponSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->knifeCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("knife");
					weaponSelected = true;
				}
			}
			if (!roomSelected && weaponSelected && charSelected) {
				if (this->data->input.isSpriteClicked(this->studyCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("study");
					roomSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->libraryCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("library");
					roomSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->conservatoryCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("conservatory");
					roomSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->hallCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("hall");
					roomSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->kitchenCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("kitchen");
					roomSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->ballroomCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("ballroom");
					roomSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->loungeCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("lounge");
					roomSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->billiardCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("billiard room");
					roomSelected = true;
				}
				if (this->data->input.isSpriteClicked(this->diningCard, sf::Mouse::Left,
							this->data->window)) {
					this->data->accusation.push_back("dining room");
					roomSelected = true;
				}
			}
			if (this->data->input.isSpriteClicked(this->cancelButton, sf::Mouse::Left,
						this->data->window) || (this->data->input.
							isSpriteClicked(this->crossButton, sf::Mouse::Left,
								this->data->window))) {
				this->data->accusation.clear();
				this->data->machine.removeState();
			}
			if (this->data->input.isSpriteClicked(this->checkButton, sf::Mouse::Left,
						this->data->window)) {
				this->data->machine.removeState();
			}
		}
	}

	void AccuseState::update(float dt) {

	}

	void AccuseState::draw(float dt) {
		this->data->window.clear();

		this->data->window.draw(this->background);
		this->data->window.draw(this->cancelButton);

		if (!charSelected) {
			this->data->window.draw(this->redChar);
			this->data->window.draw(this->blueChar);
			this->data->window.draw(this->greenChar);
			this->data->window.draw(this->brownChar);
			this->data->window.draw(this->whiteChar);
			this->data->window.draw(this->purpleChar);
		}
		if (charSelected && !weaponSelected) {
			initWeaponSelect();
			this->data->window.draw(this->candlestickCard);
			this->data->window.draw(this->gunCard);
			this->data->window.draw(this->ropeCard);
			this->data->window.draw(this->wrenchCard);
			this->data->window.draw(this->pipeCard);
			this->data->window.draw(this->knifeCard);
		}
		if (weaponSelected && !roomSelected) {
			initRoomSelect();
			this->data->window.draw(this->studyCard);
			this->data->window.draw(this->libraryCard);
			this->data->window.draw(this->conservatoryCard);
			this->data->window.draw(this->hallCard);
			this->data->window.draw(this->kitchenCard);
			this->data->window.draw(this->ballroomCard);
			this->data->window.draw(this->loungeCard);
			this->data->window.draw(this->billiardCard);
			this->data->window.draw(this->diningCard);
		}
		if (roomSelected) {
			initConfirmOrCancel();
			this->data->window.draw(this->checkButton);
			this->data->window.draw(this->crossButton);
		}

		this->data->window.display();
	}
}
