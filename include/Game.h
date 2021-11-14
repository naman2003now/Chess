#pragma once
#include <vector>
#include <map>
#include <string>
#include "Smart.h"

class Game
{
private:
	bool turn = 0;
	bool selected = false;
	sf::Vector2i cellSelected;
	void read_fen(std::string);
	bool movePossible(sf::Vector2i fromHere, sf::Vector2i toHere);
	Smart ai;
public:
	enum_pieces board[8][8];
	void kill(int x, int y);
	Game(Renderer& renderer);
	bool play(int x, int y);
	bool select(int x, int y);
};

