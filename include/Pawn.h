#pragma once
#include "PieceInfo.h"
class Pawn :
    public PieceInfo
{
public:
    bool movePossible(sf::Vector2i move, enum_pieces board[8][8]);
    Pawn(sf::Vector2i startingPosition, bool isWhite);
};

