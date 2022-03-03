#pragma once
namespace Queen{
    static void addMoves(std::vector<sf::Vector2i>& moves, sf::Vector2i position, bool isWhite, enum_pieces board[8][8]){
        bool northEast = true;
        bool northWest = true;
        bool southEast = true;
        bool southWest = true;
        bool north = true;
        bool south = true;
        bool east = true;
        bool west = true;

        for(int i = 1; i < 8; i++){
            if(southEast){
                if(position.x + i < 8 && position.x + i >= 0 && position.y + i < 8 && position.y + i >= 0){
                    if(board[position.x + i][position.y + i] == EMPTY){
                        moves.push_back(sf::Vector2i(position.x + i, position.y + i));
                    }
                    else if((int)board[position.x + i][position.y + i] >= (int)'a' && (int)board[position.x + i][position.y + i] <= (int)'z'){
                        if(isWhite) moves.push_back(sf::Vector2i(position.x + i, position.y + i));
                        southEast = false;
                    }
                    else if((int)board[position.x + i][position.y + i] >= (int)'A' && (int)board[position.x + i][position.y + i] <= (int)'Z'){
                        if(!isWhite) moves.push_back(sf::Vector2i(position.x + i, position.y + i));
                        southEast = false;
                    }
                }
            }
            if(southWest){
                if(position.x - i < 8 && position.x - i >= 0 && position.y + i < 8 && position.y + i >= 0){
                    if(board[position.x - i][position.y + i] == EMPTY){
                        moves.push_back(sf::Vector2i(position.x - i, position.y + i));
                    }
                    else if((int)board[position.x - i][position.y + i] >= (int)'a' && (int)board[position.x - i][position.y + i] <= (int)'z'){
                        if(isWhite) moves.push_back(sf::Vector2i(position.x - i, position.y + i));
                        southWest = false;
                    }
                    else if((int)board[position.x - i][position.y + i] >= (int)'A' && (int)board[position.x - i][position.y + i] <= (int)'Z'){
                        if(!isWhite) moves.push_back(sf::Vector2i(position.x - i, position.y + i));
                        southWest = false;
                    }
                }
            }
            if(northEast){
                if(position.x + i < 8 && position.x + i >= 0 && position.y - i < 8 && position.y - i >= 0){
                    if(board[position.x + i][position.y - i] == EMPTY){
                        moves.push_back(sf::Vector2i(position.x + i, position.y - i));
                    }
                    else if((int)board[position.x + i][position.y - i] >= (int)'a' && (int)board[position.x + i][position.y - i] <= (int)'z'){
                        if(isWhite) moves.push_back(sf::Vector2i(position.x + i, position.y - i));
                        northEast = false;
                    }
                    else if((int)board[position.x + i][position.y - i] >= (int)'A' && (int)board[position.x + i][position.y - i] <= (int)'Z'){
                        if(!isWhite) moves.push_back(sf::Vector2i(position.x + i, position.y - i));
                        northEast = false;
                    }
                }
            }
            if(northWest){
                if(position.x - i < 8 && position.x - i >= 0 && position.y - i < 8 && position.y - i >= 0){
                    if(board[position.x - i][position.y - i] == EMPTY){
                        moves.push_back(sf::Vector2i(position.x - i, position.y - i));
                    }
                    else if((int)board[position.x - i][position.y - i] >= (int)'a' && (int)board[position.x - i][position.y - i] <= (int)'z'){
                        if(isWhite) moves.push_back(sf::Vector2i(position.x - i, position.y - i));
                        northWest = false;
                    }
                    else if((int)board[position.x - i][position.y - i] >= (int)'A' && (int)board[position.x - i][position.y - i] <= (int)'Z'){
                        if(!isWhite) moves.push_back(sf::Vector2i(position.x - i, position.y - i));
                        northWest = false;
                    }
                }
            }

            if(east){
                if(position.x + i < 8 && position.x + i >= 0 && position.y < 8 && position.y >= 0){
                    if(board[position.x + i][position.y] == EMPTY){
                        moves.push_back(sf::Vector2i(position.x + i, position.y));
                    }
                    else if((int)board[position.x + i][position.y] >= (int)'a' && (int)board[position.x + i][position.y] <= (int)'z'){
                        if(isWhite) moves.push_back(sf::Vector2i(position.x + i, position.y));
                        east = false;
                    }
                    else if((int)board[position.x + i][position.y] >= (int)'A' && (int)board[position.x + i][position.y] <= (int)'Z'){
                        if(!isWhite) moves.push_back(sf::Vector2i(position.x + i, position.y));
                        east = false;
                    }
                }
            }
            if(west){
                if(position.x - i < 8 && position.x - i >= 0 && position.y < 8 && position.y >= 0){
                    if(board[position.x - i][position.y] == EMPTY){
                        moves.push_back(sf::Vector2i(position.x - i, position.y));
                    }
                    else if((int)board[position.x - i][position.y] >= (int)'a' && (int)board[position.x - i][position.y] <= (int)'z'){
                        if(isWhite) moves.push_back(sf::Vector2i(position.x - i, position.y));
                        west = false;
                    }
                    else if((int)board[position.x - i][position.y] >= (int)'A' && (int)board[position.x - i][position.y] <= (int)'Z'){
                        if(!isWhite) moves.push_back(sf::Vector2i(position.x - i, position.y));
                        west = false;
                    }
                }
            }
            if(north){
                if(position.x < 8 && position.x >= 0 && position.y - i < 8 && position.y - i >= 0){
                    if(board[position.x][position.y - i] == EMPTY){
                        moves.push_back(sf::Vector2i(position.x, position.y - i));
                    }
                    else if((int)board[position.x][position.y - i] >= (int)'a' && (int)board[position.x][position.y - i] <= (int)'z'){
                        if(isWhite) moves.push_back(sf::Vector2i(position.x, position.y - i));
                        north = false;
                    }
                    else if((int)board[position.x][position.y - i] >= (int)'A' && (int)board[position.x][position.y - i] <= (int)'Z'){
                        if(!isWhite) moves.push_back(sf::Vector2i(position.x, position.y - i));
                        north = false;
                    }
                }
            }
            if(south){
                if(position.x < 8 && position.x >= 0 && position.y + i < 8 && position.y + i >= 0){
                    if(board[position.x][position.y + i] == EMPTY){
                        moves.push_back(sf::Vector2i(position.x, position.y + i));
                    }
                    else if((int)board[position.x][position.y + i] >= (int)'a' && (int)board[position.x][position.y + i] <= (int)'z'){
                        if(isWhite) moves.push_back(sf::Vector2i(position.x, position.y + i));
                        south = false;
                    }
                    else if((int)board[position.x][position.y + i] >= (int)'A' && (int)board[position.x][position.y + i] <= (int)'Z'){
                        if(!isWhite) moves.push_back(sf::Vector2i(position.x, position.y + i));
                        south = false;
                    }
                }
            }
        }
    }   
};