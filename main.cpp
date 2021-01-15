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
                    cout << "正在录入第" << i+1 << "个学生的信息: " << endl;
                    app.addStudent();
                    cout << "第" << i+1 << "个学生的信息录入成功" << endl;
                    system("pause");
                }
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
