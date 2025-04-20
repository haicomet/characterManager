#include <iostream>
#include <vector>
#include <map>
#include "Mentor.h"
#include "Character.h"

using namespace std;

int main()
{
    /*auto mentors = loadMentors();
    for (Mentor m : mentors)
    {
        cout << "[" << m.getGuild() << "] "
             << "Name: " << m.getName() << "\n"
             << "Bio: " << m.getBio() << "\n"
             << "Hint: " << m.getHint() << "\n\n";
    }*/
    string name, guild, background;

        cout << "Welcome to STEM Quest!" << endl;
        cout << "Enter your character's name: ";
        getline(cin, name);

        Character player(name);

        cout << "Choose your guild (Cyber, WebDev, GameDev): ";
        getline(cin, guild);
        player.setGuild(guild);

        cout << "Choose your background (First-Gen): ";
        getline(cin, background);
        player.setBg(background);

        player.displayChar();
    return 0;
}
