
//  main.cpp

#include "Controller.hpp"
#include "Player.hpp"
#include "GameField.hpp"
#include <iostream>


int main(int argc, const char * argv[]) {
    Player player;
    Controller controller(player);
    

    player.set_Player_health(100);
    player.set_Player_money(0);
    player.set_Player_points(1);
    std::cout << player.get_Player_health() << " " << player.get_Player_money() << " " << player.get_Player_points() << "\n";

    controller.change_Player_health(-40);
    controller.change_Player_money(10000);
    controller.change_Player_points(12345);
    std::cout << player.get_Player_health() << " " << player.get_Player_money() << " " << player.get_Player_points() << "\n";
    std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    controller.set_x(500);
    std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    controller.set_x(0);
    controller.set_y(0);
    std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    controller.move(Move::Left);
    std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    controller.move(Move::Down);
    controller.move(Move::Down);
    controller.move(Move::Down);
    std::cout << controller.get_x() << " " << controller.get_y() << "\n";
    
    GameField GF;
    std::cout <<"Cуществует 3 вида полей:\n";
    std::cout <<"--маленькое 5х5\n";
    std::cout <<"--среденее 10х10\n";
    std::cout <<"--большое 15х15\n\n";
    std::cout << "введите чилсло:";
    
    int size_field;
    std::cin >> size_field;
    switch (size_field) {
        case 5:
            GF = GameField(5,5);
            break;
        case 10:
            GF = GameField(10,10);
            break;
        case 15:
            GF = GameField(15,15);
            break;
        default:
            break;
    }
    
    

    std::cout << GF.getHeight() << " " << GF.getWidth() << "\n";
    GF.setExit(12, 12);
    GF.setEntrance(0, 0);
    std::cout << GF.getentrance_X() << " " << GF.getentrance_Y() << "\n";
    std::cout << GF.getexit_X() << " " << GF.getexit_Y() << "\n";
    GF.setExit(70, 12);
    GF.setEntrance(0, 50);
    std::cout << GF.getexit_X() << " " << GF.getexit_Y() << "\n";
    std::cout << GF.getentrance_X() << " " << GF.getentrance_Y() << "\n";
    
    
    
    
    std::cout << GF.getHeight() << " " << GF.getWidth() << "\n";
    for (int i = 0; i < GF.getWidth(); i++) {
        for (int j = 0; j < GF.getHeight(); j++) {
            Cell k = GF.getCell(i, j);
            std::cout << k.get_isPassable() << " ";
        }
        std::cout << "\n";
    }
    
    GF.getCell(1, 1).set_Passable(1);
    GF.getCell(1, 2).set_Passable(1);
    GF.getCell(1, 3).set_Passable(1);
    GF.getCell(1, 4).set_Passable(1);
    GF.getCell(1, 1).set_Passable(1);
    GF.getCell(3, 3).set_Passable(1);
    GF.getCell(2, 2).set_Passable(1);
    GF.getCell(2, 1).set_Passable(1);
    
    std::cout << GF.getHeight() << " " << GF.getWidth() << "\n";
    
    for (int i = 0; i < GF.getWidth(); i++) {
        for (int j = 0; j < GF.getHeight(); j++) {
            if (i == GF.getentrance_X() && j == GF.getentrance_Y()) {
                if (i == controller.get_x() && j == controller.get_y()) {
                    std::cout << "@" << " ";
                } else {
                    std::cout << "S" << " ";
                }
                
            }
            else if (i == GF.getexit_X() && j == GF.getexit_Y()) {
                if (i == controller.get_x() && j == controller.get_y()) {
                    std::cout << "@" << " ";
                } else {
                    std::cout << "F" << " ";
                }
            }
            else if (i == controller.get_x() && j == controller.get_y()) {
                std::cout << "@" << " ";
            } else {
                Cell k = GF.getCell(i, j);
                std::cout << k.get_isPassable() << " ";
            }
        }
        std::cout << "\n";
    }

    
    return 0;
}

