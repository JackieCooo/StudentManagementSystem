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
    void addStudent();
    void findStudentInfo();
    void modifyStudentInfo();
    void exitSystem();
    void displayAllStudents();
    void deleteStudentInfo();

private:
    void inputStudentInfo();
    static void displayStudentInfo(list<Student>::iterator &i);
    static void printErrInpLog();
    void saveStudentInfo();
    list<Student>::iterator findStudent(int student_number);
    vector<list<Student>::iterator> findStudent(string &name);
    static void modifyFunction(list<Student>::iterator &i);
};

class FindBasedOnNum{  // 基于学号查找的谓词定义
public:
    explicit FindBasedOnNum(int n);
    bool operator()(Student &s) const;
private:
    int searchNum = 0;
};
