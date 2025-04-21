#include "Character.h"

Character::Character(string n){name = n;}
void Character::setGuild(string g){ guild = g;}
void Character::setBg(string bg){ background = bg;}
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
