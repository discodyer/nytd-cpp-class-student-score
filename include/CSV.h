#ifndef CSV_H_
#define CSV_H_

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Teacher.h"

using namespace std;

class CSV
{
private:
    /* data */
public:
    CSV(string pathToStudents, string pathToTeachers);
    ~CSV();

    void readStudents(vector<Student>* studientList);
    void readTeachers();
    void writeStudients();
    void writeTeachers();
};

#endif