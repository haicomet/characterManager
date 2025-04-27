#ifndef POPQUIZ_H
#define POPQUIZ_H

#include "enemy.h"

class PopQuiz : public Enemy {
public:
    PopQuiz();
    void attack() const override;
};

#endif
