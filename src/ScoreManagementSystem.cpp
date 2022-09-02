#include "ScoreManagementSystem.h"

/**
 * @brief ruct a new Score Management System:: Score Management System object
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
    for (auto it : this->studentList)//�ֶ��ڴ��ͷ�
	    delete it;
	this->studentList.clear();
	vector<Student*>().swap(studentList);
    for (auto it : this->teacherList)//�ֶ��ڴ��ͷ�
	    delete it;
	this->teacherList.clear();
	vector<Teacher*>().swap(teacherList);
}

void ScoreManagementSystem::start()
{
    cout<<"########################################"<<endl;
    cout<<"# Welcome to Score Management System ! #"<<endl;
    cout<<"########################################"<<endl;
    cout<<"[1] Help manual"<<endl;
    cout<<"[2] Login"<<endl;
    cout<<"[3] Reload .csv files"<<endl;
    cout<<"[4] Quit"<<endl;
    cout<<"Enter your option (1-4):";
    char opt = '1';
    cin >> opt;
    switch (opt)
    {
    case ('1'):
        this->helpManual();
        break;
    case ('2'):
        this->login();
        break;
    case ('3'):
        this->reloadFile();
        break;
    case ('4'):
        this->~ScoreManagementSystem();
        exit(EXIT_SUCCESS);
        break;
    default:
        cout<<"Unknown option. Press the Enter key to continue...";
        cin.get();cin.get();
        this->start();
        break;
    }
}

void ScoreManagementSystem::login()
{
    cout<<"[1] Administrator"<<endl;
    cout<<"[2] Teacher"<<endl;
    cout<<"[3] Student"<<endl;
    cout<<"[4] Back to Menu"<<endl;
    cout<<"Enter your option (1-4):";
    char id;
    cin>>id;
    switch (id)
    {
    case ('1'):
        this->admin();
        break;
    case ('2'):
        this->teacher();
        break;
    case ('3'):
        this->student();
        break;
    case ('4'):
        this->start();
        break;
    default:
        cout<<"Unknown option. Press the Enter key to continue...";
        cin.get();cin.get();
        this->login();
        break;
    }
}
void ScoreManagementSystem::admin()
{
    cout<<"[1] View teacher table"<<endl;
    cout<<"[2] View student table"<<endl;
    cout<<"[3] Edit Tables"<<endl;
    cout<<"[4] Sort Tables"<<endl;
    cout<<"[5] Save changes to files"<<endl;
    cout<<"[6] Back to menu"<<endl;
    cout<<"Enter your option (1-6):";
    char opt;
    cin>>opt;
    switch (opt)
    {
    case ('1'):
        this->showTeacherList();
        cout<<"Press the Enter key to continue...";
        cin.get();cin.get();
        this->admin();
        break;
    case ('2'):
        this->showStudentList();
        cout<<"Press the Enter key to continue...";
        cin.get();cin.get();
        this->admin();
        break;
    case ('3'):
        // this->edit();
        break;
    case ('4'):
        {
            cout<<"sort by:"<<endl;
            cout<<"[1] Chinese"<<endl;
            cout<<"[2] English"<<endl;
            cout<<"[3] Maths"<<endl;
            cout<<"[4] Total"<<endl;
            cout<<"[5] cancel"<<endl;
            cout<<"Enter your option (1-6):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                this->sort(subjectToInt("Chinese"));
                break;
            case ('2'):
                this->sort(subjectToInt("English"));
                break;
            case ('3'):
                this->sort(subjectToInt("Maths"));
                break;
            case ('4'):
                this->sort(114514);
                break;
            case ('5'):
                this->login();
                break;
            default:
                cout<<"Unknown option. Press the Enter key to continue...";
                cin.get();cin.get();
                this->login();
                break;
            }

            break;
        }
    case ('5'):
        this->csv.writeStudents(this->studentList);
        this->csv.writeTeachers(this->teacherList);
        cout<<"Press the Enter key to continue...";
        cin.get();cin.get();
        this->admin();
        break;
    case ('6'):
        this->start();
        break;
    default:
        cout<<"Unknown option. Press the Enter key to continue...";
        cin.get();cin.get();
        this->admin();
        break;
    }
}
void ScoreManagementSystem::teacher()
{

}
void ScoreManagementSystem::student()
{
    cout<<"[1] Check by ID"<<endl;
    cout<<"[2] Check by Name"<<endl;
    cout<<"[3] Back to menu"<<endl;
    cout<<"Enter your option (1-3):";
    char opt;
    cin>>opt;
    switch (opt)
    {
    case ('1'):
        {cout<<"Enter your ID:";
        int count = 0;
        string id;
        cin>>id;
        for (auto it : this->studentList)
        {
            if (it->getID() == id)
            {
                it->showScore();
                count++;
            }
        }
        if (count == 0)
        {
            cout<<"ID not found !"<<endl;
        }
        cout<<"Press the Enter key to continue...";
        cin.get();cin.get();
        this->student();
        break;}
    case ('2'):
        {cout<<"Enter your Name:";
        int count = 0;
        string name;
        cin>>name;
        for (auto it : this->studentList)
        {
            if (it->getName() == name)
            {
                it->showScore();
                count++;
            }
        }
        if (count == 0)
        {
            cout<<"Name not found !"<<endl;
        }
        cout<<"Press the Enter key to continue...";
        cin.get();cin.get();
        this->student();
        break;}
    case ('3'):
        {this->start();
        break;}
    default:
        {cout<<"Unknown option. Press the Enter key to continue...";
        cin.get();cin.get();
        this->student();
        break;}
    }
}

void ScoreManagementSystem::reloadFile()
{
    this->csv.init(&this->studentList, &this->teacherList);
    cout<<"File reload Sucessful. Press the Enter key to continue...";
    cin.get();cin.get();
    this->start();
}

void ScoreManagementSystem::helpManual()
{
    cout<<"�û�����������Ա����ʦ��ѧ����"<<endl
    <<"����Ա�������Ȩ�ޣ�����¼���ʦ��ѧ����Ϣ��"<<endl
    <<"��ʦ��¼��ѧ���ɼ���Ϣ������3�ƣ����ɼ��ύ�����޸ģ�"<<endl
    <<"���Զ�ѧ���ɼ��������򣨰������ơ��ܷ֣�"<<endl
    <<"ѧ������ѯ���˳ɼ���Ϣ"<<endl;
    cout<<"Press the Enter key to continue...";
    cin.get();cin.get();
    this->start();
}

void ScoreManagementSystem::showTeacherList()
{
    cout<<"id\t|name\t\t|subject"<<endl;
    for (auto it : this->teacherList)
    {
        cout <<it->getID()<<"\t|"
                <<it->getName()<<"\t|"
                <<intToSubject(it->getSubject())<<endl;
    }
    cout<<endl;
}
void ScoreManagementSystem::showStudentList()
{
    for (auto it : this->studentList)
    {
        cout<<"id\t|name\t|Chinese|English|Maths\t|Total"<<endl;
        cout<<it->getID()<<"\t|"<<it->getName()<<"\t|"<<it->getScore(subjectToInt("Chinese"))<<"\t|"<<it->getScore(subjectToInt("English"))<<"\t|"<<it->getScore(subjectToInt("Maths"))<<"\t|"<<it->getScore(114514)<<endl;
    }
    cout<<endl;
}

void ScoreManagementSystem::sort(int subject)
{
    cout<<"[1] Small to Big"<<endl;
    cout<<"[2] Big to Small"<<endl;
    cout<<"[3] cancel"<<endl;
    cout<<"Enter your option (1-3):";
    char opt;
    cin>>opt;
    switch (opt)
    {
    case ('1'):
        quickSort(0, this->studentList.size()-1, studentList, subject);
        cout<<"Press the Enter key to continue...";
        cin.get();cin.get();
        this->login();
        break;
    case ('2'):
        quickSort(0, this->studentList.size()-1, studentList, subject);
        std::reverse(studentList.begin(),studentList.end());
        cout<<"Press the Enter key to continue...";
        cin.get();cin.get();
        this->login();
        break;
    case ('3'):
        this->login();
        break;
    default:
        cout<<"Unknown option. Press the Enter key to continue...";
        cin.get();cin.get();
        this->login();
        break;
    }
}

//�������򣨴�С����
void quickSort(int left, int right, vector<Student*>& arr, int subject)
{
	if(left >= right)
		return;
	int i, j, base;
    Student* temp =NULL;
	i = left, j = right;
	base = arr[left]->getScore(subject);  //ȡ����ߵ���Ϊ��׼��
	while (i < j)
	{
		while (arr[j]->getScore(subject) >= base && i < j)
			j--;
		while (arr[i]->getScore(subject) <= base && i < j)
			i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//��׼����λ
    temp = arr[left];
	arr[left] = arr[i];
	arr[i] = temp;
	quickSort(left, i - 1, arr, subject);//�ݹ����
	quickSort(i + 1, right, arr, subject);//�ݹ��ұ�
}
