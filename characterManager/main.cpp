#include <iostream>
#include <vector>
#include <memory>
#include <map>

// character & mentor headers
#include "Mentor.h"
#include "Character.h"
#include "WebDev.h"
#include "GameDev.h"
#include "Cyber.h"

// enemy system
#include "enemy.h"
#include "quiz.h"
#include "popQuiz.h"
#include "midterm.h"
#include "impostorSyndrome.h"
#include "finalExam.h"

using namespace std;

shared_ptr<Character> createPlayer(){
    string name;
    int ch;
    shared_ptr<Character> player;
    
    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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


/* Test Enemy Class since i cant lol


int main() 

    // build a list of one of each enemy
    vector<unique_ptr<Enemy>> enemies;
    enemies.emplace_back(make_unique<Quiz>());
    enemies.emplace_back(make_unique<PopQuiz>());
    enemies.emplace_back(make_unique<Midterm>());
    enemies.emplace_back(make_unique<ImpostorSyndrome>());
    enemies.emplace_back(make_unique<FinalExam>());

    for (auto& enemy : enemies) {
        cout << "=== Testing Enemy: "
             << enemy->getName()
             << " (Difficulty "
             << enemy->getDifficulty()
             << ") ===\n\n";

        for (int i = 1; i <= 3; ++i) {
            cout << "--- Puzzle #" << i << " ---\n";
            enemy->attack();
            enemy->generatePuzzle();
            cout << "\n";
        }
        cout << "---------------------------------\n\n";
    }

    return 0;
}


*/