#ifndef CELL_H
#define CELL_H

#include<string>
#include<vector>

class Cell
{
public:
    Cell(int x, int y);
    Cell(const Cell &c); // copy constructor
    int getX() { return m_x; }
    int getY() { return m_y; }
    std::string getName() { return m_name; }
    void setName(std::string name) { m_name = name; }
    std::string toString();
    bool operator==(const Cell &c);
private:
    std::string m_name;
    int m_x;
    int m_y;
};

#endif // CELL_H
