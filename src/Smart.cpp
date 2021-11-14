#include "Smart.h"
#include <iostream>

std::vector<sf::Vector2i> Smart::getPossibleMoves(int x, int y)
{
	std::vector<sf::Vector2i> possibleMoves;
	switch (board[x][y]) {
	case EMPTY:
		break;
	case BLACK_PAWN:
		pawn_addMoves(possibleMoves, sf::Vector2i(x, y), false);
		break;
	case WHITE_PAWN:
		pawn_addMoves(possibleMoves, sf::Vector2i(x, y), true);
		break;
	}
	return possibleMoves;
}

void Smart::move(sf::Vector2i fromHere, sf::Vector2i toHere) // Please make sure the move is possible
{
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
			black_enpassant[fromHere.x] == true;
		}
		break;
	case WHITE_PAWN:
		if(abs(fromHere.x - toHere.x) == 1){
			if(board[toHere.x][toHere.y] == EMPTY){
				board[toHere.x][fromHere.y] = EMPTY;
			}
		}
		if(fromHere.y == 6 && toHere.y == 4){
			white_enpassant[fromHere.x] == true;
		}
		break;
	}
	for(int i = 0;i < 8; i++){
		black_enpassant[i] == false;
		white_enpassant[i] == false;
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


void Smart::pawn_addMoves(std::vector<sf::Vector2i>& moves, sf::Vector2i position, bool isWhite)
{
	if (isWhite) {

		//Pawn first move
		if (position.y == 6) {
			for (int i = 1; i <= 2; i++) {
				if (board[position.x][position.y - i] == EMPTY) {
					moves.push_back(sf::Vector2i(position.x, position.y - i));
				}
			}
		}

		//Non first move
		else {
			if (board[position.x][position.y - 1] == EMPTY) {
				moves.push_back(sf::Vector2i(position.x, position.y - 1));
			}
		}

		//Diagonal Kill
		if (	(int)board[position.x - 1][position.y - 1] >= (int)'a'
			&&	(int)board[position.x - 1][position.y - 1] <= (int)'z') {
			moves.push_back(sf::Vector2i(position.x - 1, position.y - 1));
		}
		if ((int)board[position.x + 1][position.y - 1] >= (int)'a'
			&& (int)board[position.x + 1][position.y - 1] <= (int)'z') {
			moves.push_back(sf::Vector2i(position.x + 1, position.y - 1));
		}

		//Enpassant
		if(position.y == 3){
			if(black_enpassant[position.x - 1]){
				moves.push_back(sf::Vector2i(position.x - 1, position.y - 1));
			}
			if(black_enpassant[position.x + 1]){
				moves.push_back(sf::Vector2i(position.x + 1, position.y - 1));
			}
		}
	}
	else {
		//First move
		if (position.y == 1) {
			for (int i = 1; i <= 2; i++) {
				if (board[position.x][position.y + i] == EMPTY) {
					moves.push_back(sf::Vector2i(position.x, position.y + i));
				}
			}
		}

		//Non first move
		else {
			if (board[position.x][position.y + 1] == EMPTY) {
				moves.push_back(sf::Vector2i(position.x, position.y + 1));
			}
		}

		//Diagonal kill
		if ((int)board[position.x - 1][position.y + 1] >= (int)'A'
			&& (int)board[position.x - 1][position.y + 1] <= (int)'Z') {
			moves.push_back(sf::Vector2i(position.x + 1, position.y + 1));
		}
		if ((int)board[position.x + 1][position.y + 1] >= (int)'A'
			&& (int)board[position.x + 1][position.y + 1] <= (int)'Z') {
			moves.push_back(sf::Vector2i(position.x + 1, position.y + 1));
		}

		//Enpassant
		if(position.y == 4){
			if(white_enpassant[position.x - 1]){
				moves.push_back(sf::Vector2i(position.x - 1, position.y + 1));
			}
			if(white_enpassant[position.x + 1]){
				moves.push_back(sf::Vector2i(position.x + 1, position.y + 1));
			}
		}
		
	}
}
