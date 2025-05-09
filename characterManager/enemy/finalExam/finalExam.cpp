#include "finalExam.h"
#include <iostream>

FinalExam::FinalExam()
    : Enemy("Final Exam", 100, 5, {
        {"T or F: Templates are instantiated at compile time. (T/F)", "a"},
        {"Which smart pointer holds sole ownership of a resource? A) shared_ptr B) unique_ptr C) weak_ptr", "a"},
        {"Which specifier marks a function as not throwing exceptions? (A) throw() (B) noexcept (C) throw(...)", "a"},
        {"T or F: C++17 introduced structured bindings. (T/F)", "a"},
        {"What is the syntax for deleting the copy constructor in C++11? e.g. MyClass(const MyClass&) = ?", "a"}
    })
{xpGained = 4;}

void FinalExam::attack() {
    std::cout << "Final Exam challenges your mastery of C++!\n";
}

bool FinalExam::generatePuzzle(Character &player) {
    return Enemy::generatePuzzle(player);
}
