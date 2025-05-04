#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>
#include <utility>
#include "Character.h"

class Enemy {
protected:
    std::string name;
    int health;
    int difficulty;
    std::vector<std::pair<std::string,std::string>> puzzles;

public:
    Enemy(const std::string& name,
          int health,
          int difficulty,
          const std::vector<std::pair<std::string,std::string>>& puzzles);

    virtual ~Enemy() = default;

    virtual void attack() = 0;
    virtual void generatePuzzle(Character& player);
    void takeDamage(int damage, Character& player);
    bool isDefeated();
    std::string getName();
    int getDifficulty();
};

#endif 
