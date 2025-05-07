#include "midterm.h"
#include <iostream>

Midterm::Midterm()
  : Enemy("Midterm", 60, 3, {
        {"Reverse this string: 'STEM'", "METS"},
        {"What is the result of 7 % 3?", "1"},
        {"What does RAM stand for?", "Random Access Memory"},
        {"Which operator is used for scope resolution in C++?", "::"},
        {"What keyword is used to declare a class in C++?", "class"}
    })
{}

void Midterm::attack() {
    std::cout << "Midterm hits you with an essay question!\n";
}

void Midterm::generatePuzzle(Character &player) {
    Enemy::generatePuzzle(player);
}
