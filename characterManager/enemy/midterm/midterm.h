#ifndef MIDTERM_H
#define MIDTERM_H

#include "enemy.h"

using namespace std;

class Midterm : public Enemy {
public:
    Midterm();
    void attack() override;
    void generatePuzzle(Character &player) override;
};

#endif
