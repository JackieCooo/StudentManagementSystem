#include <string>
#include "Student.h"

using namespace std;

Student::Student(const int student_number, const string& name, const bool gender, const int age){  // ³õÊ¼»¯studentÀà
    this->student_number = student_number;
    this->name = name;
    this->gender = gender;
    this->age = age;
}

Student::~Student() = default;


