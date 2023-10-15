
//  Player.cpp

#ifndef Player_cpp
#define Player_cpp

#define MAX_HP 100

#define MIN_HP 0
#define MIN_MONEY 0
#define MIN_POINTS 0

#include <iostream>
#include <stdio.h>
#include "Player.hpp"

Player::Player() : player_health(MAX_HP), player_money(MIN_MONEY), player_points(MIN_POINTS) {};

int Player::get_player_health() {
    return this->player_health;
}
int Player::get_player_money() {
    return this->player_money;
}
int Player::get_player_points() {
    return this->player_points;
}
void Player::set_player_money(int Player_money) {
    if (Player_money < MIN_MONEY) this->player_money = MIN_MONEY;
    else this->player_money = Player_money;
}
void Player::set_player_health(int Player_health) {
    if (Player_health < MIN_HP) this->player_health = MIN_HP;
    else if (Player_health > MAX_HP) this->player_health = MAX_HP;
    else this->player_health = Player_health;
}
void Player::set_player_points(int Player_points) {
    if (Player_points < MIN_POINTS) this->player_points = MIN_POINTS;
    else this->player_points = Player_points;
}


#endif

