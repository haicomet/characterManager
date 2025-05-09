#include "impostorSyndrome.h"
#include <iostream>

ImpostorSyndrome::ImpostorSyndrome()
  : Enemy("Impostor Syndrome", 50, 4, {
        {"What is the correct way to declare an integer variable?\nA) int = x;\nB) int x;\nC) x int;", "b"},
        {"Which symbol is used to access members of a pointer to an object?\nA) .\nB) ->\nC) &", "b"},
        {"Which loop is guaranteed to execute at least once?\nA) for loop\nB) while loop\nC) do-while loop", "c"},
        {"What is the default return type of a function if none is specified?\nA) void\nB) int\nC) undefined", "b"},
        {"Which operator is used for comparison?\nA) =\nB) ==\nC) !=", "b"},
        {"What is the output of: cout << 5 / 2; ?\nA) 2.5\nB) 2\nC) 2.0", "b"},
        {"What is the purpose of 'cin' in C++?\nA) Output data\nB) Read input from user\nC) Declare constants", "b"},
        {"Which of the following is used to include standard libraries?\nA) #import\nB) include()\nC) #include", "c"},
        {"Where do local variables get stored?\nA) Heap\nB) Stack\nC) CPU", "b"},
        {"What is the correct syntax to define a function that returns nothing?\nA) void myFunction() {}\nB) int myFunction[]\nC) none myFunction()", "a"}
    })
{xpGained = 5;}

void ImpostorSyndrome::attack() {
    std::cout << "Impostor Syndrome drains your confidence!\n";
}

bool ImpostorSyndrome::generatePuzzle(Character &player) {
    return Enemy::generatePuzzle(player);
}
