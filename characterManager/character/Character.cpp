#include "Character.h"

Character::Character(string n){
    name = n;
    grit = 5;
    logic = 5;
}
void Character::setGuild(string g){ guild = g;}
void Character::setBg(string bg){ background = bg;}
int Character::getGrit(){return grit;}
int Character::getLogic(){return logic;}
void Character::displayChar(){
    cout << "|CHARACTER PROFILE|" << endl;
    cout << "\t Name: "<< name << endl;
    cout << "\t Guild: " << guild << endl;
    cout << "\t Background: " << background << endl;
    cout << endl;
    cout << "----------- STATS -----------" << endl;
    cout << "Perseverance:\t\t " << grit << endl;
    cout << "Logic:        \t\t " << logic << endl;
}
