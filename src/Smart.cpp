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
	case BLACK_BISHOP:
		Bishop::addMoves(possibleMoves, sf::Vector2i(x, y), false, board);
		break;
	case WHITE_BISHOP:
		Bishop::addMoves(possibleMoves, sf::Vector2i(x, y), true, board);
		break;
	case BLACK_QUEEN:
		Queen::addMoves(possibleMoves, sf::Vector2i(x, y), false, board);
		break;
	case WHITE_QUEEN:
		Queen::addMoves(possibleMoves, sf::Vector2i(x, y), true, board);
		break;
	case WHITE_ROOK:
		Rook::addMoves(possibleMoves, sf::Vector2i(x, y), true, board);
		break;
	case BLACK_ROOK:
		Rook::addMoves(possibleMoves, sf::Vector2i(x, y), false, board);
		break;
	}
	return possibleMoves;
}

void Smart::move(sf::Vector2i fromHere, sf::Vector2i toHere) // Please make sure the move is possible
{
	
	if(fromHere == sf::Vector2i(0, 0) || toHere == sf::Vector2i(0, 0)){
		black_castle[0] = false;
	}
	else if(fromHere == sf::Vector2i(0, 7) || toHere == sf::Vector2i(0, 7)){
		black_castle[1] = false;
	}
	else if(fromHere == sf::Vector2i(7, 0) || toHere == sf::Vector2i(7, 0)){
		white_castle[0] = false;
	}
	else if(fromHere == sf::Vector2i(7, 7) || toHere == sf::Vector2i(7, 7)){
		white_castle[1] = false;
	}

	for(int i = 0;i < 8; i++){
		black_enpassant[i] = false;
		white_enpassant[i] = false;
	}
	switch (board[fromHere.x][fromHere.y]) {
	case EMPTY:
		break;
	case WHITE_KING:
		white_castle[0] = false;
		white_castle[1] = false;
		break;
	case BLACK_KING:
		black_castle[0] = false;
		black_castle[1] = false;
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
	for(int i = 0; i < 8; i++){
		black_enpassant[i] = false;
		white_enpassant[i] = false;
		black_castle[i%2] = true;
		white_castle[i%2] = true;
	}
}



