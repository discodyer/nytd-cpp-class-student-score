#include "ScoreManagementSystem.h"

ScoreManagementSystem::ScoreManagementSystem(string pathToStudents, string pathToTeachers)
{
    this->csv.setPath(pathToStudents, pathToTeachers);
    this->csv.init(&this->studentList);
}

ScoreManagementSystem::~ScoreManagementSystem()
{

}

void ScoreManagementSystem::start()
{
    
}