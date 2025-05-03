#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>
#include <memory>
#include "Mentor.h"
using namespace std;

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

    static std::vector<std::shared_ptr<Mentor>> allMentors;
    std::vector<std::shared_ptr<Mentor>> unlockedMentors;

public:
    Character(const std::string &name);
    void setGuild(const std::string &guildName);
    void setBg();
    void setIdentity();
    void setRace();
    void boostStats(int g, int l, int c);
    void setConfidence(int c);
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
    static void loadAllMentors();
    void unlockMentor();
    const std::vector<std::shared_ptr<Mentor>>& getUnlockedMentors() const;
};

#endif
