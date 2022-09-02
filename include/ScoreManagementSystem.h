#ifndef SCOREMANAGEMENTSYSTEM_H_
#define SCOREMANAGEMENTSYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "CSV.h"
#include <algorithm>

using namespace std;

void quickSort(int left, int right, vector<Student*>& arr, int subject);

class ScoreManagementSystem
{
private:
    vector<Student*> studentList;
    vector<Teacher*> teacherList;
    CSV csv;
public:
    ScoreManagementSystem(string pathToStudents, string pathToTeachers); // ¹¹Ôìº¯Êý
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
    void sort(int subject);
    void edit();
};

#endif