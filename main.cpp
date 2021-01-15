#include <iostream>
#include "StudentManager.h"

using namespace std;

void printInputErrLog(){  // 打印输入错误信息
    cout << "输入错误！" << endl;
}

int main() {
    StudentManager app;
    int op = 0;
    while (true){
        StudentManager::showMenu();
        cout << "输入你的选择: ";
        cin >> op;
        switch (op) {
            case 1:{  // 添加学生
                int n;
                cout << "请输入要添加学生的数目: ";
                cin >> n;
                for (int i = 0; i < n; ++i) {
                    app.addStudent();
                }
                break;
            }
            case 2:{  // 查找学生信息
                app.findStudent();
                break;
            }
            case 3:{  // 修改学生信息
                app.modifyStudentInfo();
                break;
            }
            case 4:{  // 删除学生信息
                break;
            }
            case 5:{  // 退出系统
                cout << "退出成功" << endl;
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
