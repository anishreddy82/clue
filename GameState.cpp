#include <sstream>
#include "GameState.hpp"
#include "PauseState.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace gui {
	GameState::GameState(GameDataRef data) : data(data) {}

	void GameState::init() {
		gameState = STATE_PLAYING;
		
		//this->data->assets.loadTexture("Background", GAME_BACKGROUND_FILEPATH);
		this->data->assets.loadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
		this->data->assets.loadTexture("White Piece", W_PIECE_FILEPATH);
		this->data->assets.loadTexture("Blue Piece", B_PIECE_FILEPATH);
		this->data->assets.loadTexture("Red Piece", R_PIECE_FILEPATH);
		this->data->assets.loadTexture("Brown Piece", Br_PIECE_FILEPATH);
		this->data->assets.loadTexture("Green Piece", G_PIECE_FILEPATH);
		this->data->assets.loadTexture("Purple Piece", P_PIECE_FILEPATH);
		this->data->assets.loadTexture("Roll Button", GAME_ROLL_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Suggest Button", GAME_SUGGEST_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Accuse Button", GAME_ACCUSE_BUTTON_FILEPATH);
		this->data->assets.loadTexture("End Turn Button", GAME_END_TURN_BUTTON_FILEPATH);
		this->data->assets.loadTexture("My Cards Button", GAME_MY_CARDS_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Notebook Button", GAME_NOTEBOOK_BUTTON_FILEPATH);

		//this->background.setTexture(this->data->assets.getTexture("Background"));
		this->gridSprite.setTexture(this->data->assets.getTexture("Grid Sprite"));

		//this->background.setScale(.8f, .8f);
		/*this->background.setPosition((SCREEN_WIDTH / 2) - 
				(this->background.getGlobalBounds().width / 2), 
				(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));*/
		this->gridSprite.setScale(5.0f, 5.0f);
		this->gridSprite.setPosition((SCREEN_WIDTH / 2) -
				(this->gridSprite.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (this->gridSprite.getGlobalBounds().height / 2));

		initGridPieces();
		initButtons();
	}

	void GameState::handleInput() {
		sf::Event event;
		int dir;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					this->data->machine.addState(stateRef(new PauseState(data)), false);
				}
				if (event.key.code == sf::Keyboard::Right) {
					piece->movePiece(1);
				}
				if (event.key.code == sf::Keyboard::Left) {
					piece->movePiece(2);
				}
				if (event.key.code == sf::Keyboard::Up) {
					piece->movePiece(3);
				}
				if (event.key.code == sf::Keyboard::Down) {
					piece->movePiece(4);
				}
			}
			if (this->data->input.isSpriteClicked(this->rollButton, sf::Mouse::Left,
						this->data->window)) {
				cout << "The roll button has been clicked\n";
			}
			if (this->data->input.isSpriteClicked(this->suggestButton, sf::Mouse::Left,
						this->data->window)) {
				cout << "The suggest button has been clicked\n";
			}
			if (this->data->input.isSpriteClicked(this->accuseButton, sf::Mouse::Left,
						this->data->window)) {
				cout << "The accuse button has been clicked\n";
			}
			if (this->data->input.isSpriteClicked(this->endTurnButton, sf::Mouse::Left,
						this->data->window)) {
				cout << "The end turn button has been clicked\n";
			}
			if (this->data->input.isSpriteClicked(this->myCardsButton, sf::Mouse::Left,
						this->data->window)) {
				cout << "The my cards button has been clicked\n";
			}
			if (this->data->input.isSpriteClicked(this->notebookButton, sf::Mouse::Left,
						this->data->window)) {
				cout << "The notebook button has been clicked\n";
			}
		}
	}

	void GameState::update(float dt) {

	}

	void GameState::draw(float dt) {
		this->data->window.clear();

		//this->data->window.draw(this->background);
		this->data->window.draw(this->gridSprite);
		this->data->window.draw(this->gridPieces[11][7]);
		this->data->window.draw(this->gridPieces[11][4]);
		piece->drawPieces();
		this->data->window.draw(this->rollButton);
		this->data->window.draw(this->suggestButton);
		this->data->window.draw(this->accuseButton);
		this->data->window.draw(this->endTurnButton);
		this->data->window.draw(this->myCardsButton);
		this->data->window.draw(this->notebookButton);

		this->data->window.display();
	}

	void GameState::initGridPieces() {
		sf::Vector2u tempSpriteSize = this->data->assets.getTexture("White Piece").getSize();
		gridPieces[11][7].setTexture(this->data->assets.getTexture("White Piece"));
		gridPieces[11][7].setPosition(gridSprite.getPosition().x + (
					tempSpriteSize.x * 10) - 32, gridSprite.getPosition().y + (
						tempSpriteSize.y * 7) + 270);

		piece = new Piece(data, "Green Piece");
		tempSpriteSize = this->data->assets.getTexture("Green Piece").getSize();
		piece->getPiece().setPosition(gridSprite.getPosition().x + (
					tempSpriteSize.x * 7) - 65, gridSprite.getPosition().y + (
						tempSpriteSize.y * 7) + 270);


		//position remaining game pieces
	}

	void GameState::initButtons() {
		sf::Vector2u tempButtonSize = this->data->assets.getTexture("Roll Button").getSize();
		this->rollButton.setTexture(this->data->assets.getTexture("Roll Button"));
		this->rollButton.setScale(.08f, .08f);
		this->rollButton.move(sf::Vector2f(gridSprite.getPosition().x, 
					(SCREEN_HEIGHT - rollButton.getGlobalBounds().height)));

		tempButtonSize = this->data->assets.getTexture("Suggest Button").getSize();
		this->suggestButton.setTexture(this->data->assets.getTexture("Suggest Button"));
		this->suggestButton.setScale(.08f, .08f);
		this->suggestButton.move(sf::Vector2f((gridSprite.getPosition().x + (
							suggestButton.getGlobalBounds().width) * 2), 
					(SCREEN_HEIGHT - suggestButton.getGlobalBounds().height)));

		tempButtonSize = this->data->assets.getTexture("Accuse Button").getSize();
		this->accuseButton.setTexture(this->data->assets.getTexture("Accuse Button"));
		this->accuseButton.setScale(.08f, .08f);
		this->accuseButton.move(sf::Vector2f((gridSprite.getPosition().x + (
							accuseButton.getGlobalBounds().width) * 3), 
					(SCREEN_HEIGHT - accuseButton.getGlobalBounds().height)));

		tempButtonSize = this->data->assets.getTexture("End Turn Button").getSize();
		this->endTurnButton.setTexture(this->data->assets.getTexture("End Turn Button"));
		this->endTurnButton.setScale(.08f, .08f);
		this->endTurnButton.move(sf::Vector2f((gridSprite.getPosition().x + (
							endTurnButton.getGlobalBounds().width) * 4), 
					(SCREEN_HEIGHT - endTurnButton.getGlobalBounds().height)));

		tempButtonSize = this->data->assets.getTexture("My Cards Button").getSize();
		this->myCardsButton.setTexture(this->data->assets.getTexture("My Cards Button"));
		this->myCardsButton.setScale(.08f, .08f);
		this->myCardsButton.move(sf::Vector2f((gridSprite.getPosition().x + (
							myCardsButton.getGlobalBounds().width) * 5), 
					(SCREEN_HEIGHT - myCardsButton.getGlobalBounds().height)));

		tempButtonSize = this->data->assets.getTexture("Notebook Button").getSize();
		this->notebookButton.setTexture(this->data->assets.getTexture("Notebook Button"));
		this->notebookButton.setScale(.08f, .08f);
		this->notebookButton.move(sf::Vector2f((gridSprite.getPosition().x + (
							notebookButton.getGlobalBounds().width) * 6), 
					(SCREEN_HEIGHT - notebookButton.getGlobalBounds().height)));
	}

}
