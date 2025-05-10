#include "enemy.h"
#include <iostream>
#include <random>
#include <cstdlib>
#include <fstream>
#include <cstdio>

using namespace std;

Enemy::Enemy(const string &n,
             int hp,
             int diff,
             const vector<pair<string, string>> &p)
    : name(n), health(hp), difficulty(diff), puzzles(p)
{
}

void Enemy::attack()
{
}

bool Enemy::generatePuzzle(Character &player)
{
    while (true)
    {

        int randomIndex = rand() % static_cast<int>(puzzles.size());
        pair<string, string> qa = puzzles[randomIndex];
        string question = qa.first;
        string answer = qa.second;

        cout << name << " asks:\n"
             << question << "\nYour answer: ";

        string response;
        getline(cin, response);

        for (char &c : response) c = toupper(c);
        if (response == answer)
        {
            cout << "Correct! You deal extra damage.\n";
            player.heal();
            return true;
        }
        else
        {
            cout << "Wrong answer. Your GPA dropped!\n";
            player.takeDamage();
        }
        
        if (player.getGPA() <= 0.0) {
            cout << "\nYou've failed the course. GPA hit 0. GAME OVER.\n";

            if (remove("characters.txt") == 0) {
                cout << "Your save file has been deleted.\n";
            } else {
                cout << "Failed to delete save file.\n";
            }

            return false;
        }
    }
}

void Enemy::takeDamage(int damage, Character &player)
{
    health -= damage;
    cout << name << " took " << damage << " damage! ";
    if (health <= 0)
    {
        cout << name << " was defeated!\n";
        plusXP(player);
    }
    else
    {
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

int Enemy::getXPGained()
{
    return xpGained;
}
