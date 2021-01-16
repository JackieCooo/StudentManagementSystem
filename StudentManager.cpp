#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "StudentManager.h"
#include "GlobalPath.h"

using namespace std;

StudentManager::StudentManager() {
    cout << "正在载入学生信息，请稍后..." << endl;
    inputStudentInfo();
    system("cls");
}

StudentManager::~StudentManager() = default;

void StudentManager::showMenu() {  // 打印菜单
    cout << "********************************" << endl;
    cout << "********欢迎使用学生管理系统********" << endl;
    cout << "*********1. 添加学生**************" << endl;
    cout << "*********2. 查找学生信息***********" << endl;
    cout << "*********3. 修改学生信息***********" << endl;
    cout << "*********4. 删除学生信息***********" << endl;
    cout << "*********5. 查看所有学生信息********" << endl;
    cout << "*********6. 退出系统**************" << endl;
    cout << "*********************************" << endl;
}

void StudentManager::inputStudentInfo() {  // 将外部文件数据加载到内存中
    fstream ifs(StudentInformation, ios::in);  // 这个读取文件的路径是以exe文件为起始路径的
    if (ifs.is_open()){  // 检查是否正常打开
        while (ifs >> student_number >> name >> gender >> age){  // 有数据的话就写入
            Student s(student_number, name, gender, age);  // 用Student类接受数据，并创建自定义类型
            StudentManager::info.push_back(s);  // 将该学生数据加入到list中
        }
        cout << "学生数据载入完毕" << endl;
    }
    else{
        cout << "文件无法打开" << endl;
        return;
    }
    ifs.close();
}

void StudentManager::addStudentFunction() {  // 添加学生功能函数
    string t;
    cout << "请输入学生学号: ";
    cin >> student_number;
    cout << "请输入学生名字: ";
    cin >> name;
    cout << "请输入学生性别: ";
    cin >> t;
    while (t != "男" || t != "女"){
        cout << "输入错误请重新输入: ";
        cin >> t;
    }
    if (t == "男") gender = true;  // gender在程序中以bool类型储存，所以要作转换
    else if (t == "女") gender = false;
    cout << "请输入学生年龄: ";
    cin >> age;
    Student s(student_number, name, gender, age);  // 创建新的学生类
    StudentManager::info.push_back(s);  // 追加到list
}

void StudentManager::findStudentInfo() {  // 查找学生
    int findMode = 0;
    cout << "请选择以哪种方式查找: " << endl;
    cout << "1. 学号" << endl;
    cout << "2. 姓名" << endl;
    cin >> findMode;
    if (findMode == 1) {
        int searchNum = 0;
        cout << "请输入学号: " ;
        cin >> searchNum;
        auto index = findStudent(searchNum);
        if (index != info.end()){
            displayStudentInfo(index);
        }
        else{
            cout << "查不到此学生" << endl;
        }
    }
    else if (findMode == 2) {
        string searchName;
        cout << "请输入姓名: ";
        cin >> searchName;
        vector<list<Student>::iterator> v = findStudent(searchName);
        if (!v.empty()){  // 检查vector是否为空，空即为查不到
            for (auto &i : v){
                displayStudentInfo(i);
            }
        }
        else{
            cout << "查不到此学生" << endl;
        }
    }
    else{

    }
}

void StudentManager::displayStudentInfo(list<Student>::iterator &i){  // 打印学生信息
    cout << "学号: " << i->student_number << "\t姓名: " << i->name << "\t性别: ";
    if (i->gender == 1) cout << "男";
    else cout << "女";
    cout << "\t年龄: " << i->age << endl;
}

bool FindBasedOnNum::operator()(Student &s) const{
    return s.student_number == searchNum;
}

FindBasedOnNum::FindBasedOnNum(int n){
    this->searchNum = n;
}

void StudentManager::modifyStudentInfo(){  // 修改学生信息
    cout << "请选择查找方式: " << endl;
    cout << "1. 学号" << endl;
    cout << "2. 姓名" << endl;
    int mode = 0;
    cin >> mode;
    if (mode == 1){
        int searchNum = 0;
        cout << "请输入学生学号:" << endl;
        cin >> searchNum;
        auto index = findStudent(searchNum);
        if (index != info.end()){
            modifyFunction(index);
        }
        else{
            cout << "查不到此学生" << endl;
        }
    }
    else if (mode == 2){
        string searchName;
        cout << "请输入学生姓名: ";
        cin >> searchName;
        vector<list<Student>::iterator> v = findStudent(searchName);
        if (!v.empty()){
            int j = 1;
            for (auto &i : v){
                cout << "序号: " << j++ << "\t";
                displayStudentInfo(i);
            }
            cout << "输入要修改的学生的序号: ";
            int n;
            cin >> n;
            modifyFunction(v[n]);
        }
        else {
            cout << "查不到此学生" << endl;
        }
    }
}

void StudentManager::saveStudentInfo(){  // 保存学生信息
    ofstream ofs;
    ofs.open(StudentInformation, ios::out);
    for (auto &i : info){
        ofs << i.student_number << " " << i.name << " " << i.gender << " " << i.age << endl;
    }
    ofs.close();
    cout << "学生信息保存完毕" << endl;
}

void StudentManager::exitSystem() {  // 退出系统
    cout << "正在保存学生信息，请稍后..." << endl;
    saveStudentInfo();
    system("cls");
}

