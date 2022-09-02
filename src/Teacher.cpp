#include "Teacher.h"

Teacher::Teacher()
{
    this->id="NULL";
    this->name="NULL";
    this->subject=SUBJECT_NULL;
}

Teacher::~Teacher()
{
}

Teacher::Teacher(string id, string name, int subject)
{
    this->id=id;
    this->name=name;
    this->subject=subject;
}


void Teacher::setName(string name)
{
    this->name=name;
}
void Teacher::setID(string id)
{
    this->id=id;
}

void Teacher::setSubject(int subject)
{
    this->subject=subject;
}


string Teacher::getName()
{
    return this->name;
}
string Teacher::getID()
{
    return this->id;
}
int Teacher::getSubject()
{
    return this->subject;
}