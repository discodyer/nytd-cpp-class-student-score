#ifndef SCOREMANAGEMENTSYSTEM_H_
#define SCOREMANAGEMENTSYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
#include "StudentList.h"
#include "TeacherList.h"
#include "CSV.h"
#include <algorithm>

using namespace std;

// void quickSort(int left, int right, vector<Student*>& arr, int subject);

class ScoreManagementSystem
{
private:
    StudentList slist;
    TeacherList tlist;
    string pathToStudents = "students.csv", pathToTeachers = "teachers.csv";
public:
    ScoreManagementSystem(string pathToStudents, string pathToTeachers);
    ~ScoreManagementSystem();
    void start();
    void login();
    void admin();
    void teacher();
    void student();
    void helpManual();
    void reloadFile();
    void showTeacherList();
    void showStudentList();
    // void sort(int subject);
    void edit();
};

#endif