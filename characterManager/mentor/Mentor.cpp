#include "Mentor.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Mentor::Mentor() : name(), guild(), bio(), hint() {}

Mentor::Mentor(
    const string &name,
    const string &guild,
    const string &bio,
    const string &hint) : name(name), guild(guild), bio(bio), hint(hint) {}

string Mentor::getName()
{
    return name;
}

string Mentor::getGuild()
{
    return guild;
}

string Mentor::getBio()
{
    return bio;
}

string Mentor::getHint()
{
    return hint;
}

void Mentor::displayBio()
{
    cout << "=== " << name << " (" << guild << ") ===\n"
              << bio << "\n\n";
}

void Mentor::displayHint()
{
    cout << name << "'s Advice: " << hint << "\n";
}

vector<shared_ptr<Mentor>> loadMentors()
{
    vector<shared_ptr<Mentor>> mentors;
    ifstream file("mentors.txt");

    if (!file.is_open())
    {
        cerr << "Error: Could not open mentors.txt" << endl;
        return mentors;
    }

     string guild, name, bio,hint;
    while (getline(file, guild))
    {
        getline(file, name);
        getline(file, bio);
        getline(file, hint);

        string emptyLine;
        getline(file, emptyLine);

        auto mentor = make_shared<Mentor>(name, guild, bio, hint);
        mentors.push_back(mentor);
    }

    return mentors;
}
