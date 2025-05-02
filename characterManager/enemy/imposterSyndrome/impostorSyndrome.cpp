#include "impostorSyndrome.h"
#include <iostream>

ImpostorSyndrome::ImpostorSyndrome()
  : Enemy("Impostor Syndrome", 50, 4, {
        {"T or F: C++ supports multiple inheritance. (T/F)", "T"},
        {"Which container provides FIFO access?\n"
         "A) std::stack\n"
         "B) std::queue\n"
         "C) std::vector", "B"},
        {"T or F: A lambda expression can capture local variables by reference. (T/F)", "T"},
        {"Which keyword deletes the copy constructor in C++11?\n"
         "A) delete\n"
         "B) override\n"
         "C) constexpr", "A"},
        {"T or F: std::array is a fixed-size container introduced in C++17. (T/F)", "F"}
    })
{}

void ImpostorSyndrome::attack() {
    std::cout << "Impostor Syndrome drains your confidence!\n";
}
