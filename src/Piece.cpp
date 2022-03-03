#include "Piece.h"

Piece::Piece(std::string file_location)
{
	png.loadFromFile(file_location);
	sprite.setTexture(png);
	sprite.setPosition(sf::Vector2f(0, 0));
}

Piece::~Piece()
{
}
