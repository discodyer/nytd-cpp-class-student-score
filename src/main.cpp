#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
    string pathToStudents = "students.csv", pathToTeachers = "teachers.csv"; // the path to .csv list files
    ScoreManagementSystem S(pathToStudents, pathToTeachers);                 // 实例化管理系统
    S.start();                                                               // 入口函数
    return 0;
}

void jixu()
{
    cout << "请按回车键继续...";
    cin.get();
    cin.get();
}