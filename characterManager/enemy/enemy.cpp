#include "Enemy.h"
#include <iostream>
#include <random>
using namespace std;

Enemy::Enemy(const string &n, int hp, int diff,
             const vector<pair<string, string>> &p)
    : name(n), health(hp), difficulty(diff), puzzles(p)
{
}

void Enemy::attack() const
{
}

void Enemy::generatePuzzle() const
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, puzzles.size() - 1);
    auto [question, answer] = puzzles[dis(gen)];

    cout << name << " asks:\n"
              << question << "\nYour answer: ";

    string response;
    getline(cin, response);

    if (response == answer)
        cout << "Correct! You deal extra damage.\n";
    else
        cout << "Wrong! The right answer was “"
                  << answer << "”.\n";
}

void Enemy::takeDamage(int damage)
{
    health -= damage;
    cout << name << " took " << damage << " damage! ";
    if (health <= 0)
        cout << name << " was defeated!\n";
    else
        cout << "Remaining health: " << health << "\n";
}

bool Enemy::isDefeated() const { return health <= 0; }
string Enemy::getName() const { return name; }
int Enemy::getDifficulty() const { return difficulty; }
