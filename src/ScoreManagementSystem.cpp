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
            this->edit();
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
                cout<<"Press the Enter key to continue...";
                cin.get();cin.get();
                continue;
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
    cout<<"�û�����������Ա����ʦ��ѧ����"<<endl
    <<"����Ա�������Ȩ�ޣ�����¼���ʦ��ѧ����Ϣ��"<<endl
    <<"��ʦ��¼��ѧ���ɼ���Ϣ������3�ƣ����ɼ��ύ�����޸ģ�"<<endl
    <<"���Զ�ѧ���ɼ��������򣨰������ơ��ܷ֣�"<<endl
    <<"ѧ������ѯ���˳ɼ���Ϣ"<<endl;
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
        // this->login();
        break;
    case ('2'):
        quickSort(0, this->studentList.size()-1, studentList, subject);
        std::reverse(studentList.begin(),studentList.end());
        cout<<"Press the Enter key to continue...";
        cin.get();cin.get();
        // this->login();
        break;
    case ('3'):
        // this->login();
        return;
        break;
    default:
        cout<<"Unknown option. Press the Enter key to continue...";
        cin.get();cin.get();
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

void ScoreManagementSystem::edit()
{
    while (true)
    {
        cout<<"Edit:"<<endl;
        cout<<"[1] Add a student"<<endl;
        cout<<"[2] Add a teacher"<<endl;
        cout<<"[3] Delete a student"<<endl;
        cout<<"[4] Delete a teacher"<<endl;
        cout<<"[5] Edit a student"<<endl;
        cout<<"[6] Edit a teacher"<<endl;
        cout<<"[7] View student list"<<endl;
        cout<<"[8] View teacher list"<<endl;
        cout<<"[9] Quit"<<endl;
        cout<<"Enter your option (1-9):";
        char opt;
        cin>>opt;
        switch (opt)
        {
        case ('9'):
            return;
            break;
        case ('1'):
        {
            while (true)
            {
                cout<<"Add a new student:"<<endl;
                string id,name;
                cout<<"Enter ID:";
                cin>>id;
                cout<<"Enter Name:";
                cin>>name;
                studentList.push_back(new Student(id,name));
                cin.get();
                cout<<"Continue Add students?[Y/n]";
                char opt = getchar();
                if (opt == 'Y' || opt == 'y' || opt == '\n')
                {
                    continue;
                }
                else
                {
                    return;
                }
            }
        }
            break;
        case ('2'):
        {
            while (true)
            {
                cout<<"Add a new teacher:"<<endl;
                string id,name,subject;
                cout<<"Enter ID:";
                cin>>id;
                cout<<"Enter Name:";
                cin>>name;
                cout<<"Enter Subject:";
                cin>>subject;
                teacherList.push_back(new Teacher(id,name,subjectToInt(subject)));
                cin.get();
                cout<<"Continue Add teachers?[Y/n]";
                char opt = getchar();
                if (opt == 'Y' || opt == 'y' || opt == '\n')
                {
                    continue;
                }
                else
                {
                    return;
                }
            }
        }
            break;
        case ('3'):
        {
            while(true)
        {
            cout<<"Delete a Student:"<<endl;
            cout<<"[1] Delete by ID"<<endl;
            cout<<"[2] Delete by Name"<<endl;
            cout<<"[3] Back to menu"<<endl;
            cout<<"Enter your option (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"Enter ID:";
                    int count = 0,countDelete=0;
                    string id;
                    cin>>id;
                    for (auto it : this->studentList)
                    {
                        count++;
                        if (it->getID() == id)
                        {
                            countDelete++;
                            it->showScore();
                            cin.get();
                            cout<<"Delete this student?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                delete(it);
                                this->studentList[count]=NULL;
                                this->studentList.erase(studentList.begin() + count);
                                continue;
                            }
                            else
                            {
                                return;
                            }
                        }
                    }
                    if (countDelete == 0)
                    {
                        cout<<"ID not found !"<<endl;
                    }
                    cout<<"Press the Enter key to continue...";
                    cin.get();cin.get();
                    break;
                }
            case ('2'):
                {
                    cout<<"Enter Name:";
                    int count = 0,countDelete=0;
                    string name;
                    cin>>name;
                    for (auto it : this->studentList)
                    {
                        count++;
                        if (it->getName() == name)
                        {
                            countDelete++;
                            it->showScore();
                            cin.get();
                            cout<<"Delete this student?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                delete(it);
                                this->studentList[count]=NULL;
                                this->studentList.erase(studentList.begin() + count);
                                continue;
                            }
                            else
                            {
                                return;
                            }
                        }
                    }
                    if (countDelete == 0)
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
            break;
        case ('4'):
        {
        while(true)
        {
            cout<<"Delete a Teacher:"<<endl;
            cout<<"[1] Delete by ID"<<endl;
            cout<<"[2] Delete by Name"<<endl;
            cout<<"[3] Back to menu"<<endl;
            cout<<"Enter your option (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"Enter ID:";
                    int count = 0,countDelete=0;
                    string id;
                    cin>>id;
                    for (auto it : this->teacherList)
                    {
                        count++;
                        if (it->getID() == id)
                        {
                            countDelete++;
                            cout<<"id\t|name\t\t|subject"<<endl;
                            cout <<it->getID()<<"\t|"
                                    <<it->getName()<<"\t|"
                                    <<intToSubject(it->getSubject())<<endl;
                            cin.get();
                            cout<<"Delete this teacher?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                delete(it);
                                this->teacherList[count]=NULL;
                                this->teacherList.erase(teacherList.begin() + count);
                                continue;
                            }
                            else
                            {
                                return;
                            }
                        }
                    }
                    if (countDelete == 0)
                    {
                        cout<<"ID not found !"<<endl;
                    }
                    cout<<"Press the Enter key to continue...";
                    cin.get();cin.get();
                    break;
                }
            case ('2'):
                {
                    cout<<"Enter Name:";
                    int count = 0,countDelete=0;
                    string name;
                    cin>>name;
                    for (auto it : this->teacherList)
                    {
                        count++;
                        if (it->getName() == name)
                        {
                            countDelete++;
                            cout<<"id\t|name\t\t|subject"<<endl;
                            cout <<it->getID()<<"\t|"
                                    <<it->getName()<<"\t|"
                                    <<intToSubject(it->getSubject())<<endl;
                            cin.get();
                            cout<<"Delete this teacher?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                delete(it);
                                this->teacherList[count]=NULL;
                                this->teacherList.erase(teacherList.begin() + count);
                                continue;
                            }
                            else
                            {
                                return;
                            }
                        }
                    }
                    if (countDelete == 0)
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
            break;
        case ('8'):
            this->showTeacherList();
            cout<<"Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        case ('7'):
            this->showStudentList();
            cout<<"Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        case ('5'):
        {
            while(true)
        {
            cout<<"Edit a Student:"<<endl;
            cout<<"[1] Edit by ID"<<endl;
            cout<<"[2] Edit by Name"<<endl;
            cout<<"[3] Back to menu"<<endl;
            cout<<"Enter your option (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"Enter ID:";
                    int count = 0;
                    string id;
                    cin>>id;
                    for (auto it : this->studentList)
                    {
                        if (it->getID() == id)
                        {
                            count++;
                            it->showScore();
                            cin.get();
                            cout<<"Edit this student?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"Enter ID:";
                                string id;
                                cin>>id;
                                it->setID(id);
                                cout<<"Enter Name:";
                                string name;
                                cin>>name;
                                it->setName(name);
                                cout<<"Enter Chinese score:";
                                int scoreChinese=0;
                                cin>>scoreChinese;
                                it->setScore(subjectToInt("Chinese"), scoreChinese);
                                cout<<"Enter English score:";
                                int scoreEnglish=0;
                                cin>>scoreEnglish;
                                it->setScore(subjectToInt("English"), scoreEnglish);
                                cout<<"Enter Maths score:";
                                int scoreMaths=0;
                                cin>>scoreMaths;
                                it->setScore(subjectToInt("Maths"), scoreMaths);
                                it->showScore();
                                continue;
                            }
                            else
                            {
                                return;
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
            case ('2'):
                {
                    cout<<"Enter Name:";
                    int count = 0,countDelete=0;
                    string name;
                    cin>>name;
                    for (auto it : this->studentList)
                    {
                        if (it->getName() == name)
                        {
                            count++;
                            it->showScore();
                            cin.get();
                            cout<<"Edit this student?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"Enter Chinese score:";
                                int scoreChinese=0;
                                cin>>scoreChinese;
                                it->setScore(subjectToInt("Chinese"), scoreChinese);
                                cout<<"Enter English score:";
                                int scoreEnglish=0;
                                cin>>scoreEnglish;
                                it->setScore(subjectToInt("English"), scoreEnglish);
                                cout<<"Enter Maths score:";
                                int scoreMaths=0;
                                cin>>scoreMaths;
                                it->setScore(subjectToInt("Maths"), scoreMaths);
                                it->showScore();
                                continue;
                            }
                            else
                            {
                                return;
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
        case ('6'):
        {
        while(true)
        {
            cout<<"Edit a Teacher:"<<endl;
            cout<<"[1] Edit by ID"<<endl;
            cout<<"[2] Edit by Name"<<endl;
            cout<<"[3] Back to menu"<<endl;
            cout<<"Enter your option (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"Enter ID:";
                    int count = 0;
                    string id;
                    cin>>id;
                    for (auto it : this->teacherList)
                    {
                        if (it->getID() == id)
                        {
                            count++;
                            cout<<"id\t|name\t\t|subject"<<endl;
                            cout <<it->getID()<<"\t|"
                                    <<it->getName()<<"\t|"
                                    <<intToSubject(it->getSubject())<<endl;
                            cin.get();
                            cout<<"Edit this teacher?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"Enter ID:";
                                string id;
                                cin>>id;
                                it->setID(id);
                                cout<<"Enter Name:";
                                string name;
                                cin>>name;
                                it->setName(name);
                                cout<<"Enter Subject:";
                                string subject;
                                cin>>subject;
                                it->setSubject(subjectToInt(subject));
                                cout<<"id\t|name\t\t|subject"<<endl;
                                cout <<it->getID()<<"\t|"
                                    <<it->getName()<<"\t|"
                                    <<intToSubject(it->getSubject())<<endl;
                                continue;
                            }
                            else
                            {
                                return;
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
            case ('2'):
                {
                    cout<<"Enter Name:";
                    int count = 0;
                    string name;
                    cin>>name;
                    for (auto it : this->teacherList)
                    {
                        if (it->getName() == name)
                        {
                            count++;
                            cout<<"id\t|name\t\t|subject"<<endl;
                            cout <<it->getID()<<"\t|"
                                    <<it->getName()<<"\t|"
                                    <<intToSubject(it->getSubject())<<endl;
                            cin.get();
                            cout<<"Edit this teacher?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"Enter ID:";
                                string id;
                                cin>>id;
                                it->setID(id);
                                cout<<"Enter Name:";
                                string name;
                                cin>>name;
                                it->setName(name);
                                cout<<"Enter Subject:";
                                string subject;
                                cin>>subject;
                                it->setSubject(subjectToInt(subject));
                                cout<<"id\t|name\t\t|subject"<<endl;
                                cout <<it->getID()<<"\t|"
                                    <<it->getName()<<"\t|"
                                    <<intToSubject(it->getSubject())<<endl;
                                continue;
                            }
                            else
                            {
                                return;
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
            break;
        default:
            cout<<"Unknown option. Press the Enter key to continue...";
            cin.get();cin.get();
            break;
        }   
    }
}