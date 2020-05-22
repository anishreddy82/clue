#include "Piece.hpp"

namespace gui {
	Piece::Piece(GameDataRef data, std::string name) : data(data) , name(name) {
		piece.setTexture(data->assets.getTexture(name));
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

	void Piece::setName(std::string name) {
		this->name = name;
	}

	std::string Piece::getName() {
		return name;
	}

	sf::Sprite& Piece::getPiece() {
		return piece;
	}
}
