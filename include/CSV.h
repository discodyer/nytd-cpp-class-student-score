#ifndef CSV_H_
#define CSV_H_

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include <fstream>
#include <cstdlib>

using namespace std;

int subjectToInt(string subject);

string intToSubject(int subject);

void split(string str,vector<string> &v,string spacer); // csv条目分割函数

class CSV
{
private:
    string pathToStudents, pathToTeachers; // the path to .csv list files
public:
    CSV();
    CSV(string pathToStudents, string pathToTeachers);
    ~CSV();
    void setPath(string pathToStudents, string pathToTeachers);
    void init(vector<Student*> * studentList, vector<Teacher*> * teacherList);

    void readStudents(vector<Student*>& studentList);
    void readTeachers(vector<Teacher*> & teacherList);
    void writeStudients();
    void writeTeachers();
};

#endif