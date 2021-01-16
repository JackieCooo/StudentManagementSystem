#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Score.h"

using namespace std;

class Student{
public:
    int student_number;
    string name;
    bool gender;
    int age;
    vector<Score> score;  // ´æ³É¼¨

public:
    Student(int student_number, const string& name, bool gender, int age);
    ~Student();
};
