
//  main.cpp

#include "Controller.hpp"
#include "Player.hpp"
#include "GameField.hpp"
// #include "Intro.hpp"
#include "View.hpp"

#include <iostream>
#include <limits>
int main(int argc, const char * argv[]) {
    Player player;
    GameField GF;
    View v;
    v.intro(GF);
    Controller controller(player, GF);
    // Controller controller(player, GF, intro_h, intro_w);

    // задаю игровое поле 

    GF.set_entrance(1,4);
    controller.set_x(GF.get_entrance_x());
    controller.set_y(GF.get_entrance_y());
    GF.set_exit(5,5);
    GF.get_cell(1, 1).set_Passable(true);
    GF.get_cell(3, 3).set_Passable(true);
    GF.get_cell(2, 3).set_Passable(true);
    GF.get_cell(3, 2).set_Passable(true);
    GF.get_cell(2, 2).set_Passable(true);

    // std::cout <<"print GF:\n";
    // GF.GF_print(controller,player);

    // std::cout << "\n------------------------------\n";

    // копирование с помощью конструктора копирования
    // получается при копировании GF -> GF1 нам не важно какого размера GF, я просто должен сделать абсолютную копию GF
    // и при этом GF не теряет никаких своих качест(остается таким же каким и был)
    // на выходе имеем полностью совпадающие GF и GF1
    // GameField GF1(GF); // == GameField GF1(GF); // C Copy
    // std::cout <<"print GF1:\n";
    // GF1.GF_print(controller,player); 
    
    //копирование 
    // GameField GF1(GF);
    // GF1.GF_print(controller,player); 

    //копирование 
    // GameField GF2 = GF;
    // GF2.GF_print(controller,player);    

    // копирование  через = 
    // GameField GF3(10,10);
    // GF3 = GF;
    // GF3.GF_print(controller,player);    


    // перемещение через =
    // GameField f(10,10);
    // f = GameField(20,20);
    // f.GF_print(controller,player);

    // перемещение через конструтор (не работает)
    // GameField g(make());


    // std::cout << "\n------------------------------\n";

    // копирование с помощью оператора присванивания
    // здесь имеет занчение какого размера GF2 и GF, тк копирование поля GF будут просто накладываться на поля GF2
    // то есть у нас выоста и ширина GF должны совпадать с высотой и шириной GF2 соответственно
    // и при этом GF не теряет никаких своих качест(остается таким же каким и был)
    // на выходе имеем полностью совпадающие GF и GF1
    
    
    // GameField GF2(10,10); // Cons
    // std::cout <<"print GF2:\n";
    // GF2.GF_print(controller,player);
    
    // GF2 = GF; // Assig Copy // C Copy
    // std::cout <<"print GF2:\n";
    // GF2.GF_print(controller,player);

    // std::cout << "\n------------------------------\n";
    
    // конструктор перемещения 
    // здесь мы создаем новый экземпляр класса GF5, который должен перенять все данные из GF
    // при этом GF должен совободить память
    // GameField GF5(GF); // тут должен вызываться оператор присванивания с перемещением???????
    // std::cout <<"print GF2:\n";
    // GF5.GF_print(controller,player);

    // std::cout << "\n------------------------------\n";

    // оператор присванивания с перемещением 
    // здесь мы у сущетвующего элемента должны освободить память (очистить все ячейки)
    // и  установить ему новые значения нового поля

    // GF = GameField(20,20);// Cons // Assig Move // type = &&GameField
    // std::cout <<"print GF:\n";
    // GF.GF_print(controller,player);

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
    // while ((controller.get_current_x() != GF.get_exit_x() ||  controller.get_current_y() != GF.get_exit_y()) && std::cin >> c) {
    //     if (controller.get_current_x() == GF.get_exit_x() && controller.get_current_y() == GF.get_exit_y()) {
            
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



    controller.print_game();
    char c;
    while ((controller.get_current_x() != GF.get_exit_x() ||  controller.get_current_y() != GF.get_exit_y()) && std::cin >> c) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if (controller.get_current_x() == GF.get_exit_x() && controller.get_current_y() == GF.get_exit_y()) {
            break;
        } else {
            if (c == 'a') {
                controller.move(Move::Left);
            } else if (c == 'd') {
                controller.move(Move::Right);
            } else if (c == 'w') {
                controller.move(Move::Up);
            } else if (c == 's') {
                controller.move(Move::Down);
            }
            controller.print_game();
        }
    }    
    std::cout << "Вы дошли до финиша!!!\n";
    std::cout << GF.get_entrance_x() << " " << GF.get_entrance_y() << "\n";
    std::cout << GF.get_exit_x() << " " << GF.get_exit_y() << "\n";

    return 0;
}

