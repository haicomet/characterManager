#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character{
private:
    string name, guild, background;
    int grit, logic, confidence;
public:
    Character(string);
    void setGuild(string);
    void setBg(string);
    void setStats(int,int,int);
    int getGrit();
    int getLogic();
    int getConfidence();
    void displayChar();
    
};

#endif
