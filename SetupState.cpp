#include "SetupState.hpp"
#include "DEFINITIONS.hpp"

namespace gui {
	SetupState::SetupState(GameDataRef data) {}

	void SetupState::init() {
		this->data->assets.loadTexture("Setup Background", GRID_SPRITE_FILEPATH);
		this->data->assets.loadTexture("Next Grayed", NEXT_GRAYED_FILEPATH);
		this->data->assets.loadTexture("Next Button", NEXT_ACTIVE_FILEPATH);
		this->data->assets.loadTexture("Increase", INC_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Decrease", DEC_BUTTON_FILEPATH);
		this->data->assets.loadTexture("Confirm", CONFIRM_BUTTON_FILEPATH);

		this->background.setTexture(this->data->assets.getTexture("Setup Background"));
		this->nextGrayed.setTexture(this->data->assets.getTexture("Next Grayed"));
		this->nextButton.setTexture(this->data->assets.getTexture("Next Button"));
		this->inc.setTexture(this->data->assets.getTexture("Increase"));
		this->dec.setTexture(this->data->assets.getTexture("Decrease"));
		this->confirmButton.setTexture(this->data->assets.getTexture("Confirm"));

		//positioning
		this->background.setScale(5.0f, 5.0f);
		this->background.setPosition((SCREEN_WIDTH / 2) -
				(this->background.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (this->background.getGlobalBounds().height / 2));
	}

	void SetupState::handleInput() {

	}

	void SetupState::update(float dt) {

	}

	void SetupState::draw(float dt) {

	}
}
