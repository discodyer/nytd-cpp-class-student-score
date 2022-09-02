#include "ScoreManagementSystem.h"

/**
 * @brief Construct a new Score Management System:: Score Management System object
 * 
 * @param pathToStudents 
 * @param pathToTeachers 
 */
ScoreManagementSystem::ScoreManagementSystem(string pathToStudents, string pathToTeachers)
{
    this->csv.setPath(pathToStudents, pathToTeachers);
    this->csv.init(&this->studentList, &this->teacherList);
}

/**
 * @brief Destroy the Score Management System:: Score Management System object
 * 
 */
ScoreManagementSystem::~ScoreManagementSystem()
{
    this->csv.~CSV();
    for (auto it : this->studentList)//手动内存释放
	    delete it;
	this->studentList.clear();
	vector<Student*>().swap(studentList);
    for (auto it : this->teacherList)//手动内存释放
	    delete it;
	this->teacherList.clear();
	vector<Teacher*>().swap(teacherList);
}

void ScoreManagementSystem::start()
{
    
}