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

void split(string str,vector<string> &v,string spacer);

class CSV
{
private:
    string pathToStudents, pathToTeachers; // the path to .csv list files
public:
    CSV();
    CSV(string pathToStudents, string pathToTeachers);
    ~CSV();
    void setPath(string pathToStudents, string pathToTeachers);
    void init(vector<Student>* studientList);

    void readStudents(vector<Student>* studientList);
    void readTeachers();
    void writeStudients();
    void writeTeachers();
};

#endif