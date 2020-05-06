#ifndef GAME_H
#define GAME_H

#include "Card.hpp"
#include "Player.hpp"
#include "board.hpp"
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include <vector>

using std::vector;

namespace gui {
	struct GameData {
		StateMachine machine;
		sf::RenderWindow window;
		AssetManager assets;
		InputManager input;
	};

	typedef std::shared_ptr<GameData> GameDataRef;

	class Game {
		private:
			vector<Card> deck;
			vector<Player> players;
			Board gameBoard;

			const float dt = 1.0f/ 60.0f;
			sf::Clock clock;
			GameDataRef data = std::make_shared<GameData>();
			void run();
			
		public:
			Game();
			Game(int w, int h, std::string title);
			void givePlayerCard(vector<Card> &v);
			void giveBoardCards(vector<Card> &v);
			void dealAllCards();
			void setPlayers(std::vector<Player> setupPlayers);
			void setBoard(Board createdBoard);
			void movePlayer(std::vector<Player> players);
			vector<Player> getPlayers();
	};
}

#endif
