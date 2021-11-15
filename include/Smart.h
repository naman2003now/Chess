#pragma once
#include "Renderer.h"
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include <vector>

class Smart
{
private:
	void pawn_addMoves(std::vector<sf::Vector2i>& moves, sf::Vector2i position, bool isWhite);
	bool black_enpassant[8];
	bool white_enpassant[8];

public:
	enum_pieces board[8][8];
	std::vector<sf::Vector2i> getPossibleMoves(int x, int y);
	void move(sf::Vector2i fromHere, sf::Vector2i toHere);
	void makeBoard(enum_pieces t_board[8][8]);
};