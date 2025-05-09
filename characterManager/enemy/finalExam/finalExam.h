#ifndef FINALEXAM_H
#define FINALEXAM_H

#include "enemy.h"
using namespace std;

class FinalExam : public Enemy {
public:
    FinalExam();
    void attack() override;
    virtual bool generatePuzzle(Character &player) override;
};

#endif
