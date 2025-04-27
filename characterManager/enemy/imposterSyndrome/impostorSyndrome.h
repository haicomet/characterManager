#ifndef IMPOSTORSYNDROME_H
#define IMPOSTORSYNDROME_H

#include "enemy.h"

class ImpostorSyndrome : public Enemy {
public:
    ImpostorSyndrome();
    void attack() const override;
};

#endif 
