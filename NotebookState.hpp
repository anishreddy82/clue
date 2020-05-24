#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

namespace gui {
	class NotebookState : public State {
		public:
			NotebookState(GameDataRef data);
			void init();
			void handleInput();
			void update(float dt);
			void draw(float dt);

		private:
			GameDataRef data;
			sf::Sprite background;
			sf::Sprite returnButton;
			sf::Sprite emptyBox;
			sf::Sprite checkedBox;
			sf::Sprite crossedBox;
			vector<sf::Sprite>* boxes;

			void updateBoxPosition(int);
	};
}
