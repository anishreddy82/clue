#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

namespace gui {
	class TurnTransitionState : public State {
	public:
		TurnTransitionState(GameDataRef data);

		void init();

		void handleInput();
		void update(float dt);
		void draw(float dt);

	private:
		GameDataRef data;

		sf::Clock clock;

		sf::Sprite readyButton;
		sf::Sprite background;
		sf::Text playerNameText;
		sf::RectangleShape pwBox;
		sf::Text passwordInput;
		sf::String playerPw;

		bool pwFieldClicked;
	};
}
#pragma once
