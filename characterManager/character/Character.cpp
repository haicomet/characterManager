#include "Character.h"

Character::Character(string n):
    name(n), guild(""), background(""), identity(""),
    grit(0), logic(0), confidence(0),
    xp(0), level(0), xpGained(1), toLvlUp(2), gpa(5.0) {}
void Character::setGuild(string g){ guild = g;}
void Character::setBg(){
    int choice;
    cout << "Which background best describes you?\n"
    << "1. First-Generation College Student\n"
    << "2. Working Parent\n"
    << "3. Returning Student\n"
    << "4. Unlisted? No worries! Every path matters:)\n";
    cin >> choice;
    
    switch (choice) {
        case 1:
            background = "First-Gen";
            grit+=2;
            confidence+=1;
            break;
        case 2:
            background = "Working-Parent";
            grit+=3;
            break;
        case 3:
            background = "Returning-Student";
            logic+=2;
            grit+=1;
            break;
        case 4:
            background = "-";
            confidence+=2;
            break;
            
        default:
            cout << "INVALID SELECTION\n";
            break;
    }
}
void Character::setIdentity(){
    int choice;
    cout << "What do you identify as?\n"
    << "1. Nonbinary (they/them)\n"
    << "2. Female (she/her)\n"
    << "3. Male (he/him)\n"
    << "4. Other\n"
    << "5. Prefer not to say\n";
    cin >> choice;
    
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
            identity = "-";
            break;
        case 5:
            identity = "-";
            break;
            
        default:
            cout << "INVALID SELECTION\n";
            break;
    }
}

void Character::setRace() {
    int choice;
    cout << "Which racial/ethnic identity do you most identify with?\n"
         << "1. Black or African American\n"
         << "2. Hispanic or Latino/a/x\n"
         << "3. Asian or Pacific Islander\n"
         << "4. Native American or Indigenous\n"
         << "5. White\n"
         << "6. Multiracial\n"
         << "7. Prefer not to say / Other\n";
    cin >> choice;

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
    }
}

void Character::boostStats(int g,int l,int c){
    grit += g;
    logic += l;
    confidence += c;
}
int Character::getGrit(){return grit;}
int Character::getLogic(){return logic;}
int Character::getConfidence(){return confidence;}
void Character::displayChar(){
    cout << "\t|CHARACTER PROFILE|" << endl;
    cout << "Name: "<< name << endl;
    cout << "Guild: " << guild << endl;
    cout << "Background: " << background << endl;
    cout << "Identity: " << identity << endl;
    cout << "Race/Ethnicity: " << race << endl;
    cout << endl;
    cout << "----------- STATS -----------" << endl;
    cout << "Perseverance:\t\t " << grit << endl;
    cout << "Confidence:  \t\t " << confidence << endl;
    cout << "Logic:       \t\t " << logic << endl;
    cout << "GPA:         \t\t " << gpa << endl;
}
void Character::takeDamage(){
    gpa -= 0.1;
    confidence -= 0.5;
    if (gpa < 0.0)
        gpa = 0.0;
}
void Character::heal(){
    gpa += 0.1;
    confidence += 0.2;
    if (gpa > 5.0)
        gpa = 5.0;
}
void Character::levelUp(){
    level++;
    cout << "You've leveled up to: LEVEL " << level << endl;
}

void plusXP(Character& c){
    c.xp += c.xpGained;
    
    while (c.xp >= c.toLvlUp){
        c.xp -= c.toLvlUp;
        c.levelUp();
        c.toLvlUp+=2;
        c.boostStats(2,2,1);
        cout << "Stats increased!" << "\nGrit:\t" << c.grit << "\nLogic:\t" << c.logic << "\nConfidence:\t" << c.confidence ;
        cout << "Current XP: " << c.xp << " \t" << " needed for next level up!\n";
    }
}

void Character::saveCharacter(){
    ofstream outFile("characters.txt");
    if (!outFile){
        cout << "Could not open file.\n";
    }
    outFile << name << "\n";
    outFile << guild << "\n";
    outFile << background << "\n";
    outFile << identity << "\n";
    outFile << race << "\n";
    outFile << grit << "\n";
    outFile << logic << "\n";
    outFile << confidence << "\n";
    outFile << gpa << "\n";
    outFile << xp << "\n";
    outFile << level << "\n";
    outFile << xpGained << "\n";
    outFile << toLvlUp << "\n";

    outFile.close();
    
    cout << "Character saved :)\n";
}

void Character::loadCharacter(){
    ifstream inFile("characters.txt");
    if (!inFile){
        cout << "Could not open file.\n";
    }
    getline(inFile, name);
    getline(inFile, guild);
    getline(inFile, background);
    getline(inFile, identity);
    getline(inFile, race);
    inFile >> grit >> logic >> confidence >> gpa;
    inFile >> xp >> level >> xpGained >> toLvlUp;

    inFile.close();
    
    cout << "Character loaded...\n";
}

void Character::getMentorList(){
    mentorList = loadMentors();
}
void Character::unlockMentor(){
    if (level < mentorList.size()){
        unlockedMentors.push_back(mentorList[level]);
    }
}
void Character::displayUnlockedMentors(){
    for (auto& mentor : unlockedMentors) {
        mentor.getBio();
    }
}
