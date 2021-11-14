#pragma once
#include <SFML/Graphics.hpp>
#include <string>



class Piece
{
private:
	sf::Texture png;
public:
	sf::Sprite sprite;
	Piece(std::string file_location);
	~Piece();
};

