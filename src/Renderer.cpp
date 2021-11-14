#include "Renderer.h"
#include <iostream>
#include <map>


#define FILE_BLACK_ROOK	"Assets/black_rook.png"
#define FILE_BLACK_BISHOP "Assets/black_bishop.png"
#define FILE_BLACK_QUEEN "Assets/black_queen.png"
#define FILE_BLACK_KING	"Assets/black_king.png"
#define FILE_BLACK_KNIGHT "Assets/black_knight.png"
#define FILE_BLACK_PAWN	"Assets/black_pawn.png"
#define FILE_WHITE_ROOK	"Assets/white_rook.png"
#define FILE_WHITE_BISHOP "Assets/white_bishop.png"
#define FILE_WHITE_QUEEN "Assets/white_queen.png"
#define FILE_WHITE_KING	"Assets/white_king.png"
#define FILE_WHITE_KNIGHT "Assets/white_knight.png"
#define FILE_WHITE_PAWN	"Assets/white_pawn.png"

std::map<enum_pieces, std::string> map{
	{BLACK_KING  , FILE_BLACK_KING},
	{BLACK_QUEEN , FILE_BLACK_QUEEN},
	{BLACK_BISHOP, FILE_BLACK_BISHOP},
	{BLACK_ROOK  , FILE_BLACK_ROOK},
	{BLACK_KNIGHT, FILE_BLACK_KNIGHT},
	{BLACK_PAWN  , FILE_BLACK_PAWN},

	{WHITE_KING  , FILE_WHITE_KING},
	{WHITE_QUEEN , FILE_WHITE_QUEEN},
	{WHITE_BISHOP, FILE_WHITE_BISHOP},
	{WHITE_ROOK  , FILE_WHITE_ROOK},
	{WHITE_KNIGHT, FILE_WHITE_KNIGHT},
	{WHITE_PAWN  , FILE_WHITE_PAWN},
};

void Renderer::drawBoard()
{
	sf::RectangleShape cell;
	for(int i = 0; i < 8; i++)
	for (int j = 0; j < 8; j++) {
		if ((i + j) % 2) {
			cell.setFillColor(sf::Color(183, 192, 216));
		}
		else {
			cell.setFillColor(sf::Color(232, 237, 249));
		}
		cell.setPosition(sf::Vector2f(i*RESOLUTION_WIDTH/8, j*RESOLUTION_HEIGHT/8));
		cell.setSize(sf::Vector2f(RESOLUTION_WIDTH / 8, RESOLUTION_HEIGHT / 8));
		window->draw(cell);
	}
}

Renderer::Renderer()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8.0;
	window = new sf::RenderWindow(sf::VideoMode(RESOLUTION_WIDTH, RESOLUTION_HEIGHT), "Chess", sf::Style::Close, settings);
	window->setVerticalSyncEnabled(true);
}

Renderer::~Renderer()
{
	window->close();
}

void Renderer::update(enum_pieces board[8][8])
{
	window->clear();
	drawBoard();
	window->draw(selected);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] != EMPTY) {
				Piece piece(map[board[i][j]]);
				sf::IntRect textureRect = piece.sprite.getTextureRect();
				piece.sprite.setScale(((float)(RESOLUTION_WIDTH) / 8.0f) / textureRect.width, ((float)(RESOLUTION_HEIGHT) / 8.0f) / textureRect.height);
				piece.sprite.setPosition(sf::Vector2f(i * (float)(RESOLUTION_WIDTH) / 8.0f, j * (float)(RESOLUTION_HEIGHT) / 8.0f));
				window->draw(piece.sprite);
			}

		}
	}
	window->display();
}

bool Renderer::pollEvents(sf::Event& e)
{
	return window->pollEvent(e);
}

sf::Vector2i Renderer::getMousePostion() {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
	sf::Vector2i positionOnGrid = sf::Vector2i((mousePosition.x * 8) / RESOLUTION_WIDTH, (mousePosition.y * 8) / RESOLUTION_WIDTH);
	return positionOnGrid;
}


void Renderer::addPiece(Piece piece)
{
	sf::IntRect textureRect = piece.sprite.getTextureRect();
	piece.sprite.setScale(((float)(RESOLUTION_WIDTH) / 8.0f) / textureRect.width, ((float)(RESOLUTION_HEIGHT) / 8.0f) / textureRect.height);
	renderArray.push_back(piece);
}

void Renderer::select(sf::Vector2i xy)
{
	selected.setFillColor(sf::Color(255, 150, 150));
	selected.setSize(sf::Vector2f(RESOLUTION_WIDTH/8, RESOLUTION_HEIGHT/8));
	selected.setPosition(xy.x * RESOLUTION_WIDTH / 8, xy.y * RESOLUTION_HEIGHT / 8);
}
