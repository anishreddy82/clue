#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace gui {
	class AccuseState : public State {
		public:
			AccuseState(GameDataRef data);
			void init();
			void handleInput();
			void update(float dt);
			void draw(float dt);

		private:
			GameDataRef data;

			bool charSelected;
			bool weaponSelected;
			bool roomSelected;

			sf::Sprite background;

			sf::Sprite redChar;
			sf::Sprite brownChar;
			sf::Sprite greenChar;
			sf::Sprite purpleChar;
			sf::Sprite blueChar;
			sf::Sprite whiteChar;

			sf::Sprite candlestickCard;
			sf::Sprite gunCard;
			sf::Sprite ropeCard;
			sf::Sprite wrenchCard;
			sf::Sprite pipeCard;
			sf::Sprite knifeCard;

			sf::Sprite studyCard;
			sf::Sprite libraryCard;
			sf::Sprite conservatoryCard;
			sf::Sprite hallCard;
			sf::Sprite kitchenCard;
			sf::Sprite ballroomCard;
			sf::Sprite loungeCard;
			sf::Sprite billiardCard;
			sf::Sprite diningCard;

			sf::Sprite cancelButton;
			sf::Sprite checkButton;
			sf::Sprite crossButton;

			void initPlayerSelect();
			void initWeaponSelect();
			void initRoomSelect();
			void initConfirmOrCancel();

	};
}
