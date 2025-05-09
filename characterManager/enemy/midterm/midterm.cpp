#include "midterm.h"
#include <iostream>

Midterm::Midterm()
  : Enemy("Midterm", 60, 3, {
        {"Reverse this string: 'STEM'", "a"},
        {"What is the result of 7 % 3?", "a"},
        {"What does RAM stand for?", "a"},
        {"Which operator is used for scope resolution in C++?", "a"},
        {"What keyword is used to declare a class in C++?", "a"}
    })
{}

void Midterm::attack() {
    std::cout << "Midterm hits you with an essay question!\n";
}

void Midterm::generatePuzzle(Character &player) {
    Enemy::generatePuzzle(player);
}
