#include "Game.h"
#include <random>
#include <time.h>
#include <iostream>
#include <vector>

class coord{
public:
    int x;
    int y;
};

void Game::Click(int x, int y){
    std::vector<coord> queue;
    if(!open[x][y]){ 
        open[x][y] = true;
        if(!numbers[x][y]){
            coord element;
            element.x = x;
            element.y = y;
            queue.push_back(element);
        }
    }
    while(!queue.empty()){
        int x = queue.back().x;
        int y = queue.back().y;
        std::cout << x << " " << y << std::endl;
        open[x][y] = true;
        queue.pop_back();
        if(!numbers[x][y]){
            if(x + 1 < 20 && !open[x + 1][y]){
                coord element;
                element.x = x + 1;
                element.y = y;
                queue.push_back(element);
            }
            if(x > 0 && !open[x - 1][y]){
                coord element;
                element.x = x - 1;
                element.y = y;
                queue.push_back(element);
            }
            if(y + 1 < 20 && !open[x][y + 1]){
                coord element;
                element.x = x;
                element.y = y + 1;
                queue.push_back(element);
            }
            if(y > 0 && !open[x][y - 1]){
                coord element;
                element.x = x;
                element.y = y - 1;
                queue.push_back(element);
            }
            if(x + 1 < 20 && y + 1 < 20 && !open[x + 1][y + 1]){
                coord element;
                element.x = x + 1;
                element.y = y + 1;
                queue.push_back(element);
            }
            if(x + 1 < 20 && y > 0 && !open[x + 1][y - 1]){
                coord element;
                element.x = x + 1;
                element.y = y - 1;
                queue.push_back(element);
            }
            if(x > 0 && y + 1 < 20 && !open[x - 1][y + 1]){
                coord element;
                element.x = x - 1;
                element.y = y + 1;
                queue.push_back(element);
            }
            if(x > 0 && y > 0 && !open[x - 1][y - 1]){
                coord element;
                element.x = x - 1;
                element.y = y - 1;
                queue.push_back(element);
            }
        }
    }
}

void Game::Flagged(int x, int y){
    Click(x, y);
}

Game::Game(const int size, const int numberOfBombs){
    srand(time(NULL));

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            numbers[i][j] = 0;
            open[i][j] = false;
        }
    }
    

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(!(rand()%numberOfBombs)){
                board[i][j] = BOMB;
                std::cout << "B ";
            }else{
                board[i][j] = EMPTY;
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(!board[i][j]){
            if(i != 0){
                numbers[i][j] += board[i - 1][j];
            }
            if(i + 1 < size){
                numbers[i][j] += board[i + 1][j];
            }
            if(j != 0){
                numbers[i][j] += board[i][j - 1];
            }
            if(j + 1 < size){
                numbers[i][j] += board[i][j + 1];
            }
            if(i != 0 && j != 0){
                numbers[i][j] += board[i - 1][j - 1];
            }
            if(i + 1 < size && j + 1 < size){
                numbers[i][j] += board[i + 1][j + 1];
            }
            if(i != 0 && j + 1 < size){
                numbers[i][j] += board[i - 1][j + 1];
            }
            if(i + 1 < size && j != 0){
                numbers[i][j] += board[i + 1][j - 1];
            }
            }
        }
    }

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            int number = numbers[i][j];
            if(number){
                std::cout << number  << " ";
            }
            else{
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
}

Game::~Game(){

}