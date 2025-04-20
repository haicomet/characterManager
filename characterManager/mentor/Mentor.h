#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Mentor
{
private:
    string name;
    string guild;
    string bio;
    string hint;

public:
    Mentor();
    Mentor( string &name, string &guild, string &bio, string &hint);

    string getName();
    string getGuild();
    string getBio();
    string getHint();

    void displayBio();
    void displayHint();

    friend vector<Mentor> loadMentors();
};

vector<Mentor> loadMentors();
