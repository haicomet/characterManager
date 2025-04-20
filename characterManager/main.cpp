#include <iostream>
#include <vector>
#include <map>
#include "Mentor/Mentor.h"

using namespace std;

int main()
{
    auto mentors = loadMentors();
    for (Mentor m : mentors)
    {
        cout << "[" << m.getGuild() << "] " 
             << "Name: " << m.getName() << "\n"
             << "Bio: " << m.getBio() << "\n"
             << "Hint: " << m.getHint() << "\n\n";
    }
    return 0;
}