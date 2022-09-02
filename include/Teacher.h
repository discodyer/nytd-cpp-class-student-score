#ifndef TEACHER_H_
#define TEACHER_H_

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

class Teacher
{
private:
    string id;
    string name;
    int subject;
public:
    Teacher();
    Teacher(string id, string name, int subject);

    ~Teacher();

    void setName(string name);
    void setID(string id);
    void setSubject(int subject);

    string getName();
    string getID() ;
    int getSubject();
    
};


#endif