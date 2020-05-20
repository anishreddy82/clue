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
			sf::Sprite setButton;

			sf::RectangleShape nameBox;
			sf::RectangleShape pwBox;

			sf::Font setupFont;
			sf::Text playerCount;
			sf::Text playerLabel;
			sf::Text nameLabel;
			sf::Text nameText;
			sf::Text pwLabel;
			sf::Text pwText;
			sf::String playerName;
			sf::String playerPw;

			int numPlayers;
			int playerId;
			bool countChanged;
			bool playerCountSet;
			bool playerDataSet;
			bool nameFieldClicked;
			bool pwFieldClicked;

			void initButtons();
			void initText();
			char generate_color();
			vector<char> colors;
			vector<int> positions;
	};
}
