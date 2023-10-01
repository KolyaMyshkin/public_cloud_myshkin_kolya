
//  Controller.cpp

#include "Controller.hpp"
#include <iostream>

#define MAX_HEIGHT 20
#define MAX_WEIGHT 20


Controller::Controller(Player &player): player(player), x(0), y(0) {}

void Controller::move(Move step) {
    switch (step) {
        case Move::Left:
            if (this->x <= 0) std::cout << "Out of bounds!\n";
            else this->x--;
            break;
        case Move::Right:
            if (this->x >=  MAX_WEIGHT - 1) std::cout << "Out of bounds!\n";
            else this->x++;
        case Move::Up:
            if (this->y >= MAX_HEIGHT - 1) std::cout << "Out of bounds!\n";
            else this->y++;
            break;
        case Move::Down:
            if (this->y <= 0) std::cout << "Out of bounds!\n";
            else this->y--;
            break;
    }
}

int Controller::get_x() {
    return this->x;
}

int Controller::get_y() {
    return this->y;
}

void Controller::set_x(int new_x) {
    if (new_x >= 0 && new_x < MAX_WEIGHT) this->x = new_x;
    else std::cout << "Invalid X!\n";
}

void Controller::set_y(int new_y) {
    if (new_y >= 0 && new_y < MAX_HEIGHT) this->y = new_y;
    else std::cout << "Invalid Y!\n";
}

void Controller::change_Player_money(int difference_money) {
    int new_money = this->player.get_Player_money() + difference_money;
    this->player.set_Player_money(new_money);
}

void Controller::change_Player_health(int difference_health) {
    int new_health = this->player.get_Player_health() + difference_health;
    this->player.set_Player_health(new_health);
}

void Controller::change_Player_points(int difference_points) {
    int new_points = this->player.get_Player_points() + difference_points;
    this->player.set_Player_points(new_points);
}
