#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace gui {
	class SplashState : public State {
		public:
			SplashState(GameDataRef data);

			void init();

			void handleInput();
			void update(float dt);
			void draw(float dt);

		private:
			GameDataRef data;

			sf::Clock clock;

			sf::Sprite background;
	};
}
