#ifndef MENTOR_H
#define MENTOR_H

#include <string>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

class Mentor
{
protected:
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

    virtual void displayHint() = 0;
};

vector<shared_ptr<Mentor>> loadMentors();

#endif
