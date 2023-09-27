
//  Player.cpp

#ifndef Player_cpp
#define Player_cpp

#include <iostream>
#include <stdio.h>
#include "Player.hpp"

Player::Player(int Player_health, int Player_money, int Player_points){
    this->Player_health = Player_health;
    this->Player_money = Player_money;
    this->Player_points = Player_points;
//        this->Gun = new Pistol("PISTOL_NAME_USPS", PISTOL_USPS_DAMAGE, PISTOL_USPS_RADIUS);
    Pistol USPS = Pistol(PISTOL_NAME_USPS, PISTOL_USPS_DAMAGE, PISTOL_USPS_RADIUS);
    Pistol FIVE_SEVEN = Pistol(PISTOL_NAME_FIVE_SEVEN, PISTOL_FIVE_SEVEN_DAMAGE, PISTOL_FIVE_SEVEN_RADIUS);
    Pistol DESERT_EAGLE = Pistol(PISTOL_NAME_DESERT_EAGLE, PISTOL_DESERT_EAGLE_DAMAGE, PISTOL_DESERT_EAGLE_RADIUS);
    Map_Pistol[PISTOL_NAME_USPS] = USPS;
    Map_Pistol[PISTOL_NAME_FIVE_SEVEN] = FIVE_SEVEN;
    Map_Pistol[PISTOL_NAME_DESERT_EAGLE] = DESERT_EAGLE;
    this->Player_pistol = Map_Pistol[PISTOL_NAME_USPS];
};

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
    this->Player_money = Player_money;
}
void Player::set_Player_health(int Player_health) {
    this->Player_health = Player_health;
}
void Player::set_Player_points(int Player_points) {
    this->Player_points = Player_points;
}


#endif
