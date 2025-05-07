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

public:
    Enemy(const string &n,
          int hp,
          int diff,
          const vector<pair<string,string>> &p);

    virtual ~Enemy() = default;

    virtual void attack();

    virtual void generatePuzzle(Character &player);

    void takeDamage(int damage, Character &player);

    bool isDefeated();
    string getName();
    int getDifficulty();
};

#endif