#ifndef QUIZ_H
#define QUIZ_H

#include "enemy.h"

using namespace std;

class Quiz : public Enemy {
public:
    Quiz();
    void attack() override;
    virtual bool generatePuzzle(Character &player) override;
};

#endif
