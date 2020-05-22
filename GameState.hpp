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
			void initText();
			void initGameDeck();
			void initPlayers();
			void initWinningCards(vector<Card>&);
			void givePlayerCard(vector<Card>&);
			void dealOutCards();
			char generate_color();
			bool checkSpriteCollision();
			void checkForMoves();
			bool validateHorizontalMove(int, int);
			bool validateVerticalMove(int, int);
			void rollDice();
			GameDataRef data;
			sf::Sprite background;
			sf::Sprite rollButton;
			sf::Sprite suggestButton;
			sf::Sprite accuseButton;
			sf::Sprite endTurnButton;
			sf::Sprite myCardsButton;
			sf::Sprite notebookButton;
			sf::Sprite gridSprite;
			sf::Font rollFont;
			sf::Text rollText;
			sf::Text turnText;

			int gridArray[12][12] = { 1, 1, 1, 0, 0, 2, 2, 0, 0, 3, 3, 3,
					          1, 1, 1, 0, 0, 2, 2, 0, 0, 3, 3, 3,
					          0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0,
					          4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					          4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					          0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5,
					          6, 6, 6, 0, 0, 0, 0, 0, 0, 5, 5, 5,
					          6, 6, 6, 0, 0, 0, 0, 0, 0, 5, 5, 5,
					          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					          0, 0, 0, 0, 0, 7, 7, 0, 0, 0, 0, 0,
					          8, 8, 8, 0, 0, 7, 7, 0, 0, 9, 9, 9,
					          8, 8, 8, 0, 0, 7, 7, 0, 0, 9, 9, 9 };

			Piece* activePiece;
			vector<Piece*> pieces;
			vector<Card> deck;
			vector<Card> murderCards;
			//vector<Player> players;
			vector<char> colors;
			vector<int> positions;

			int turn;
			int moves;
			int gameState;
	};
}
