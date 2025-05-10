#include "midterm.h"
#include <iostream>

Midterm::Midterm()
  : Enemy("Midterm", 60, 3, {
        {"What does RAM stand for?\nA) Random Access Memory\nB) Read Access Module\nC) Run After Main", "A"},
        {"What is the result of 7 % 3?\nA) 1\nB) 2\nC) 0", "B"},
        {"Which keyword is used to declare a constant in C++?\nA) const\nB) static\nC) define", "A"},
        {"What does the '++' operator do?\nA) Decreases a value by 1\nB) Adds 1 to a value\nC) Multiplies by 2", "B"},
        {"Which function is the entry point of a C++ program?\nA) start()\nB) init()\nC) main()", "C"},
        {"What does 'cout' do in C++?\nA) Reads user input\nB) Outputs text to the console\nC) Creates a file", "B"},
        {"Which symbol represents the 'logical AND' operator?\nA) &&\nB) ||\nC) &", "A"},
        {"Which of the following is a valid loop structure?\nA) repeat-until\nB) for\nC) foreach", "B"},
        {"What is the purpose of the return statement?\nA) Stop the program\nB) Output a value from a function\nC) Repeat a function", "B"},
        {"Which of the following is not a data type in C++?\nA) int\nB) string\nC) num", "C"},
        {"Which keyword is used to define a class?\nA) def\nB) object\nC) class", "C"},
        {"What is the correct way to comment a single line?\nA) # comment\nB) // comment\nC) /* comment */", "B"},
        {"What is the result of: 10 / 4 in integer division?\nA) 2\nB) 2.5\nC) 3", "C"},
        {"Which header is required to use 'cout'?\nA) <stdio.h>\nB) <iostream>\nC) <stream>", "B"},
        {"What is the file extension for a C++ source file?\nA) .cpp\nB) .ccs\nC) .exe", "A"},
        {"What is a function?\nA) A loop structure\nB) A reusable block of code\nC) A file name", "B"},
        {"What is the scope resolution operator in C++?\nA) ::\nB) .\nC) ->", "A"},
        {"What is the correct syntax for a for loop?\nA) for (int i = 0; i < 10; i++)\nB) for i in range(10)\nC) loop(i, 10)", "A"},
        {"Which container automatically resizes?\nA) array\nB) vector\nC) int", "B"},
        {"What does 'break' do inside a loop?\nA) Skips current iteration\nB) Ends the loop\nC) Pauses the loop", "B"}
    })
{xpGained = 2;
}

void Midterm::attack() {
    std::cout << "Midterm hits you with an essay question!\n";
}

bool Midterm::generatePuzzle(Character &player) {
    return Enemy::generatePuzzle(player);
}
