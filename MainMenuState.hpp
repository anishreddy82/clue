#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace gui {
	class MainMenuState : public State {
		public:
			MainMenuState(GameDataRef data);
			void init();
			void handleInput();
			void update(float dt);
			void draw(float dt);

		private:
			GameDataRef data;
			sf::Sprite background;
			sf::Sprite playButton;
			sf::Sprite playButtonOuter;
			sf::Sprite title;
	};
}
