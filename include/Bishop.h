#pragma once
namespace Bishop{
    static void addMoves(std::vector<sf::Vector2i>& moves, sf::Vector2i position, bool isWhite, enum_pieces board[8][8]){
        bool northEast = true;
        bool northWest = true;
        bool southEast = true;
        bool southWest = true;

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
        }
    }   
}