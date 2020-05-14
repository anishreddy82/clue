#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Piece.hpp"

namespace gui {
	class GameState : public State {
		public:
			GameState(GameDataRef data);
			void init();
			void handleInput();
			void update(float dt);
			void draw(float dt);

		private:
			void initGridPieces();
			void initButtons();
			void initGameDeck();
			void initPlayers();
			void initWinningCards(vector<Card>&);
			void givePlayerCard(vector<Card>&);
			void dealOutCards();
			char generate_color();
			int generate_randPos();
			GameDataRef data;
			sf::Sprite background;
			sf::Sprite rollButton;
			sf::Sprite suggestButton;
			sf::Sprite accuseButton;
			sf::Sprite endTurnButton;
			sf::Sprite myCardsButton;
			sf::Sprite notebookButton;
			sf::Sprite gridSprite;

			sf::Sprite gridPieces[12][12];
			int gridArray[12][12];

			Piece* activePiece;
			vector<Piece*> pieces;
			vector<Card> deck;
			vector<Card> murderCards;
			vector<Player> players;
			vector<char> colors;
			vector<int> positions;

			int turn;
			int moves;
			int gameState;
	};
}
