#ifndef GENERALMENTOR_H
#define GENERALMENTOR_H

#include "Mentor.h"

class GeneralMentor : public Mentor {
public:
    GeneralMentor(const string &name, const string &guild, const string &bio, const string &hint);
    void displayHint() override;
};

#endif
