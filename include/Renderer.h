#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Piece.h"
#define RESOLUTION_HEIGHT 1000
#define RESOLUTION_WIDTH 1000
enum enum_pieces
{
	EMPTY,
	BLACK_ROOK = 'r',
	BLACK_KNIGHT = 'n',
	BLACK_KING = 'k',
	BLACK_QUEEN = 'q',
	BLACK_BISHOP = 'b',
	BLACK_PAWN = 'p',
	WHITE_ROOK = 'R',
	WHITE_KNIGHT = 'N',
	WHITE_KING = 'K',
	WHITE_QUEEN = 'Q',
	WHITE_BISHOP = 'B',
	WHITE_PAWN = 'P'
};

class Renderer
{
private:
	sf::Clock frameTime;
	sf::RenderWindow *window;
	void drawBoard();
	sf::RectangleShape selected;
public:
	Renderer();
	~Renderer();

public:
	sf::Vector2i getMousePostion();
	std::vector<Piece> renderArray;
	void update(enum_pieces board[8][8]);
	bool pollEvents(sf::Event &e);
	void addPiece(Piece piece);
	void select(sf::Vector2i);
};

