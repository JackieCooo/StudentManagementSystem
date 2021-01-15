#pragma once
#include "Student.h"
#include <list>

using namespace std;

class StudentManager{
private:
    list<Student> info;
    int student_number = 0;
    string name;
    bool gender = true;
    int age = 0;

public:
    StudentManager();
    ~StudentManager();
    static void showMenu() ;
    void addStudent();
    void findStudent();
    void modifyStudentInfo();
    void exitSystem();
    void displayAllStudents();

private:
    void inputStudentInfo();
    static void displayStudentInfo(list<Student>::iterator &i);
    static void printErrInpLog();
    void saveStudentInfo();
};

class FindBasedOnNum{  // 基于学号查找的谓词定义
public:
    explicit FindBasedOnNum(int n);
    bool operator()(Student &s) const;
private:
    int searchNum = 0;
};
