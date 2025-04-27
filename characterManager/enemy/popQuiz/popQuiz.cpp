#include "popQuiz.h"
#include <iostream>

PopQuiz::PopQuiz()
  : Enemy("Pop Quiz", 20, 2, {
        {"Is C++ an object-oriented language? (Y/N)", "Y"},
        {"True or False: In C++, 0 is treated as false. (T/F)", "T"},
        {"Do you need <vector> to use std::vector? (Y/N)", "Y"},
        {"True or False: A function in C++ can directly return multiple values. (T/F)", "F"},
        {"Is `int main()` mandatory in every C++ program? (Y/N)", "Y"}
    })
{}

void PopQuiz::attack() const {
    std::cout << "Pop Quiz ambushes you with true/false questions!\n";
}
