#include "popQuiz.h"
#include <iostream>

PopQuiz::PopQuiz()
  : Enemy("Pop Quiz", 20, 2, {
        {"Is C++ an object-oriented language? (Y/N)", "Y"},
        {"True or False: In C++, 0 is treated as false. (T/F)", "T"},
        {"Do you need <vector> to use std::vector? (Y/N)", "Y"},
        {"True or False: A function in C++ can directly return multiple values. (T/F)", "F"},
        {"Is `int main()` mandatory in every C++ program? (Y/N)", "Y"},
        {"Which of these initializes a string?\nA) string s = \"Hello\";\nB) s = String(\"Hello\");\nC) String s = Hello;", "A"},
        {"What does 'endl' do in cout?\nA) Ends the file\nB) Adds a newline\nC) Ends logic", "B"},
        {"Which of the following is a correct if-statement?\nA) if x > 3\nB) if (x > 3)\nC) if x > 3 then", "B"},
        {"True or False: You must always use using namespace std; to use cout. (T/F)", "F"},
        {"What value does an uninitialized int variable contain?\nA) 0\nB) Garbage/Unknown\nC) NULL", "B"}
    })
{xpGained = 3;}

void PopQuiz::attack() {
    std::cout << "Pop Quiz ambushes you with true/false questions!\n";
}

bool PopQuiz::generatePuzzle(Character &player) {
    return Enemy::generatePuzzle(player);
}
