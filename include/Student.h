#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <vector>

#define SUBJECT_CHINESE 0
#define SUBJECT_ENGLISH 1
#define SUBJECT_MATHS 2
#define SUBJECT_ALL 3
#define SUBJECT_NULL -1
using namespace std;

class Student
{
private:
    string id,name;
    int scoreChinese,scoreEnglish,scoreMaths,scoreTotal;
public:
    Student(string id, string name, int scoreChinese, int scoreEnglish, int scoreMaths, int scoreTotal);
    Student(string id, string name, int scoreChinese, int scoreEnglish, int scoreMaths);
    Student(string id, string name);
    Student();

    void setScore(int subject, int score);
    int getScore(int subject);
    void showScore();
    ~Student();
};

#endif