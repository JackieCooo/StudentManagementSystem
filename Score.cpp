#include <iostream>
#include "Score.h"

using namespace std;

Score::Score(string &subject, int score) {
    this->subject = subject;
    this->score = score;
}

Score::~Score() = default;
