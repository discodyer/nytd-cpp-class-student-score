#ifndef TEACHERLIST_H_
#define TEACHERLIST_H_

#include <iostream>
#include <string>
#include <vector>
#include "StudentList.h"
#define TEACHER_NOT_FOUND -1

using namespace std;

extern void jixu();
extern int subjectToInt(string subject);
extern string intToSubject(int subject);

struct tch
{
    string
        id = "",
        name = "";
    int
        subject = SUBJECT_NULL;
};

class TeacherList
{
private:
    vector<tch> list;

public:
    TeacherList();

    void deleteOne(int i);
    void deleteAll();
    void add();
    void add(string id, string name, int subject);
    void editSubject(int i);
    void editSubject(int i, int subject);
    void editID(int i, string id);
    void editID(int i);
    void editName(int i, string name);
    void editName(int i);
    string getID(int i);
    string getName(int i);
    int getSubject(int i);
    void show(int i);
    void showAll();
    int findID();
    int findName();
    int getSize();
    ~TeacherList();
};

#endif