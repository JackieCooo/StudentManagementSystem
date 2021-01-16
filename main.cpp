#include <iostream>
#include "StudentManager.h"

using namespace std;

int main() {
    StudentManager app;
    int op = 0;
    while (true){
        StudentManager::showMenu();  // 显示目录
        cout << "输入你的选择: ";
        cin >> op;
        switch (op) {
            case 1:{  // 添加学生
                app.addStudentInfo();
                system("pause");
                break;
            }
            case 2:{  // 查找学生信息
                app.findStudentInfo();
                system("pause");
                break;
            }
            case 3:{  // 修改学生信息
                app.modifyStudentInfo();
                system("pause");
                break;
            }
            case 4:{  // 删除学生信息
                app.deleteStudentInfo();
                system("pause");
                break;
            }
            case 5:{  // 查看所有学生信息
                app.displayAllStudents();
                system("pause");
                break;
            }
            case 6:{  // 退出系统
                app.exitSystem();
                cout << "系统退出成功" << endl;
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
