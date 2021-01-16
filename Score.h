#pragma once
#include <istream>
#include <string>

using namespace std;

class Score{
public:
    string subject;
    int score = 0;

public:
    Score(string &subject, int score);
    ~Score();
};
