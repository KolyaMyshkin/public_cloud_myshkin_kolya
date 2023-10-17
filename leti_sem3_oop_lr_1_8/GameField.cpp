
//  GameField.cpp

#include "GameField.hpp"

#include <iostream>
#define ENTRANCE 0
#define MIN_WIDTH_HEIGHT 0


GameField::GameField(int h, int w) : width(w), height(h),
entrance_x(ENTRANCE), entrance_y(ENTRANCE), exit_x(h), exit_y(w) {
    std::cout << "Cons\n";
    cells = new Cell*[height];
    for (int i = 0; i < height; i++) {
        cells[i] = (Cell*)malloc(sizeof(Cell) * width);
    }
}



GameField::GameField(const GameField& other) : width(other.width), height(other.height),
entrance_x(other.entrance_x), entrance_y(other.entrance_y), exit_x(other.exit_x), exit_y(other.exit_y)  {
    std::cout << "C Copy\n";
    cells = nullptr;
    cells = new Cell*[height];
    for (int i = 0; i < height; i++) {
        cells[i] = (Cell*)malloc(sizeof(Cell) * width);
        std::copy(other.cells[i], other.cells[i]+width, cells[i]);
    }
}
 
GameField& GameField::operator=(const GameField& other){
    std::cout << "Assig Copy\n";
    GameField GF_tmp(other);
    this->width = GF_tmp.width;
    this->height = GF_tmp.height;
    this->entrance_x = GF_tmp.entrance_x;
    this->entrance_y = GF_tmp.entrance_y;
    this->exit_x = GF_tmp.exit_x;
    this->exit_y = GF_tmp.exit_y;
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            this->cells[i][j] = other.cells[i][j];
        }
    }
    return *this;
}
 
GameField::GameField(GameField&& other) {
    std::cout << "C Move\n";
    this->width = other.width;
    this->height = other.height;
    this->entrance_x = other.entrance_x;
    this->entrance_y = other.entrance_y;
    this->exit_x = other.exit_x;
    this->exit_y = other.exit_y;
    this->cells = other.cells;
    // corrections
    other.cells = nullptr;
    other.width = 0;
    other.height = 0;
}

GameField& GameField::operator=(GameField&& other){
    std::cout << "Assig Move\n";
    if (this == &other) {
        return *this;
    }
    this->width = other.width;
    this->height = other.height;
    this->entrance_x = other.entrance_x;
    this->entrance_y = other.entrance_y;
    this->exit_x = other.exit_x;
    this->exit_y = other.exit_y;
    this->cells = new Cell*[this->height];
    for (int i = 0; i < this->height; i++) {
        this->cells[i] = (Cell*)malloc(sizeof(Cell) * this->width);
        for (int j = 0; j < this->width; j++) {
            this->cells[i][j] = other.cells[i][j];
        }
    }
    return *this;
}
 
GameField::~GameField() {
    std::cout << "Dest\n";
    for (int i = 0; i < height; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}
 
Cell& GameField::get_cell(int x, int y){
    return cells[x][y];
}
 
int GameField::get_width(){
    return width;
}
 
int GameField::get_height(){
    return height;
}
 
int GameField::get_entrance_x(){
    return entrance_x;
}
 
int GameField::get_entrance_y(){
    return entrance_y;
}
 
int GameField::get_exit_x(){
    return exit_x-1;
}
 
int GameField::get_exit_y(){
    return exit_y-1;
}
 
void GameField::set_entrance(int x , int y){
    if((x <= height-1 && x >= ENTRANCE) && (y <= width-1 && y >= ENTRANCE)){
        this->entrance_x = x;
        this->entrance_y = y;
    } else {
        std::cout << "Неверная точка входа\n";
    }
}
 
void GameField::set_exit(int x , int y){
    if((x <= height-1 && x >= MIN_WIDTH_HEIGHT) && (y <= width-1 && y >= MIN_WIDTH_HEIGHT)){
        this->exit_x = x;
        this->exit_y = y;
    } else {
        std::cout << "Неверная точка выхода\n";
    }
}

void GameField::GF_print(Controller& controller, Player& player) {
    for (int i = 0; i < this->get_height(); i++) {
        for (int j = 0; j < this->get_width(); j++) {
            if (i == this->get_entrance_x() && j == this->get_entrance_y()) {
                if (i == controller.get_x() && j == controller.get_y()) {
                    std::cout << "@" << " ";
                } else {
                    std::cout << "S" << " ";
                }      
            }
            else if (i == this->get_exit_x() && j == this->get_exit_y()) {
                if (i == controller.get_x() && j == controller.get_y()) {
                    std::cout << "@" << " ";
                } else {
                    std::cout << "F" << " ";
                }
            }
            else if (i == controller.get_x() && j == controller.get_y()) {
                std::cout << "@" << " ";
            } else {
                if (this->cells[i][j].get_is_Passable() == true) {
                    std::cout << '#' << " ";
                } else {
                    std::cout << '.' << " ";
                }
            }
        }
        std::cout << "\n";
    }
    std::cout << "(x: " << controller.get_x() << ", y: " << controller.get_y() << ")" << "   (hp: " << player.get_player_health() << ", mny: " << player.get_player_money() << ", pnts: " << player.get_player_points() << ")\n";
    return;
}
