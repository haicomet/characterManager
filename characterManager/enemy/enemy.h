#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>
#include <utility>
#include "Character.h"

using namespace std;

class Enemy {
protected:
    string name;
    int health;
    int difficulty;
    vector<pair<string,string>> puzzles;

public:
    Enemy(const string& name,
          int health,
          int difficulty,
          const vector<pair<string,string>>& puzzles);

    virtual ~Enemy() = default;

    virtual void attack() = 0;
    virtual void generatePuzzle(Character& player);
    void takeDamage(int damage, Character& player);
    bool isDefeated();
    string getName();
    int getDifficulty();
};

#endif 
