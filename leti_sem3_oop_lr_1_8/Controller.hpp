
//  Controller.hpp

#ifndef Controller_hpp
#define Controller_hpp

#include "Player.hpp"
#include "GameField.hpp"

enum class Move{
    Up,
    Down,
    Left,
    Right
};

class Controller {
private:
    Player& player;
    GameField& gf;
    int current_x;
    int current_y;
public:
    Controller(Player& Player, GameField& GF);
    void move(Move step);
    int get_current_x();
    int get_current_y();
    void set_x(int new_x);
    void set_y(int new_y);

    void change_entrance(int new_entrance_x , int new_entrance_y);
    void change_exit(int new_exit_x , int new_exit_y);
    void print_game();

    void change_player_health(int difference_health);
    void change_player_money(int difference_money);
    void change_player_points(int difference_points);
};

#endif /* Controller_hpp */

