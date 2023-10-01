
//  Player.hpp

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <iostream>
#include <map>
//#include "Weapon.hpp"
//#include "Pistol.hpp"

#define PISTOL_NAME_USPS "USPS"
#define PISTOL_USPS_DAMAGE 10
#define PISTOL_USPS_RADIUS 5
#define PISTOL_NAME_FIVE_SEVEN "FIVE-SEVEN"
#define PISTOL_FIVE_SEVEN_DAMAGE 20
#define PISTOL_FIVE_SEVEN_RADIUS 5
#define PISTOL_NAME_DESERT_EAGLE "DESERT_EAGLE"
#define PISTOL_DESERT_EAGLE_DAMAGE 50
#define PISTOL_DESERT_EAGLE_RADIUS 5

class Player {
    int Player_health;
    int Player_money;
    int Player_points;
    // std::map <std::string, Pistol> Map_Pistol;
    // Pistol Player_pistol;
public:
//    Player(int Player_health, int Player_money, int Player_points);
    Player();
    int get_Player_health();
    int get_Player_money();
    int get_Player_points();
    
    void set_Player_health(int Player_health);
    void set_Player_money(int Player_money);
    void set_Player_points(int Player_points);
    // void set_Player_weapon(Weapon weapon);
    // ~Player();
};

#endif /* Player_hpp */
/*
 вопросы:
 -как добавить гранаты и игрока уставноку и показать значения?
 -надо ли делать гет и сет в гранате и оружии если все значения забаются потом?
 -как написать контроллер?
 -
 */

