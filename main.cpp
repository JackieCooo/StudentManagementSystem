#include <iostream>
#include "StudentManager.h"

using namespace std;

int main() {
    StudentManager app;
    int op = 0;
    while (true){
        StudentManager::showMenu();  // ��ʾĿ¼
        cout << "�������ѡ��: ";
        cin >> op;
        switch (op) {
            case 1:{  // ���ѧ��
                app.addStudentInfo();
                system("pause");
                break;
            }
            case 2:{  // ����ѧ����Ϣ
                app.findClass(StudentManager::displayStudentInfo);
                system("pause");
                break;
            }
            case 3:{  // �޸�ѧ����Ϣ
                app.findClass(StudentManager::modifyStudentInfo);
                system("pause");
                break;
            }
            case 4:{  // ɾ��ѧ����Ϣ
                app.deleteStudentInfo();
                system("pause");
                break;
            }
            case 5:{  // �鿴����ѧ����Ϣ
                app.displayAllStudents();
                system("pause");
                break;
            }
            case 6:{  // ¼��ѧ���ɼ�
                app.uploadStudentScores();
                system("pause");
                break;
            }
            case 7:{  // �鿴����ѧ���ɼ�
                app.displayAllStudentScores();
                system("pause");
                break;
            }
            case 8:{  // �޸�ѧ���ɼ�
                app.modifyStudentScore();
                system("pause");
                break;
            }
            case 9:{  // �˳�ϵͳ
                app.exitSystem();
                cout << "ϵͳ�˳��ɹ�" << endl;
                system("pause");
                exit(0);
            }
            default:{
                system("pause");
                system("cls");
                break;
            }
        }
    }
    system("pause");
    return 0;
}
