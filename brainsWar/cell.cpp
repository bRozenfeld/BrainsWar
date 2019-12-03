#include "cell.h"

Cell::Cell(int x, int y)
{
    m_x = x;
    m_y = y;
    m_name = "";
    if(x==0) m_name += "A";
    else if (x==1) m_name += "B";
    else if (x==2) m_name += "C";
    else if (x==3) m_name += "D";
    else if (x==4) m_name += "E";
    else if (x==5) m_name += "F";
    else if (x==6) m_name += "G";
    else if (x==7) m_name += "H";
    if(y==0) m_name += "8";
    else if (y==1) m_name += "7";
    else if (y==2) m_name += "6";
    else if (y==3) m_name += "5";
    else if (y==4) m_name += "4";
    else if (y==5) m_name += "3";
    else if (y==6) m_name += "2";
    else if (y==7) m_name += "1";

}

Cell::Cell(const Cell &c)
{
    m_x = c.m_x;
    m_y = c.m_y;
    m_name = c.m_name;
}

std::string Cell::toString()
{
    std::string s_x = std::to_string(m_x);
    std::string s_y = std::to_string(m_y);
    return m_name + ": [" + s_x + "," + s_y + "]";
}


bool Cell::operator==(const Cell &c)
{
    return m_x == c.m_x && m_y == c.m_y;
}
