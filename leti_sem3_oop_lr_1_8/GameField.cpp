
//  GameField.cpp

#include "GameField.hpp"

#include <iostream>
#define MAX_WIDTH 20
#define MAX_HEIGHT 20
#define ENTRANCE 0
#define MIN_WIDTH_HEIGHT 0
GameField::GameField() : width(MAX_WIDTH), height(MAX_HEIGHT),
entrance_X(ENTRANCE), entrance_Y(ENTRANCE), exit_X(MAX_WIDTH - 1), exit_Y(MAX_HEIGHT - 1) {
    cells = new Cell*[width];
    for (int i = 0; i < width; i++) {
//        cells[i] = new Cell[height];
        cells[i] = (Cell*)malloc(sizeof(Cell) * height);
    }
    exit_X = width - 1;
    exit_Y = height - 1;
}
 
GameField::GameField(int w, int h) : width(w), height(h),
entrance_X(ENTRANCE), entrance_Y(ENTRANCE), exit_X(MAX_WIDTH - 1), exit_Y(MAX_HEIGHT - 1) {
    if (w > MAX_WIDTH ||  w < MIN_WIDTH_HEIGHT || h > MAX_HEIGHT || h < MIN_WIDTH_HEIGHT) {
        std::cout << "Неверные размеры поля, размеры будут установлены по умолчанию\n";
        width = MAX_WIDTH;
        height = MAX_HEIGHT;
    }
    cells = new Cell*[width];
    for (int i = 0; i < width; i++) {
//        cells[i] = new Cell[height];
        cells[i] = (Cell*)malloc(sizeof(Cell) * height);
    }
 
    exit_X = width - 1;
    exit_Y = height - 1;
}
 
GameField::GameField(const GameField& other) : width(other.width), height(other.height),
entrance_X(other.entrance_X), entrance_Y(other.entrance_Y), exit_X(other.exit_X), exit_Y(other.exit_Y)
{
    cells = new Cell*[width];
    for (int i = 0; i < width; i++) {
//        cells[i] = new Cell[height];
        cells[i] = (Cell*)malloc(sizeof(Cell) * height);
        for (int j = 0; j < height; j++) {
            cells[i][j] = other.cells[i][j];
        }
    }
}
 
GameField& GameField::operator=(const GameField& other){
    if (this == &other) {
        return *this;
    }
 
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }
    delete[] cells;
 
    width = other.width;
    height = other.height;
    entrance_X = other.entrance_X;
    entrance_Y = other.entrance_Y;
    exit_X = other.exit_X;
    exit_Y = other.exit_Y;
 
    cells = new Cell*[width];
    for (int i = 0; i < width; i++) {
//        cells[i] = new Cell[height];
        cells[i] = (Cell*)malloc(sizeof(Cell) * height);
        for (int j = 0; j < height; j++) {
            cells[i][j] = other.cells[i][j];
        }
    }
 
    return *this;
}
 
GameField::GameField(GameField&& other) : cells(other.cells), width(other.width), height(other.height),
entrance_X(other.entrance_X), entrance_Y(other.entrance_Y), exit_X(other.exit_X), exit_Y(other.exit_Y)
{
    other.cells = nullptr;
    other.width = 0;
    other.height = 0;
    other.entrance_X = 0;
    other.entrance_Y = 0;
    other.exit_X = 0;
    other.exit_Y = 0;
}
 
GameField& GameField::operator=(GameField&& other){
    if (this == &other) {
        return *this;
    }
    
//    for (int i = 0; i < width; i++) {
//        for (int j = 0; j < height; j++) {
//            delete cells[i][j];
//        }
//        delete[] cells[i];
//    }
//    delete[] cells;
    
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }
    delete[] cells;
 
    cells = other.cells;
    width = other.width;
    height = other.height;
    entrance_X = other.entrance_X;
    entrance_Y = other.entrance_Y;
    exit_X = other.exit_X;
    exit_Y = other.exit_Y;
 
    other.cells = nullptr;
    other.width = 0;
    other.height = 0;
    other.entrance_X = 0;
    other.entrance_Y = 0;
    other.exit_X = 0;
    other.exit_Y = 0;
 
    return *this;
}
 
GameField::~GameField() {
    std::cout << "dest\n";
    for (int i = 0; i < width; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}
 
Cell& GameField::getCell(int x, int y){
    return cells[x][y];
}
 
int GameField::getWidth(){
    return width;
}
 
int GameField::getHeight(){
    return height;
}
 
int GameField::getentrance_X(){
    return entrance_X;
}
 
int GameField::getentrance_Y(){
    return entrance_Y;
}
 
int GameField::getexit_X(){
    return exit_X;
}
 
int GameField::getexit_Y(){
    return exit_Y;
}
 
void GameField::setEntrance(int x , int y){
    if((x <= width && x >= ENTRANCE) && (y <= height && y >= ENTRANCE)){
        entrance_X = x;
        entrance_Y = y;
    }else{
        std::cout << "Неверная точка входа\n";
    }
}
 
void GameField::setExit(int x , int y){
    if((x <= width && x >= MIN_WIDTH_HEIGHT) && (y <= height && y >= MIN_WIDTH_HEIGHT)){
        exit_X = x;
        exit_Y = y;
    }else{
        std::cout << "Неверная точка выхода\n";
    }
}
