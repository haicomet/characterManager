#include "finalExam.h"
#include <iostream>

FinalExam::FinalExam()
    : Enemy("Final Exam", 100, 5,{
        {"Which of the following is a correct variable declaration?\nA) int 1x;\nB) int x;\nC) int x = 'Hello';", "B"},
        {"What symbol is used to end a statement in C++?\nA) ,\nB) :\nC) ;", "C"},
        {"Which data type is used to store decimal numbers?\nA) int\nB) float\nC) char", "B"},
        {"Which keyword is used to create a loop that repeats until a condition is false?\nA) if\nB) while\nC) switch", "B"},
        {"Which operator is used for assignment?\nA) =\nB) ==\nC) !=", "A"},
        {"Which function is the entry point of every C++ program?\nA) start()\nB) main()\nC) init()", "B"},
        {"What is the output of: cout << 2 + 3 * 4?\nA) 20\nB) 14\nC) 24", "B"},
        {"Which of these is not a loop structure?\nA) for\nB) until\nC) do-while", "B"},
        {"What is used to store a sequence of characters?\nA) string\nB) bool\nC) int", "A"},
        {"What is the result of 10 % 3?\nA) 1\nB) 3\nC) 0", "A"},
        {"Which keyword is used to define a constant?\nA) final\nB) const\nC) static", "B"},
        {"What will this return: sizeof(char)?\nA) 2\nB) 0\nC) 1", "C"},
        {"Which line correctly gets input from the user?\nA) cout >> x;\nB) cin >> x;\nC) scanf(x);", "B"},
        {"What is the purpose of 'if' statements?\nA) Repeat code\nB) Test conditions\nC) Define variables", "B"},
        {"Which of these is used to group related code and variables?\nA) array\nB) class\nC) for loop", "B"},
        {"What does 'return 0;' mean in main()?\nA) Error occurred\nB) Program ended successfully\nC) Infinite loop", "B"},
        {"Which type stores only true or false?\nA) bool\nB) char\nC) double", "A"},
        {"What is the extension of a C++ source file?\nA) .txt\nB) .cpp\nC) .doc", "B"},
        {"Which keyword is used to define a function that does not return anything?\nA) return\nB) void\nC) int", "B"},
        {"Which container type allows storing multiple values of the same type?\nA) loop\nB) class\nC) array", "C"}
    })
{xpGained = 4;}

void FinalExam::attack() {
    std::cout << "Final Exam challenges your mastery of C++!\n";
}

bool FinalExam::generatePuzzle(Character &player) {
    return Enemy::generatePuzzle(player);
}
