#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace gui {
	class SetupState : public State {
		public:
			SetupState(GameDataRef data);
			void init();
			void handleInput();
			void update(float dt);
			void draw(float dt);

		private:
			GameDataRef data;
			sf::Sprite background;
			sf::Sprite nextGrayed;
			sf::Sprite nextButton;
			sf::Sprite inc;
			sf::Sprite dec;
			sf::Sprite confirmButton;
	};
}
