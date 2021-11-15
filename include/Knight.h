#pragma once
namespace Knight{
    static void addMoves(std::vector<sf::Vector2i>& moves, sf::Vector2i position, bool isWhite, enum_pieces board[8][8])
    {
        for(int i = -2; i <= 2; i+=4){
            for(int j = -1; j <= 1; j+= 2){
                if(position.x + i >= 0 && position.x + i < 8 && position.y + j >= 0 && position.y + j < 8){
                    if(isWhite){
                        if(     ((int)board[position.x + i][position.y + j] >= (int)'a'
                            &&  (int)board[position.x + i][position.y + j] <= (int)'z') || board[position.x + i][position.y + j] == EMPTY){
                                    moves.push_back(sf::Vector2i(position.x + i, position.y + j));
                            }
                    }else{
                        if(     ((int)board[position.x + i][position.y + j] >= (int)'A'
                            &&  (int)board[position.x + i][position.y + j] <= (int)'Z') || board[position.x + i][position.y + j] == EMPTY){
                                    moves.push_back(sf::Vector2i(position.x + i, position.y + j));
                            }
                    }
                }
                if(position.x + j >= 0 && position.x + j < 8 && position.y + i >= 0 && position.y + i < 8){
                    if(isWhite){
                        if(     ((int)board[position.x + j][position.y + i] >= (int)'a'
                            &&  (int)board[position.x + j][position.y + i] <= (int)'z') || board[position.x + j][position.y + i] == EMPTY){
                                    moves.push_back(sf::Vector2i(position.x + j, position.y + i));
                            }
                    }else{
                        if(     ((int)board[position.x + j][position.y + i] >= (int)'A'
                            &&  (int)board[position.x + j][position.y + i] <= (int)'Z') || board[position.x + j][position.y + i] == EMPTY){
                                    moves.push_back(sf::Vector2i(position.x + j, position.y + i));
                            }
                    }
                }
            }
        }
    }
};

