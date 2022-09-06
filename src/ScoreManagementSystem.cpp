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
        cout<<"============================"<<endl;
        cout<<"# 欢迎来到学生成绩管理系统 ! #"<<endl;
        cout<<"============================"<<endl;
        cout<<"[1] 显示帮助文本"<<endl;
        cout<<"[2] 登陆系统"<<endl;
        cout<<"[3] 重新读取 .csv 文件"<<endl;
        cout<<"[4] 退出系统"<<endl;
        cout<<"请输入你的选择并按回车键继续 (1-4):";
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
            cout<<"未知选项，请按回车键继续...";
            cin.get();cin.get();
            break;
        }
    }
    
}

void ScoreManagementSystem::login()
{
    while(true)
    {
        cout<<"选择登陆身份 :"<<endl;
        cout<<"[1] 管理员"<<endl;
        cout<<"[2] 教师"<<endl;
        cout<<"[3] 学生"<<endl;
        cout<<"[4] 回到主菜单"<<endl;
        cout<<"请输入你的选择并按回车键继续 (1-4):";
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
            cout<<"未知选项，请按回车键继续...";
            cin.get();cin.get();
            break;
        }
    }
    
}

void ScoreManagementSystem::admin()
{
    while(true)
    {
        cout<<"管理员菜单:"<<endl;
        cout<<"[1] 查看教师列表"<<endl;
        cout<<"[2] 查看学生列表"<<endl;
        cout<<"[3] 编辑表格"<<endl;
        cout<<"[4] 表格排序"<<endl;
        cout<<"[5] 保存修改到文件"<<endl;
        cout<<"[6] 回到主菜单"<<endl;
        cout<<"请输入你的选择并按回车键继续 (1-6):";
        char opt;
        cin>>opt;
        switch (opt)
        {
        case ('1'):
            this->showTeacherList();
            cout<<"请按回车键继续...";
            cin.get();cin.get();
            break;
        case ('2'):
            this->showStudentList();
            cout<<"请按回车键继续...";
            cin.get();cin.get();
            break;
        case ('3'):
            this->edit();
            break;
        case ('4'):
            {
                cout<<"选择排序科目:"<<endl;
                cout<<"[1] 语文"<<endl;
                cout<<"[2] 英语"<<endl;
                cout<<"[3] 数学"<<endl;
                cout<<"[4] 总分"<<endl;
                cout<<"[5] 取消"<<endl;
                cout<<"请输入你的选择并按回车键继续 (1-6):";
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
                    cout<<"未知选项，请按回车键继续...";
                    cin.get();cin.get();
                    // this->login();
                    break;
                }
            }
            break;
        case ('5'):
            this->csv.writeStudents(this->studentList);
            this->csv.writeTeachers(this->teacherList);
            cout<<"请按回车键继续...";
            cin.get();cin.get();
            break;
        case ('6'):
            return;
            break;
        default:
            cout<<"请按回车键继续...";
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
            cout<<"选择登陆的教师:"<<endl;
            cout<<"[1] 以ID登陆"<<endl;
            cout<<"[2] 以教师姓名登陆"<<endl;
            cout<<"[3] 查看教师列表"<<endl;
            cout<<"[4] 回到主菜单"<<endl;
            cout<<"请输入你的选择并按回车键继续 (1-4):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"输入你的ID:";
                    int count = 0;
                    string id;
                    cin>>id;
                    for (auto it : this->teacherList)
                    {
                        if (it->getID() == id)
                        {
                            count++;
                            cout<<"你的教师科目是 :"<<intToSubject(it->getSubject())<<endl;
                            *psub = it->getSubject();
                            // break;
                        }
                    }
                    if (count == 0)
                    {
                        cout<<"没有找到ID !"<<endl;
                    }
                    cout<<"请按回车键继续...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"输入你的姓名:";
                    int count = 0;
                    string name;
                    cin>>name;
                    for (auto it : this->teacherList)
                    {
                        if (it->getName() == name)
                        {
                            cout<<"你的教师科目是 :"<<intToSubject(it->getSubject())<<endl;
                            count++;
                            *psub = it->getSubject();
                        }
                    }
                    if (count == 0)
                    {
                        cout<<"没有找到姓名 !"<<endl;
                    }
                    cout<<"请按回车键继续...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('3'):
                this->showTeacherList();
                cout<<"请按回车键继续...";
                cin.get();cin.get();
                continue;
                break;
            case ('4'):
                return;
                break;
            default:
                cout<<"未知选项，请按回车键继续...";
                cin.get();cin.get();
                break;
            }
        }

        cout<<"正在以 "<<intToSubject(subject)<<" 老师身份登陆:"<<endl;
        cout<<"[1] 查看学生列表"<<endl;
        cout<<"[2] 通过学生ID输入成绩"<<endl;
        cout<<"[3] 通过学生姓名输入成绩"<<endl;
        cout<<"[4] 排序学生列表"<<endl;
        cout<<"[5] 保存修改到文件"<<endl;
        cout<<"[6] 登出"<<endl;
        cout<<"请输入你的选择并按回车键继续 (1-6):";
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
            cout<<"输入学生ID:";
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
                        cout<<"输入成绩:";
                        int score;
                        cin>> score;
                        it->setScore(subject, score);
                        it->showScore();
                        count++;
                    }
                    else
                    {
                        cout<<"成绩不能修改！"<<endl;
                    }
                }
            }
            if (count == 0)
            {
                cout<<"没有找到ID !"<<endl;
            }
            cout<<"请按回车键继续...";
            cin.get();cin.get();
            break;
        }
            break;
        case ('3'):
        {
            cout<<"输入学生姓名:";
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
                        cout<<"输入成绩:";
                        int score;
                        cin>> score;
                        it->setScore(subject, score);
                        it->showScore();
                        count++;
                    }
                    else
                    {
                        cout<<"成绩不能修改！"<<endl;
                    }
                }
            }
            if (count == 0)
            {
                cout<<"没有找到姓名 !"<<endl;
            }
            cout<<"请按回车键继续...";
            cin.get();cin.get();
            break;
        }
            break;
        case ('4'):
            {
                cout<<"选择排序科目:"<<endl;
                cout<<"[1] 语文"<<endl;
                cout<<"[2] 英语"<<endl;
                cout<<"[3] 数学"<<endl;
                cout<<"[4] 总分"<<endl;
                cout<<"[5] 取消"<<endl;
                cout<<"请输入你的选择并按回车键继续 (1-6):";
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
                    cout<<"未知选项，请按回车键继续...";
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
            cout<<"请按回车键继续...";
            cin.get();cin.get();
            break;
        }
            break;
        case ('6'):
        {
            *psub = SUBJECT_NULL;
            cout<<"成功登出，请按回车键继续...";
            cin.get();cin.get();
            return;
            break;
        }
        default:
        {
            cout<<"未知选项，请按回车键继续...";
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
        cout<<"以学生身份登陆:"<<endl;
        cout<<"[1] 通过ID查找成绩"<<endl;
        cout<<"[2] 通过姓名查找成绩"<<endl;
        cout<<"[3] 回到主菜单"<<endl;
        cout<<"请输入你的选择并按回车键继续 (1-3):";
        char opt;
        cin>>opt;
        switch (opt)
        {
        case ('1'):
            {
                cout<<"输入你的ID:";
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
                    cout<<"没有找到ID !"<<endl;
                }
                cout<<"请按回车键继续...";
                cin.get();cin.get();
                break;
            }
            break;
        case ('2'):
            {
                cout<<"输入你的姓名:";
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
                    cout<<"没有找到姓名 !"<<endl;
                }
                cout<<"请按回车键继续...";
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
                cout<<"未知选项，请按回车键继续...";
                cin.get();cin.get();
                break;
            }
        }
    }

}

