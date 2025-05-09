#include "quiz.h"
#include <iostream>

Quiz::Quiz()
  : Enemy("Quiz", 30, 1, {
        {"T or F: In C++, keywords cannot be used as identifiers. (T/F)", "a"},
        {"Which operator gives you the address of a variable?\n"
         "A) *\n"
         "B) &\n"
         "C) %", "B"},
        {"T or F: std::string is part of the C++ standard library. (T/F)", "a"},
        {"Which header must you include to use std::cout?\n"
         "A) <vector>\n"
         "B) <map>\n"
         "C) <iostream>", "a"},
        {"T or F: C++ arrays know their own size at runtime. (T/F)", "a"}
    })
{}

void Quiz::attack() {
    std::cout << "Quiz throws multiple-choice questions at you!\n";
}

bool Quiz::generatePuzzle(Character &player) {
    return Enemy::generatePuzzle(player);
}
