#include "GeneralMentor.h"
#include <iostream>

using namespace std;

GeneralMentor::GeneralMentor(const string &name, const string &guild, const string &bio, const string &hint)
    : Mentor(name, guild, bio, hint) {}

void GeneralMentor::displayHint() {
    cout << name << "'s Advice: " << hint << "\n";
}
