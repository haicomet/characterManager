#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include "Mentor.h"
#include "Character.h"
#include "WebDev.h"
#include "GameDev.h"
#include "Cyber.h"
using namespace std;

shared_ptr<Character> createPlayer(){
    string name;
    int ch;
    shared_ptr<Character> player;
    
    cout << "Enter name: "; //getting skipped for some reason
    getline(cin,name);
    
    cout << "\nTech area of interest: \n"
    << "1. Cyber\n2. WebDev\n3. GameDev\n";
    cin >> ch;
    cin.ignore();
    
    switch (ch) {
        case 1:
            player = make_shared<Cyber>(name);
            break;
        case 2:
            player = make_shared<WebDev>(name);
            break;
        case 3:
            player = make_shared<GameDev>(name);
            break;
        default:
            cout << "INVALID SELECTION. Defaulting to Web Development...\n";
            player = make_shared<WebDev>(name);
            break;
    }
    player->setBg();
    player->setIdentity();
    player->displayChar();
    
    return player;
}
    
int main()
{
    int click;
    shared_ptr<Character> newPlayer;
    do {
        (void)system("clear");
        cout << "--Menu--\n"
        << "1. Create New Player\n";
        cin >> click;
        (void)system("clear");
        switch (click) {
            case 1:
                newPlayer = createPlayer();
                break;
            case 2:
                break;
            default:
                break;
        }
    } while (click != 6);
    
    return 0;
}
/*auto mentors = loadMentors();
for (Mentor m : mentors)
{
    cout << "[" << m.getGuild() << "] "
         << "Name: " << m.getName() << "\n"
         << "Bio: " << m.getBio() << "\n"
         << "Hint: " << m.getHint() << "\n\n";
}*/
