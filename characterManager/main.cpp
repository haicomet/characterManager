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
bool startBattle(shared_ptr<Character>& player);
void viewMentors(shared_ptr<Character> player);
void askMentor(shared_ptr<Character> player);
void checkStats(shared_ptr<Character> player);
void showMainMenu(shared_ptr<Character> player);
void setupEnemies();

static size_t nextEnemy = 0;

//init of the enemy vecor
vector<unique_ptr<Enemy>> enemies;

int main() {

	Character::loadAllMentors();
	srand(static_cast<unsigned>(time(nullptr)));
	shared_ptr<Character> player = nullptr;

	while (true) {
		system("clear");
		int click;

		while (true) {
			try {//exceptioin handling 
				cout << "-- MAIN MENU --\n"
				     << "1. Create New Player\n"
				     << "2. Returning Player\n"
				     << "3. Start Game\n"
				     << "4. Quit\n"
				     << ">> ";

				if (!(cin >> click)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw string("Invalid input: Please enter a number.");
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (click < 1 || click > 4)
					throw string("Invalid input: Number not in menu range.");
				break;
			}
			catch(const string& e) {
				cout << "Error! " << e << "\n\n";
			}
		}


		switch (click) {
		case 1:
			player = createPlayer();
			break;
		case 2: {
			ifstream inFile("characters.txt");
			if (!inFile) {
				cout << "No saved character found.\n";
				break;
			}
			string line, guild;
			getline(inFile, line);
			getline(inFile, guild);
			inFile.close();

			if (guild == "Cyber") {
				player = make_shared<Cyber>("");
			} else if (guild == "WebDev") {
				player = make_shared<WebDev>("");
			} else if (guild == "GameDev") {
				player = make_shared<GameDev>("");
			} else {
				player = make_shared<Character>("");
			}

			player->loadCharacter();
            nextEnemy = 0;
			break;
		}
		case 3:
			if (player) {
				showMainMenu(player);
				player = nullptr;
			} else {
				cout << "Create a character first!\n";
			}
			break;
		case 4:
			return 0;
		}

		cout << "\nPress Enter to continue...";
		cin.get();
	}

}

void showMainMenu(shared_ptr<Character> player)
{
	int choice;
	do
	{
		system("clear");
		cout << "=== STEM Quest ===\n"
		     << "1. Start Battle\n"
		     << "2. View Mentors\n"
		     << "3. Ask Mentor for Advice\n"
		     << "4. Check Stats\n"
		     << "5. Return to Character Creation\n"
		     << "6. Quit\n"
		     << ">> ";
		
        try {
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw string("Invalid input! Please enter a number (1-6).");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            if (choice < 1 || choice > 6) {
                throw string("Invalid input! Please enter a number between 1-6.");
            }
            
            system("clear");
            
            switch (choice)
            {
                case 1:
                    if (player)
                    {
                        setupEnemies();
                        if (!startBattle(player))
                        {
                            return;
                        }
                    }
                    else
                    {
                        cout << "Create a character first!\n";
                    }
                    break;
                case 2:
                    viewMentors(player);
                    break;
                case 3:
                    askMentor(player);
                    break;
                case 4:
                    if (player)
                        checkStats(player);
                    else
                        cout << "No character created yet!\n";
                    break;
                case 5:
                    player = createPlayer();
                    break;
                case 6:
                    player->saveCharacter();
                    cout << "Thanks for playing!\n";
                    return;
            }
        }catch(const string& errorMsg) {
            system("clear");
            cout << "Error: " << errorMsg << "\n";
            cout << "Press Enter to retry...";
            cin.get();
            continue;
        }
		cout << "\nPress Enter to continue...";
		cin.get();
	} while (true);
}

bool startBattle(shared_ptr<Character>& player)
{
    cout << "=== BATTLE CHALLENGE ===\n";

    while (true)
    {
        if (nextEnemy >= enemies.size())
        {
            cout << "You've defeated all available enemies!\n";
            return true;
        }

        unique_ptr<Enemy>& enemy = enemies[nextEnemy];
        nextEnemy++;

        cout << "Challenge: " << enemy->getName() << "!\n";

        bool survived = enemy->generatePuzzle(*player);

        if (!survived)
        {
            player = nullptr;
            return false;
        }

        cout << "\nResult: You survived the challenge!\n";
        player->gainXP(enemy->getXPGained());
        string cont;
        cout << "\nDo you want to continue battling? (Y/N): ";
        getline(cin, cont);
        if (cont != "Y" && cont != "y")
        {
            break;
        }

        cout << "\n";
    }

    return true;
}


void viewMentors(shared_ptr<Character> player)
{
	cout << "=== MENTORS ===\n";
	const vector<shared_ptr<Mentor>> &unlocked = player->getUnlockedMentors();

	if (unlocked.empty())
	{
		cout << "None yet! Earn more XP.\n";
		return;
	}
	for (size_t i = 0; i < unlocked.size(); ++i)
	{
		shared_ptr<Mentor> mentor = unlocked[i];
		mentor->displayBio();
	}
}

void askMentor(shared_ptr<Character> player)
{
	const vector<shared_ptr<Mentor>> &unlocked = player->getUnlockedMentors();
	if (unlocked.empty())
	{
		cout << "Level up to unlock mentors!\n";
		return;
	}
	cout << "Choose a mentor for advice:\n";
	for (size_t i = 0; i < unlocked.size(); ++i)
	{
		cout << (i + 1) << ". " << unlocked[i]->getName() << "\n";
	}
	cout << ">> ";
	int sel;
	cin >> sel;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (sel < 1 || sel > static_cast<int>(unlocked.size()))
	{
		cout << "Invalid choice.\n";
	}
	else
	{
		shared_ptr<Mentor> mentor = unlocked[sel - 1];
		mentor->displayHint();
		player->setConfidence(player->getConfidence() + 1);
	}
}

void checkStats(shared_ptr<Character> player)
{
	cout << "=== PLAYER STATS ===\n";
	player->displayChar();
}



shared_ptr<Character> createPlayer()
{
    nextEnemy = 0;
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

	switch (ch)
	{
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

//setup that puts enemies into the vector
void setupEnemies() {
    enemies.clear();
    
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());
    enemies.push_back(make_unique<Quiz>());

    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<Midterm>());
    enemies.push_back(make_unique<Midterm>());
    

    enemies.push_back(make_unique<PopQuiz>());
    enemies.push_back(make_unique<PopQuiz>());
    enemies.push_back(make_unique<PopQuiz>());
    enemies.push_back(make_unique<PopQuiz>());
    enemies.push_back(make_unique<PopQuiz>());

    
    enemies.push_back(make_unique<FinalExam>());
    enemies.push_back(make_unique<FinalExam>());
    enemies.push_back(make_unique<FinalExam>());
    enemies.push_back(make_unique<FinalExam>());

    enemies.push_back(make_unique<ImpostorSyndrome>());
    enemies.push_back(make_unique<ImpostorSyndrome>());
    enemies.push_back(make_unique<ImpostorSyndrome>());
    enemies.push_back(make_unique<ImpostorSyndrome>());
    enemies.push_back(make_unique<ImpostorSyndrome>());

};
