#include "impostorSyndrome.h"
#include <iostream>

ImpostorSyndrome::ImpostorSyndrome()
  : Enemy("Impostor Syndrome", 50, 4, {
        {"T or F: C++ supports multiple inheritance. (T/F)", "a"},
        {"Which container provides FIFO access?\n"
         "A) std::stack\n"
         "B) std::queue\n"
         "C) std::vector", "a"},
        {"T or F: A lambda expression can capture local variables by reference. (T/F)", "a"},
        {"Which keyword deletes the copy constructor in C++11?\n"
         "A) delete\n"
         "B) override\n"
         "C) constexpr", "a"},
        {"T or F: std::array is a fixed-size container introduced in C++17. (T/F)", "a"}
    })
{xpGained = 5;}

void ImpostorSyndrome::attack() {
    std::cout << "Impostor Syndrome drains your confidence!\n";
}

bool ImpostorSyndrome::generatePuzzle(Character &player) {
    return Enemy::generatePuzzle(player);
}
