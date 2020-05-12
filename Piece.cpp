#include "Piece.hpp"

namespace gui {
	Piece::Piece(GameDataRef data, std::string name) : data(data) {
		piece.setTexture(data->assets.getTexture(name));
		piece.setPosition((data->window.getSize().x / 4) - (
					piece.getGlobalBounds().width / 2), (data->window.getSize().y / 2) -
				(piece.getGlobalBounds().height / 2));
	}

	void Piece::drawPieces() {
		data->window.draw(piece);
	}

	void Piece::movePiece(int dir) {
		if (dir == 1)
			piece.move(GRID_CELL_SIZE, 0);
		else if (dir == 2)
			piece.move(-GRID_CELL_SIZE, 0);
		else if (dir == 3)
			piece.move(0, -GRID_CELL_SIZE);
		else
			piece.move(0, GRID_CELL_SIZE);
	}

	void Piece::update(float dt) {

	}

	sf::Sprite& Piece::getPiece() {
		return piece;
	}
}
