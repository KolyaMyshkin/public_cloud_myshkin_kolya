
//  GameField.hpp

#ifndef GameField_hpp
#define GameField_hpp
#include "Cell.hpp"

#include <stdio.h>

class GameField{
    int width;
    int height;
    int entrance_X;
    int entrance_Y;
    int exit_X;
    int exit_Y;
    Cell** cells;
public:
    GameField();
    GameField(int w, int h);
    GameField(const GameField& other);
    GameField& operator=(const GameField& other);
    GameField(GameField&& other);
    GameField& operator=(GameField&& other);
    ~GameField();
    Cell& getCell(int x, int y);
    int getWidth();
    int getHeight();
    int getentrance_X();
    int getentrance_Y();
    int getexit_X();
    int getexit_Y();
    void setEntrance(int x , int y);
    void setExit(int x , int y);
};

#endif /* GameField_hpp */
