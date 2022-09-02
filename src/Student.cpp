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