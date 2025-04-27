#include "quiz.h"
#include <iostream>

Quiz::Quiz()
  : Enemy("Quiz", 30, 1, {
        {"True or False: In C++, keywords cannot be used as identifiers. (T/F)", "T"},
        {"Which operator gives you the address of a variable?\n"
         "A) *\n"
         "B) &\n"
         "C) %", "B"},
        {"True or False: std::string is part of the C++ standard library. (T/F)", "T"},
        {"Which header must you include to use std::cout?\n"
         "A) <vector>\n"
         "B) <map>\n"
         "C) <iostream>", "C"},
        {"True or False: C++ arrays know their own size at runtime. (T/F)", "F"}
    })
{}

void Quiz::attack() const {
    std::cout << "Quiz throws multiple-choice questions at you!\n";
}
