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
void viewMentors(shared_ptr<Character> player);
void askMentor(shared_ptr<Character> player);
void checkStats(shared_ptr<Character> player);

void showMainMenu(shared_ptr<Character> player) {
    int choice;
    do {
        system("clear");
        cout << "=== STEM Quest ===\n"
             << "1. Start Battle\n"
             << "2. View Mentors\n"
             << "3. Ask Mentor for Advice\n"
             << "4. Check Stats\n"
             << "5. Return to Character Creation\n"
             << "6. Quit\n"
             << ">> ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("clear");
        
        switch (choice) {
            case 1:
                if (player) startBattle(player);
                else cout << "Create a character first!\n";
                break;
            case 2:
                viewMentors(player);
                break;
            case 3:
                askMentor(player);
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

    enemy->generatePuzzle(*player);

    cout << "\nResult: You survived the challenge!\n";
    plusXP(*player);
}

void viewMentors(shared_ptr<Character> player) {
    cout << "=== MENTORS ===\n";
    const vector<shared_ptr<Mentor>>& unlocked = player->getUnlockedMentors();
    if (unlocked.empty()) {
        cout << "None yet! Earn more XP.\n";
        return;
    }
    for (size_t i = 0; i < unlocked.size(); ++i) {
        shared_ptr<Mentor> mentor = unlocked[i];
        mentor->displayBio();
    }
}

void askMentor(shared_ptr<Character> player) {
    const vector<shared_ptr<Mentor>>& unlocked = player->getUnlockedMentors();
    if (unlocked.empty()) {
        cout << "Level up to unlock mentors!\n";
        return;
    }
    cout << "Choose a mentor for advice:\n";
    for (size_t i = 0; i < unlocked.size(); ++i) {
        cout << (i + 1) << ". " << unlocked[i]->getName() << "\n";
    }
    cout << ">> ";
    int sel;
    cin >> sel;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (sel < 1 || sel > static_cast<int>(unlocked.size())) {
        cout << "Invalid choice.\n";
    } else {
        shared_ptr<Mentor> mentor = unlocked[sel - 1];
        mentor->displayHint();
        player->setConfidence(player->getConfidence() + 1);
    }
}

  

void checkStats(shared_ptr<Character> player) {
    cout << "=== PLAYER STATS ===\n";
    player->displayChar();
}

int main() {
    Character::loadAllMentors();
    srand(static_cast<unsigned>(time(nullptr)));

    shared_ptr<Character> player = nullptr;
    int click;

    do {
        system("clear");
        cout << "-- MAIN MENU --\n"
             << "1. Create New Player\n"
             << "2. Returning Player\n"
             << "3. Start Game\n"
             << "4. Quit\n"
             << ">> ";
        cin >> click;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (click) {
            case 1:
                player = createPlayer();
                break;
            case 2:
                if (!player)
                {
                    player = make_shared<Character> (string());
                }
                player->loadCharacter();
                break;
            case 3:
                if (player) showMainMenu(player);
                else cout << "Create a character first!\n";
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }

        cout << "\nPress Enter to continue...";
        cin.get();
    } while (true);
}

shared_ptr<Character> createPlayer() {
    string name;
    int ch;
    shared_ptr<Character> player;
    cout << "\nEnter name: ";
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
    player->saveCharacter();

    return player;
}
