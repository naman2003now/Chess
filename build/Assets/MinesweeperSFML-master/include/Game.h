#pragma once
inline const int BOMB = 1;
inline const int EMPTY = 0;

class Game{
public:
    int board[100][100];
    int numbers[100][100];
    bool clicked[100][100];
    bool flagged[100][100];
    bool open[100][100];
    void Click(int x, int y);
    void Flagged(int x, int y);
    Game(const int size, const int numberOfBombs);
    ~Game();
};