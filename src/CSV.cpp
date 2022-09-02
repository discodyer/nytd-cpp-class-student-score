#include "CSV.h"


CSV::CSV()
{
    this->pathToStudents = "students.csv";
    this->pathToTeachers = "teachers.csv";
}

CSV::CSV(string pathToStudents, string pathToTeachers)
{
    this->pathToStudents = pathToStudents;
    this->pathToTeachers = pathToTeachers;
}

void CSV::setPath(string pathToStudents, string pathToTeachers)
{
    this->pathToStudents = pathToStudents;
    this->pathToTeachers = pathToTeachers;
}

CSV::~CSV()
{
}

void CSV::init(vector<Student>* studientList)
{
    this->readStudents(studientList);
}

void CSV::readStudents(vector<Student>* studientList)
{
    ifstream inFile;
    cout<<"opening file : "<< this->pathToStudents << endl;
    inFile.open(this->pathToStudents);
    if(!inFile.is_open())
    {
        cout<<"Could not open students file. Create a new file here?[Y/n]";
        char opt = getchar();
        if (opt == 'Y' || opt == 'y' || opt == '\n')
        {
            inFile.close();
            ofstream outFile;
            outFile.open(pathToStudents);
            outFile << "id,name,Chinese,English,Maths,Total" << endl;
            outFile.close();
            cout<< "Created a new file at : "<<pathToStudents<<endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            inFile.close();
            cout<<"Abort."<<endl;
            exit(EXIT_FAILURE);
        }
    }
    char tmpLine[1000] = "";
    inFile.getline(tmpLine, 1000);
    string tmpStringLine = tmpLine;
    if ( tmpStringLine == "id,name,Chinese,English,Maths,Total")
    {
        cout<<"file format is correct."<<endl;
    }
    else
    {
        cout<<"file format is NOT correct. Create a new file here?[Y/n]";
        char opt = getchar();
        if (opt == 'Y' || opt == 'y' || opt == '\n')
        {
            inFile.close();
            ofstream outFile;
            outFile.open(pathToStudents);
            outFile << "id,name,Chinese,English,Maths,Total" << endl;
            outFile.close();
            cout<< "Created a new file at : "<<pathToStudents<<endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            inFile.close();
            cout<<"Abort."<<endl;
            exit(EXIT_FAILURE);
        }
    }
    int count = 0;
    inFile.getline(tmpLine, 1000);
    while (inFile.good())
    {
        ++count;
        string tmpStringLine = tmpLine;
        vector<string> v;
        split(tmpStringLine, v, ",");
        inFile.getline(tmpLine, 1000);
    }
}

void split(string str,vector<string> &v,string spacer)
{
    int pos1,pos2;
    int len=spacer.length();     //记录分隔符的长度
    pos1=0;
    pos2=str.find(spacer);
    while( pos2 != string::npos )
    {
        v.push_back( str.substr(pos1,pos2-pos1) );
        pos1 = pos2 + len;
        pos2 = str.find(spacer,pos1);    // 从str的pos1位置开始搜寻spacer
    }
    if(pos1 != str.length()) //分割最后一个部分
       v.push_back(str.substr(pos1));
}