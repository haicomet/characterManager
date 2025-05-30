#include "Character.h"
#include "Mentor.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <algorithm>

using namespace std;

vector<shared_ptr<Mentor>> Character::allMentors;

Character::Character(const string &name)
    : name(name), guild(""), background(""), identity(""), race(""),
      grit(0), logic(0), confidence(0),
      xp(0), level(0), xpGained(1), toLvlUp(2),
      gpa(5.0) {}

void Character::setGuild(const string &guildName) {
    guild = guildName;
}

void Character::setBg() {
    int choice;
    cout << "\nWhich background best describes you?\n"
         << "1. First-Generation College Student\n"
         << "2. Working Parent\n"
         << "3. Returning Student\n"
         << "4. Unlisted? No worries! Every path matters:)\n"
         << ">> ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case 1: background = "First-Gen"; grit += 2; confidence += 1; break;
        case 2: background = "Working-Parent"; grit += 3; break;
        case 3: background = "Returning-Student"; logic += 2; grit += 1; break;
        case 4: background = "-"; confidence += 2; break;
        default: cout << "INVALID SELECTION\n"; break;
    }
}

void Character::setIdentity() {
    int choice;
    cout << "\nWhat do you identify as?\n"
         << "1. Nonbinary (they/them)\n"
         << "2. Female (she/her)\n"
         << "3. Male (he/him)\n"
         << "4. Other\n"
         << "5. Prefer not to say\n"
         << ">> ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case 1: identity = "they/them"; break;
        case 2: identity = "she/her";   break;
        case 3: identity = "he/him";    break;
        case 4:
        case 5: identity = "-";         break;
        default: cout << "INVALID SELECTION\n"; break;
    }
}

void Character::setRace() {
    int choice;
    cout << "\nWhich racial/ethnic identity do you most identify with?\n"
         << "1. Black or African American\n"
         << "2. Hispanic or Latino/a/x\n"
         << "3. Asian or Pacific Islander\n"
         << "4. Native American or Indigenous\n"
         << "5. White\n"
         << "6. Multiracial\n"
         << "7. Prefer not to say / Other\n"
         << ">> ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice) {
        case 1: race = "Black or African American"; break;
        case 2: race = "Hispanic or Latino/a/x";     break;
        case 3: race = "Asian or Pacific Islander";  break;
        case 4: race = "Native American or Indigenous"; break;
        case 5: race = "White";                     break;
        case 6: race = "Multiracial";               break;
        case 7: race = "Prefer not to say / Other"; break;
        default: cout << "INVALID SELECTION\n";     break;
    }
}

void Character::boostStats(int g, int l, int c) {
    grit += g; logic += l; confidence += c;
}

void Character::setConfidence(int c) {
    confidence = c;
}

int Character::getGrit() { return grit; }
int Character::getLogic() { return logic; }
int Character::getConfidence() { return confidence; }
int Character::getLevel() {return level; }

void Character::displayChar() {
    cout << "\t|CHARACTER PROFILE|\n"
         << "Name: " << name << "\n"
         << "Guild: " << guild << "\n"
         << "Background: " << background << "\n"
         << "Identity: " << identity << "\n"
         << "Race/Ethnicity: " << race << "\n\n"
         << "----------- STATS -----------\n"
         << "Perseverance:    " << grit << "\n"
         << "Confidence:      " << confidence << "\n"
         << "Logic:           " << logic << "\n"
         << "GPA:             " << gpa << "\n"
         << "Level:           " << level << "\n"
         << "XP:              " << xp << "\n";
}

void Character::levelUp() {
    level++;
    cout << "You've leveled up to: LEVEL " << level << "\n";
}

void Character::takeDamage() {
    gpa -= 0.5;
    confidence -= 0.5;

    if (gpa < 0.0) gpa = 0.0;
    if (confidence < 0.0) confidence = 0.0;

    cout << "Your GPA dropped by 0.5! Current GPA: " << gpa << "\n";
}

void Character::heal() {
    gpa += 0.1;
    confidence += 0.2;
    if (gpa > 5.0) gpa = 5.0;
}

// friend function that adds xp to the player
void plusXP(Character &c) {
    c.xp += c.xpGained;
    cout << "Gained " << c.xpGained
         << " XP! Current XP: " << c.xp
         << " / " << c.toLvlUp << "\n";

    while (c.xp >= c.toLvlUp) {
        c.xp -= c.toLvlUp;
        c.levelUp();
        c.toLvlUp += 2;
        c.boostStats(2,2,1);
        cout << "Stats increased!\n"
             << "  Grit:       " << c.grit     << "\n"
             << "  Logic:      " << c.logic    << "\n"
             << "  Confidence: " << c.confidence << "\n"
             << "Current XP: " << c.xp
             << " / " << c.toLvlUp << "\n";
                
        c.unlockMentor(true);
        
    }
}

void Character::saveCharacter() {
    ofstream outFile("characters.txt");
    if (!outFile) {
        cout << "Could not open file.\n";
        return;
    }
    outFile << name << "\n"
            << guild << "\n"
            << background << "\n"
            << identity << "\n"
            << race << "\n"
            << grit << "\n"
            << logic << "\n"
            << confidence << "\n"
            << gpa << "\n"
            << xp << "\n"
            << level << "\n"
            << xpGained << "\n"
            << toLvlUp << "\n";
}

void Character::loadCharacter() {
    ifstream inFile("characters.txt");
    if (!inFile) {
        cout << "Could not open file.\n";
        return;
    }
    getline(inFile, name);
    getline(inFile, guild);
    getline(inFile, background);
    getline(inFile, identity);
    getline(inFile, race);
    inFile >> grit >> logic >> confidence >> gpa;
    inFile >> xp >> level >> xpGained >> toLvlUp;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');
    inFile.close();

    unlockMentor(false);
    cout << "Character loaded...\n";
}

void Character::loadAllMentors() {
    allMentors = loadMentors();
}

void Character::unlockMentor(bool showMessages) {
    if (level < allMentors.size()) {
        shared_ptr<Mentor> mentorToUnlock = allMentors[level-1];

        bool alreadyUnlocked = false;
        for (int i = 0; i < unlockedMentors.size(); ++i) {
            if (unlockedMentors[i]->getName() == mentorToUnlock->getName()) {
                alreadyUnlocked = true;
                break;
            }
        }

        if (!alreadyUnlocked) {
            unlockedMentors.push_back(mentorToUnlock);
            if (showMessages) {
                cout << "Unlocked mentor: " << mentorToUnlock->getName() << "!\n";
            }
        } else {
            if (showMessages) {
                cout << "No more mentors to unlock!\n";
            }
        }
    } else {
        if (showMessages) {
            cout << "No more mentors to unlock!\n";
        }
    }
}
        
const vector<shared_ptr<Mentor>>& Character::getUnlockedMentors() const {
    return unlockedMentors;
}

double Character::getGPA() const {
    return gpa;
}

void Character::gainXP(int amount){
    xp += amount;
        cout << "Gained " << amount << " XP! Current XP: " << xp << " / " << toLvlUp << "\n";
        while (xp >= toLvlUp) {
            xp -= toLvlUp;
            levelUp();
            toLvlUp += 2;
            boostStats(2, 2, 1);
            unlockMentor(true);
        }}
