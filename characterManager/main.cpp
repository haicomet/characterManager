#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <cstdlib>
#include <ctime>

#include "Mentor.h"
#include "Character.h"
#include "WebDev.h"
#include "GameDev.h"
#include "Cyber.h"
#include "enemy.h"
#include "quiz.h"
#include "popQuiz.h"
#include "midterm.h"
#include "impostorSyndrome.h"
#include "finalExam.h"

using namespace std;

shared_ptr<Character> createPlayer();
void startBattle(shared_ptr<Character> player);
void viewMentors();
void askMentor();
void checkStats(shared_ptr<Character> player);

vector<Mentor> mentors = loadMentors();

void showMainMenu(shared_ptr<Character> player) {
    int choice;
    do {
        system("clear");
        cout << "=== STEM Quest ===\n"
             << "1. Start Battle\n"
             << "2. View Mentors\n"
             << "3. Ask Mentor for Hint\n"
             << "4. Check Stats\n"
             << "5. Return to Character Creation\n"
             << "6. Quit\n"
             << ">> ";
        cin >> choice;
        system("clear");

        switch (choice) {
            case 1:
                if (player) startBattle(player);
                else cout << "Create a character first!\n";
                break;
            case 2:
                viewMentors();
                break;
            case 3:
                askMentor();
                break;
            case 4:
                if (player) checkStats(player);
                else cout << "No character created yet!\n";
                break;
            case 5:
                player = createPlayer();
                break;
            case 6:
                cout << "Thanks for playing!\n";
                return;
            default:
                cout << "Invalid choice!\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    } while (true);
}

void startBattle(shared_ptr<Character> player) {
    cout << "=== BATTLE CHALLENGE ===\n";

    static size_t nextEnemy = 0;
    vector<unique_ptr<Enemy>> enemies;
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<PopQuiz>());
    enemies.push_back(make_unique<FinalExam>());
    enemies.push_back(make_unique<ImpostorSyndrome>());

    unique_ptr<Enemy>& enemy = enemies[nextEnemy];
    nextEnemy = (nextEnemy + 1) % enemies.size();

    cout << "Challenge: " << enemy->getName() << "!\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    enemy->generatePuzzle();

    cout << "\nResult: You survived the challenge!\n";
}

void viewMentors() {
    cout << "=== MENTORS ===\n";
    for (Mentor& mentor : mentors) {
        mentor.displayBio();
    }
}

void askMentor() {
    if (mentors.empty()) {
        cout << "No mentors available yet!\n";
        return;
    }
    mentors[0].displayHint();
}

void checkStats(shared_ptr<Character> player) {
    cout << "=== PLAYER STATS ===\n";
    player->displayChar();
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    shared_ptr<Character> player = nullptr;
    int click;

    do {
        system("clear");
        cout << "-- MAIN MENU --\n"
             << "1. Create New Player\n"
             << "2. Start Game\n"
             << "3. Quit\n"
             << ">> ";
        cin >> click;

        switch (click) {
            case 1:
                player = createPlayer();
                break;
            case 2:
                if (player) showMainMenu(player);
                else cout << "Create a character first!\n";
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    } while (true);
}

shared_ptr<Character> createPlayer() {
    string name;
    int ch;
    shared_ptr<Character> player;

    cout << "Enter name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "\nTech area of interest:\n"
         << "1. Cyber\n"
         << "2. WebDev\n"
         << "3. GameDev\n"
         << ">> ";
    cin >> ch;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            cout << "INVALID SELECTION. Defaulting to Web Development!\n";
            player = make_shared<WebDev>(name);
            break;
    }

    player->setBg();
    player->setIdentity();
    player->setRace();
    player->displayChar();

    return player;
}
