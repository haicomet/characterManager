#include "finalExam.h"
#include <iostream>

FinalExam::FinalExam()
  : Enemy("Final Exam", 100, 5, {
        {"True or False: In C++, you can overload functions by changing only the return type.", "F"},
        {"Which of these adds an element to the end of a std::vector?\n"
         "A) push_front()\n"
         "B) push_back()\n"
         "C) insert()", "B"},
        {"True or False: A virtual destructor in a base class ensures derived destructors are called.", "T"},
        {"Which keyword declares a compile-time constant in C++?\n"
         "A) const\n"
         "B) constexpr\n"
         "C) static", "B"},
        {"True or False: The && operator has higher precedence than || in C++.", "T"}
    })
{}

void FinalExam::attack() const {
    std::cout << "Final Exam unleashes a brutal problem set!\n";
}
