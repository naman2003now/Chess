#include "Piece.h"

Piece::Piece(std::string file_location)
{
	png.loadFromFile(file_location);
	sprite.setTexture(png);
	sprite.setPosition(0, 0);
}

Piece::~Piece()
{
}
