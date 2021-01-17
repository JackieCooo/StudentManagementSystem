#pragma once
#include "Student.h"
#include <list>
#include <string>
#include <vector>

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
    void addStudentInfo();
    void exitSystem();
    void displayAllStudents();
    void deleteStudentInfo();
    void uploadStudentScores();
    void displayAllStudentScores();
    void modifyStudentScore();
    void findClass(void (*pointerToFunc)(list<Student>::iterator &i));
    static void displayStudentInfo(list<Student>::iterator &i);
    static void modifyStudentInfo(list<Student>::iterator &i);

private:
    void inputStudentInfo();
    void saveStudentInfo();
    list<Student>::iterator findStudent(int student_number);
    vector<list<Student>::iterator> findStudent(string &name);
    void addStudentFunction();
    void uploadScoresFunction();
    void modifyStudentScoreFunction(list<Student>::iterator &i);
};

class FindBasedOnNum{  // 基于int查找的谓词定义
public:
    explicit FindBasedOnNum(int n);
    bool operator()(Student &s) const;
private:
    int searchNum = 0;
};

class FindBasedOnString{  // 基于string查找的谓词定义
public:
    explicit FindBasedOnString(string &s);
    bool operator()(Score &s) const;
private:
    string searchStr;
};
