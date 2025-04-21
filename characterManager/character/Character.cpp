#include "Character.h"

Character::Character(string n){name = n;}
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
void Character::setStats(int g,int l,int c){
    grit = g;
    logic = l;
    confidence = c;
}
int Character::getGrit(){return grit;}
int Character::getLogic(){return logic;}
int Character::getConfidence(){return confidence;}
void Character::displayChar(){
    cout << "\t|CHARACTER PROFILE|" << endl;
    cout << "Name: "<< name << endl;
    cout << "Guild: " << guild << endl;
    cout << "Background: " << background << endl;
    cout << endl;
    cout << "----------- STATS -----------" << endl;
    cout << "Perseverance:\t\t " << grit << endl;
    cout << "Confidence:  \t\t " << confidence << endl;
    cout << "Logic:       \t\t " << logic << endl;
}
