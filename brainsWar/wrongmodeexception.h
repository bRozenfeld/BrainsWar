#ifndef WRONGMODEEXCEPTION_H
#define WRONGMODEEXCEPTION_H

#include<iostream>
#include<exception>

class WrongModeException : public std::exception
{
public:
    WrongModeException();
    const char * what() { return "Game mode invalid !"; };
};

#endif // WRONGMODEEXCEPTION_H
