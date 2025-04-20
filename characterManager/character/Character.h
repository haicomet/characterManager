#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Character{
private:
    string name, guild, background, identity;
    int grit, logic, confidence;
public:
    Character(string);
    void setGuild(string);
    void setBg();
    void setIdentity();
    void setStats(int,int,int);
    int getGrit();
    int getLogic();
    int getConfidence();
    void displayChar();
    
};

#endif
