#include <sstream>
#include "SetupState.hpp"
#include "GameState.hpp"
#include "DEFINITIONS.hpp"

namespace gui {
	SetupState::SetupState(GameDataRef data) : data(data) {}

	void SetupState::init() {
		colors = { 'r', 'b', 'g', 'y', 'v', 'w' };
		positions = { 1, 2, 3, 4, 5, 6 };

		this->data->assets.loadTexture("Setup Background", GRID_SPRITE_FILEPATH);
		this->data->assets.loadTexture("Next Grayed", NEXT_GRAYED_FILEPATH);
		this->data->assets.loadTexture("Next Button", NEXT_ACTIVE_FILEPATH);
		this->data->assets.loadTexture("Increase", INC_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Decrease", DEC_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Confirm", CONFIRM_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Set Players", SET_BUTTON_FILEPATH);

		this->background.setTexture(this->data->assets.getTexture("Setup Background"));
		

		//positioning
		this->background.setScale(5.0f, 5.0f);
		this->background.setPosition((SCREEN_WIDTH / 2) -
				(this->background.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));

		this->data->assets.loadFont("Setup Font", ROLL_FONT_FILEPATH);

		pwBox = nameBox = sf::RectangleShape(sf::Vector2f(550.0f, 50.0f));

		numPlayers = 4;
		playerCountSet = false;
		playerDataSet = false;
		nameFieldClicked = false;
		pwFieldClicked = false;
		playerId = 0;

		initButtons();
		initText();
	}

	void SetupState::handleInput() {
		sf::Event event;
		while (this->data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				this->data->window.close();
			}
			if (this->data->input.isSpriteClicked(this->nextButton, sf::Mouse::Left, 
						this->data->window)) {
				this->data->machine.addState(stateRef(new GameState(data)), true);
			}
			if (this->data->input.isSpriteClicked(this->inc, sf::Mouse::Left,
						this->data->window)) {
				if (numPlayers < 6 && !playerCountSet) {
					numPlayers++;
					countChanged = true;
				}
			}
			if (this->data->input.isSpriteClicked(this->dec, sf::Mouse::Left,
						this->data->window)) {
				if (numPlayers > 4 && !playerCountSet) {
					numPlayers--;
					countChanged = true;
				}
			}
			if (this->data->input.isSpriteClicked(this->setButton, sf::Mouse::Left,
						this->data->window)) {
				playerCountSet = true;
			}
			if (this->data->input.isRectClicked(this->nameBox, sf::Mouse::Left,
						this->data->window)) {
				nameFieldClicked = true;
				pwFieldClicked = false;
			}
			if (this->data->input.isRectClicked(this->pwBox, sf::Mouse::Left,
						this->data->window)) {
				pwFieldClicked = true;
				nameFieldClicked = false;
			}
			if (sf::Event::TextEntered == event.type && nameFieldClicked) {
				if (event.text.unicode == '\b' && playerName.getSize() > 0) {
					playerName.erase(playerName.getSize() - 1, 1);
				}
				else {
					playerName += event.text.unicode;
				}
				nameText.setString(playerName);
			}
			if (sf::Event::TextEntered == event.type && pwFieldClicked) {
				if (event.text.unicode == '\b' && playerPw.getSize() > 0) {
					playerPw.erase(playerPw.getSize() - 1, 1);
				}
				else {
					playerPw += event.text.unicode;
				}
				
				pwText.setString(playerPw);
			}
			if (sf::Event::KeyPressed == event.type) {
				if (sf::Keyboard::Enter == event.key.code) {
					if (nameFieldClicked)
						nameFieldClicked = false;
					if (pwFieldClicked)
						pwFieldClicked = false;
				}
			}
			if (this->data->input.isSpriteClicked(this->confirmButton, sf::Mouse::Left,
						this->data->window)) {
				if (!playerDataSet) {
					Player new_player = Player(playerId);
					new_player.setName(playerName);
					new_player.setColor(generate_color());
					new_player.setStartingPosition();
					new_player.setPassword(playerPw);
					this->data->players.push_back(new_player);
					playerId++;
					if (playerId == numPlayers) {
						playerDataSet = true;
					}
				}

				nameText.setString("");
				playerName.clear();
				pwText.setString("");
				playerPw.clear();

				for (int i = 0; i < this->data->players.size(); i++) {
					std::cout << this->data->players.at(i).getName() << std::endl;
				}
			}
		}
	}

	void SetupState::update(float dt) {
		if (countChanged) {
			playerCount.setString(std::to_string(numPlayers));
			countChanged = false;
		}
	}

