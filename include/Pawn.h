#pragma once
namespace Pawn{
    static void addMoves(std::vector<sf::Vector2i>& moves, sf::Vector2i position, bool isWhite, enum_pieces board[8][8], bool black_enpassant[8], bool white_enpassant[8])
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
};

