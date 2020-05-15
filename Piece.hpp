#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Game.hpp"

namespace gui {
	class Piece {
		public:
			Piece(GameDataRef data, std::string name);
			~Piece();
			void drawPieces();
			void movePiece(int);
			void update(float dt);
			sf::Sprite& getPiece();

		private:
			GameDataRef data;
			sf::Sprite piece;
	};
}
