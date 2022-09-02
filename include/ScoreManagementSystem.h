#ifndef SCOREMANAGEMENTSYSTEM_H_
#define SCOREMANAGEMENTSYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "CSV.h"

using namespace std;

class ScoreManagementSystem
{
private:
    vector<Student> studentList;
    vector<Teacher> teacherList;
    CSV csv;
public:
    ScoreManagementSystem(string pathToStudents, string pathToTeachers); // 无参构造函数
    ~ScoreManagementSystem();
    void start();
};

#endif