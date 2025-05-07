#ifndef POPQUIZ_H
#define POPQUIZ_H

#include "enemy.h"

using namespace std;

class PopQuiz : public Enemy {
public:
    PopQuiz();
    void attack() override;
    void generatePuzzle(Character &player) override;
};

#endif