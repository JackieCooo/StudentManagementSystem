# StudentManagementSystem
# 学生管理系统
  
## 注意事项：  
  
1. 使用外部文件输入时，若填写相对路径，以cmake-build-debug文件夹下的.exe文件为起始。  
2. 学生信息外部文件导入格式，在项目根目录下有一个样例文件OutsideStudentInformationImportExample.txt。学生的信息有4种，分别是学号，姓名，性别，年龄。性别的表示用0和1表示，0代表女，1代表男。  
3. 学生成绩外部文件导入格式，在项目根目录下有一个样例文件OutsideStudentScoreImportExample.txt。首先输入科目的类型，这个类型可以与数据文件重叠，程序会自动提示是否覆盖，科目类型输入完用1条“-”表示输入结束。接下来是一个矩阵，矩阵的n行代表第n个同学的每一科成绩，成绩的顺序按照上面输入的顺序。要注意，如果该科没有成绩的话，输入-1来表示。  
4. IDE里面，文件的解码方式改为GBK，不然中文无法正常显示。  
