#include <sstream>
#include "GameState.hpp"
#include "PauseState.hpp"
#include "HandOfCardsState.hpp"
#include "TurnTransitionState.hpp"
#include "AccuseState.hpp"
#include "SuggestState.hpp"
#include "NotebookState.hpp"
#include "GameOverState.hpp"
#include "DEFINITIONS.hpp"
#include "Helper.hpp"
#include <iostream>

namespace gui {
	GameState::GameState(GameDataRef data) : data(data) {}

	void GameState::init() {
		colors = { 'r', 'b', 'g', 'y', 'v', 'w' };
		positions = { 1, 2, 3, 4, 5, 6 };

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

		this->data->assets.loadTexture("Candlestick", CSTICK_FILEPATH);
		this->data->assets.loadTexture("Knife", KNIFE_FILEPATH);
		this->data->assets.loadTexture("Pipe", PIPE_FILEPATH);
		this->data->assets.loadTexture("Revolver", GUN_FILEPATH);
		this->data->assets.loadTexture("Rope", ROPE_FILEPATH);
		this->data->assets.loadTexture("Wrench", WRENCH_FILEPATH);

		this->gridSprite.setTexture(this->data->assets.getTexture("Grid Sprite"));
		this->gridSprite.setScale(5.0f, 5.0f);
		this->gridSprite.setPosition((SCREEN_WIDTH / 2) -
				(this->gridSprite.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (this->gridSprite.getGlobalBounds().height / 2));

		this->data->assets.loadFont("Roll Font", ROLL_FONT_FILEPATH);

		initGridPieces();
		initButtons();
		initText();
		initGameDeck();
		initCards();
		this->data->turnNumber = 0;
		initPlayers();
		this->moves = 0;

		gameState = GameStates::eTurnOver;
		dealOutCards();

		//DEBUG
		std::cout << "\nGameState name recall:\n";
		for (int i = 0; i < this->data->players.size(); i++) {
			std::cout << std::endl << this->data->players.at(i).getName() << std::endl;
			for (int j = 0; j < this->data->players.at(i).hand.size(); j++) {
				std::cout << this->data->players.at(i).hand.at(j).getName() << std::endl;
			}
		}
		for (int i = 0; i < murderCards.size(); i++) {
			std::cout << std::endl << murderCards.at(i).getName() << std::endl;
		}

	}

	void GameState::handleInput() {
		sf::Event event;
		int dir, pos;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					this->data->machine.addState(stateRef(new PauseState(data)), false);
				}
				if (event.key.code == sf::Keyboard::Right) {
					if (gameState == GameStates::ePlaying) {
						pos = (this->data->players.at(this->data->turnNumber)
								.getPositionX() 
								+ MOVE_RIGHT);
						if (pos < CELLS_X) {
							if (!validateHorizontalMove(pos, MOVE_RIGHT))
									activePiece->movePiece(MOVE_LEFT);
						}
						else
							std::cout << "You have reached the edge\n";
					}
				}
				if (event.key.code == sf::Keyboard::Left) {
					if (gameState == GameStates::ePlaying) {
						pos = (this->data->players.at(this->data->turnNumber)
								.getPositionX() - 1);
						if (pos >= 0) {
							if(!validateHorizontalMove(pos, MOVE_LEFT))
								activePiece->movePiece(MOVE_RIGHT);
						}
						else
							std::cout << "You have reached the edge\n";
					}
				}
				if (event.key.code == sf::Keyboard::Up) {
					if (gameState == GameStates::ePlaying) {
						pos = (this->data->players.at(this->data->turnNumber)
								.getPositionY() - 1);
						if (pos >= 0) {
							if (!validateVerticalMove(pos, MOVE_UP))
								activePiece->movePiece(MOVE_DOWN);
						}
						else
							std::cout << "You have reached the edge\n";
					}
				}
				if (event.key.code == sf::Keyboard::Down) {
					if (gameState == GameStates::ePlaying) {
						pos = (this->data->players.at(this->data->turnNumber)
								.getPositionY() + 1);
						if (pos < CELLS_Y) {
							if (!validateVerticalMove(pos, MOVE_DOWN))
								activePiece->movePiece(MOVE_UP);
						}
						else
							std::cout << "You have reached the edge\n";
					}
				}
			}
			if (this->data->input.isSpriteClicked(this->rollButton, sf::Mouse::Left,
						this->data->window)) {
				if (gameState == GameStates::eTurnOver) {
					rollDice();
				}
			}
			if (this->data->input.isSpriteClicked(this->suggestButton, sf::Mouse::Left,
						this->data->window)) {
				if (!this->data->players.at(this->data->turnNumber).getHasLost()) {
					if (this->data->players.at(this->data->turnNumber).getLocation() != Locations::eHallway
						&& (this->data->players.at(this->data->turnNumber).getSuggestion() == false)) {
						//DEBUG
						cout << "You may make a suggestion from room: " << 
							Helper::getRoomNameFromNumber(this->data->players.at(this->data->turnNumber)
							.getLocation()) << std::endl;
						this->data->machine.addState(stateRef(new SuggestState(data)), false);
					}
					else
						cout << "You have to enter a room first\n";
				}
			}
			if (this->data->input.isSpriteClicked(this->accuseButton, sf::Mouse::Left,
						this->data->window)) {
				if (!this->data->players.at(this->data->turnNumber).getHasLost()) {
					this->data->machine.addState(stateRef(new AccuseState(data)), false);
				}
				
			}
			if (this->data->input.isSpriteClicked(this->endTurnButton, sf::Mouse::Left,
						this->data->window)) {
				this->data->players.at(this->data->turnNumber).resetSuggestion();
				this->data->turnNumber++;
				//this->data->turnNumber = turn;
				if (this->data->turnNumber >= this->data->players.size()) 
					this->data->turnNumber = 0;
				gameState = GameStates::eTurnOver;
				this->moves = 0;
				this->rollButton.setColor(sf::Color(255, 255, 255));
				newTurn = true;
				this->data->machine.addState(stateRef(new TurnTransitionState(data)), false);
			}
			if (this->data->input.isSpriteClicked(this->myCardsButton, sf::Mouse::Left,
						this->data->window)) {
				this->data->machine.addState(stateRef(new HandOfCardsState(data)), false);
			}
			if (this->data->input.isSpriteClicked(this->notebookButton, sf::Mouse::Left,
						this->data->window)) {
				this->data->machine.addState(stateRef(new NotebookState(data)), false);
			}
		}
	}

	/*
	state checking
	*/
	void GameState::update(float dt) {
		int activePlayers = 0;
		if (gameState == GameStates::eGameOver) {
			this->data->machine.addState(stateRef(new GameOverState(data)), true);
		}
		if (gameState == GameStates::eTurnOver) {
			char next = this->data->players.at(this->data->turnNumber).getColor();
			turnText.setString(this->data->players.at(this->data->turnNumber)
					.getName() + "'s Turn" + 
					"(" + this->data->players.at(this->data->turnNumber)
					.getColor() + ")");
			if (next == 'r')
				activePiece = pieces.at(3);
			else if (next == 'b')
				activePiece = pieces.at(2);
			else if (next == 'g')
				activePiece = pieces.at(1);
			else if (next == 'y')
				activePiece = pieces.at(4);
			else if (next == 'v')
				activePiece = pieces.at(5);
			else
				activePiece = pieces.at(0);
		}

		/*
		create new eGameDoneMoving
		prevents rolling of die
		*/
		if (gameState == GameStates::eNoMoreMoves) {
			//grey out the roll button
			this->rollButton.setColor(sf::Color(102, 102, 102));
		}

		if (gameState == GameStates::ePlaying) {
			this->rollButton.setColor(sf::Color(0, 0, 0));
		}

		if (this->data->players.at(this->data->turnNumber).getHasLost()) {
			this->accuseButton.setColor(sf::Color(102, 102, 102));
			this->suggestButton.setColor(sf::Color(102, 102, 102));
		}
		else {
			this->accuseButton.setColor(sf::Color::White);
			this->suggestButton.setColor(sf::Color::White);
		}

		if (moves && !newTurn) {
			rollText.setString(std::to_string(moves));
		}
		else {
			rollText.setString("<--");
		}
		if (this->data->accusation.size() == 3) {
			int count = 0;
			for (int i = 0; i < this->data->accusation.size(); i++) {
				for (int j = 0; j < murderCards.size(); j++) {
					if (this->data->accusation.at(i) == murderCards.at(i).getName())
						count++;
				}
			}
			if (count != 3) {
				std::cout << this->data->players.at(this->data->turnNumber)
					.getName() << " has lost\n";
				this->data->players.at(this->data->turnNumber).setHasLost();
				this->data->accusation.clear();
			}
			else {
				gameState = GameStates::eGameOver;
			}
		}
		for (int i = 0; i < this->data->players.size(); i++) {
			if (!this->data->players.at(i).getHasLost())
				activePlayers++;
		}
		if (activePlayers == 0)
			gameState = GameStates::eGameOver;
	}

	void GameState::draw(float dt) {
		this->data->window.clear();

		this->data->window.draw(this->gridSprite);
		this->data->window.draw(this->turnText);
		for (int i = 0; i < pieces.size(); i++) {
			pieces.at(i)->drawPieces();
		}
		this->data->window.draw(this->rollText);
		this->data->window.draw(this->rollButton);
		this->data->window.draw(this->suggestButton);
		this->data->window.draw(this->accuseButton);
		this->data->window.draw(this->endTurnButton);
		this->data->window.draw(this->myCardsButton);
		this->data->window.draw(this->notebookButton);

		this->data->window.display();
	}

	void GameState::initGridPieces() {
		pieces.emplace(pieces.begin(), new Piece(data, "White Piece"));
		sf::Vector2u tempSpriteSize = this->data->assets.getTexture("White Piece").getSize();
		pieces.at(0)->getPiece().setPosition(gridSprite.getPosition().x + (
					tempSpriteSize.x * 10) - 32, gridSprite.getPosition().y + (
						tempSpriteSize.y * 7) + 270);

		pieces.emplace_back(new Piece(data, "Green Piece"));
		tempSpriteSize = this->data->assets.getTexture("Green Piece").getSize();
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x + (
					tempSpriteSize.x * 7) - 65, gridSprite.getPosition().y + (
						tempSpriteSize.y * 7) + 270);

		pieces.emplace_back(new Piece(data, "Blue Piece"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x + 8, 
				gridSprite.getPosition().y + (GRID_CELL_SIZE * 9) + 7);

		pieces.emplace_back(new Piece(data, "Red Piece"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x + 
				(GRID_CELL_SIZE * 8) + 8, gridSprite.getPosition().y + 7);

		pieces.emplace_back(new Piece(data, "Brown Piece"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x +
				(GRID_CELL_SIZE * 11) + 8, gridSprite.getPosition().y + 
				(GRID_CELL_SIZE * 3) + 7);

		pieces.emplace_back(new Piece(data, "Purple Piece"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x + 8,
				gridSprite.getPosition().y + (GRID_CELL_SIZE * 2) + 7);

		pieces.emplace_back(new Piece(data, "Candlestick"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x + 8,
				gridSprite.getPosition().y + (GRID_CELL_SIZE) + 7);

		pieces.emplace_back(new Piece(data, "Knife"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x +
				(GRID_CELL_SIZE * 6) + 8, gridSprite.getPosition().y + 7);

		pieces.emplace_back(new Piece(data, "Pipe"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x +
				(GRID_CELL_SIZE * 10) + 8, gridSprite.getPosition().y + 7);

		pieces.emplace_back(new Piece(data, "Revolver"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x +
				(GRID_CELL_SIZE * 11) + 8, gridSprite.getPosition().y +
				(GRID_CELL_SIZE * 6) + 7);

		pieces.emplace_back(new Piece(data, "Rope"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x +
				(GRID_CELL_SIZE * 10) + 8, gridSprite.getPosition().y +
				(GRID_CELL_SIZE * 11) + 7);

		pieces.emplace_back(new Piece(data, "Wrench"));
		pieces.at(pieces.size() - 1)->getPiece().setPosition(gridSprite.getPosition().x +
				(GRID_CELL_SIZE * 5) + 8, gridSprite.getPosition().y +
				(GRID_CELL_SIZE * 11) + 7);
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

	void GameState::initText() {
		this->rollFont = this->data->assets.getFont("Roll Font");
		rollText.setFont(rollFont);
		rollText.setString(std::to_string(moves));
		rollText.setCharacterSize(45);
		rollText.setFillColor(sf::Color::White);
		rollText.setPosition(sf::Vector2f(gridSprite.getPosition().x + (
			rollButton.getGlobalBounds().width) + 
			(GRID_CELL_SIZE / 2), 
			(SCREEN_HEIGHT - rollButton.getGlobalBounds().height)));

		turnText.setFont(rollFont);
		turnText.setCharacterSize(60);
		turnText.setFillColor(sf::Color::White);
		turnText.setPosition(sf::Vector2f(gridSprite.getPosition().x + 
						(GRID_CELL_SIZE * 3), 0));
	}

	void GameState::initGameDeck() {
		//colors begin at index 0
		deck.emplace(deck.begin(), Card("white", 'c'));
		deck.emplace_back(Card("blue", 'c'));
		deck.emplace_back(Card("red", 'c'));
		deck.emplace_back(Card("brown", 'c'));
		deck.emplace_back(Card("green", 'c'));
		deck.emplace_back(Card("purple", 'c'));

		//weapons begin at index 6
		deck.emplace_back(Card("candlestick", 'w'));
		deck.emplace_back(Card("revolver", 'w'));
		deck.emplace_back(Card("rope", 'w'));
		deck.emplace_back(Card("wrench", 'w'));
		deck.emplace_back(Card("lead pipe", 'w'));
		deck.emplace_back(Card("knife", 'w'));

		//rooms begin at index 12
		deck.emplace_back(Card("study", 'r'));
		deck.emplace_back(Card("library", 'r'));
		deck.emplace_back(Card("conservatory", 'r'));
		deck.emplace_back(Card("hall", 'r'));
		deck.emplace_back(Card("kitchen", 'r'));
		deck.emplace_back(Card("ballroom", 'r'));
		deck.emplace_back(Card("lounge", 'r'));
		deck.emplace_back(Card("billiard room", 'r'));
		deck.emplace_back(Card("dining room", 'r'));

	}

	void GameState::initCards() {
		this->data->assets.loadTexture("Study Room Card", STUDY_CARD_FILEPATH);
		this->data->assets.loadTexture("Library Room Card", LIBRARY_CARD_FILEPATH);
		this->data->assets.loadTexture("Conservatory Room Card", CONSERVATORY_CARD_FILEPATH);
		this->data->assets.loadTexture("Hall Room Card", HALL_CARD_FILEPATH);
		this->data->assets.loadTexture("Kitchen Room Card", KITCHEN_CARD_FILEPATH);
		this->data->assets.loadTexture("Ballroom Room Card", BALLROOM_CARD_FILEPATH);
		this->data->assets.loadTexture("Lounge Room Card", LOUNGE_CARD_FILEPATH);
		this->data->assets.loadTexture("Billiard Room Card", BILLARD_CARD_FILEPATH);
		this->data->assets.loadTexture("Dining Room Card", DINING_CARD_FILEPATH);

		this->data->assets.loadTexture("Candlestick Weapon Card", CANDLESTICK_CARD_FILEPATH);
		this->data->assets.loadTexture("Revolver Weapon Card", REVOLVER_CARD_FILEPATH);
		this->data->assets.loadTexture("Rope Weapon Card", ROPE_CARD_FILEPATH);
		this->data->assets.loadTexture("Wrench Weapon Card", WRENCH_CARD_FILEPATH);
		this->data->assets.loadTexture("Lead Pipe Weapon Card", LEADPIPE_CARD_FILEPATH);
		this->data->assets.loadTexture("Knife Weapon Card", KNIFE_CARD_FILEPATH);

		this->data->assets.loadTexture("White Color Card", WHITE_CARD_FILEPATH);
		this->data->assets.loadTexture("Blue Color Card", BLUE_CARD_FILEPATH);
		this->data->assets.loadTexture("Red Color Card", RED_CARD_FILEPATH);
		this->data->assets.loadTexture("Brown Color Card", BROWN_CARD_FILEPATH);
		this->data->assets.loadTexture("Green Color Card", GREEN_CARD_FILEPATH);
		this->data->assets.loadTexture("Purple Color Card", PURPLE_CARD_FILEPATH);

	}

	void GameState::initPlayers() {

		for (int i = 0; i < this->data->players.size(); i++) {
			if (this->data->players.at(i).getColor() == 'r') {
				this->data->turnNumber = i;
				break;
			}
			else
				this->data->turnNumber = rand() % this->data->players.size();
		}
	}

	void GameState::initWinningCards(vector<Card> &v) {
		int idx = (rand() % ((deck.size() - 1) - 12 + 1) + 12);
		v.push_back(deck.at(idx));
		deck.erase(deck.begin() + idx);
		  
		idx = (rand() % (11 - 6 + 1) + 6);
		v.push_back(deck.at(idx));
		deck.erase(deck.begin() + idx);
		    
		idx = rand() % 6;
		v.push_back(deck.at(idx));
		deck.erase(deck.begin() + idx);	
	}

	void GameState::givePlayerCard(vector<Card> &v) {
		int idx = rand() % deck.size();
		v.push_back(deck.at(idx));
		deck.erase(deck.begin() + idx);
	}

	void GameState::dealOutCards() {
		//first deal out the murder cards
		initWinningCards(murderCards);
		int i = 0;
		//deal the rest of the cards to the players hands
		while (static_cast<int>(deck.size() > 0)) {
			//mod the number of players for even distribution
			givePlayerCard(this->data->players.at(i % (this->data->players.size())).hand);
			i++;
		}
	}


	bool GameState::checkSpriteCollision() {
		sf::FloatRect shape1 = activePiece->getPiece().getGlobalBounds();
		for (int i = 0; i < pieces.size(); i++) {
			sf::FloatRect shape2 = pieces.at(i)->getPiece().getGlobalBounds();
			if (activePiece != pieces.at(i)) {
				if (shape1.intersects(shape2))
					return true;
			}
		}
		return false;
	}

	bool GameState::validateHorizontalMove(int pos, int dir) {
		activePiece->movePiece(dir);
		if (this->data->players.at(this->data->turnNumber).getHasLost()) {
			std::cout << "You can't move for the rest of the game\n";
			return false;
		}
		if (checkSpriteCollision()) {
			std::cout << "Collision\n";
			return false;
		}
		else {
			moves--;
			this->data->players.at(this->data->turnNumber).setPositionX(pos);
			this->data->players.at(this->data->turnNumber).setLocation
				(gridArray[this->data->players.at(this->data->turnNumber).
					getPositionY()][this->data->players.at(this->data->turnNumber)
					.getPositionX()]);
			checkForMoves();
		}
		return true;
	}

	bool GameState::validateVerticalMove(int pos, int dir) {
		activePiece->movePiece(dir);
		if (this->data->players.at(this->data->turnNumber).getHasLost()) {
			std::cout << "You can't move for the rest of the game\n";
			return false;
		}
		if (checkSpriteCollision()) {
			std::cout << "Collision\n";
			return false;
		}
		else {
			moves--;
			this->data->players.at(this->data->turnNumber).setPositionY(pos);
			this->data->players.at(this->data->turnNumber).setLocation
				(gridArray[this->data->players.at(this->data->turnNumber).
					getPositionY()][this->data->players.at(this->data->turnNumber)
					.getPositionX()]);
			checkForMoves();
		}
		return true;
	}

	void GameState::rollDice() {
		cout << "The roll button has been clicked\n";
		srand(time(NULL));
		moves = rand() % 3 + 1;
		std::cout << this->data->players.at(this->data->turnNumber).getColor() << " has rolled "
			<< moves << "\n";
		gameState = GameStates::ePlaying;
		newTurn = false;
	}


	void GameState::checkForMoves() {
		if (!moves) {
			gameState = GameStates::eNoMoreMoves;
		}
	}

}
