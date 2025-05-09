#include "quiz.h"
#include <iostream>

Quiz::Quiz()
  : Enemy("Quiz", 30, 1, {
        {"T or F: In C++, keywords cannot be used as identifiers. (T/F)", "T"},
        {"Which operator gives you the address of a variable?\nA) *\nB) &\nC) %", "B"},
        {"T or F: std::string is part of the C++ standard library. (T/F)", "T"},
        {"Which header must you include to use std::cout?\nA) <vector>\nB) <map>\nC) <iostream>", "C"},
        {"T or F: C++ arrays know their own size at runtime. (T/F)", "F"},
        {"What does the following print: cout << 5 + 3; ?\nA) 53\nB) 8\nC) Error", "B"},
        {"Which keyword is used to define a constant in C++?\nA) let\nB) const\nC) define", "B"},
        {"What is the correct syntax to declare an integer variable?\nA) int x;\nB) x = int;\nC) integer x;", "A"},
        {"Which symbol is used for single-line comments?\nA) //\nB) /* */\nC) #", "A"},
        {"T or F: C++ uses semicolons to end statements. (T/F)", "T"},
        {"Which of the following is a valid function declaration?\nA) void func()\nB) func void()\nC) function func()", "A"},
        {"How do you start a loop that runs 5 times?\nA) for (int i = 0; i < 5; i++)\nB) for (i < 5; i++)\nC) loop 5", "A"},
        {"T or F: 'cin' is used for output. (T/F)", "F"},
        {"Which of the following data types can store decimal values?\nA) int\nB) double\nC) char", "B"},
        {"What is the output of: cout << 'A'; ?\nA) 65\nB) A\nC) 'A'", "B"},
        {"What is the default value of an uninitialized `int`?\nA) 0\nB) Garbage\nC) -1", "B"},
        {"T or F: Functions must always return a value. (T/F)", "F"},
        {"Which access specifier allows class members to be accessible from outside the class?\nA) private\nB) public\nC) protected", "B"},
        {"Which loop checks the condition before executing?\nA) do-while\nB) while\nC) both", "B"},
        {"T or F: A class in C++ is a blueprint for objects. (T/F)", "T"},
        {"Which of these is not a valid variable name?\nA) score\nB) 2ndPlace\nC) total_score", "B"},
        {"What is the size of `int` on most systems?\nA) 2 bytes\nB) 4 bytes\nC) 8 bytes", "B"},
        {"Which operator is used to access members of a pointer to an object?\nA) .\nB) ->\nC) &", "B"},
        {"T or F: `main()` can return void in standard C++. (T/F)", "F"},
        {"Which of these creates a string object?\nA) string s = \"hello\";\nB) s = string(\"hello\");\nC) both", "C"},
        {"What is the output of: cout << (3 > 2); ?\nA) 1\nB) true\nC) yes", "A"},
        {"Which of the following represents a character literal?\nA) 'A'\nB) \"A\"\nC) A", "A"},
        {"What keyword is used to exit a loop?\nA) end\nB) stop\nC) break", "C"},
        {"T or F: You can overload functions by changing parameter types. (T/F)", "T"},
        {"Which of these is not a primitive data type in C++?\nA) float\nB) bool\nC) string", "C"}
    })
{xpGained = 1;
}

void Quiz::attack() {
    std::cout << "Quiz throws multiple-choice questions at you!\n";
}

bool Quiz::generatePuzzle(Character &player) {
    return Enemy::generatePuzzle(player);
}

