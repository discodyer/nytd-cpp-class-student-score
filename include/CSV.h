#ifndef CSV_H_
#define CSV_H_

#include <iostream>
#include <string>
#include <vector>
#include "StudentList.h"
#include "TeacherList.h"
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
    void read(StudentList* slist, TeacherList* tlist);
    void save(StudentList* slist, TeacherList* tlist);

    void readStudents(StudentList* slist);
    void readTeachers(TeacherList* tlist);
    void writeStudents(StudentList* slist);
    void writeTeachers(TeacherList* tlist);
};

#endif