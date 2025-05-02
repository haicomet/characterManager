#include "Mentor.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

Mentor::Mentor() : name(), guild(), bio(), hint() {}

Mentor::Mentor(
    const std::string &name,
    const std::string &guild,
    const std::string &bio,
    const std::string &hint) : name(name), guild(guild), bio(bio), hint(hint) {}

std::string Mentor::getName()
{
    return name;
}

std::string Mentor::getGuild()
{
    return guild;
}

std::string Mentor::getBio()
{
    return bio;
}

std::string Mentor::getHint()
{
    return hint;
}

void Mentor::displayBio()
{
    std::cout << "=== " << name << " (" << guild << ") ===\n"
              << bio << "\n\n";
}

void Mentor::displayHint()
{
    std::cout << name << "'s Advice: " << hint << "\n";
}

std::vector<Mentor> loadMentors()
{
    std::vector<Mentor> mentors;
    std::ifstream file("mentors.txt");

    if (!file.is_open())
    {
        std::cerr << "Error: Could not open mentors.txt" << std::endl;
        return mentors;
    }

    Mentor mentor;
    while (std::getline(file, mentor.guild))
    {
        std::getline(file, mentor.name);
        std::getline(file, mentor.bio);
        std::getline(file, mentor.hint);

        std::string emptyLine;
        std::getline(file, emptyLine);

        mentors.push_back(mentor);
    }

    return mentors;
}
