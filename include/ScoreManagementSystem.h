#ifndef SCOREMANAGEMENTSYSTEM_H_
#define SCOREMANAGEMENTSYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Teacher.h"

using namespace std;

class ScoreManagementSystem
{
private:
    vector<Student> studentList;
    vector<Teacher> teacherList;

    
public:
    ScoreManagementSystem(); // 无参构造函数
    ~ScoreManagementSystem();
    void init();
    void start();

    void setRating(); // 设置评级

    void output(); // 展示信息

    
};

#endif