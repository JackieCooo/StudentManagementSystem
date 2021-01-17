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
    cout << "*********6. ����¼��ѧ���ɼ�********" << endl;
    cout << "*********7. �鿴����ѧ���ɼ�********" << endl;
    cout << "*********8. �޸�ѧ���ɼ�***********" << endl;
    cout << "*********9. �˳�ϵͳ**************" << endl;
    cout << "*********************************" << endl;
}

void StudentManager::inputStudentInfo() {  // ���ⲿ�ļ����ݼ��ص��ڴ���
    fstream ifs(StudentInformation, ios::in);  // �����ȡ�ļ���·������exe�ļ�Ϊ��ʼ·����
    if (ifs.is_open()){  // ����Ƿ�������
        while (true){
            string d1, d2, d3, d4;
            ifs >> d1 >> d2 >> d3 >> d4;
            if (d1 == "-" && d2 == "-" && d3 == "-" && d4 == "-") break;  // 4��-����ʾ��Ϣ���ݽ��ܽ���
            student_number = stoi(d1);
            name = d2;
            gender = stoi(d3);
            age = stoi(d4);
            Student s(student_number, name, gender, age);  // ��Student��������ݣ��������Զ�������
            info.push_back(s);  // ����ѧ�����ݼ��뵽list��
        }
        cout << "ѧ�������������" << endl;
        vector<string> v;
        while (true){
            string d;
            ifs >> d;
            if (d == "-") break;  // ��ʾ��Ŀ���ͽ��ܽ���
            v.push_back(d);  // ����vector�����Ŀ����
        }
        // ����ѧ���ɼ�
        for (auto &i : info) {
            for (auto & j : v) {
                int d;
                ifs >> d;
                Score s(j, d);
                i.score.push_back(s);
            }
        }
        cout << "ѧ���ɼ��������" << endl;
    }
    else{
        cout << "�ļ��޷���" << endl;
        return;
    }
    ifs.close();
}

void StudentManager::addStudentFunction() {  // ���ѧ�����ܺ���
    string t;
    cout << "������ѧ��ѧ��: ";
    cin >> student_number;
    cout << "������ѧ������: ";
    cin >> name;
    cout << "������ѧ���Ա�: ";
    cin >> t;
    while (t != "��" || t != "Ů"){
        cout << "�����������������: ";
        cin >> t;
    }
    if (t == "��") gender = true;  // gender�ڳ�������bool���ʹ��棬����Ҫ��ת��
    else if (t == "Ů") gender = false;
    cout << "������ѧ������: ";
    cin >> age;
    Student s(student_number, name, gender, age);  // �����µ�ѧ����
    StudentManager::info.push_back(s);  // ׷�ӵ�list
}

void StudentManager::displayStudentInfo(list<Student>::iterator &i){  // ��ӡѧ����Ϣ
    cout << "ѧ��: " << i->student_number << "\t����: " << i->name << "\t�Ա�: ";
    if (i->gender == 1) cout << "��";
    else cout << "Ů";
    cout << "\t����: " << i->age << endl;
}

