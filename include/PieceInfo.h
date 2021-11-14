#pragma once
#include <SFML/Graphics.hpp>
#include "Renderer.h"

class PieceInfo
{
public:
	enum_pieces which_piece_are_you;
	sf::Vector2i position;
	int number_of_times_moved;
	bool isWhite;
	bool isDead;

};

