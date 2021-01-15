#include <iostream>
#include "StudentManager.h"

using namespace std;

void printInputErrLog(){  // ��ӡ���������Ϣ
    cout << "�������" << endl;
}

int main() {
    StudentManager app;
    int op = 0;
    while (true){
        StudentManager::showMenu();
        cout << "�������ѡ��: ";
        cin >> op;
        switch (op) {
            case 1:{  // ���ѧ��
                int n;
                cout << "������Ҫ���ѧ������Ŀ: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    app.addStudent();
                }
                break;
            }
            case 2:{  // ����ѧ����Ϣ
                app.findStudent();
                break;
            }
            case 3:{  // �޸�ѧ����Ϣ
                app.modifyStudentInfo();
                break;
            }
            case 4:{  // ɾ��ѧ����Ϣ
                break;
            }
            case 5:{  // �˳�ϵͳ
                cout << "�˳��ɹ�" << endl;
                system("pause");
                exit(0);
            }
            default:{
                printInputErrLog();
                system("pause");
                system("cls");
                break;
            }
        }
    }
    system("pause");
    return 0;
}
