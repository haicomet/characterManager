#ifndef POPQUIZ_H
#define POPQUIZ_H

#include "enemy.h"

using namespace std;

class PopQuiz : public Enemy {
public:
    PopQuiz();
    void attack() override;
    virtual bool generatePuzzle(Character &player) override;
};

#endif