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
    static void isCheck(sf::Vector2i position, bool isWhite, enum_pieces board[8][8], bool kingMove=false){
        
    }
};