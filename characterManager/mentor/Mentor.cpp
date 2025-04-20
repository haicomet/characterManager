#include "Mentor.h"
#include <string>
#include <iostream>

using namespace std;

Mentor::Mentor()
{
    name = "";
    guild = "";
    bio = "";
    hint = "";
}

Mentor::Mentor(string &name, string &guild, string &bio, string &hint)
    : name(name), guild(guild), bio(bio), hint(hint) {}

string Mentor::getName() { return name; }
string Mentor::getGuild() { return guild; }
string Mentor::getBio() { return bio; }
string Mentor::getHint() { return hint; }

void Mentor::displayBio()
{
    cout << "=== " << name << " (" << guild << ") ===\n";
    cout << bio << "\n\n";
}

void Mentor::displayHint()
{
    cout << name << "'s Advice: " << hint << "\n";
}

vector<Mentor> loadMentors()
{
    vector<Mentor> mentors;
    ifstream file("mentors.txt");

    if (!file.is_open())
    {
        cerr << "Error: Could not open mentors.txt" << endl;
        return mentors;
    }

    Mentor mentor;
    while (getline(file, mentor.guild))
    {
        getline(file, mentor.name);
        getline(file, mentor.bio);
        getline(file, mentor.hint);

        string emptyLine;
        getline(file, emptyLine);

        mentors.push_back(mentor);
    }

    return mentors;
}