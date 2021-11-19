#pragma once
namespace King{
    static void addMoves(std::vector<sf::Vector2i>& moves, sf::Vector2i position, bool isWhite, enum_pieces board[8][8], bool black_castle[2], bool white_castle[2])
    {
        for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++){
            if( position.x + i >= 0 && position.x + i < 8 &&
                position.y + j >= 0 && position.y + j < 8){
                if(board[position.x + i][position.y + j] == EMPTY){
                    moves.push_back(sf::Vector2i(position.x + i, position.y + j)); 
                }
                if(isWhite){
                    if(board[position.x + i][position.y + j] >= (int)'a' && board[position.x + i][position.y + j] <= (int)'z')
                        moves.push_back(sf::Vector2i(position.x + i, position.y + j));
                }
                else{
                    if(board[position.x + i][position.y + j] >= (int)'A' && board[position.x + i][position.y + j] <= (int)'Z') 
                        moves.push_back(sf::Vector2i(position.x + i, position.y + j));
                }
            }
        }
        if(isWhite){
            if(position.x == 3 && position.y == 7){
                if(white_castle[0])
                {
                    if(
                        board[2][7] == EMPTY &&
                        board[1][7] == EMPTY 
                    )
                    moves.push_back(sf::Vector2i(1, 7));
                }
                if(white_castle[1])
                {
                    if(
                        board[3][7] == EMPTY &&
                        board[4][7] == EMPTY &&
                        board[5][7] == EMPTY 
                    )
                    moves.push_back(sf::Vector2i(5, 7));
                }
            }
        }
        else{
            if(position.x == 3 && position.y == 0){
                if(black_castle[0])
                {
                    if(
                        board[2][0] == EMPTY &&
                        board[1][0] == EMPTY 
                    )
                    moves.push_back(sf::Vector2i(1, 0));
                }
                if(black_castle[1])
                {
                    if(
                        board[3][0] == EMPTY &&
                        board[4][0] == EMPTY &&
                        board[5][0] == EMPTY 
                    )
                    moves.push_back(sf::Vector2i(5, 0));
                }
            }
        }
    }
    static bool isCheck(sf::Vector2i position, sf::Vector2i toHere, bool isWhite, enum_pieces given_board[8][8], bool kingMove=false){
        sf::Vector2i king_position;

        //Make a copy of the board and look for the king
        enum_pieces board[8][8];
        for(int i = 0; i < 8; i++){
            for(int j = 0;j< 8; j++){
                if(isWhite) if(given_board[i][j] == WHITE_KING) king_position = sf::Vector2i(i, j);
                if(!isWhite) if(given_board[i][j] == BLACK_KING) king_position = sf::Vector2i(i, j);
                board[i][j] = given_board[i][j];
            }
        }

        //Change board according to the given parameters
        switch (board[position.x][position.y]) {
        case WHITE_KING:
            if(position.x == 3 && toHere.x == 1){
                board[0][7] = EMPTY;
                board[2][7] = WHITE_ROOK;
            }
            if(position.x == 3 && toHere.x == 5){
                board[7][7] = EMPTY;
                board[4][7] = WHITE_ROOK;
            }
            break;
        case BLACK_KING:
            if(position.x == 3 && toHere.x == 1){
                board[0][0] = EMPTY;
                board[2][0] = BLACK_ROOK;
            }
            if(position.x == 3 && toHere.x == 5){
                board[7][0] = EMPTY;
                board[4][0] = WHITE_ROOK;
            }
            break;
        }
        board[toHere.x][toHere.y] = board[position.x][position.y];
        board[position.x][position.y] = EMPTY;

        bool northEast = true;
        bool northWest = true;
        bool southEast = true;
        bool southWest = true;
        bool north = true;
        bool south = true;
        bool east = true;
        bool west = true;

        for(int i = 1; i < 8; i++){

            //death by bishop or queen
            if(southEast){
                if(king_position.x + i < 8 && king_position.x + i >= 0 && king_position.y + i < 8 && king_position.y + i >= 0){
                    if(
                        ((int)board[king_position.x + i][king_position.y + i] >= 97 && (int)board[king_position.x + i][king_position.y + i] <= 122) ||
                        ((int)board[king_position.x + i][king_position.y + i] >= 65 && (int)board[king_position.x + i][king_position.y + i] <= 90)
                    ) southEast = false;
                    if((int)board[king_position.x + i][king_position.y + i] == BLACK_BISHOP || (int)board[king_position.x + i][king_position.y + i] == BLACK_QUEEN){
                        if(isWhite) return true;
                    }
                    else if((int)board[king_position.x + i][king_position.y + i] == WHITE_BISHOP || (int)board[king_position.x + i][king_position.y + i] == WHITE_QUEEN){
                        if(!isWhite) return true;
                    }
                }
            }
            if(southWest){
                if(
                        ((int)board[king_position.x - i][king_position.y + i] >= 97 && (int)board[king_position.x - i][king_position.y + i] <= 122) ||
                        ((int)board[king_position.x - i][king_position.y + i] >= 65 && (int)board[king_position.x - i][king_position.y + i] <= 90)
                ) southWest = false;
                if(king_position.x - i < 8 && king_position.x - i >= 0 && king_position.y + i < 8 && king_position.y + i >= 0){
                    if((int)board[king_position.x - i][king_position.y + i] == BLACK_BISHOP || (int)board[king_position.x - i][king_position.y + i] == BLACK_QUEEN){
                        if(isWhite) return true;
                    }
                    else if((int)board[king_position.x - i][king_position.y + i] == WHITE_BISHOP || (int)board[king_position.x - i][king_position.y + i] == WHITE_QUEEN){
                        if(!isWhite) return true;
                    }
                }
            }
            if(northEast){
                if(
                        ((int)board[king_position.x + i][king_position.y - i] >= 97 && (int)board[king_position.x + i][king_position.y - i] <= 122) ||
                        ((int)board[king_position.x + i][king_position.y - i] >= 65 && (int)board[king_position.x + i][king_position.y - i] <= 90)
                ) northEast = false;
                if(king_position.x + i < 8 && king_position.x + i >= 0 && king_position.y - i < 8 && king_position.y - i >= 0){
                    if((int)board[king_position.x + i][king_position.y - i] == BLACK_BISHOP || (int)board[king_position.x + i][king_position.y - i] == BLACK_QUEEN){
                        if(isWhite) return true;
                    }
                    else if((int)board[king_position.x + i][king_position.y - i] == WHITE_BISHOP || (int)board[king_position.x + i][king_position.y - i] == WHITE_QUEEN){
                        if(!isWhite) return true;
                    }
                }
            }
            if(northWest){
                if(
                        ((int)board[king_position.x - i][king_position.y - i] >= 97 && (int)board[king_position.x - i][king_position.y - i] <= 122) ||
                        ((int)board[king_position.x - i][king_position.y - i] >= 65 && (int)board[king_position.x - i][king_position.y - i] <= 90)
                ) northWest = false;
                if(king_position.x - i < 8 && king_position.x - i >= 0 && king_position.y - i < 8 && king_position.y - i >= 0){
                    if((int)board[king_position.x - i][king_position.y - i] == BLACK_BISHOP || (int)board[king_position.x - i][king_position.y - i] == BLACK_QUEEN){
                        if(isWhite) return true;
                    }
                    else if((int)board[king_position.x - i][king_position.y - i] == WHITE_BISHOP || (int)board[king_position.x - i][king_position.y - i] == WHITE_QUEEN){
                        if(!isWhite) return true;
                    }
                }
            }

            //death by rook or queen
            if(east){
                if(
                        ((int)board[king_position.x + i][king_position.y] >= 97 && (int)board[king_position.x + i][king_position.y] <= 122) ||
                        ((int)board[king_position.x + i][king_position.y] >= 65 && (int)board[king_position.x + i][king_position.y] <= 90)
                ) east = false;
                if(king_position.x + i < 8 && king_position.x + i >= 0 && king_position.y < 8 && king_position.y >= 0){
                    if((int)board[king_position.x + i][king_position.y] == BLACK_ROOK || (int)board[king_position.x + i][king_position.y] == BLACK_QUEEN){
                        if(isWhite) return true;
                    }
                    else if((int)board[king_position.x + i][king_position.y] == WHITE_ROOK || (int)board[king_position.x + i][king_position.y] == WHITE_QUEEN){
                        if(!isWhite) return true;
                    }
                }
            }
            if(west){
                if(
                        ((int)board[king_position.x - i][king_position.y] >= 97 && (int)board[king_position.x - i][king_position.y] <= 122) ||
                        ((int)board[king_position.x - i][king_position.y] >= 65 && (int)board[king_position.x - i][king_position.y] <= 90)
                ) west = false;
                if(king_position.x - i < 8 && king_position.x - i >= 0 && king_position.y < 8 && king_position.y >= 0){
                    if((int)board[king_position.x - i][king_position.y] == BLACK_ROOK || (int)board[king_position.x - i][king_position.y] == BLACK_QUEEN){
                        if(isWhite) return true;
                    }
                    else if((int)board[king_position.x - i][king_position.y] == WHITE_ROOK || (int)board[king_position.x - i][king_position.y] == WHITE_QUEEN){
                        if(!isWhite) return true;
                    }
                }
            }
            if(north){
                if(
                        ((int)board[king_position.x][king_position.y - i] >= 97 && (int)board[king_position.x][king_position.y - i] <= 122) ||
                        ((int)board[king_position.x][king_position.y - i] >= 65 && (int)board[king_position.x][king_position.y - i] <= 90)
                ) north = false;
                if(king_position.x < 8 && king_position.x >= 0 && king_position.y - i < 8 && king_position.y - i >= 0){
                    if((int)board[king_position.x][king_position.y - i] == BLACK_ROOK || (int)board[king_position.x][king_position.y - i] == BLACK_QUEEN){
                        if(isWhite) return true;
                    }
                    else if((int)board[king_position.x][king_position.y - i] == WHITE_ROOK || (int)board[king_position.x][king_position.y - i] == WHITE_QUEEN){
                        if(!isWhite) return true;
                    }
                }
            }
            if(south){
                if(
                        ((int)board[king_position.x][king_position.y + i] >= 97 && (int)board[king_position.x][king_position.y + i] <= 122) ||
                        ((int)board[king_position.x][king_position.y + i] >= 65 && (int)board[king_position.x][king_position.y + i] <= 90)
                ) south = false;
                if(king_position.x < 8 && king_position.x >= 0 && king_position.y + i < 8 && king_position.y + i >= 0){
                    if((int)board[king_position.x][king_position.y + i] == BLACK_ROOK || (int)board[king_position.x][king_position.y + i] == BLACK_QUEEN){
                        if(isWhite) return true;
                    }
                    else if((int)board[king_position.x][king_position.y + i] == WHITE_ROOK || (int)board[king_position.x][king_position.y + i] == WHITE_QUEEN){
                        if(!isWhite) return true;
                    }
                }
            }
        }

        return false;
    }
};