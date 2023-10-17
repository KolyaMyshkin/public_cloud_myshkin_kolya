
//  GameField.hpp

#ifndef GameField_hpp
#define GameField_hpp
#include "Cell.hpp"
#include "Controller.hpp"
#include "Player.hpp"

#include <stdio.h>

class GameField{
    int height;
    int width;
    int entrance_x;
    int entrance_y;
    int exit_x;
    int exit_y;
    Cell** cells;

public:
    GameField();
    GameField(int h, int w);
    GameField(const GameField& other);
    GameField& operator=(const GameField& other);
    GameField(GameField&& other);
    GameField& operator=(GameField&& other);
    ~GameField();
    Cell& get_cell(int x, int y);
    int get_width();
    int get_height();
    int get_entrance_x();
    int get_entrance_y();
    int get_exit_x();
    int get_exit_y();
    void set_entrance(int x , int y);
    void set_exit(int x , int y);
    void GF_print(Controller& controller, Player& player);
};

#endif /* GameField_hpp */
