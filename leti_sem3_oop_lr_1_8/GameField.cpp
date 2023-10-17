
//  GameField.cpp

#include "GameField.hpp"

#include <iostream>
#define ENTRANCE 0
#define MIN_WIDTH_HEIGHT 0
// GameField::GameField() : width(MAX_WIDTH), height(MAX_HEIGHT),
// entrance_x(ENTRANCE), entrance_y(ENTRANCE), exit_x(MAX_WIDTH - 1), exit_y(MAX_HEIGHT - 1) {
//     cells = new Cell*[width];
//     for (int i = 0; i < width; i++) {
//         cells[i] = (Cell*)malloc(sizeof(Cell) * height);
//     }
//     exit_x = width - 1;
//     exit_y = height - 1;
// }
 
// GameField::GameField(int w, int h) : width(w), height(h),
// entrance_x(ENTRANCE), entrance_y(ENTRANCE), exit_x(MAX_WIDTH - 1), exit_y(MAX_HEIGHT - 1) {
//     if (w > MAX_WIDTH ||  w < MIN_WIDTH_HEIGHT || h > MAX_HEIGHT || h < MIN_WIDTH_HEIGHT) {
//         std::cout << "Неверные размеры поля, размеры будут установлены по умолчанию\n";
//         width = MAX_WIDTH;
//         height = MAX_HEIGHT;
//     }
//     cells = new Cell*[width];
//     for (int i = 0; i < width; i++) {
//         cells[i] = (Cell*)malloc(sizeof(Cell) * height);
//     }
 
//     exit_x = width - 1;
//     exit_y = height - 1;
// }

GameField::GameField(int h, int w) {
// : width(w), height(h),
// entrance_x(ENTRANCE), entrance_y(ENTRANCE), exit_x(height), exit_y(width) {
    
    // здесь сразу идут верные кординты
    // if (w > width ||  w < MIN_WIDTH_HEIGHT || h > height || h < MIN_WIDTH_HEIGHT) {
    //     std::cout << "Неверные размеры поля, размеры будут установлены по умолчанию\n";
    //     width = width;
    //     height = MAX_HEIGHT;
    // } // 
    this->width = w;
    this->height = h;
    this->entrance_x = ENTRANCE;
    this->entrance_y = ENTRANCE;
    this->exit_x = h;
    this->exit_y = w;

    this->cells = new Cell*[height];
    for (int i = 0; i < height; i++) {
        this->cells[i] = (Cell*)malloc(sizeof(Cell) * width);
    }
}
 
GameField::GameField(const GameField& other) {
    std::cout << "C Copy\n";
    this->width = other.width;
    this->height = other.height;
    this->entrance_x = other.entrance_x;
    this->entrance_y = other.entrance_y;
    this->exit_x = other.exit_x;
    this->exit_y = other.exit_y;
 
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            this->cells[i][j] = other.cells[i][j];
        }
    }
    
    // this->cells = new Cell*[height];
    // for (int i = 0; i < height; i++) {
    //     this->cells[i] = (Cell*)malloc(sizeof(Cell) * width);
    //     for (int j = 0; j < width; j++) {
    //         this->cells[i][j] = other.cells[i][j];
    //     }
    // }
}
 
GameField& GameField::operator=(const GameField& other){
    std::cout << "Assig Copy\n";
    if (this == &other) {
        return *this;
    }
    this->width = other.width;
    this->height = other.height;
    this->entrance_x = other.entrance_x;
    this->entrance_y = other.entrance_y;
    this->exit_x = other.exit_x;
    this->exit_y = other.exit_y;
 
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            this->cells[i][j] = other.cells[i][j];
        }
    }
    
    // this->cells = new Cell*[height];
    // for (int i = 0; i < height; i++) {
    //     this->cells[i] = (Cell*)malloc(sizeof(Cell) * width);
    //     for (int j = 0; j < width; j++) {
    //         this->cells[i][j] = other.cells[i][j];
    //     }
    // }
    return *this;
}
 
GameField::GameField(GameField&& other) {
// : cells(other.cells), width(other.width), height(other.height),
// entrance_x(other.entrance_x), entrance_y(other.entrance_y), exit_x(other.exit_x), exit_y(other.exit_y) {
    std::cout << "C Move\n";
    this->width = other.width;
    this->height = other.height;
    this->entrance_x = other.entrance_x;
    this->entrance_y = other.entrance_y;
    this->exit_x = other.exit_x;
    this->exit_y = other.exit_y;

    this->cells = new Cell*[height];
    for (int i = 0;i < height; i++) {
        this->cells[i] = (Cell*)malloc(sizeof(Cell) * width);
        for (int j = 0; j < width; j++) {
            this->cells[i][j] = other.cells[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        delete[] other.cells[i];
    }
    delete[] other.cells;

    other.width = 0;
    other.height = 0;
    other.entrance_x = 0;
    other.entrance_y = 0;
    other.exit_x = 0;
    other.exit_y = 0;
}
 
GameField& GameField::operator=(GameField&& other){
     std::cout << "Assig Move\n";
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < this->height; i++) {
        delete[] this->cells[i];
    }
    delete[] this->cells;

    this->width = other.width;
    this->height = other.height;
    this->entrance_x = other.entrance_x;
    this->entrance_y = other.entrance_y;
    this->exit_x = other.exit_x;
    this->exit_y = other.exit_y;

    this->cells = new Cell*[height];
    for (int i = 0;i < height; i++) {
        this->cells[i] = (Cell*)malloc(sizeof(Cell) * width);
        for (int j = 0; j < width; j++) {
            this->cells[i][j] = other.cells[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        delete[] other.cells[i];
    }
    delete[] other.cells;

    other.width = 0;
    other.height = 0;
    other.entrance_x = 0;
    other.entrance_y = 0;
    other.exit_x = 0;
    other.exit_y = 0;


    // for (int i = 0; i < height; i++) {
    //     delete[] cells[i];
    // }
    // delete[] cells;
 
    // cells = other.cells;
    // width = other.width;
    // height = other.height;
    // entrance_x = other.entrance_x;
    // entrance_y = other.entrance_y;
    // exit_x = other.exit_x;
    // exit_y = other.exit_y;
 
    // other.cells = nullptr;
    // other.width = 0;
    // other.height = 0;
    // other.entrance_x = 0;
    // other.entrance_y = 0;
    // other.exit_x = 0;
    // other.exit_y = 0;
 
    return *this;
}
 
GameField::~GameField() {
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
