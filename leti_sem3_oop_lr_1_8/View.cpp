#ifndef View_cpp
#define View_cpp

#include "View.hpp"

#include <iostream>

View::View(){};
View::~View(){};
void View::intro(GameField& GF) {
    int hig = -1, wid = -1;
    std::cout<< "Для начала игры необходимо задать размеры игрового поля\n";
    std::cout<< "Вы хотите иметь квалратное поле?\n";
    std::cout<< "Введите:[y/n]:";
    char p;
    std::cin >> p;
    if (p == 'y') {
        std::cout <<"--маленькое 10х10\n";
        std::cout <<"--среденее 15х15\n";
        std::cout <<"--большое 20х20\n";
        std::cout << "Если зададите не корректные данные, то поле будет принудительно создано размером 10х10\n";
        std::cout << "введите чилсло[10, 15, 20]:";
        std::cin >> wid;
        if (wid != 10 && wid != 15 and wid != 20) {
            hig = 10;
            wid = 10;
            std::cout << "!!!ОШИБКА!!! Размеры поля: 10х10\n";
        } else {
            int t = wid;
            hig = t;
            std::cout << "Размеры поля: " << wid << "x" << hig << "\n";
        }
    } else {
        std::cout << "Вы можете задать произвольные размеры игрового поля со следующими ограничениями:\n";
        std::cout << "--высота от 10 до 20(вкл)\n";
        std::cout << "--ширина от 10 до 20(вкл)\n";
        std::cout << "Если зададите не корректные данные, то поле будет принудительно создано размером 10х10\n";
        std::cout << "Введите ширину и высоту соответственно:";
        std::cin >> hig >> wid;
        if (hig < 10 || hig > 20 || wid < 10 || wid > 20) {
            hig = 10;
            wid = 10;
            std::cout << "!!!ОШИБКА!!! Размеры поля: 10х10\n";
        } else {
            std::cout << "Размеры поля: " << hig << "x" << wid << "\n";
        }
    }
    GF = GameField(hig,wid);
    return;
}


#endif 
