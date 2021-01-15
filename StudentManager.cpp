#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "StudentManager.h"
#include "GlobalPath.h"

using namespace std;

StudentManager::StudentManager() {
    cout << "��������ѧ����Ϣ�����Ժ�..." << endl;
    inputStudentInfo();
    system("cls");
}

StudentManager::~StudentManager() = default;

void StudentManager::showMenu() {  // ��ӡ�˵�
    cout << "********************************" << endl;
    cout << "********��ӭʹ��ѧ������ϵͳ********" << endl;
    cout << "*********1. ���ѧ��**************" << endl;
    cout << "*********2. ����ѧ����Ϣ***********" << endl;
    cout << "*********3. �޸�ѧ����Ϣ***********" << endl;
    cout << "*********4. ɾ��ѧ����Ϣ***********" << endl;
    cout << "*********5. �鿴����ѧ����Ϣ********" << endl;
    cout << "*********6. �˳�ϵͳ**************" << endl;
    cout << "*********************************" << endl;
}

void StudentManager::inputStudentInfo() {  // ���ⲿ�ļ����ݼ��ص��ڴ���
    fstream ifs(StudentInformation, ios::in);  // �����ȡ�ļ���·������exe�ļ�Ϊ��ʼ·����
    if (ifs.is_open()){  // ����Ƿ�������
        while (ifs >> student_number >> name >> gender >> age){  // �����ݵĻ���д��
            Student s(student_number, name, gender, age);  // ��Student��������ݣ��������Զ�������
            StudentManager::info.push_back(s);  // ����ѧ�����ݼ��뵽list��
        }
        cout << "ѧ�������������" << endl;
    }
    else{
        cout << "�ļ��޷���" << endl;
        return;
    }
    ifs.close();
}

void StudentManager::addStudent() {  // ���ѧ��
    string t;
    cout << "������ѧ��ѧ��: ";
    cin >> student_number;
    cout << "������ѧ������: ";
    cin >> name;
    cout << "������ѧ���Ա�: ";
    cin >> t;
    if (t == "��") gender = true;  // gender�ڳ�������bool���ʹ��棬����Ҫ��ת��
    else if (t == "Ů") gender = false;
    cout << "������ѧ������: ";
    cin >> age;
    Student s(student_number, name, gender, age);  // �����µ�ѧ����
    StudentManager::info.push_back(s);  // ׷�ӵ�list
}

void StudentManager::findStudentInfo() {  // ����ѧ��
    int findMode = 0;
    cout << "��ѡ�������ַ�ʽ����: " << endl;
    cout << "1. ѧ��" << endl;
    cout << "2. ����" << endl;
    cin >> findMode;
    if (findMode == 1) {
        int searchNum = 0;
        cout << "������ѧ��: " ;
        cin >> searchNum;
        auto index = findStudent(searchNum);
        if (index != info.end()){
            displayStudentInfo(index);
        }
        else{
            cout << "�鲻����ѧ��" << endl;
        }
    }
    else if (findMode == 2) {
        string searchName;
        cout << "����������: ";
        cin >> searchName;
        vector<list<Student>::iterator> v = findStudent(searchName);
        if (!v.empty()){  // ���vector�Ƿ�Ϊ�գ��ռ�Ϊ�鲻��
            for (auto &i : v){
                displayStudentInfo(i);
            }
        }
        else{
            cout << "�鲻����ѧ��" << endl;
        }
    }
    else{

    }
}

void StudentManager::displayStudentInfo(list<Student>::iterator &i){  // ��ӡѧ����Ϣ
    cout << "ѧ��: " << i->student_number << "\t����: " << i->name << "\t�Ա�: ";
    if (i->gender == 1) cout << "��";
    else cout << "Ů";
    cout << "\t����: " << i->age << endl;
}

bool FindBasedOnNum::operator()(Student &s) const{
    return s.student_number == searchNum;
}

FindBasedOnNum::FindBasedOnNum(int n){
    this->searchNum = n;
}

void StudentManager::modifyStudentInfo(){  // �޸�ѧ����Ϣ

}

void StudentManager::printErrInpLog(){
    cout << "�������" << endl;
}

void StudentManager::saveStudentInfo(){  // ����ѧ����Ϣ
    ofstream ofs;
    ofs.open(StudentInformation, ios::out);
    for (auto &i : info){
        ofs << i.student_number << " " << i.name << " " << i.gender << " " << i.age << endl;
    }
    ofs.close();
    cout << "ѧ����Ϣ�������" << endl;
}

void StudentManager::exitSystem() {  // �˳�ϵͳ
    cout << "���ڱ���ѧ����Ϣ�����Ժ�..." << endl;
    saveStudentInfo();
    system("cls");
}

void StudentManager::displayAllStudents(){  // �鿴����ѧ����Ϣ
    if (!info.empty()){
        for (auto i = info.begin(); i != info.end(); ++i){
            displayStudentInfo(i);
        }
    }
    else{
        cout << "����ѧ����Ϣ" << endl;
    }
}

void StudentManager::deleteStudentInfo(){  // ɾ��ѧ����Ϣ
    int searchNum = 0;
    cout << "������ѧ��ѧ��:" << endl;
    cin >> searchNum;
    auto index = findStudent(searchNum);
    if (index != info.end()){
        info.erase(index);  // ɾ����Ϣ
        cout << "ѧ����Ϣɾ���ɹ�" << endl;
    }
    else{
        cout << "�鲻����ѧ��" << endl;
    }
}

list<Student>::iterator StudentManager::findStudent(int searchNum){  // ���ҹ��ܺ���������list�ĵ�����
    auto index = find_if(info.begin(), info.end(), FindBasedOnNum(searchNum));
    if (index != info.end()){
        return index;
    }
    else{
        return info.end();
    }
}

vector<list<Student>::iterator> StudentManager::findStudent(string &searchName){  // ���ҹ��ܺ�����������list�ĵ�����ΪԪ�ص�vector
    vector<list<Student>::iterator> res;
    for (auto i = info.begin(); i != info.end(); ++i){  // ѧ���п�����ͬ�������Բ���find_if
        if ((*i).name == searchName){
            res.push_back(i);
        }
    }
    return res;
}
