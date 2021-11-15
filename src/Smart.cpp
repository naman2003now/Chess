#include "Smart.h"
#include <iostream>

std::vector<sf::Vector2i> Smart::getPossibleMoves(int x, int y)
{
	std::vector<sf::Vector2i> possibleMoves;
	switch (board[x][y]) {
	case EMPTY:
		break;
	case BLACK_PAWN:
		Pawn::addMoves(possibleMoves, sf::Vector2i(x, y), false, board, black_enpassant, white_enpassant);
		break;
	case WHITE_PAWN:
		Pawn::addMoves(possibleMoves, sf::Vector2i(x, y), true, board, black_enpassant, white_enpassant);
		break;
	case BLACK_KNIGHT:
		Knight::addMoves(possibleMoves, sf::Vector2i(x, y), false, board);
		break;
	case WHITE_KNIGHT:
		Knight::addMoves(possibleMoves, sf::Vector2i(x, y), true, board);
		break;
	}
	return possibleMoves;
}

void Smart::move(sf::Vector2i fromHere, sf::Vector2i toHere) // Please make sure the move is possible
{
	
	for(int i = 0;i < 8; i++){
		black_enpassant[i] = false;
		white_enpassant[i] = false;
	}
	switch (board[fromHere.x][fromHere.y]) {
	case EMPTY:
		std::cout << "What the fuck??" << std::endl;
		break;
	case BLACK_PAWN:
		if(abs(fromHere.x - toHere.x) == 1){
			if(board[toHere.x][toHere.y] == EMPTY){
				board[toHere.x][fromHere.y] = EMPTY;
			}
		}
		if(fromHere.y == 1 && toHere.y == 3){
			black_enpassant[fromHere.x] = true;
		}
		break;
	case WHITE_PAWN:
		if(abs(fromHere.x - toHere.x) == 1){
			if(board[toHere.x][toHere.y] == EMPTY){
				board[toHere.x][fromHere.y] = EMPTY;
			}
		}
		if(fromHere.y == 6 && toHere.y == 4){
			white_enpassant[fromHere.x] = true;
		}
		break;
	}
	board[toHere.x][toHere.y] = board[fromHere.x][fromHere.y];
	board[fromHere.x][fromHere.y] = EMPTY;
}

void Smart::makeBoard(enum_pieces t_board[8][8])
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			board[i][j] = t_board[i][j];
		}
}



