#include "Game.h"
#include <iostream>
#include "Renderer.h"

Game::Game(Renderer &renderer)
{
	read_fen("rnbkqnbr/pppppppp/8/8/8/8/PPPPPPPP/RNBKQBNR");
	ai.makeBoard(board);
}

bool Game::play(int x, int y)
{
	if (movePossible(cellSelected, sf::Vector2i(x, y))) {
		ai.move(cellSelected, sf::Vector2i(x, y));
		for(int i = 0; i < 8; i++){
			for( int j = 0; j < 8; j++){
				board[i][j] = ai.board[i][j];
			}
		}
		turn = !turn;
		selected = false;
		return true;
	}
	else {
		cellSelected = sf::Vector2i(x, y);
		selected = false;
		return false;
	}

}

bool Game::select(int x, int y)
{
	bool validSelection = true;
	turn = !turn;
	sf::Vector2i tempSelected = sf::Vector2i(x, y);
	if (selected) 
		return play(x, y);
	selected = true;

	if (turn) {
		switch (board[x][y]) {
		case WHITE_KING:
			break;
		case WHITE_PAWN:
			break;
		case WHITE_ROOK:
			break;
		case WHITE_BISHOP:
			break;
		case WHITE_QUEEN:
			break;
		case WHITE_KNIGHT:
			break;
		default:
			validSelection = false;
			selected = false;
			turn = !turn;
			tempSelected = sf::Vector2i(cellSelected.x, cellSelected.y);
			break;
		}
	}
	else {
		switch (board[x][y]) {
		case BLACK_KING:
			break;
		case BLACK_PAWN:
			break;
		case BLACK_ROOK:
			break;
		case BLACK_BISHOP:
			break;
		case BLACK_QUEEN:
			break;
		case BLACK_KNIGHT:
			break;
		default:
			validSelection = false;
			selected = false;
			tempSelected = sf::Vector2i(cellSelected.x, cellSelected.y);
			turn = !turn;
			break;
		}
	}
	cellSelected = tempSelected;
	return selected;
}

void Game::read_fen(std::string fen)
{
	for (int i = 0; i < 8; i++)for (int j = 0; j < 8; j++)board[i][j] = EMPTY;
	int x = 0;
	int y = 0;
	for (int i = 0; i < fen.length(); i++) {
		if (fen[i] == '/') {
			y++;
			x = 0;
		}
		else if ((int)fen[i] <= 56 && (int)fen[i] > 48) {
			x += (int)fen[i] - 48;
		}
		else {
			board[x][y] = (enum_pieces)fen[i];
			x++;
		}
	}
}

bool Game::movePossible(sf::Vector2i fromHere, sf::Vector2i toHere)
{
	bool playable = false;

	std::printf("\nFrom (%i, %i) to (%i, %i) \n", fromHere.x, fromHere.y, toHere.x, toHere.y);
	std::vector<sf::Vector2i> possibleMoves = ai.getPossibleMoves(fromHere.x, fromHere.y);
	for (int i = 0; i < possibleMoves.size(); i++) {
		std::printf("Possible move (%i, %i)\n", possibleMoves[i].x, possibleMoves[i].y);
		if (possibleMoves[i] == toHere) {
			playable = true;
		}
	}

	return playable;
}
