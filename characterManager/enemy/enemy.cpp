#include "enemy.h"
#include <iostream>
#include <random>
#include <cstdlib>

using namespace std;

Enemy::Enemy(const string &n,
             int hp,
             int diff,
             const vector<pair<string,string>> &p)
  : name(n), health(hp), difficulty(diff), puzzles(p)
{
}

void Enemy::attack()
{
}

void Enemy::generatePuzzle(Character &player)
{
    int randomIndex = rand() % static_cast<int>(puzzles.size());
    pair<string,string> qa = puzzles[randomIndex];
    string question = qa.first;
    string answer   = qa.second;

    cout << name << " asks:\n"
         << question << "\nYour answer: ";

    string response;
    getline(cin, response);

    if (response == answer) {
        cout << "Correct! You deal extra damage.\n";
        player.heal();
        plusXP(player);
    } else {
        cout << "Wrong! The right answer was “" << answer << "”.\n";
        player.takeDamage();
    }
}

void Enemy::takeDamage(int damage, Character &player)
{
    health -= damage;
    cout << name << " took " << damage << " damage! ";
    if (health <= 0) {
        cout << name << " was defeated!\n";
        plusXP(player);
    } else {
        cout << "Remaining health: " << health << "\n";
    }
}

bool Enemy::isDefeated()
{
    return health <= 0;
}

string Enemy::getName()
{
    return name;
}

int Enemy::getDifficulty()
{
    return difficulty;
}
