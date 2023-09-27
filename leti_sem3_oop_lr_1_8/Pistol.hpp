
//  Pistol.hpp

#ifndef Pistol_hpp
#define Pistol_hpp

#include <stdio.h>
#include "Weapon.hpp"

class Pistol:public Weapon{
public:
    Pistol(std::string name, int damage, int radius): Weapon(name, damage, radius) {};
};

#endif /* Pistol_hpp */
