
//  Weapon.hpp

#ifndef Weapon_hpp
#define Weapon_hpp

#include <stdio.h>
#include <iostream>

class Weapon{
private:
    int damage;
    int radius;
    std::string name;
public:
    Weapon(std::string name, int damage, int radius);
    void set_damage(int damage);
    void set_radius(int radius);
    void set_name(std::string name);
    int get_damage();
    int get_radius();
    std::string get_name();
    ~Weapon();
};

#endif /* Weapon_hpp */

