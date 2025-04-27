#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Character{
private:
    string name, guild, background, identity, race;
    int grit, logic, confidence; //add gpa as health
    int xp, level, xpGained, toLvlUp;
public:
    Character(string);
    void setGuild(string);
    void setBg();
    void setIdentity();
    void setRace();
    void boostStats(int,int,int);
    int getGrit();
    int getLogic();
    int getConfidence();
    void displayChar();
    void levelUp();
    friend void plusXP(Character&);
    void saveCharacter();
    void loadCharacter();
    
};

#endif
