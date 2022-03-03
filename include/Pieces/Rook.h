#pragma once
#include <iostream>
namespace Rook{
    static void addMoves(std::vector<sf::Vector2i>& moves, sf::Vector2i position, bool isWhite, enum_pieces board[8][8]){
        bool north = true;
        bool south = true;
        bool east = true;
        bool west = true;
        if(!isWhite) std::cout << "Fuck, this shit i'm out : " << isWhite << std::endl;
        for(int i = 1; i < 8; i++){
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