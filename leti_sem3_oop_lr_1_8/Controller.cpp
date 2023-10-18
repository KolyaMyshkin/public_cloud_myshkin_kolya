
//  Controller.cpp

#include "Controller.hpp"
#include <iostream>

void Controller::move(Move step) {
    switch (step) {
        case Move::Up:
            if (this->get_current_x() <= 0) {
                std::cout << "Out of bounds!\n";
            } else {
                if (this->get_current_x()-1 >= 0 &&
                    (gf.get_cell(this->get_current_x()-1,this->get_current_y())).get_is_Passable() == false) {
                    this->set_x(this->get_current_x()-1);
                } else {
                    std::cout << "Cell is not passiable!\n";
                }
            } 
            break;
        case Move::Down:
            if (this->get_current_x() >= this->gf.get_height()-1) {
                std::cout << "Out of bounds!\n";
            } else {
                if (this->get_current_x() + 1 < this->gf.get_height() &&
                    (gf.get_cell(this->get_current_x()+1,this->get_current_y())).get_is_Passable() == false) {
                    this->set_x(this->get_current_x()+1);
                } else {
                    std::cout << "Cell is not passiable!\n";
                }
            }
            // if (this->x >= this->height - 1) { 
            //     std::cout << "Out of bounds!\n";
            // } else {
            //     this->x++;
            // }
            break;
        case Move::Right:
            if (this->get_current_y() >= this->gf.get_width() - 1) {
                std::cout << "Out of bounds!\n";
            } else {
                if (this->get_current_y() + 1 < this->gf.get_width() &&
                    (gf.get_cell(this->get_current_x(),this->get_current_y()+1)).get_is_Passable() == false) {
                        this->set_y(this->get_current_y()+1);
                } else {
                    std::cout << "Cell is not passiable!\n";
                }
            }
            // if (this->y >= this->width - 1) { 
            //     std::cout << "Out of bounds!\n";
            // } else {
            //     this->y++;
            // }
            break;
        case Move::Left:
            if (this->get_current_y() <= 0) {
                std::cout << "Out of bounds!\n";
            } else {
                if (this->get_current_y()-1 >= 0 &&
                    (gf.get_cell(this->get_current_x(),this->get_current_y()-1)).get_is_Passable() == false) {
                        this->set_y(this->get_current_y()-1);
                } else {
                        std::cout << "Cell is not passiable!\n";
                }
            }



            // if (this->y <= 0) {
            //     std::cout << "Out of bounds!\n";
            // } else {
            //     this->y--;
            // }
            break;
    }
}

Controller::Controller(Player& player, GameField& GF): player(player), gf(GF) {
    this->current_x = GF.get_entrance_x();
    this->current_y = GF.get_entrance_y();    
}  //: player(player), x(0), y(0), height(height), width(width) {}



int Controller::get_current_x() {
    return this->current_x;
}

int Controller::get_current_y() {
    return this->current_y;
}

// void Controller::set_x(int new_x) {
//     if (new_x >= 0 && new_x <= this->height-1) this->x = new_x;
//     else std::cout << "Invalid X!\n";
// }

void Controller::set_x(int new_x) {
    if (new_x >= 0 && new_x <= this->gf.get_height()-1) {
        this->current_x = new_x;
    } else {
        std::cout << "Invalid X!\n";
    }
}

// void Controller::set_y(int new_y) {
//     if (new_y >= 0 && new_y <= this->width-1) this->y = new_y;
//     else std::cout << "Invalid Y!\n";
// }

void Controller::set_y(int new_y) {
    if (new_y >= 0 && new_y <= this->gf.get_width()-1) {
        this->current_y = new_y;
    } else {
        std::cout << "Invalid Y!\n";
    }
}


void Controller::change_player_money(int difference_money) {
    int new_money = this->player.get_player_money() + difference_money;
    this->player.set_player_money(new_money);
}

void Controller::change_player_health(int difference_health) {
    int new_health = this->player.get_player_health() + difference_health;
    this->player.set_player_health(new_health);
}

void Controller::change_player_points(int difference_points) {
    int new_points = this->player.get_player_points() + difference_points;
    this->player.set_player_points(new_points);
}

void Controller::print_game() {
    for (int i = 0; i < this->gf.get_height(); i++) {
        for (int j = 0; j < this->gf.get_width(); j++) {
            if (i == this->gf.get_entrance_x() && j == this->gf.get_entrance_y()) {
                if (i == this->get_current_x() && j == this->get_current_y()) {
                    std::cout << "@" << " ";
                } else {
                    std::cout << "S" << " ";
                }      
            }
            else if (i == this->gf.get_exit_x() && j == this->gf.get_exit_y()) {
                if (i == this->get_current_x() && j == this->get_current_y()) {
                    std::cout << "@" << " ";
                } else {
                    std::cout << "F" << " ";
                }
            }
            else if (i == this->get_current_x() && j == this->get_current_y()) {
                std::cout << "@" << " ";
            } else {
                if ((this->gf.get_cell(i,j)).get_is_Passable() != false) {
                    std::cout << '#' << " ";
                } else {
                    std::cout << '.' << " ";
                }
            }
        }
        std::cout << "\n";
    }
    std::cout << "(x: " << this->get_current_x() << ", y: " << this->get_current_y() << ")" << "   (hp: " << this->player.get_player_health() << ", mny: " << this->player.get_player_money() << ", pnts: " << this->player.get_player_points() << ")\n";
    return;
}