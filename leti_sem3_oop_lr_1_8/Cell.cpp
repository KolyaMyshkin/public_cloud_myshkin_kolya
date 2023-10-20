
//  Cell.cpp

#include "Cell.hpp"

#include <iostream>

Cell::Cell(bool isPassable) : passable(isPassable){}
 
Cell::Cell(const Cell& other) : passable(other.passable){}
 
Cell& Cell::operator=(const Cell& other){
    // if(this == &other){
    //     return *this;
    // }
    passable = other.passable;
    return *this;
}
 
Cell::Cell(Cell&& other) : passable(other.passable){}
 
Cell& Cell::operator=(Cell&& other){
    if(this == &other){
        return *this;
    }
    passable = other.passable;
    return *this;
}
 
bool Cell::get_is_Passable(){
    return passable;
}
 
void Cell::set_Passable(bool value) {
    passable = value;
}
