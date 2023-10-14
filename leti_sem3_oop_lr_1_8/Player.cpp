
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

Player::Player() : Player_health(MAX_HP), Player_money(MIN_MONEY), Player_points(MIN_POINTS) {};
//     this->Gun = new Pistol("PISTOL_NAME_USPS", PISTOL_USPS_DAMAGE, PISTOL_USPS_RADIUS);
//     Pistol USPS = Pistol(PISTOL_NAME_USPS, PISTOL_USPS_DAMAGE, PISTOL_USPS_RADIUS);
//     Pistol FIVE_SEVEN = Pistol(PISTOL_NAME_FIVE_SEVEN, PISTOL_FIVE_SEVEN_DAMAGE, PISTOL_FIVE_SEVEN_RADIUS);
//     Pistol DESERT_EAGLE = Pistol(PISTOL_NAME_DESERT_EAGLE, PISTOL_DESERT_EAGLE_DAMAGE, PISTOL_DESERT_EAGLE_RADIUS);
//     Map_Pistol[PISTOL_NAME_USPS] = USPS;
//     Map_Pistol[PISTOL_NAME_FIVE_SEVEN] = FIVE_SEVEN;
//     Map_Pistol[PISTOL_NAME_DESERT_EAGLE] = DESERT_EAGLE;
//     this->Player_pistol = Map_Pistol[PISTOL_NAME_USPS];
// };

int Player::get_Player_health() {
    return this->Player_health;
}
int Player::get_Player_money() {
    return this->Player_money;
}
int Player::get_Player_points() {
    return this->Player_points;
}
void Player::set_Player_money(int Player_money) {
    if (Player_money < MIN_MONEY) this->Player_money = MIN_MONEY;
    else this->Player_money = Player_money;
}
void Player::set_Player_health(int Player_health) {
    if (Player_health < MIN_HP) this->Player_health = MIN_HP;
    else if (Player_health > MAX_HP) this->Player_health = MAX_HP;
    else this->Player_health = Player_health;
}
void Player::set_Player_points(int Player_points) {
    if (Player_points < MIN_POINTS) this->Player_points = MIN_POINTS;
    else this->Player_points = Player_points;
}


#endif

