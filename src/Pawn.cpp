#include "Pawn.h"

bool Pawn::movePossible(sf::Vector2i move, enum_pieces board[8][8])
{
    bool is_it_possible = false;

    if (move.x == position.x) {
        if (board[move.x][move.y] == EMPTY) {
            if (number_of_times_moved == 0) {
                if (isWhite) {
                    if (move.y - position.y == -1 || move.y - position.y == -2)
                        is_it_possible =  true;
                }
                else {
                    if (move.y - position.y == 1 || move.y - position.y == 2)
                        is_it_possible =  true;
                }
            }
            else {
                if (isWhite) {
                    if (move.y - position.y == -1)
                        is_it_possible =  true;
                }
                else {
                    if (move.y - position.y == 1)
                        is_it_possible =  true;
                }
            }
        }
    }
    else if(abs(move.x - position.x) == 1){
        if (isWhite) {
            if (move.y - position.y == -1)
                switch (board[move.x][move.y]) {
                case BLACK_KING:
                    is_it_possible = true;
                    break;
                case BLACK_PAWN:
                    is_it_possible = true;
                    break;
                case BLACK_ROOK:
                    is_it_possible = true;
                    break;
                case BLACK_BISHOP:
                    is_it_possible = true;
                    break;
                case BLACK_QUEEN:
                    is_it_possible = true;
                    break;
                case BLACK_KNIGHT:
                    is_it_possible = true;
                    break;
                }
        }
        else {
            if (move.y - position.y == 1)
                switch (board[move.x][move.y]) {
                case WHITE_KING:
                    is_it_possible = true;
                    break;
                case WHITE_PAWN:
                    is_it_possible = true;
                    break;
                case WHITE_ROOK:
                    is_it_possible = true;
                    break;
                case WHITE_BISHOP:
                    is_it_possible = true;
                    break;
                case WHITE_QUEEN:
                    is_it_possible = true;
                    break;
                case WHITE_KNIGHT:
                    is_it_possible = true;
                    break;
                }
        }
    }
    if (is_it_possible) position = move;
    number_of_times_moved++;
    return is_it_possible;
}

Pawn::Pawn(sf::Vector2i startingPosition, bool isWhite)
{
    this->position = startingPosition;
    this->isWhite = isWhite;
    this->number_of_times_moved = 0;
}
