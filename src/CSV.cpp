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


void CSV::read(StudentList* slist, TeacherList* tlist)
{
    this->readStudents(slist);
    this->readTeachers(tlist);
}

void CSV::save(StudentList* slist, TeacherList* tlist)
{
    this->writeStudents(slist);
    this->writeTeachers(tlist);
}

/**
 * @brief ��ȡѧ������
 * 
 * @param studentList ѧ������
 */
void CSV::readStudents(StudentList* slist)
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
            // exit(EXIT_FAILURE);
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
            // exit(EXIT_FAILURE);
        }
        else
        {
            inFile.close();
            cout<<"Abort."<<endl;
            exit(EXIT_FAILURE);
        }
    }

    slist->deleteAll(); 

    // int count = 0;
    for(int i=0;i<1000;i++)
    {
        tmpLine[i] = '\0';
    }
    inFile.getline(tmpLine, 1000);   // ��ȡһ������
    while (inFile.good())
    {
        // ++count;
        cout<<'.';
        vector<string> v;
        split(tmpLine, v, ","); // ����ȡ�������зֳ��ַ�������v
        slist->add(v[0],v[1],stoi(v[2]),stoi(v[3]),stoi(v[4])); // ����ȡ����һ��ת��ΪStudent����
        for(int i=0;i<1000;i++)
        {
            tmpLine[i] = '\0';
        }
        inFile.getline(tmpLine, 1000); // ��ȡ��һ��
    }
    cout<<"Done."<<endl;
}

void CSV::readTeachers(TeacherList* tlist)
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
            // exit(EXIT_FAILURE);
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
            // exit(EXIT_FAILURE);
        }
        else
        {
            inFile.close();
            cout<<"Abort."<<endl;
            exit(EXIT_FAILURE);
        }
    }

    tlist->deleteAll();

    // int count = 0;
    for(int i=0;i<1000;i++)
    {
        tmpLine[i] = '\0';
    }
    inFile.getline(tmpLine, 1000);   // ��ȡһ������
    while (inFile.good())
    {
        // ++count;
        cout<<'.';
        vector<string> v;
        split(tmpLine, v, ","); // ����ȡ�������зֳ��ַ�������v
        tlist->add(v[0],v[1],subjectToInt(v[2])); // ����ȡ����һ��ת��ΪStudent����
        for(int i=0;i<1000;i++)
        {
            tmpLine[i] = '\0';
        }
        inFile.getline(tmpLine, 1000); // ��ȡ��һ��
    }
    cout<<"Done."<<endl;
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


void CSV::writeStudents(StudentList* slist)
{
    ofstream outFile;
    outFile.open(pathToStudents);
    outFile << "id,name,Chinese,English,Maths,Total" << endl;
    for (int i=0;i<slist->getSize();i++)
    {
        outFile <<slist->getID(i)<<','
                <<slist->getName(i)<<','
                <<slist->getScore(i,subjectToInt("Chinese"))<<','
                <<slist->getScore(i,subjectToInt("English"))<<','
                <<slist->getScore(i,subjectToInt("Maths"))<<','
                <<slist->getScore(i,114514)<<endl;
    }
    outFile.close();
    cout<< "File saved at : "<<pathToStudents<<endl;
}

void CSV::writeTeachers(TeacherList* tlist)
{
    ofstream outFile;
    outFile.open(pathToTeachers);
    outFile << "id,name,subject" << endl;
    for (int i=0;i<tlist->getSize();i++)
    {
        outFile <<tlist->getID(i)<<','
                <<tlist->getName(i)<<','
                <<intToSubject(tlist->getSubject(i))<<endl;
    }
    outFile.close();
    cout<< "File saved at : "<<pathToTeachers<<endl;
}