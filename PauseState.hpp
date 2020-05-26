#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace gui {
	class PauseState : public State {
		public:
			PauseState(GameDataRef data);
			void init();
			void handleInput();
			void update(float dt);
			void draw(float dt);

		private:
			GameDataRef data;
			sf::Sprite background;
			int gameState;
	};
}