void StudentManager::displayAllStudents(){  // 查看所有学生信息
    if (!info.empty()){
        for (auto i = info.begin(); i != info.end(); ++i){
            displayStudentInfo(i);
        }
    }
    else{
        cout << "暂无学生信息" << endl;
    }
}

void StudentManager::deleteStudentInfo(){  // 删除学生信息
    cout << "请选择查找方式: " << endl;
    cout << "1. 学号" << endl;
    cout << "2. 姓名" << endl;
    int mode = 0;
    cin >> mode;
    if (mode == 1){
        int searchNum = 0;
        cout << "请输入学生学号:";
        cin >> searchNum;
        auto index = findStudent(searchNum);
        if (index != info.end()){
            info.erase(index);  // 删除信息
            cout << "学生信息删除成功" << endl;
        }
        else{
            cout << "查不到此学生" << endl;
        }
    }
    else if (mode == 2){
        string searchName;
        cout << "请输入学生姓名: ";
        cin >> searchName;
        vector<list<Student>::iterator> v = findStudent(searchName);
        if (!v.empty()){
            int j = 1;
            for (auto &i : v){
                cout << "序号: " << j++ << "\t";
                displayStudentInfo(i);
            }
            cout << "输入要删除的学生的序号: ";
            int n;
            cin >> n;
            info.erase(v[n-1]);
        }
        else {
            cout << "查不到此学生" << endl;
        }
    }
}

list<Student>::iterator StudentManager::findStudent(int searchNum){  // 查找功能函数，返回list的迭代器
    auto index = find_if(info.begin(), info.end(), FindBasedOnNum(searchNum));
    if (index != info.end()){
        return index;
    }
    else{
        return info.end();
    }
}

vector<list<Student>::iterator> StudentManager::findStudent(string &searchName){  // 查找功能函数，返回以list的迭代器为元素的vector
    vector<list<Student>::iterator> res;
    for (auto i = info.begin(); i != info.end(); ++i){  // 学生有可能有同名，所以不用find_if
        if ((*i).name == searchName){
            res.push_back(i);
        }
    }
    return res;
}

void StudentManager::modifyFunction(list<Student>::iterator &i){  // 修改学生信息功能函数
    int mode = 0;
    bool flag = false;  // while退出标志
    cout << "请输入要修改学生的信息: " << endl;
    cout << "1. 学号" << endl;
    cout << "2. 姓名" << endl;
    cout << "3. 性别" << endl;
    cout << "4. 年龄" << endl;
    cout << "输入0退出此学生信息的修改" << endl;
    while (true){
        cin >> mode;
        switch (mode) {
            case 0:{  // 退出修改
                cout << "此学生修改已保存" << endl;
                flag = true;
                break;
            }
            case 1:{  // 修改学号
                int changeNum = 0;
                cout << "请输入修改后的学号: ";
                cin >> changeNum;
                i->student_number = changeNum;
                cout << "修改成功" << endl;
                break;
            }
            case 2:{  // 修改姓名
                string changeName;
                cout << "请输入修改后的姓名: ";
                cin >> changeName;
                i->name = changeName;
                cout << "修改成功" << endl;
                break;
            }
            case 3:{  // 修改性别
                string changeGender;
                cout << "请输入修改后的性别: ";
                cin >> changeGender;
                while (changeGender != "男" || changeGender != "女"){
                    cout << "输入错误请重新输入: ";
                    cin >> changeGender;
                }
                if (changeGender == "男") i->gender = true;
                else if (changeGender == "女") i->gender = false;
                cout << "修改成功" << endl;
                break;
            }
            case 4:{  // 修改年龄
                int changeAge = 0;
                cout << "请输入修改后的年龄: ";
                cin >> changeAge;
                i->age = changeAge;
                cout << "修改成功" << endl;
                break;
            }
            default:{
                break;
            }
        }
        if (flag) break;
    }
}

void StudentManager::addStudentInfo(){  // 添加学生
    int mode = 0;
    cout << "请选择添加方式: " << endl;
    cout << "1. 命令行输入" << endl;
    cout << "2. 外部文件录入" << endl;  // 仅支持txt文件
    cin >> mode;
    switch (mode) {
        case 1:{
            int n;
            cout << "请输入要添加学生的数目: ";
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cout << "正在录入第" << i+1 << "个学生的信息: " << endl;
                addStudentFunction();
                cout << "第" << i+1 << "个学生的信息录入成功" << endl;
            }
            cout << "所有学生信息已录入" << endl;
            break;
        }
        case 2:{
            cout << "请输入文件路径: ";  // 相对路径、绝对路径均可
            string filepath;
            cin >> filepath;
            fstream ifs(filepath, ios::in);  // 这个读取文件的路径是以exe文件为起始路径的
            if (ifs.is_open()){  // 检查是否正常打开
                while (ifs >> student_number >> name >> gender >> age){  // 有数据的话就写入
                    Student s(student_number, name, gender, age);  // 用Student类接受数据，并创建自定义类型
                    StudentManager::info.push_back(s);  // 将该学生数据加入到list中
                }
                cout << "学生数据录入完毕" << endl;
            }
            else{
                cout << "文件无法打开" << endl;
                return;
            }
            ifs.close();
            break;
        }
        default:{
            break;
        }
    }
}
