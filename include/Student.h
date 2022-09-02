#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <vector>

#define LESSON_CHINESE 0
#define LESSON_ENGLISH 1
#define LESSON_MATHS 2
#define LESSON_TOTAL 3
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

    void setScore(int lesson, int score);
    int getScore(int lesson);
    void showScore();
    ~Student();
};

#endif