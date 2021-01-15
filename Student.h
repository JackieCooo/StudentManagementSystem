#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student{
public:
    int student_number;
    string name;
    bool gender;
    int age;

public:
    Student(int student_number, const string& name, bool gender, int age);
    ~Student();
};
