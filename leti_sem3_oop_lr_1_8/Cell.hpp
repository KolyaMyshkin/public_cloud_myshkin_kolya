
//  Cell.hpp

#ifndef Cell_hpp
#define Cell_hpp

class Cell{
    bool passable;
public:
    Cell() = default;
    Cell(bool isPassable);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    Cell(Cell&& other);
    Cell& operator=(Cell&& other);
    bool get_is_Passable();
    void set_Passable(bool value);
};

#endif /* Cell_hpp */