void ScoreManagementSystem::reloadFile()
{
    this->csv.init(&this->studentList, &this->teacherList);
    cout<<"成功保存文件，请按回车键继续...";
    cin.get();cin.get();
}

void ScoreManagementSystem::helpManual()
{
    cout<<"用户包含：管理员、教师、学生；"<<endl
    <<"管理员具有最高权限，可以录入教师、学生信息；"<<endl
    <<"教师：录入学生成绩信息（至少3科），成绩提交后不能修改；"<<endl
    <<"可以对学生成绩进行排序（包括单科、总分）"<<endl
    <<"学生：查询个人成绩信息"<<endl;
    cout<<"请按回车键继续...";
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
    cout<<"[1] 从小到大排序"<<endl;
    cout<<"[2] 从大到小排序"<<endl;
    cout<<"[3] 取消"<<endl;
    cout<<"请输入你的选择并按回车键继续 (1-3):";
    char opt;
    cin>>opt;
    switch (opt)
    {
    case ('1'):
        quickSort(0, this->studentList.size()-1, studentList, subject);
        cout<<"请按回车键继续...";
        cin.get();cin.get();
        // this->login();
        break;
    case ('2'):
        quickSort(0, this->studentList.size()-1, studentList, subject);
        std::reverse(studentList.begin(),studentList.end());
        cout<<"请按回车键继续...";
        cin.get();cin.get();
        // this->login();
        break;
    case ('3'):
        // this->login();
        return;
        break;
    default:
        cout<<"未知选项，请按回车键继续...";
        cin.get();cin.get();
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

void ScoreManagementSystem::edit()
{
    while (true)
    {
        cout<<"修改菜单:"<<endl;
        cout<<"[1] 添加一个学生"<<endl;
        cout<<"[2] 添加一个老师"<<endl;
        cout<<"[3] 删除一个学生"<<endl;
        cout<<"[4] 删除一个老师"<<endl;
        cout<<"[5] 修改一个学生"<<endl;
        cout<<"[6] 修改一个老师"<<endl;
        cout<<"[7] 查看学生列表"<<endl;
        cout<<"[8] 查看老师列表"<<endl;
        cout<<"[9] 退出"<<endl;
        cout<<"请输入你的选择并按回车键继续 (1-9):";
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
                cout<<"添加一个学生:"<<endl;
                string id,name;
                cout<<"输入学生ID:";
                cin>>id;
                cout<<"输入学生姓名:";
                cin>>name;
                studentList.push_back(new Student(id,name));
                cin.get();
                cout<<"是否继续添加学生?[Y/n]";
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
                cout<<"添加一个教师:"<<endl;
                string id,name,subject;
                cout<<"输入教师ID:";
                cin>>id;
                cout<<"输入教师姓名:";
                cin>>name;
                cout<<"输入教师科目:";
                cin>>subject;
                teacherList.push_back(new Teacher(id,name,subjectToInt(subject)));
                cin.get();
                cout<<"是否继续添加教师?[Y/n]";
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
            cout<<"删除一个学生:"<<endl;
            cout<<"[1] 通过学生ID删除"<<endl;
            cout<<"[2] 通过学生姓名删除"<<endl;
            cout<<"[3] 回到主菜单"<<endl;
            cout<<"请输入你的选择并按回车键继续 (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"输入ID:";
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
                            cout<<"是否删除这个学生?[Y/n]";
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
                        cout<<"没有找到ID !"<<endl;
                    }
                    cout<<"请按回车键继续...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"输入姓名:";
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
                            cout<<"是否删除这个学生?[Y/n]";
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
                        cout<<"没有找到姓名 !"<<endl;
                    }
                    cout<<"请按回车键继续...";
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
                    cout<<"未知选项，请按回车键继续...";
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
            cout<<"删除一个教师:"<<endl;
            cout<<"[1] 通过ID删除"<<endl;
            cout<<"[2] 通过姓名删除"<<endl;
            cout<<"[3] 回到菜单"<<endl;
            cout<<"请输入你的选择并按回车键继续 (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"输入ID:";
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
                            cout<<"是否删除这个教师?[Y/n]";
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
                        cout<<"没有找到ID !"<<endl;
                    }
                    cout<<"请按回车键继续...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"输入姓名:";
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
                            cout<<"是否删除这个教师?[Y/n]";
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
                        cout<<"没有找到姓名 !"<<endl;
                    }
                    cout<<"请按回车键继续...";
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
                    cout<<"未知选项，请按回车键继续...";
                    cin.get();cin.get();
                    break;
                }
            }
        }
        }
            break;
        case ('8'):
            this->showTeacherList();
            cout<<"请按回车键继续...";
            cin.get();cin.get();
            break;
        case ('7'):
            this->showStudentList();
            cout<<"请按回车键继续...";
            cin.get();cin.get();
            break;
        case ('5'):
        {
            while(true)
        {
            cout<<"编辑一个学生:"<<endl;
            cout<<"[1] 通过ID编辑"<<endl;
            cout<<"[2] 通过姓名编辑"<<endl;
            cout<<"[3] 回到菜单"<<endl;
            cout<<"请输入你的选择并按回车键继续 (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"输入ID:";
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
                            cout<<"是否修改这个学生?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"输入ID:";
                                string id;
                                cin>>id;
                                it->setID(id);
                                cout<<"输入姓名:";
                                string name;
                                cin>>name;
                                it->setName(name);
                                cout<<"输入语文成绩:";
                                int scoreChinese=0;
                                cin>>scoreChinese;
                                it->setScore(subjectToInt("Chinese"), scoreChinese);
                                cout<<"输入英语成绩:";
                                int scoreEnglish=0;
                                cin>>scoreEnglish;
                                it->setScore(subjectToInt("English"), scoreEnglish);
                                cout<<"输入数学成绩:";
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
                        cout<<"没有找到ID !"<<endl;
                    }
                    cout<<"请按回车键继续...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"输入姓名:";
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
                            cout<<"是否修改这个学生?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"输入语文成绩:";
                                int scoreChinese=0;
                                cin>>scoreChinese;
                                it->setScore(subjectToInt("Chinese"), scoreChinese);
                                cout<<"输入英语成绩:";
                                int scoreEnglish=0;
                                cin>>scoreEnglish;
                                it->setScore(subjectToInt("English"), scoreEnglish);
                                cout<<"输入数学成绩:";
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
                        cout<<"没有找到姓名 !"<<endl;
                    }
                    cout<<"请按回车键继续...";
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
                    cout<<"未知选项，请按回车键继续...";
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
            cout<<"修改教师:"<<endl;
            cout<<"[1] 通过ID编辑"<<endl;
            cout<<"[2] 通过姓名编辑"<<endl;
            cout<<"[3] 回到菜单"<<endl;
            cout<<"请输入你的选择并按回车键继续 (1-3):";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case ('1'):
                {
                    cout<<"输入ID:";
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
                            cout<<"是否修改这位教师?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"输入ID:";
                                string id;
                                cin>>id;
                                it->setID(id);
                                cout<<"输入姓名:";
                                string name;
                                cin>>name;
                                it->setName(name);
                                cout<<"输入科目:";
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
                        cout<<"没有找到ID !"<<endl;
                    }
                    cout<<"请按回车键继续...";
                    cin.get();cin.get();
                    break;
                }
                break;
            case ('2'):
                {
                    cout<<"输入姓名:";
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
                            cout<<"是否修改这位教师?[Y/n]";
                            char opt = getchar();
                            if (opt == 'Y' || opt == 'y' || opt == '\n')
                            {
                                cout<<"输入ID:";
                                string id;
                                cin>>id;
                                it->setID(id);
                                cout<<"输入姓名:";
                                string name;
                                cin>>name;
                                it->setName(name);
                                cout<<"输入科目:";
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
                        cout<<"没有找到姓名 !"<<endl;
                    }
                    cout<<"请按回车键继续...";
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
                    cout<<"未知选项，请按回车键继续...";
                    cin.get();cin.get();
                    break;
                }
            }
        }
        }
            break;
        default:
            cout<<"未知选项，请按回车键继续...";
            cin.get();cin.get();
            break;
        }   
    }
}