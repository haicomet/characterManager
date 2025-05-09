#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <memory>
#include "Mentor.h"

using namespace std;

class Character {
private:
    string name;
    string guild;
    string background;
    string identity;
    string race;

    int grit;
    int logic;
    int confidence;

    int xp;
    int level;
    int xpGained;
    int toLvlUp;

    double gpa;

    static vector<shared_ptr<Mentor>> allMentors;
    vector<shared_ptr<Mentor>> unlockedMentors;

public:
    Character(const string &name);
    void setGuild(const string &guildName);
    void setBg();
    void setIdentity();
    void setRace();
    void boostStats(int g, int l, int c);
    void setConfidence(int c);
    int getGrit();
    int getLogic();
    int getConfidence();
    int getLevel();
    void displayChar();
    void levelUp();
    void takeDamage();
    void heal();
    friend void plusXP(Character &c);
    void saveCharacter();
    void loadCharacter();
    static void loadAllMentors();
    void unlockMentor(bool showMessages = true);
    const vector<shared_ptr<Mentor>>& getUnlockedMentors() const;
    double getGPA() const;
};

#endif 
