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
        cout<<"============================"<<endl;
        cout<<"# ��ӭ����ѧ���ɼ�����ϵͳ ! #"<<endl;
        cout<<"============================"<<endl;
        cout<<"[1] ��ʾ�����ı�"<<endl;
        cout<<"[2] ��½ϵͳ"<<endl;
        cout<<"[3] ���¶�ȡ .csv �ļ�"<<endl;
        cout<<"[4] �˳�ϵͳ"<<endl;
        cout<<"���������ѡ�񲢰��س������� (1-4):";
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
            cout<<"δ֪ѡ��밴�س�������...";
            cin.get();cin.get();
            break;
        }
    }
    
}

void ScoreManagementSystem::login()
{
    while(true)
    {
        cout<<"ѡ���½��� :"<<endl;
        cout<<"[1] ����Ա"<<endl;
        cout<<"[2] ��ʦ"<<endl;
        cout<<"[3] ѧ��"<<endl;
        cout<<"[4] �ص����˵�"<<endl;
        cout<<"���������ѡ�񲢰��س������� (1-4):";
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
            cout<<"δ֪ѡ��밴�س�������...";
            cin.get();cin.get();
            break;
        }
    }
    
}

void ScoreManagementSystem::admin()
{
    while(true)
    {
        cout<<"����Ա�˵�:"<<endl;
        cout<<"[1] �鿴��ʦ�б�"<<endl;
        cout<<"[2] �鿴ѧ���б�"<<endl;
        cout<<"[3] �༭���"<<endl;
        cout<<"[4] �������"<<endl;
        cout<<"[5] �����޸ĵ��ļ�"<<endl;
        cout<<"[6] �ص����˵�"<<endl;
        cout<<"���������ѡ�񲢰��س������� (1-6):";
        char opt;
        cin>>opt;
        switch (opt)
        {
        case ('1'):
            this->showTeacherList();
            cout<<"�밴�س�������...";
            cin.get();cin.get();
            break;
        case ('2'):
            this->showStudentList();
            cout<<"�밴�س�������...";
            cin.get();cin.get();
            break;
        case ('3'):
            this->edit();
            break;
        case ('4'):
            {
                cout<<"ѡ�������Ŀ:"<<endl;
                cout<<"[1] ����"<<endl;
                cout<<"[2] Ӣ��"<<endl;
                cout<<"[3] ��ѧ"<<endl;
                cout<<"[4] �ܷ�"<<endl;
                cout<<"[5] ȡ��"<<endl;
                cout<<"���������ѡ�񲢰��س������� (1-6):";
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
                    cout<<"δ֪ѡ��밴�س�������...";
                    cin.get();cin.get();
                    // this->login();
                    break;
                }
            }
            break;
        case ('5'):
            this->csv.writeStudents(this->studentList);
            this->csv.writeTeachers(this->teacherList);
            cout<<"�밴�س�������...";
            cin.get();cin.get();
            break;
        case ('6'):
            return;
            break;
        default:
            cout<<"�밴�س�������...";
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
            cout<<"ѡ���½�Ľ�ʦ:"<<endl;
            cout<<"[1] ��ID��½"<<endl;
            cout<<"[2] �Խ�ʦ������½"<<endl;
            cout<<"[3] �鿴��ʦ�б�"<<endl;
            cout<<"[4] �ص����˵�"<<endl;
            cout<<"���������ѡ�񲢰��س������� (1-4):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"�������ID:";
                    int count = 0;
                    string id;
                    cin>>id;
                    for (auto it : this->teacherList)
                    {
                        if (it->getID() == id)
                        {
                            count++;
                            cout<<"��Ľ�ʦ��Ŀ�� :"<<intToSubject(it->getSubject())<<endl;
                            *psub = it->getSubject();
                            // break;
                        }
                    }
                    if (count == 0)
                    {
                        cout<<"û���ҵ�ID !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"�����������:";
                    int count = 0;
                    string name;
                    cin>>name;
                    for (auto it : this->teacherList)
                    {
                        if (it->getName() == name)
                        {
                            cout<<"��Ľ�ʦ��Ŀ�� :"<<intToSubject(it->getSubject())<<endl;
                            count++;
                            *psub = it->getSubject();
                        }
                    }
                    if (count == 0)
                    {
                        cout<<"û���ҵ����� !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('3'):
                this->showTeacherList();
                cout<<"�밴�س�������...";
                cin.get();cin.get();
                continue;
                break;
            case ('4'):
                return;
                break;
            default:
                cout<<"δ֪ѡ��밴�س�������...";
                cin.get();cin.get();
                break;
            }
        }

        cout<<"������ "<<intToSubject(subject)<<" ��ʦ��ݵ�½:"<<endl;
        cout<<"[1] �鿴ѧ���б�"<<endl;
        cout<<"[2] ͨ��ѧ��ID����ɼ�"<<endl;
        cout<<"[3] ͨ��ѧ����������ɼ�"<<endl;
        cout<<"[4] ����ѧ���б�"<<endl;
        cout<<"[5] �����޸ĵ��ļ�"<<endl;
        cout<<"[6] �ǳ�"<<endl;
        cout<<"���������ѡ�񲢰��س������� (1-6):";
        char opt;
        cin>>opt;
        switch (opt)
        {
        case ('1'):
        {
            this->showStudentList();
            break;
        }
            break;
        case ('2'):
        {
            cout<<"����ѧ��ID:";
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
                        cout<<"����ɼ�:";
                        int score;
                        cin>> score;
                        it->setScore(subject, score);
                        it->showScore();
                        count++;
                    }
                    else
                    {
                        cout<<"�ɼ������޸ģ�"<<endl;
                    }
                }
            }
            if (count == 0)
            {
                cout<<"û���ҵ�ID !"<<endl;
            }
            cout<<"�밴�س�������...";
            cin.get();cin.get();
            break;
        }
            break;
        case ('3'):
        {
            cout<<"����ѧ������:";
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
                        cout<<"����ɼ�:";
                        int score;
                        cin>> score;
                        it->setScore(subject, score);
                        it->showScore();
                        count++;
                    }
                    else
                    {
                        cout<<"�ɼ������޸ģ�"<<endl;
                    }
                }
            }
            if (count == 0)
            {
                cout<<"û���ҵ����� !"<<endl;
            }
            cout<<"�밴�س�������...";
            cin.get();cin.get();
            break;
        }
            break;
        case ('4'):
            {
                cout<<"ѡ�������Ŀ:"<<endl;
                cout<<"[1] ����"<<endl;
                cout<<"[2] Ӣ��"<<endl;
                cout<<"[3] ��ѧ"<<endl;
                cout<<"[4] �ܷ�"<<endl;
                cout<<"[5] ȡ��"<<endl;
                cout<<"���������ѡ�񲢰��س������� (1-6):";
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
                    cout<<"δ֪ѡ��밴�س�������...";
                    cin.get();cin.get();
                    // this->login();
                    break;
                }
            }
            break;
        case ('5'):
        {
            this->csv.writeStudents(this->studentList);
            // this->csv.writeTeachers(this->teacherList);
            cout<<"�밴�س�������...";
            cin.get();cin.get();
            break;
        }
            break;
        case ('6'):
        {
            *psub = SUBJECT_NULL;
            cout<<"�ɹ��ǳ����밴�س�������...";
            cin.get();cin.get();
            return;
            break;
        }
        default:
        {
            cout<<"δ֪ѡ��밴�س�������...";
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
        cout<<"��ѧ����ݵ�½:"<<endl;
        cout<<"[1] ͨ��ID���ҳɼ�"<<endl;
        cout<<"[2] ͨ���������ҳɼ�"<<endl;
        cout<<"[3] �ص����˵�"<<endl;
        cout<<"���������ѡ�񲢰��س������� (1-3):";
        char opt;
        cin>>opt;
        switch (opt)
        {
        case ('1'):
            {
                cout<<"�������ID:";
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
                    cout<<"û���ҵ�ID !"<<endl;
                }
                cout<<"�밴�س�������...";
                cin.get();cin.get();
                break;
            }
            break;
        case ('2'):
            {
                cout<<"�����������:";
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
                    cout<<"û���ҵ����� !"<<endl;
                }
                cout<<"�밴�س�������...";
                cin.get();cin.get();
                break;
            }
            break;
        case ('3'):
            {
                return;
                break;
            }
        default:
            {
                cout<<"δ֪ѡ��밴�س�������...";
                cin.get();cin.get();
                break;
            }
        }
    }

}

