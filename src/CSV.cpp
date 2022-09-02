#include "CSV.h"

/**
 * @brief Construct a new CSV::CSV object
 * 
 */
CSV::CSV()
{
    this->pathToStudents = "students.csv";
    this->pathToTeachers = "teachers.csv";
}

/**
 * @brief Construct a new CSV::CSV object
 * 
 * @param pathToStudents 学生数据文件路径
 * @param pathToTeachers 教师数据文件路径
 */
CSV::CSV(string pathToStudents, string pathToTeachers)
{
    this->pathToStudents = pathToStudents;
    this->pathToTeachers = pathToTeachers;
}

/**
 * @brief 
 * 
 * @param pathToStudents 学生数据文件路径
 * @param pathToTeachers 教师数据文件路径
 */
void CSV::setPath(string pathToStudents, string pathToTeachers)
{
    this->pathToStudents = pathToStudents;
    this->pathToTeachers = pathToTeachers;
}

/**
 * @brief Destroy the CSV::CSV object
 * 
 */
CSV::~CSV()
{
}


void CSV::init(vector<Student*> * studentList, vector<Teacher*> * teacherList)
{
    this->readStudents(*studentList);
    this->readTeachers(*teacherList);
}

/**
 * @brief 读取学生数据
 * 
 * @param studentList 学生数组
 */
void CSV::readStudents(vector<Student*> & studentList)
{
    ifstream inFile;
    cout<<"opening file : "<< this->pathToStudents << endl;
    inFile.open(this->pathToStudents);
    if(!inFile.is_open()) // 判断文件能否打开
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
    if ( tmpStringLine == "id,name,Chinese,English,Maths,Total") // 文件合法性检测
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

    // vector <Student>().swap(studentList);
    for (auto it : studentList)//手动内存释放
	    delete it;
	studentList.clear();
	vector<Student*>().swap(studentList);

    // int count = 0;
    inFile.getline(tmpLine, 1000);   // 读取一行数据
    while (inFile.good())
    {
        // ++count;
        vector<string> v;
        split(tmpLine, v, ","); // 将读取到的行切分成字符串数组v
        studentList.push_back(new Student(v[0],v[1],stoi(v[2]),stoi(v[3]),stoi(v[4]),stoi(v[5]))); // 将读取到的一行转换为Student对象
        inFile.getline(tmpLine, 1000); // 读取下一行
    }
}

void CSV::readTeachers(vector<Teacher*> & teacherList)
{
    ifstream inFile;
    cout<<"opening file : "<< this->pathToTeachers << endl;
    inFile.open(this->pathToTeachers);
    if(!inFile.is_open()) // 判断文件能否打开
    {
        cout<<"Could not open teacher file. Create a new file here?[Y/n]";
        char opt = getchar();
        if (opt == 'Y' || opt == 'y' || opt == '\n')
        {
            inFile.close();
            ofstream outFile;
            outFile.open(pathToTeachers);
            outFile << "id,name,subject" << endl;
            outFile.close();
            cout<< "Created a new file at : "<<pathToTeachers<<endl;
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
    if ( tmpStringLine == "id,name,subject") // 文件合法性检测
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
            outFile.open(pathToTeachers);
            outFile << "id,name,subject" << endl;
            outFile.close();
            cout<< "Created a new file at : "<<pathToTeachers<<endl;
            exit(EXIT_FAILURE);
        }
        else
        {
            inFile.close();
            cout<<"Abort."<<endl;
            exit(EXIT_FAILURE);
        }
    }

    for (auto it : teacherList)//手动内存释放
	    delete it;
	teacherList.clear();
	vector<Teacher*>().swap(teacherList);

    // int count = 0;
    inFile.getline(tmpLine, 1000);   // 读取一行数据
    while (inFile.good())
    {
        // ++count;
        vector<string> v;
        split(tmpLine, v, ","); // 将读取到的行切分成字符串数组v
        teacherList.push_back(new Teacher(v[0],v[1],subjectToInt(v[2]))); // 将读取到的一行转换为Student对象
        inFile.getline(tmpLine, 1000); // 读取下一行
    }
}

int subjectToInt(string subject)
{
    if(subject=="Chinese")
    {
        return SUBJECT_CHINESE;
    }
    else if(subject == "English")
    {
        return SUBJECT_ENGLISH;
    }
    else if (subject == "Maths")
    {
        return SUBJECT_MATHS;
    }
    else if (subject == "All")
    {
        return SUBJECT_ALL;
    }
    else if (subject == "NULL")
    {
        return SUBJECT_NULL;
    }
    else
    {
        return SUBJECT_NULL;
    }
}


string intToSubject(int subject)
{
    string str="NULL";
    switch (subject)
    {
    case (SUBJECT_CHINESE):
        str = "Chinese";
        break;
    case (SUBJECT_ENGLISH):
        str = "English";
        break;
    case (SUBJECT_MATHS):
        str = "Maths";
        break;
    case (SUBJECT_ALL):
        str = "All";
        break;
    default:
        str = "NULL";
        break;
    }
    return str;
}

/**
 * @brief csv条目分割函数
 * 
 * @param str 输入的一行数据
 * @param v 分割数组
 * @param spacer 分隔符
 */
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