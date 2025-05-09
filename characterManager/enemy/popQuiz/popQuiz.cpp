#include "popQuiz.h"
#include <iostream>

PopQuiz::PopQuiz()
  : Enemy("Pop Quiz", 20, 2, {
        {"Is C++ an object-oriented language? (Y/N)", "a"},
        {"True or False: In C++, 0 is treated as false. (T/F)", "a"},
        {"Do you need <vector> to use std::vector? (Y/N)", "a"},
        {"True or False: A function in C++ can directly return multiple values. (T/F)", "a"},
        {"Is `int main()` mandatory in every C++ program? (Y/N)", "a"}
    })
{}

void PopQuiz::attack() {
    std::cout << "Pop Quiz ambushes you with true/false questions!\n";
}

void PopQuiz::generatePuzzle(Character &player) {
    Enemy::generatePuzzle(player);
}
