#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "StudentManager.h"
#include "Student.h"

using namespace std;

StudentManager::StudentManager(){
    cout << "��������ѧ����Ϣ�����Ժ�..." << endl;
    inputStudentInfo();
    system("cls");
}

StudentManager::~StudentManager() = default;

void StudentManager::showMenu() {  // ��ӡ�˵�
    cout << "********************************" << endl;
    cout << "********��ӭʹ��ѧ������ϵͳ********" << endl;
    cout << "**********1. ���ѧ��*************" << endl;
    cout << "**********2. ����ѧ����Ϣ**********" << endl;
    cout << "**********3. �޸�ѧ����Ϣ**********" << endl;
    cout << "**********4. ɾ��ѧ����Ϣ**********" << endl;
    cout << "**********5. �˳�ϵͳ*************" << endl;
    cout << "*********************************" << endl;
}

void StudentManager::inputStudentInfo() {  // ���ⲿ�ļ����ݼ��ص��ڴ���
    fstream ifs("../StudentInformation.txt", ios::in);  // �����ȡ�ļ���·������exe�ļ�Ϊ��ʼ·����
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
    else gender = false;
    cout << "������ѧ������: ";
    cin >> age;
    Student s(student_number, name, gender, age);  // �����µ�ѧ����
    StudentManager::info.push_back(s);  // ׷�ӵ�list
}

void StudentManager::findStudent() {  // ����ѧ��
    int findMode = 0;
    cout << "��ѡ�������ַ�ʽ����: " << endl;
    cout << "1. ѧ��" << endl;
    cout << "2. ����" << endl;
    cin >> findMode;
    if (findMode == 1) {
        int searchNum = 0;
        cout << "������ѧ��: " ;
        cin >> searchNum;
        auto index = find_if(info.begin(), info.end(), FindBasedOnNum(searchNum));
        if (index != info.end()){
            displayStudentInfo(index);
        }
        else{
            cout << "�鲻����ѧ��";
        }
    }
    else if (findMode == 2) {
        string searchName;
        bool flag = false;  // �ж��Ƿ�鵽ѧ��
        cout << "����������: ";
        cin >> searchName;
        for (auto i = info.begin(); i != info.end(); ++i){  // ѧ���п�����ͬ�������Բ���find_if
            if ((*i).name == searchName){
                displayStudentInfo(i);
                flag = true;
            }
        }
        if (!flag){
            cout << "�鲻����ѧ��";
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

void StudentManager::modifyStudentInfo(){

}
