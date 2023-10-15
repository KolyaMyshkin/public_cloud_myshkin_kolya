
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
    int height;
    int width;
public:
    Controller(Player &Player, int height, int width);
    void move(Move step);
    int get_x();
    int get_y();
    void set_x(int new_x);
    void set_y(int new_y);
    void change_player_health(int difference_health);
    void change_player_money(int difference_money);
    void change_player_points(int difference_points);
};

#endif /* Controller_hpp */

