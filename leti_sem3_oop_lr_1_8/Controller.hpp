
//  Controller.hpp

#ifndef Controller_hpp
#define Controller_hpp

#include "Player.hpp"

enum class Move{
    Up,
    Down,
    Left,
    Right
};

class Controller {
private:
    Player& player;
    int x;
    int y;
public:
    Controller(Player &Player);
    void move(Move step);
    int get_x();
    int get_y();
    void set_x(int new_x);
    void set_y(int new_y);
    void change_Player_health(int difference_health);
    void change_Player_money(int difference_money);
    void change_Player_points(int difference_points);
};

#endif /* Controller_hpp */

