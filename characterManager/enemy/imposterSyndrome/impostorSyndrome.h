#ifndef IMPOSTORSYNDROME_H
#define IMPOSTORSYNDROME_H

#include "enemy.h"
using namespace std;

class ImpostorSyndrome : public Enemy {
public:
    ImpostorSyndrome();
    void attack() override;
    virtual bool generatePuzzle(Character &player) override;
};

#endif