	void SetupState::draw(float dt) {
		this->data->window.clear();

		this->data->window.draw(this->playerLabel);
		this->data->window.draw(this->playerCount);
		this->data->window.draw(this->inc);
		this->data->window.draw(this->dec);
		this->data->window.draw(this->setButton);

		if (playerCountSet) {
			if (playerDataSet)
				this->data->window.draw(this->nextButton);
			else
				this->data->window.draw(this->nextGrayed);


			this->data->window.draw(this->nameLabel);
			this->data->window.draw(nameBox);
			this->data->window.draw(nameText);
			this->data->window.draw(pwBox);
			this->data->window.draw(pwText);
			this->data->window.draw(this->pwLabel);
			this->data->window.draw(this->confirmButton);
		}

		this->data->window.display();
	}

	void SetupState::initButtons() {
		this->nextGrayed.setTexture(this->data->assets.getTexture("Next Grayed"));
		this->nextGrayed.setScale(BUTTON_SCALE, BUTTON_SCALE);
		this->nextGrayed.setPosition((SCREEN_WIDTH / 1.2), (SCREEN_HEIGHT / 1.2));

		this->nextButton.setTexture(this->data->assets.getTexture("Next Button"));
		this->nextButton.setScale(BUTTON_SCALE, BUTTON_SCALE);
		this->nextButton.setPosition((SCREEN_WIDTH / 1.2), (SCREEN_HEIGHT / 1.2));

		this->inc.setTexture(this->data->assets.getTexture("Increase"));
		this->inc.setScale(BUTTON_SCALE, BUTTON_SCALE);
		this->inc.setPosition((SCREEN_WIDTH / 1.4), (SCREEN_HEIGHT / 5));

		this->dec.setTexture(this->data->assets.getTexture("Decrease"));
		this->dec.setScale(BUTTON_SCALE, BUTTON_SCALE);
		this->dec.setPosition((SCREEN_WIDTH / 1.7), (SCREEN_HEIGHT / 5));

		this->setButton.setTexture(this->data->assets.getTexture("Set Players"));
		this->setButton.setScale(BUTTON_SCALE, BUTTON_SCALE);
		this->setButton.setPosition((SCREEN_WIDTH / 1.3) + 50, (SCREEN_HEIGHT / 5));

		this->confirmButton.setTexture(this->data->assets.getTexture("Confirm"));
		this->confirmButton.setScale(BUTTON_SCALE, BUTTON_SCALE);
		this->confirmButton.setPosition((SCREEN_WIDTH / 4), (SCREEN_HEIGHT / 1.7));
	}

	void SetupState::initText() {
		this->setupFont = this->data->assets.getFont("Setup Font");

		playerLabel.setFont(setupFont);
		playerLabel.setString("# Players: ");
		playerLabel.setCharacterSize(45);
		playerLabel.setFillColor(sf::Color::White);
		playerLabel.setPosition((SCREEN_WIDTH / 3.5), (SCREEN_HEIGHT / 5)); 

		playerCount.setFont(setupFont);
		playerCount.setString(std::to_string(numPlayers));
		playerCount.setCharacterSize(45);
		playerCount.setFillColor(sf::Color::Red);
		playerCount.setPosition((SCREEN_WIDTH / 2), (SCREEN_HEIGHT / 5));

		nameLabel.setFont(setupFont);
		nameLabel.setString("Name: ");
		nameLabel.setCharacterSize(45);
		nameLabel.setFillColor(sf::Color::White);
		nameLabel.setPosition((SCREEN_WIDTH / 4), (SCREEN_HEIGHT / 2.5));

		nameText.setFont(setupFont);
		nameText.setCharacterSize(45);
		nameText.setFillColor(sf::Color::Black);
		nameText.setPosition((SCREEN_WIDTH / 2.5), (SCREEN_HEIGHT / 2.5));

		nameBox.setPosition((SCREEN_WIDTH / 2.5), (SCREEN_HEIGHT / 2.5));

		pwLabel.setFont(setupFont);
		pwLabel.setString("Password: ");
		pwLabel.setCharacterSize(45);
		pwLabel.setFillColor(sf::Color::White);
		pwLabel.setPosition((SCREEN_WIDTH / 4), (SCREEN_HEIGHT / 2));

		pwText.setFont(setupFont);
		pwText.setCharacterSize(45);
		pwText.setFillColor(sf::Color::Black);
		pwText.setPosition((SCREEN_WIDTH / 2.2) + 20, (SCREEN_HEIGHT / 2));
		
		pwBox.setPosition((SCREEN_WIDTH / 2.2) + 20, (SCREEN_HEIGHT / 2));

	}

	char SetupState::generate_color() {
		srand(time(NULL));
 		int randIndex = rand() % static_cast<int>(colors.size());
		char choice = colors.at(randIndex);
		colors.erase(colors.begin() + randIndex);
		return choice;
	}
}
