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
 * @param pathToStudents ѧ�������ļ�·��
 * @param pathToTeachers ��ʦ�����ļ�·��
 */
CSV::CSV(string pathToStudents, string pathToTeachers)
{
    this->pathToStudents = pathToStudents;
    this->pathToTeachers = pathToTeachers;
}

/**
 * @brief 
 * 
 * @param pathToStudents ѧ�������ļ�·��
 * @param pathToTeachers ��ʦ�����ļ�·��
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
 * @brief ��ȡѧ������
 * 
 * @param studentList ѧ������
 */
void CSV::readStudents(vector<Student*> & studentList)
{
    ifstream inFile;
    cout<<"opening file : "<< this->pathToStudents << endl;
    inFile.open(this->pathToStudents);
    if(!inFile.is_open()) // �ж��ļ��ܷ��
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
    if ( tmpStringLine == "id,name,Chinese,English,Maths,Total") // �ļ��Ϸ��Լ��
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
    for (auto it : studentList)//�ֶ��ڴ��ͷ�
	    delete it;
	studentList.clear();
	vector<Student*>().swap(studentList);

    // int count = 0;
    inFile.getline(tmpLine, 1000);   // ��ȡһ������
    while (inFile.good())
    {
        // ++count;
        vector<string> v;
        split(tmpLine, v, ","); // ����ȡ�������зֳ��ַ�������v
        studentList.push_back(new Student(v[0],v[1],stoi(v[2]),stoi(v[3]),stoi(v[4]),stoi(v[5]))); // ����ȡ����һ��ת��ΪStudent����
        inFile.getline(tmpLine, 1000); // ��ȡ��һ��
    }
}

void CSV::readTeachers(vector<Teacher*> & teacherList)
{
    ifstream inFile;
    cout<<"opening file : "<< this->pathToTeachers << endl;
    inFile.open(this->pathToTeachers);
    if(!inFile.is_open()) // �ж��ļ��ܷ��
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
    if ( tmpStringLine == "id,name,subject") // �ļ��Ϸ��Լ��
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

    for (auto it : teacherList)//�ֶ��ڴ��ͷ�
	    delete it;
	teacherList.clear();
	vector<Teacher*>().swap(teacherList);

    // int count = 0;
    inFile.getline(tmpLine, 1000);   // ��ȡһ������
    while (inFile.good())
    {
        // ++count;
        vector<string> v;
        split(tmpLine, v, ","); // ����ȡ�������зֳ��ַ�������v
        teacherList.push_back(new Teacher(v[0],v[1],subjectToInt(v[2]))); // ����ȡ����һ��ת��ΪStudent����
        inFile.getline(tmpLine, 1000); // ��ȡ��һ��
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
 * @brief csv��Ŀ�ָ��
 * 
 * @param str �����һ������
 * @param v �ָ�����
 * @param spacer �ָ���
 */
void split(string str,vector<string> &v,string spacer)
{
    int pos1,pos2;
    int len=spacer.length();     //��¼�ָ����ĳ���
    pos1=0;
    pos2=str.find(spacer);
    while( pos2 != string::npos )
    {
        v.push_back( str.substr(pos1,pos2-pos1) );
        pos1 = pos2 + len;
        pos2 = str.find(spacer,pos1);    // ��str��pos1λ�ÿ�ʼ��Ѱspacer
    }
    if(pos1 != str.length()) //�ָ����һ������
       v.push_back(str.substr(pos1));
}


void CSV::writeStudents(vector<Student*> & studentList)
{
    ofstream outFile;
    outFile.open(pathToStudents);
    outFile << "id,name,Chinese,English,Maths,Total" << endl;
    for (auto it : studentList)
    {
        outFile <<it->getID()<<','
                <<it->getName()<<','
                <<it->getScore(subjectToInt("Chinese"))<<','
                <<it->getScore(subjectToInt("English"))<<','
                <<it->getScore(subjectToInt("Maths"))<<','
                <<it->getScore(114514)<<endl;
    }
    outFile.close();
    cout<< "File saved at : "<<pathToStudents<<endl;
}