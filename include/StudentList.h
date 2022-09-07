#ifndef STUDENTLIST_H_
#define STUDENTLIST_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>

#define SUBJECT_CHINESE 0
#define SUBJECT_ENGLISH 1
#define SUBJECT_MATHS 2
#define SUBJECT_ALL 3
#define SUBJECT_NULL -1
#define STUDENT_NOT_FOUND -1

using namespace std;

extern void jixu();
extern int subjectToInt(string subject);

struct stu
{
    string
        id = "",
        name = "";
    int
        scoreChinese = 0,
        scoreEnglish = 0,
        scoreMaths = 0,
        scoreTotal = 0;
};

class StudentList
{
private:
    vector<stu> list;

public:
    StudentList();

    void deleteOne(int i);
    void deleteAll();
    void add();
    void add(string id, string name, int scoreChinese, int scoreEnglish, int scoreMaths);
    void editScore(int i);
    void editScore(int i, int subject, int score);
    void editID(int i, string id);
    void editID(int i);
    void editName(int i, string name);
    void editName(int i);
    string getID(int i);
    string getName(int i);
    int getScore(int i, int subject);
    void show(int i);
    void showAll();
    int findID();
    int findName();
    void sort();
    void sort(int subject);
    void sortSubject(int subject);
    int getSize();
    ~StudentList();
};

#endif