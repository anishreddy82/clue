#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "State.hpp"
#include "Game.hpp"

namespace gui {
	class HandOfCardsState : public State {
	public:
		HandOfCardsState(GameDataRef data);

		void init();
		void loadPlayerCards();
		void initWeaponCard(std::string weaponName);
		void initRoomCard(std::string roomName);
		void initColorCard(std::string colorName);

		void handleInput();
		void update(float dt);
		void draw(float dt);
		
	private:
		GameDataRef data;

		sf::Clock clock;

		sf::Sprite background;
		std::vector<sf::Sprite> playerCards;
		sf::Sprite returnButton;
	};
}
