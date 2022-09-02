#include "Student.h"

Student::Student(/* args */)
{
    this->id="";
    this->name="";
    this->scoreChinese=0;
    this->scoreEnglish=0;
    this->scoreMaths=0;
    this->scoreTotal=0;
}

Student::Student(string id,string name,int scoreChinese,int scoreEnglish,int scoreMaths,int scoreTotal)
{
    this->id=id;
    this->name=name;
    this->scoreChinese=scoreChinese;
    this->scoreEnglish=scoreEnglish;
    this->scoreMaths=scoreMaths;
    this->scoreTotal=scoreTotal;
}

Student::Student(string id,string name,int scoreChinese,int scoreEnglish,int scoreMaths)
{
    this->id=id;
    this->name=name;
    this->scoreChinese=scoreChinese;
    this->scoreEnglish=scoreEnglish;
    this->scoreMaths=scoreMaths;
    this->scoreTotal=scoreChinese+scoreEnglish+scoreMaths;
}

Student::Student(string id,string name)
{
    this->id=id;
    this->name=name;
    this->scoreChinese=0;
    this->scoreEnglish=0;
    this->scoreMaths=0;
    this->scoreTotal=0;
}

void Student::showScore()
{
    cout<<"id\tname\tChinese\tEnglish\tMaths\tTotal"<<endl;
    cout<<this->id<<'\t'<<this->name<<'\t'<<this->scoreChinese<<'\t'<<this->scoreEnglish<<'\t'<<this->scoreMaths<<'\t'<<this->scoreTotal<<endl;
}


Student::~Student()
{
}

string Student::getID()
{
    return this->id;
}
string Student::getName()
{
    return this->name;
}

void Student::setScore(int subject, int score)
{
    switch (subject)
    {
    case(SUBJECT_CHINESE):
        this->scoreChinese=score;
        break;
    case(SUBJECT_ENGLISH):
        this->scoreEnglish=score;
        break;
    case(SUBJECT_MATHS):
        this->scoreMaths=score;
        break;
    default:
        break;
    }
    this->scoreTotal=this->scoreChinese+this->scoreEnglish+this->scoreMaths;
}

int Student::getScore(int subject)
{
    switch (subject)
    {
    case(SUBJECT_CHINESE):
        return this->scoreChinese;
        break;
    case(SUBJECT_ENGLISH):
        return this->scoreEnglish;
        break;
    case(SUBJECT_MATHS):
        return this->scoreMaths;
        break;
    default:
        this->scoreTotal=this->scoreChinese+this->scoreEnglish+this->scoreMaths;
        return this->scoreTotal;
        break;
    }
}