void ScoreManagementSystem::reloadFile()
{
    this->csv.init(&this->studentList, &this->teacherList);
    cout<<"�ɹ������ļ����밴�س�������...";
    cin.get();cin.get();
}

void ScoreManagementSystem::helpManual()
{
    cout<<"�û�����������Ա����ʦ��ѧ����"<<endl
    <<"����Ա�������Ȩ�ޣ�����¼���ʦ��ѧ����Ϣ��"<<endl
    <<"��ʦ��¼��ѧ���ɼ���Ϣ������3�ƣ����ɼ��ύ�����޸ģ�"<<endl
    <<"���Զ�ѧ���ɼ��������򣨰������ơ��ܷ֣�"<<endl
    <<"ѧ������ѯ���˳ɼ���Ϣ"<<endl;
    cout<<"�밴�س�������...";
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
    cout<<"[1] ��С��������"<<endl;
    cout<<"[2] �Ӵ�С����"<<endl;
    cout<<"[3] ȡ��"<<endl;
    cout<<"���������ѡ�񲢰��س������� (1-3):";
    char opt;
    cin>>opt;
    switch (opt)
    {
    case ('1'):
        quickSort(0, this->studentList.size()-1, studentList, subject);
        cout<<"�밴�س�������...";
        cin.get();cin.get();
        // this->login();
        break;
    case ('2'):
        quickSort(0, this->studentList.size()-1, studentList, subject);
        std::reverse(studentList.begin(),studentList.end());
        cout<<"�밴�س�������...";
        cin.get();cin.get();
        // this->login();
        break;
    case ('3'):
        // this->login();
        return;
        break;
    default:
        cout<<"δ֪ѡ��밴�س�������...";
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
        cout<<"�޸Ĳ˵�:"<<endl;
        cout<<"[1] ���һ��ѧ��"<<endl;
        cout<<"[2] ���һ����ʦ"<<endl;
        cout<<"[3] ɾ��һ��ѧ��"<<endl;
        cout<<"[4] ɾ��һ����ʦ"<<endl;
        cout<<"[5] �޸�һ��ѧ��"<<endl;
        cout<<"[6] �޸�һ����ʦ"<<endl;
        cout<<"[7] �鿴ѧ���б�"<<endl;
        cout<<"[8] �鿴��ʦ�б�"<<endl;
        cout<<"[9] �˳�"<<endl;
        cout<<"���������ѡ�񲢰��س������� (1-9):";
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
                cout<<"���һ��ѧ��:"<<endl;
                string id,name;
                cout<<"����ѧ��ID:";
                cin>>id;
                cout<<"����ѧ������:";
                cin>>name;
                studentList.push_back(new Student(id,name));
                cin.get();
                cout<<"�Ƿ�������ѧ��?[Y/n]";
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
                cout<<"���һ����ʦ:"<<endl;
                string id,name,subject;
                cout<<"�����ʦID:";
                cin>>id;
                cout<<"�����ʦ����:";
                cin>>name;
                cout<<"�����ʦ��Ŀ:";
                cin>>subject;
                teacherList.push_back(new Teacher(id,name,subjectToInt(subject)));
                cin.get();
                cout<<"�Ƿ������ӽ�ʦ?[Y/n]";
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
            cout<<"ɾ��һ��ѧ��:"<<endl;
            cout<<"[1] ͨ��ѧ��IDɾ��"<<endl;
            cout<<"[2] ͨ��ѧ������ɾ��"<<endl;
            cout<<"[3] �ص����˵�"<<endl;
            cout<<"���������ѡ�񲢰��س������� (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"����ID:";
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
                            cout<<"�Ƿ�ɾ�����ѧ��?[Y/n]";
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
                        cout<<"û���ҵ�ID !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"��������:";
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
                            cout<<"�Ƿ�ɾ�����ѧ��?[Y/n]";
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
                        cout<<"û���ҵ����� !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('3'):
                {
                    return;
                    break;
                }
            default:
                {
                    cout<<"δ֪ѡ��밴�س�������...";
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
            cout<<"ɾ��һ����ʦ:"<<endl;
            cout<<"[1] ͨ��IDɾ��"<<endl;
            cout<<"[2] ͨ������ɾ��"<<endl;
            cout<<"[3] �ص��˵�"<<endl;
            cout<<"���������ѡ�񲢰��س������� (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"����ID:";
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
                            cout<<"�Ƿ�ɾ�������ʦ?[Y/n]";
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
                        cout<<"û���ҵ�ID !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"��������:";
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
                            cout<<"�Ƿ�ɾ�������ʦ?[Y/n]";
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
                        cout<<"û���ҵ����� !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
            case ('3'):
                {
                    return;
                    break;
                }
                break;
            default:
                {
                    cout<<"δ֪ѡ��밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
            }
        }
        }
            break;
        case ('8'):
            this->showTeacherList();
            cout<<"�밴�س�������...";
            cin.get();cin.get();
            break;
        case ('7'):
            this->showStudentList();
            cout<<"�밴�س�������...";
            cin.get();cin.get();
            break;
        case ('5'):
        {
            while(true)
        {
            cout<<"�༭һ��ѧ��:"<<endl;
            cout<<"[1] ͨ��ID�༭"<<endl;
            cout<<"[2] ͨ�������༭"<<endl;
            cout<<"[3] �ص��˵�"<<endl;
            cout<<"���������ѡ�񲢰��س������� (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"����ID:";
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
                            cout<<"�Ƿ��޸����ѧ��?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"����ID:";
                                string id;
                                cin>>id;
                                it->setID(id);
                                cout<<"��������:";
                                string name;
                                cin>>name;
                                it->setName(name);
                                cout<<"�������ĳɼ�:";
                                int scoreChinese=0;
                                cin>>scoreChinese;
                                it->setScore(subjectToInt("Chinese"), scoreChinese);
                                cout<<"����Ӣ��ɼ�:";
                                int scoreEnglish=0;
                                cin>>scoreEnglish;
                                it->setScore(subjectToInt("English"), scoreEnglish);
                                cout<<"������ѧ�ɼ�:";
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
                        cout<<"û���ҵ�ID !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"��������:";
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
                            cout<<"�Ƿ��޸����ѧ��?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"�������ĳɼ�:";
                                int scoreChinese=0;
                                cin>>scoreChinese;
                                it->setScore(subjectToInt("Chinese"), scoreChinese);
                                cout<<"����Ӣ��ɼ�:";
                                int scoreEnglish=0;
                                cin>>scoreEnglish;
                                it->setScore(subjectToInt("English"), scoreEnglish);
                                cout<<"������ѧ�ɼ�:";
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
                        cout<<"û���ҵ����� !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('3'):
                {
                    return;
                    break;
                }
            default:
                {
                    cout<<"δ֪ѡ��밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
            }
        }
        }
        break;
        case ('6'):
        {
        while(true)
        {
            cout<<"�޸Ľ�ʦ:"<<endl;
            cout<<"[1] ͨ��ID�༭"<<endl;
            cout<<"[2] ͨ�������༭"<<endl;
            cout<<"[3] �ص��˵�"<<endl;
            cout<<"���������ѡ�񲢰��س������� (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"����ID:";
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
                            cout<<"�Ƿ��޸���λ��ʦ?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"����ID:";
                                string id;
                                cin>>id;
                                it->setID(id);
                                cout<<"��������:";
                                string name;
                                cin>>name;
                                it->setName(name);
                                cout<<"�����Ŀ:";
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
                        cout<<"û���ҵ�ID !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"��������:";
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
                            cout<<"�Ƿ��޸���λ��ʦ?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"����ID:";
                                string id;
                                cin>>id;
                                it->setID(id);
                                cout<<"��������:";
                                string name;
                                cin>>name;
                                it->setName(name);
                                cout<<"�����Ŀ:";
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
                        cout<<"û���ҵ����� !"<<endl;
                    }
                    cout<<"�밴�س�������...";
                    cin.get();cin.get();
                    break;
            }
            break;
            case ('3'):
                {
                    return;
                    break;
                }
            default:
                {
                    cout<<"δ֪ѡ��밴�س�������...";
                    cin.get();cin.get();
                    break;
                }
            }
        }
        }
            break;
        default:
            cout<<"δ֪ѡ��밴�س�������...";
            cin.get();cin.get();
            break;
        }   
    }
}