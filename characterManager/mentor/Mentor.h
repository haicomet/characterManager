#ifndef MENTOR_H
#define MENTOR_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Mentor
{
private:
    string name;
    string guild;
    string bio;
    string hint;

public:
    Mentor();
    Mentor(const string &name, const string &guild, const string &bio, const string &hint);

    string getName();
    string getGuild();
    string getBio();
    string getHint();

    void displayBio();
    void displayHint();

    friend vector<Mentor> loadMentors();
};

vector<Mentor> loadMentors();

#endif