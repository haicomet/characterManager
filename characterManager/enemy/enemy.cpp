#include "enemy.h"
#include <iostream>
#include <random>
#include <cstdlib>

Enemy::Enemy(const std::string &n,
             int hp,
             int diff,
             const std::vector<std::pair<std::string,std::string>> &p)
  : name(n), health(hp), difficulty(diff), puzzles(p)
{
}

void Enemy::attack()
{
}

void Enemy::generatePuzzle(Character& player)
{
    int randomIndex = rand() % static_cast<int>(puzzles.size());

    std::pair<std::string,std::string> qa = puzzles[randomIndex];
    std::string question = qa.first;
    std::string answer   = qa.second;

    std::cout << name << " asks:\n"
              << question << "\nYour answer: ";

    std::string response;
    std::getline(std::cin, response);

    if (response == answer){
        std::cout << "Correct! You deal extra damage.\n";
        player.heal();
        plusXP(player);
    }
    else{
        std::cout << "Wrong! The right answer was “" << answer << "”.\n";
        player.takeDamage();
    }
}

void Enemy::takeDamage(int damage,Character& player)
{
    health -= damage;
    std::cout << name << " took " << damage << " damage! ";
    if (health <= 0){
        std::cout << name << " was defeated!\n";
        plusXP(player);
    }
    else
        std::cout << "Remaining health: " << health << "\n";
}

bool Enemy::isDefeated()
{
    return health <= 0;
}

std::string Enemy::getName()
{
    return name;
}

int Enemy::getDifficulty()
{
    return difficulty;
}
