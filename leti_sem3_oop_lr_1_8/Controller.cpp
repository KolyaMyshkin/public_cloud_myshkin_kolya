
//  Controller.cpp

#include "Controller.hpp"
#include <iostream>

void Controller::move(Move step) {
    switch (step) {
        case Move::Up:
            if (this->x <= 0) {
                std::cout << "Out of bounds!\n";
            } else {
                this->x--;
            } 
            break;
        case Move::Down:
            if (this->x >= this->height - 1) { 
                std::cout << "Out of bounds!\n";
            } else {
                this->x++;
            }
            break;
        case Move::Right:
            if (this->y >= this->width - 1) { 
                std::cout << "Out of bounds!\n";
            } else {
                this->y++;
            }
            break;
        case Move::Left:
            if (this->y <= 0) {
                std::cout << "Out of bounds!\n";
            } else {
                this->y--;
            }
            break;
    }
}

Controller::Controller(Player &player, int height, int width): player(player), x(0), y(0), height(height), width(width) {}

int Controller::get_x() {
    return this->x;
}

int Controller::get_y() {
    return this->y;
}

void Controller::set_x(int new_x) {
    if (new_x >= 0 && new_x <= this->height-1) this->x = new_x;
    else std::cout << "Invalid X!\n";
}

void Controller::set_y(int new_y) {
    if (new_y >= 0 && new_y <= this->width-1) this->y = new_y;
    else std::cout << "Invalid Y!\n";
}

void Controller::change_player_money(int difference_money) {
    int new_money = this->player.get_player_money() + difference_money;
    this->player.set_player_money(new_money);
}

void Controller::change_player_health(int difference_health) {
    int new_health = this->player.get_player_health() + difference_health;
    this->player.set_player_health(new_health);
}

void Controller::change_player_points(int difference_points) {
    int new_points = this->player.get_player_points() + difference_points;
    this->player.set_player_points(new_points);
}