void StudentManager::saveStudentInfo(){  // ����ѧ����Ϣ
    ofstream ofs;
    ofs.open(StudentInformation, ios::out);
    for (auto &i : info){  // ����ѧ����Ϣ
        ofs << i.student_number << " " << i.name << " " << i.gender << " " << i.age << endl;
    }
    ofs << "- - - -" << endl;
    if (!info.empty()){  // �����Ŀ����
        for (auto &i : info.front().score){
            ofs << i.subject << endl;
        }
    }
    ofs << "-" << endl;
    for (auto &i : info){  // ����ɼ�
        for (auto &j : i.score){
            ofs << j.score << " ";
        }
        ofs << endl;
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
    cout << "��ѡ����ҷ�ʽ: " << endl;
    cout << "1. ѧ��" << endl;
    cout << "2. ����" << endl;
    int mode = 0;
    cin >> mode;
    if (mode == 1){
        int searchNum = 0;
        cout << "������ѧ��ѧ��:" << endl;
        cin >> searchNum;
        auto index = findStudent(searchNum);
        if (index != info.end()){
            info.erase(index);
        }
        else{
            cout << "�鲻����ѧ��" << endl;
        }
    }
    else if (mode == 2){
        string searchName;
        cout << "������ѧ������: ";
        cin >> searchName;
        vector<list<Student>::iterator> v = findStudent(searchName);
        if (!v.empty()){
            int j = 1;
            for (auto &i : v){
                cout << "���: " << j++ << "\t";
                displayStudentInfo(i);
            }
            cout << "����Ҫ�޸ĵ�ѧ�������: ";
            int n;
            cin >> n;
            info.erase(v[n-1]);
        }
        else {
            cout << "�鲻����ѧ��" << endl;
        }
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

void StudentManager::modifyStudentInfo(list<Student>::iterator &i){  // �޸�ѧ����Ϣ���ܺ���
    int mode = 0;
    bool flag = false;  // while�˳���־
    cout << "������Ҫ�޸�ѧ������Ϣ: " << endl;
    cout << "1. ѧ��" << endl;
    cout << "2. ����" << endl;
    cout << "3. �Ա�" << endl;
    cout << "4. ����" << endl;
    cout << "����0�˳���ѧ����Ϣ���޸�" << endl;
    while (true){
        cin >> mode;
        switch (mode) {
            case 0:{  // �˳��޸�
                cout << "��ѧ���޸��ѱ���" << endl;
                flag = true;
                break;
            }
            case 1:{  // �޸�ѧ��
                int changeNum = 0;
                cout << "�������޸ĺ��ѧ��: ";
                cin >> changeNum;
                i->student_number = changeNum;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            case 2:{  // �޸�����
                string changeName;
                cout << "�������޸ĺ������: ";
                cin >> changeName;
                i->name = changeName;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            case 3:{  // �޸��Ա�
                string changeGender;
                cout << "�������޸ĺ���Ա�: ";
                cin >> changeGender;
                while (changeGender != "��" || changeGender != "Ů"){
                    cout << "�����������������: ";
                    cin >> changeGender;
                }
                if (changeGender == "��") i->gender = true;
                else if (changeGender == "Ů") i->gender = false;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            case 4:{  // �޸�����
                int changeAge = 0;
                cout << "�������޸ĺ������: ";
                cin >> changeAge;
                i->age = changeAge;
                cout << "�޸ĳɹ�" << endl;
                break;
            }
            default:{
                break;
            }
        }
        if (flag) break;
    }
}

void StudentManager::addStudentInfo(){  // ���ѧ��
    int mode = 0;
    cout << "��ѡ����ӷ�ʽ: " << endl;
    cout << "1. ����������" << endl;
    cout << "2. �ⲿ�ļ�¼��" << endl;  // ��֧��txt�ļ�
    cin >> mode;
    switch (mode) {
        case 1:{
            int n;
            cout << "������Ҫ���ѧ������Ŀ: ";
            cin >> n;
            for (int i = 0; i < n; ++i) {
                cout << "����¼���" << i+1 << "��ѧ������Ϣ: " << endl;
                addStudentFunction();
                cout << "��" << i+1 << "��ѧ������Ϣ¼��ɹ�" << endl;
            }
            cout << "����ѧ����Ϣ��¼��" << endl;
            break;
        }
        case 2:{
            cout << "�������ļ�·��: ";  // ���·��������·������
            string filepath;
            cin >> filepath;
            fstream ifs(filepath, ios::in);  // �����ȡ�ļ���·������exe�ļ�Ϊ��ʼ·����
            if (ifs.is_open()){  // ����Ƿ�������
                while (ifs >> student_number >> name >> gender >> age){  // �����ݵĻ���д��
                    auto index = find_if(info.begin(), info.end(), FindBasedOnNum(student_number));
                    if (index != info.end()){  // ����Ƿ����Ѵ���ѧ����Ϣ������ѧ�ţ���Ϊѧ�Ų����ظ�
                        cout << "ԭ�ļ�: " << endl;
                        displayStudentInfo(index);
                        cout << "�ⲿ�ļ�: " << endl;
                        cout << "ѧ��: " << student_number << "\t����: " << name << "\t�Ա�: ";
                        if (gender == 1) cout << "��";
                        else cout << "Ů";
                        cout << "\t����: " << age << endl;
                        cout << "������Ϣ���ص����Ƿ�Ҫ����(y/n): ";
                        char choice;
                        cin >> choice;
                        if (choice == 'y'){
                            Student s(student_number, name, gender, age);  // ��Student��������ݣ��������Զ�������
                            info.push_back(s);  // ����ѧ�����ݼ��뵽list��
                        }
                    }
                    else{
                        Student s(student_number, name, gender, age);  // ��Student��������ݣ��������Զ�������
                        info.push_back(s);  // ����ѧ�����ݼ��뵽list��
                    }
                }
                cout << "ѧ������¼�����" << endl;
            }
            else{
                cout << "�ļ��޷���" << endl;
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

void StudentManager::uploadStudentScores(){  // ѧ���ɼ�¼��
    if (info.empty()){
        cout << "û���κ�ѧ����Ϣ�������ѧ��" << endl;
        return;
    }
    cout << "������¼��ķ�ʽ: " << endl;
    cout << "1. ������¼��" << endl;
    cout << "2. �ⲿ�ļ�¼��" << endl;
    int mode = 0;
    cin >> mode;
    if (mode == 1){
        uploadScoresFunction();
    }
    else if (mode == 2){
        cout << "�������ļ�·��: ";  // ���·��������·������
        string filepath;
        cin >> filepath;
        fstream ifs(filepath, ios::in);  // �����ȡ�ļ���·������exe�ļ�Ϊ��ʼ·����
        if (ifs.is_open()){  // ����Ƿ�������
            vector<string>v;
            while (true){  // ¼���Ŀ����
                string d;
                ifs >> d;
                if (d == "-") break;  // ��ʾ��Ŀ����¼�����
                v.push_back(d);
            }
            int temp[v.size()][info.size()];  // ����ʱ�������ɼ�
            for (int i = 0; i < v.size(); ++i) {
                for (int j = 0; j < info.size(); ++j) {
                    ifs >> temp[i][j];
                }
            }
            for (int i = 0; i < v.size(); ++i){  // �����Ŀ¼��
                auto index = find_if(info.front().score.begin(), info.front().score.end(), FindBasedOnString(v[i]));
                if (index != info.front().score.end()){  // ����Ƿ����Ѵ��ڸÿ�Ŀ�ɼ�
                    cout << index->subject << "�ɼ��Ѵ��ڣ��Ƿ�Ҫ����(y/n): ";
                    char choice;
                    cin >> choice;
                    if (choice == 'y'){
                        int k = 0;
                        for (auto &j : info){  // ���ѧ��¼��
                            index = find_if(j.score.begin(), j.score.end(), FindBasedOnString(v[i]));  // Ѱ�ҳɼ�λ��
                            index->score = temp[i][k];  // �޸ĳɼ�
                            ++k;
                        }
                    }
                    else continue;
                }
                else{
                    int k = 0;
                    for (auto &j : info){  // ���ѧ��¼��
                        Score s(v[i], temp[i][k]);
                        j.score.push_back(s);
                        ++k;
                    }
                }
            }
            cout << "ѧ������¼�����" << endl;
        }
        else{
            cout << "�ļ��޷���" << endl;
            return;
        }
        ifs.close();
    }
}

void StudentManager::uploadScoresFunction(){  // �ɼ�¼�빦�ܺ���
    cout << "��ѡ��Ҫ¼��Ŀ�Ŀ: " << endl;
    cout << "0. �����Ŀ" << endl;
    if (!info.front().score.empty()){  // �жϳɼ��б��Ƿ�Ϊ��
        int j = 1;
        for (auto &i : info.front().score) {  // ���������Ŀ
            cout << j++ << ". " << i.subject << endl;
        }
    }
    int choice;
    cin >> choice;
    string subjectName;
    if (choice == 0){
        cout << "�������Ŀ��: ";
        cin >> subjectName;
        if (find_if(info.front().score.begin(), info.front().score.end(), FindBasedOnString(subjectName)) != info.front().score.end()){  // �鿴�Ƿ��Ѿ��д˿�Ŀ
            cout << "�˿�Ŀ�Ѵ���" << endl;
        }
    }
    for (auto &i : info){  // ���ѧ��¼��
        int n;
        cout << "������ѧ��Ϊ" << i.student_number << "��" << i.name << "ͬѧ��" << i.score[choice-1].subject << "�ɼ�: ";
        cin >> n;  // ���������������ͬѧ�ĳɼ�¼�룬����-1
        if (!choice){  // ���˿�ĿΪ�¼ӿ�Ŀ
            Score s(subjectName, n);  // ������Score��
            i.score.push_back(s);  // ѹ��vector
        }
        else{
            i.score[choice-1].score = n;
        }
    }
}

void StudentManager::displayAllStudentScores(){  // ���ȫ��ѧ���ɼ�
    for (auto &i : info){
        cout << "ѧ��: " << i.student_number << "\t����: " << i.name << "\t";
        for (auto &j : i.score){
            if (j.score == -1) cout << j.subject << ": �޳ɼ�\t";
            else cout << j.subject << ": " << j.score << "\t";
        }
        cout << endl;
    }
}

void StudentManager::findClass(void (*pointerToFunc)(list<Student>::iterator &i)) {
    cout << "��ѡ����ҷ�ʽ: " << endl;
    cout << "1. ѧ��" << endl;
    cout << "2. ����" << endl;
    int mode = 0;
    cin >> mode;
    if (mode == 1){
        int searchNum = 0;
        cout << "������ѧ��ѧ��:" << endl;
        cin >> searchNum;
        auto index = findStudent(searchNum);
        if (index != info.end()){
            (*pointerToFunc)(index);
        }
        else{
            cout << "�鲻����ѧ��" << endl;
        }
    }
    else if (mode == 2){
        string searchName;
        cout << "������ѧ������: ";
        cin >> searchName;
        vector<list<Student>::iterator> v = findStudent(searchName);
        if (!v.empty()){
            int j = 1;
            for (auto &i : v){
                cout << "���: " << j++ << "\t";
                displayStudentInfo(i);
            }
            cout << "����Ҫ�޸ĵ�ѧ�������: ";
            int n;
            cin >> n;
            (*pointerToFunc)(v[n-1]);
        }
        else {
            cout << "�鲻����ѧ��" << endl;
        }
    }
}

void StudentManager::modifyStudentScoreFunction(list<Student>::iterator &i) {  // �޸�ѧ���ɼ�
    if (info.empty()){
        cout << "û���κ�ѧ����Ϣ�������ѧ��" << endl;
        return;
    }
    if (i->score.empty()){
        cout << "û���κεĿ�Ŀ��Ϣ���뵽����¼��ѧ���ɼ��½���Ŀ" << endl;
        return;
    }
    string subjectName;
    cout << "������Ҫ�޸ĵĿ�Ŀ:" << endl;
    int k = 1;
    for (auto &j : info.front().score){
        cout << k++ << ". " << j.subject << endl;
    }
    cin >> subjectName;
    int n;
    cout << "���������:" << endl;
    cin >> n;
    auto index = find_if(i->score.begin(), i->score.end(), FindBasedOnString(subjectName));  // ��ȡĿ�������
    if (index != i->score.end()){
        index->score = n;
    }
    else{
        cout << "��Ŀ������" << endl;
    }
}

void StudentManager::modifyStudentScore() {
    cout << "��ѡ����ҷ�ʽ: " << endl;
    cout << "1. ѧ��" << endl;
    cout << "2. ����" << endl;
    int mode = 0;
    cin >> mode;
    if (mode == 1){
        int searchNum = 0;
        cout << "������ѧ��ѧ��:" << endl;
        cin >> searchNum;
        auto index = findStudent(searchNum);
        if (index != info.end()){
            modifyStudentScoreFunction(index);
        }
        else{
            cout << "�鲻����ѧ��" << endl;
        }
    }
    else if (mode == 2){
        string searchName;
        cout << "������ѧ������: ";
        cin >> searchName;
        vector<list<Student>::iterator> v = findStudent(searchName);
        if (!v.empty()){
            int j = 1;
            for (auto &i : v){
                cout << "���: " << j++ << "\t";
                displayStudentInfo(i);
            }
            cout << "����Ҫ�޸ĵ�ѧ�������: ";
            int n;
            cin >> n;
            modifyStudentScoreFunction(v[n-1]);
        }
        else {
            cout << "�鲻����ѧ��" << endl;
        }
    }
}

bool FindBasedOnNum::operator()(Student &s) const{
    return s.student_number == searchNum;
}

FindBasedOnNum::FindBasedOnNum(int n){
    this->searchNum = n;
}

FindBasedOnString::FindBasedOnString(string &s){
    this->searchStr = s;
}

bool FindBasedOnString::operator()(Score &s) const{
    return s.subject == searchStr;
}
