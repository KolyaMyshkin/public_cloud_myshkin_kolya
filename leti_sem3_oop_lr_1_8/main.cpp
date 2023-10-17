
//  main.cpp

#include "Controller.hpp"
#include "Player.hpp"
#include "GameField.hpp"
#include "Intro.hpp"

#include <iostream>


int main(int argc, const char * argv[]) {
    int intro_h=-1,intro_w=-1;
    intro(intro_h,intro_w);
    Player player;
    Controller controller(player, intro_h, intro_w);
    // Controller controller(Player,hig,wid);
    // Controller controller(player);
    // std::cout << player.get_Player_health() << " " << player.get_Player_money() << " " << player.get_Player_points() << "\n";
    // std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    // controller.set_x(500);
    // std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    // controller.set_x(0);
    // controller.set_y(0);
    // std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    // controller.move(Move::Left);
    // std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    // controller.move(Move::Down);
    // controller.move(Move::Down);
    // controller.move(Move::Down);
    // std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    

    // задаю игровое поле
    GameField GF(intro_h, intro_w);
    GF.set_entrance(1,8);
    controller.set_x(1);
    controller.set_y(8);
    GF.set_exit(8,3);
    GF.get_cell(1, 1).set_Passable(1);
    GF.get_cell(1, 2).set_Passable(1);
    GF.get_cell(1, 3).set_Passable(1);
    GF.get_cell(1, 4).set_Passable(1);
    GF.get_cell(1, 1).set_Passable(1);
    GF.get_cell(3, 3).set_Passable(1);
    GF.get_cell(2, 2).set_Passable(1);
    GF.get_cell(2, 1).set_Passable(1);
    GF.GF_print(controller,player);

    std::cout << "\n------------------------------\n";

    GameField GF1(4,4);
    GF1 = GF;

    // GF1.GF_print(controller,player); 

    std::cout << "\n------------------------------\n";

    // GameField GF2 = GF; /// 111
    
    // GF2.GF_print(controller,player);

    // std::cout << "\n------------------------------\n";

    // GameField GF3(4,4);

    // GF3 = GF; /// 222
    
    // GF3.GF_print(controller,player);
    
    // std::cout << "\n------------------------------\n";

    // GameField GF4(4,4);

    // GF4(GF);

    // std::cout << "\n------------------------------\n";


    // GF.set_entrance(1,8);
    // controller.set_x(1);
    // controller.set_y(8);
    // GF.set_exit(8,3);
    // GF.get_cell(1, 1).set_Passable(1);
    // GF.get_cell(1, 2).set_Passable(1);
    // GF.get_cell(1, 3).set_Passable(1);
    // GF.get_cell(1, 4).set_Passable(1);
    // GF.get_cell(1, 1).set_Passable(1);
    // GF.get_cell(3, 3).set_Passable(1);
    // GF.get_cell(2, 2).set_Passable(1);
    // GF.get_cell(2, 1).set_Passable(1);
    // GF.GF_print(controller,player);
    // char c = ' ';
    // while ((controller.get_x() != GF.get_exit_x() ||  controller.get_y() != GF.get_exit_y()) && std::cin >> c) {
    //     if (controller.get_x() == GF.get_exit_x() && controller.get_y() == GF.get_exit_y()) {
            
    //         break;
    //     } else {
    //         if (c == 'a') {
    //             controller.move(Move::Left);
    //         } else if (c == 'd') {
    //             controller.move(Move::Right);
    //         } else if (c == 'w') {
    //             controller.move(Move::Up);
    //         } else if (c == 's') {
    //             controller.move(Move::Down);
    //         }
    //         GF.GF_print(controller,player);
    //     }
    // }    
    // std::cout << "Вы дошли до финиша!!!\n";
    // std::cout << GF.get_entrance_x() << " " << GF.get_entrance_y() << "\n";
    // std::cout << GF.get_exit_x() << " " << GF.get_exit_y() << "\n";

    return 0;
}

