
//  Weapon.cpp

#ifndef Weapon_cpp
#define Weapon_cpp

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string name, int damage, int radius) {
    this->name = name;
    this->damage = damage;
    this->radius = radius;
};

void Weapon::set_name(std::string name) {
    this->name = name;
}
void Weapon::set_damage(int damage) {
    this->damage = damage;
}
void Weapon::set_radius(int radius) {
    this->radius = radius;
}
std::string Weapon::get_name() {
    return this->name;
}
int Weapon::get_damage() {
    return this->damage;
}
int Weapon::get_radius() {
    return this->radius;
}

Weapon::~Weapon() {};

#endif
