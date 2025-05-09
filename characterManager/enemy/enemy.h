#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>
#include "Character.h"

using namespace std;

class Enemy {
protected:
    string name;
    int health;
    int difficulty;
    vector<pair<string,string>> puzzles;
    int xpGained;

public:
    Enemy(const string &n,
          int hp,
          int diff,
          const vector<pair<string,string>> &p);

    virtual ~Enemy() = default;

    virtual void attack() = 0;
    virtual bool generatePuzzle(Character &player) = 0;
    void takeDamage(int damage, Character &player);

    bool isDefeated();
    string getName();
    int getDifficulty();
    int getXPGained();
};

#endif
