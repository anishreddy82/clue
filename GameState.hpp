#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace gui {
	class GameState : public State {
		public:
			GameState(GameDataRef data);
			void init();
			void handleInput();
			void update(float dt);
			void draw(float dt);

		private:
			GameDataRef data;
			sf::Sprite background;
			sf::Sprite rollButton;
			sf::Sprite suggestButton;
			sf::Sprite accuseButton;
			sf::Sprite endTurnButton;
			sf::Sprite myCardsButton;
			sf::Sprite notebookButton;

			int turn;
			int gameState;
	};
}
