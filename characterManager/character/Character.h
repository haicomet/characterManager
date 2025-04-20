#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character{
private:
    string name, guild, background;
    int grit,logic;
public:
    Character(string);
    void setGuild(string);
    void setBg(string);
    int getGrit();
    int getLogic();
    void displayChar();
    
};

#endif
