#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include "Mentor.h"
using namespace std;

class Character{
private:
    string name, guild, background, identity, race;
    int grit, logic, confidence;
    int xp, level, xpGained, toLvlUp;
    double gpa;
    vector<Mentor> mentorList, unlockedMentors;
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
    double getGPA();
    void takeDamage();
    void heal();
    friend void plusXP(Character&);
    void saveCharacter();
    void loadCharacter();
    void getMentorList();
    void unlockMentor();
    void displayUnlockedMentors();
};

#endif
