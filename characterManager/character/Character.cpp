#include "Character.h"
#include <iostream>
#include <limits>
#include <fstream>

Character::Character(const std::string &name)
    : name(name), guild(""), background(""), identity(""), race(""),
      grit(0), logic(0), confidence(0),
      xp(0), level(0), xpGained(1), toLvlUp(2), gpa(5.0) {}

void Character::setGuild(const std::string &guildName) {
    guild = guildName;
}

void Character::setBg() {
    int choice;
    std::cout << "\nWhich background best describes you?\n"
              << "1. First-Generation College Student\n"
              << "2. Working Parent\n"
              << "3. Returning Student\n"
              << "4. Unlisted? No worries! Every path matters:)\n"
              << ">> ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
        case 1:
            background = "First-Gen";
            grit += 2;
            confidence += 1;
            break;
        case 2:
            background = "Working-Parent";
            grit += 3;
            break;
        case 3:
            background = "Returning-Student";
            logic += 2;
            grit += 1;
            break;
        case 4:
            background = "-";
            confidence += 2;
            break;
        default:
            std::cout << "INVALID SELECTION\n";
            break;
    }
}

void Character::setIdentity() {
    int choice;
    std::cout << "\nWhat do you identify as?\n"
              << "1. Nonbinary (they/them)\n"
              << "2. Female (she/her)\n"
              << "3. Male (he/him)\n"
              << "4. Other\n"
              << "5. Prefer not to say\n"
              << ">> ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
        case 1:
            identity = "they/them";
            break;
        case 2:
            identity = "she/her";
            break;
        case 3:
            identity = "he/him";
            break;
        case 4:
        case 5:
            identity = "-";
            break;
        default:
            std::cout << "INVALID SELECTION\n";
            break;
    }
}

void Character::setRace() {
    int choice;
    std::cout << "\nWhich racial/ethnic identity do you most identify with?\n"
              << "1. Black or African American\n"
              << "2. Hispanic or Latino/a/x\n"
              << "3. Asian or Pacific Islander\n"
              << "4. Native American or Indigenous\n"
              << "5. White\n"
              << "6. Multiracial\n"
              << "7. Prefer not to say / Other\n"
              << ">> ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (choice) {
        case 1:
            race = "Black or African American";
            break;
        case 2:
            race = "Hispanic or Latino/a/x";
            break;
        case 3:
            race = "Asian or Pacific Islander";
            break;
        case 4:
            race = "Native American or Indigenous";
            break;
        case 5:
            race = "White";
            break;
        case 6:
            race = "Multiracial";
            break;
        case 7:
            race = "Prefer not to say / Other";
            break;
        default:
            std::cout << "INVALID SELECTION\n";
            break;
    }
}
void Character::setConfidence(int c){confidence = c;}

void Character::boostStats(int g, int l, int c) {
    grit += g;
    logic += l;
    confidence += c;
}

int Character::getGrit() { return grit; }
int Character::getLogic() { return logic; }
int Character::getConfidence() { return confidence; }

void Character::displayChar() {
    std::cout << "\n" <<std::endl;
    std::cout << "\t|CHARACTER PROFILE|" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Guild: " << guild << std::endl;
    std::cout << "Background: " << background << std::endl;
    std::cout << "Identity: " << identity << std::endl;
    std::cout << "Race/Ethnicity: " << race << std::endl;
    std::cout << std::endl;
    std::cout << "----------- STATS -----------" << std::endl;
    std::cout << "Perseverance:\t\t " << grit << std::endl;
    std::cout << "Confidence:  \t\t " << confidence << std::endl;
    std::cout << "Logic:       \t\t " << logic << std::endl;
    std::cout << "GPA:         \t\t " << gpa << std::endl;
    std::cout << "XP:          \t\t " << xp << std::endl;
}

void Character::takeDamage() {
    gpa -= 0.1;
    confidence -= 0.5;
    if (gpa < 0.0)
        gpa = 0.0;
}

void Character::heal() {
    gpa += 0.1;
    confidence += 0.2;
    if (gpa > 5.0)
        gpa = 5.0;
}

void Character::levelUp() {
    level++;
    std::cout << "You've leveled up to: LEVEL " << level << std::endl;
}

void plusXP(Character &c) {
    c.xp += c.xpGained;
    while (c.xp >= c.toLvlUp) {
        c.xp -= c.toLvlUp;
        c.levelUp();
        c.toLvlUp += 2;
        c.boostStats(2, 2, 1);
        std::cout << "Stats increased!"
                  << "\nPerseverance:\t" << c.grit
                  << "\nLogic:\t" << c.logic
                  << "\nConfidence:\t" << c.confidence
                  << std::endl;
        std::cout << "Current XP: " << c.xp <<"\t"
        << c.toLvlUp << " needed for next level up!\n";
    }
}

void Character::saveCharacter() {
    std::ofstream outFile("characters.txt");
    if (!outFile) {
        std::cout << "Could not open file.\n";
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
    outFile.close();
    std::cout << "Character saved :)\n";
}

void Character::loadCharacter() {
    std::ifstream inFile("characters.txt");
    if (!inFile) {
        std::cout << "Could not open file.\n";
        return;
    }
    std::string line;
    std::getline(inFile, name);
    std::getline(inFile, guild);
    std::getline(inFile, background);
    std::getline(inFile, identity);
    std::getline(inFile, race);
    inFile >> grit >> logic >> confidence >> gpa;
    inFile >> xp >> level >> xpGained >> toLvlUp;
    inFile.close();
    std::cout << "Character loaded successfully. Welcome back!\n";
    displayChar();
}
std::vector<std::shared_ptr<Mentor>> Character::allMentors;
void Character::loadAllMentors() {
    allMentors = loadMentors();
}

void Character::unlockMentor() {
    if (level < allMentors.size()) {
        unlockedMentors.push_back(allMentors[level]);
        cout << "Unlocked mentor: " << allMentors[level]->getName() << "!\n";
    }else{
        cout << "No more mentors to unlock!\n";
    }
}

const std::vector<std::shared_ptr<Mentor>>& Character::getUnlockedMentors() const {
    return unlockedMentors;
}
