#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
    string pathToStudents = "students.csv", pathToTeachers = "teachers.csv"; // the path to .csv list files
    ScoreManagementSystem S(pathToStudents, pathToTeachers);                 // ʵ��������ϵͳ
    S.start();                                                               // ��ں���
    return 0;
}

void jixu()
{
    cout << "�밴�س�������...";
    cin.get();
    cin.get();
}