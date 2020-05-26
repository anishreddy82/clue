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
			sf::Sprite boxBorder;
			vector<sf::Sprite>* boxes;
			vector<sf::Text> labels;
			sf::Font labelFont;
			sf::Text labelText;

			void updateBoxPosition(int);
			void initLabels();
			void setLabelPosition(int);
	};
}
