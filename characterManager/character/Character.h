#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include "Mentor.h"

class Character {
private:
    std::string name;
    std::string guild;
    std::string background;
    std::string identity;
    std::string race;

    int grit;
    int logic;
    int confidence;

    int xp;
    int level;
    int xpGained;
    int toLvlUp;

    double gpa;

    std::vector<Mentor> mentorList;
    std::vector<Mentor> unlockedMentors;

public:
    Character(const std::string &name);
    void setGuild(const std::string &guildName);
    void setBg();
    void setIdentity();
    void setRace();
    void boostStats(int g, int l, int c);
    int getGrit();
    int getLogic();
    int getConfidence();
    void displayChar();
    void levelUp();
    void takeDamage();
    void heal();
    friend void plusXP(Character &c);
    void saveCharacter();
    void loadCharacter();
    void getMentorList();
    void unlockMentor();
    void displayUnlockedMentors();
};

#endif
