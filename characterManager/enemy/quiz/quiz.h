#ifndef QUIZ_H
#define QUIZ_H

#include "enemy.h"

class Quiz : public Enemy {
public:
    Quiz();
    void attack() const override;
};

#endif 
