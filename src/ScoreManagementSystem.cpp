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
    while(true)
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
            break;
        }
    }
    
}

void ScoreManagementSystem::login()
{
    while(true)
    {
        cout<<"Login as :"<<endl;
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
            return;
            break;
        default:
            cout<<"Unknown option. Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        }
    }
    
}
void ScoreManagementSystem::admin()
{
    while(true)
    {
        cout<<"Login as Admin:"<<endl;
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
            break;
        case ('2'):
            this->showStudentList();
            cout<<"Press the Enter key to continue...";
            cin.get();cin.get();
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
                    break;
                default:
                    cout<<"Unknown option. Press the Enter key to continue...";
                    cin.get();cin.get();
                    this->login();
                    break;
                }
            }
        case ('5'):
            this->csv.writeStudents(this->studentList);
            this->csv.writeTeachers(this->teacherList);
            cout<<"Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        case ('6'):
            return;
            break;
        default:
            cout<<"Unknown option. Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        }
    }
    
}
void ScoreManagementSystem::teacher()
{
    int subject = SUBJECT_NULL ;
    int* psub=&subject;
    while(true)
    {
        if(*psub == SUBJECT_NULL)
        {
            cout<<"Login as teacher:"<<endl;
            cout<<"[1] login by ID"<<endl;
            cout<<"[2] login by Name"<<endl;
            cout<<"[3] Show teachers list"<<endl;
            cout<<"[4] Back to menu"<<endl;
            cout<<"Enter your option (1-4):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"Enter your ID:";
                    int count = 0;
                    string id;
                    cin>>id;
                    for (auto it : this->teacherList)
                    {
                        if (it->getID() == id)
                        {
                            count++;
                            cout<<"Your subject is :"<<intToSubject(it->getSubject())<<endl;
                            *psub = it->getSubject();
                            // break;
                        }
                    }
                    if (count == 0)
                    {
                        cout<<"ID not found !"<<endl;
                    }
                    cout<<"Press the Enter key to continue...";
                    cin.get();cin.get();
                    break;
                }
            case ('2'):
                {
                    cout<<"Enter your Name:";
                    int count = 0;
                    string name;
                    cin>>name;
                    for (auto it : this->teacherList)
                    {
                        if (it->getName() == name)
                        {
                            cout<<"Your subject is :"<<intToSubject(it->getSubject())<<endl;
                            count++;
                            *psub = it->getSubject();
                        }
                    }
                    if (count == 0)
                    {
                        cout<<"Name not found !"<<endl;
                    }
                    cout<<"Press the Enter key to continue...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('3'):
                this->showTeacherList();
                break;
            case ('4'):
                return;
                break;
            default:
                cout<<"Unknown option. Press the Enter key to continue...";
                cin.get();cin.get();
                break;
            }
        }

        cout<<"Login as "<<intToSubject(subject)<<" teacher:"<<endl;
        cout<<"[1] view student table"<<endl;
        cout<<"[2] set score by student ID"<<endl;
        cout<<"[3] set score by student Name"<<endl;
        cout<<"[4] save changes"<<endl;
        cout<<"[5] Log out"<<endl;
        cout<<"Enter your option (1-5):";
        char opt;
        cin>>opt;
        switch (opt)
        {
        case ('1'):
        {
            this->showStudentList();
            break;
        }
        case ('2'):
        {
            cout<<"Enter Student ID:";
            int count = 0;
            string id;
            cin>>id;
            for (auto it : this->studentList)
            {
                if (it->getID() == id)
                {
                    // it->showScore();
                    if (it->getScore(subject)==0)
                    {
                        it->showScore();
                        cout<<"Enter the score:";
                        int score;
                        cin>> score;
                        it->setScore(subject, score);
                        it->showScore();
                        count++;
                    }
                    else
                    {
                        cout<<"The score cannot modify."<<endl;
                    }
                }
            }
            if (count == 0)
            {
                cout<<"ID not found !"<<endl;
            }
            cout<<"Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        }
        case ('3'):
        {
            cout<<"Enter Student Name:";
            int count = 0;
            string name;
            cin>>name;
            for (auto it : this->studentList)
            {
                if (it->getName() == name)
                {
                    // it->showScore();
                    if (it->getScore(subject)==0)
                    {
                        it->showScore();
                        cout<<"Enter the score:";
                        int score;
                        cin>> score;
                        it->setScore(subject, score);
                        it->showScore();
                        count++;
                    }
                    else
                    {
                        cout<<"The score cannot modify."<<endl;
                    }
                }
            }
            if (count == 0)
            {
                cout<<"Name not found !"<<endl;
            }
            cout<<"Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        }
        case ('4'):
        {
            this->csv.writeStudents(this->studentList);
            // this->csv.writeTeachers(this->teacherList);
            cout<<"Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        }
        case ('5'):
        {
            *psub = SUBJECT_NULL;
            cout<<"Log out successful. Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        }
        default:
        {
            cout<<"Unknown option. Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        }
        }
    }
}
void ScoreManagementSystem::student()
{
    while(true)
    {
        cout<<"Login as Student:"<<endl;
        cout<<"[1] Check by ID"<<endl;
        cout<<"[2] Check by Name"<<endl;
        cout<<"[3] Back to menu"<<endl;
        cout<<"Enter your option (1-3):";
        char opt;
        cin>>opt;
        switch (opt)
        {
        case ('1'):
            {
                cout<<"Enter your ID:";
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
                break;
            }
        case ('2'):
            {
                cout<<"Enter your Name:";
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
                break;
            }
        case ('3'):
            {
                return;
                break;
            }
        default:
            {
                cout<<"Unknown option. Press the Enter key to continue...";
                cin.get();cin.get();
                break;
            }
        }
    }

}

void ScoreManagementSystem::reloadFile()
{
    this->csv.init(&this->studentList, &this->teacherList);
    cout<<"File reload Sucessful. Press the Enter key to continue...";
    cin.get();cin.get();
}

void ScoreManagementSystem::helpManual()
{
    cout<<"用户包含：管理员、教师、学生；"<<endl
    <<"管理员具有最高权限，可以录入教师、学生信息；"<<endl
    <<"教师：录入学生成绩信息（至少3科），成绩提交后不能修改；"<<endl
    <<"可以对学生成绩进行排序（包括单科、总分）"<<endl
    <<"学生：查询个人成绩信息"<<endl;
    cout<<"Press the Enter key to continue...";
    cin.get();cin.get();
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
    cout<<"id\t|name\t|Chinese|English|Maths\t|Total"<<endl;
    for (auto it : this->studentList)
    {
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

//快速排序（从小到大）
void quickSort(int left, int right, vector<Student*>& arr, int subject)
{
	if(left >= right)
		return;
	int i, j, base;
    Student* temp =NULL;
	i = left, j = right;
	base = arr[left]->getScore(subject);  //取最左边的数为基准数
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
	//基准数归位
    temp = arr[left];
	arr[left] = arr[i];
	arr[i] = temp;
	quickSort(left, i - 1, arr, subject);//递归左边
	quickSort(i + 1, right, arr, subject);//递归右边
}
