#include "ScoreManagementSystem.h"

/**
 * @brief ruct a new Score Management System:: Score Management System object
 *
 * @param pathToStudents
 * @param pathToTeachers
 */
ScoreManagementSystem::ScoreManagementSystem(string pathToStudents, string pathToTeachers)
{
    CSV csv(pathToStudents, pathToTeachers);
    csv.read(&this->slist, &this->tlist);
    csv.~CSV();
}

/**
 * @brief Destroy the Score Management System:: Score Management System object
 *
 */
ScoreManagementSystem::~ScoreManagementSystem()
{
}

void ScoreManagementSystem::start()
{
    while (true)
    {
        cout << "==============================" << endl;
        cout << "# 欢迎来到学生成绩管理系统 ! #" << endl;
        cout << "==============================" << endl;
        cout << "[1] 显示帮助文本" << endl;
        cout << "[2] 登陆系统" << endl;
        cout << "[3] 重新读取 .csv 文件" << endl;
        cout << "[4] 退出系统" << endl;
        cout << "请输入你的选择并按回车键继续 (1-4):";
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
            exit(EXIT_SUCCESS);
            break;
        default:
            cout << "未知选项，";
            jixu();
        }
    }
}

void ScoreManagementSystem::login()
{
    while (true)
    {
        cout << "选择登陆身份 :" << endl;
        cout << "[1] 管理员" << endl;
        cout << "[2] 教师" << endl;
        cout << "[3] 学生" << endl;
        cout << "[4] 回到主菜单" << endl;
        cout << "请输入你的选择并按回车键继续 (1-4):";
        char id;
        cin >> id;
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
            cout << "未知选项，";
            jixu();
        }
    }
}

void ScoreManagementSystem::admin()
{
    while (true)
    {
        cout << "管理员菜单:" << endl;
        cout << "[1] 查看教师列表" << endl;
        cout << "[2] 查看学生列表" << endl;
        cout << "[3] 编辑表格" << endl;
        cout << "[4] 表格排序" << endl;
        cout << "[5] 保存修改到文件" << endl;
        cout << "[6] 回到主菜单" << endl;
        cout << "请输入你的选择并按回车键继续 (1-6):";
        char opt;
        cin >> opt;
        switch (opt)
        {
        case ('1'):
            this->tlist.showAll();
            // jixu();
            break;
        case ('2'):
            this->slist.showAll();
            // jixu();
            break;
        case ('3'):
            this->edit();
            break;
        case ('4'):
            this->slist.sort();
            break;
        case ('5'):
        {
            CSV csv(this->pathToStudents, this->pathToTeachers);
            csv.save(&this->slist, &this->tlist);
            csv.~CSV();
            jixu();
            break;
        }
        case ('6'):
            return;
            break;
        default:
            jixu();
            break;
        }
    }
}

void ScoreManagementSystem::teacher()
{
    int subject = SUBJECT_NULL;
    int *psub = &subject;
    while (true)
    {
        if (*psub == SUBJECT_NULL)
        {
            cout << "选择登陆的教师:" << endl;
            cout << "[1] 以ID登陆" << endl;
            cout << "[2] 以教师姓名登陆" << endl;
            cout << "[3] 查看教师列表" << endl;
            cout << "[4] 回到主菜单" << endl;
            cout << "请输入你的选择并按回车键继续 (1-4):";
            char opt;
            cin >> opt;
            switch (opt)
            {
            case ('1'):
            {
                int i = this->tlist.findID();
                if (i == TEACHER_NOT_FOUND)
                {
                    cout << "没有找到ID !" << endl;
                    *psub = SUBJECT_NULL;
                    jixu();
                    break;
                }
                *psub = this->tlist.getSubject(i);
                cout << "你的教师科目是 :" << intToSubject(this->tlist.getSubject(i)) << endl;
                jixu();
                break;
            }
            case ('2'):
            {
                int i = this->tlist.findName();
                if (i == TEACHER_NOT_FOUND)
                {
                    cout << "没有找到姓名 !" << endl;
                    *psub = SUBJECT_NULL;
                    jixu();
                    break;
                }
                *psub = this->tlist.getSubject(i);
                cout << "你的教师科目是 :" << intToSubject(this->tlist.getSubject(i)) << endl;
                jixu();
                break;
            }
            case ('3'):
                this->tlist.showAll();
                jixu();
                continue;
                break;
            case ('4'):
                return;
                break;
            default:
                cout << "未知选项，";
                jixu();
                break;
            }
        }

        cout << "正在以 " << intToSubject(subject) << " 老师身份登陆:" << endl;
        cout << "[1] 查看学生列表" << endl;
        cout << "[2] 通过学生ID输入成绩" << endl;
        cout << "[3] 通过学生姓名输入成绩" << endl;
        cout << "[4] 排序学生列表" << endl;
        cout << "[5] 保存修改到文件" << endl;
        cout << "[6] 登出" << endl;
        cout << "请输入你的选择并按回车键继续 (1-6):";
        char opt;
        cin >> opt;
        switch (opt)
        {
        case ('1'):
        {
            this->slist.showAll();
            // jixu();
            break;
        }
        break;
        case ('2'):
        {
            int i = this->slist.findID();
            if (this->slist.getScore(i, subject) == 0)
            {
                this->slist.show(i);
                cout << "输入成绩:";
                int score;
                cin >> score;
                this->slist.editScore(i, subject, score);
                this->slist.show(i);
                jixu();
                break;
            }
            else
            {
                cout << "成绩不能修改！" << endl;
                jixu();
                break;
            }
        }
        break;
        case ('3'):
        {
            int i = this->slist.findName();
            if (this->slist.getScore(i, subject) == 0)
            {
                this->slist.show(i);
                cout << "输入成绩:";
                int score;
                cin >> score;
                this->slist.editScore(i, subject, score);
                this->slist.show(i);
                jixu();
                break;
            }
            else
            {
                cout << "成绩不能修改！" << endl;
                jixu();
                break;
            }
        }
        break;
        case ('4'):
            this->slist.sort();
            break;
        case ('5'):
        {
            CSV csv(this->pathToStudents, this->pathToTeachers);
            csv.save(&this->slist, &this->tlist);
            jixu();
            break;
        }
        break;
        case ('6'):
        {
            *psub = SUBJECT_NULL;
            cout << "成功登出，";
            jixu();
            return;
            break;
        }
        default:
        {
            cout << "未知选项，";
            jixu();
            break;
        }
        }
    }
}

void ScoreManagementSystem::student()
{
    while (true)
    {
        cout << "以学生身份登陆:" << endl;
        cout << "[1] 通过ID查找成绩" << endl;
        cout << "[2] 通过姓名查找成绩" << endl;
        cout << "[3] 回到主菜单" << endl;
        cout << "请输入你的选择并按回车键继续 (1-3):";
        char opt;
        cin >> opt;
        switch (opt)
        {
        case ('1'):
        {
            this->slist.show(this->slist.findID());
            jixu();
            break;
        }
        break;
        case ('2'):
        {
            this->slist.show(this->slist.findName());
            jixu();
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
            cout << "未知选项，";
            jixu();
            break;
        }
        }
    }
}

void ScoreManagementSystem::reloadFile()
{
    CSV csv(this->pathToStudents, this->pathToTeachers);
    csv.read(&this->slist, &this->tlist);
    jixu();
}

void ScoreManagementSystem::helpManual()
{
    cout << "用户包含：管理员、教师、学生；" << endl
         << "管理员具有最高权限，可以录入教师、学生信息；" << endl
         << "教师：录入学生成绩信息（至少3科），成绩提交后不能修改；" << endl
         << "可以对学生成绩进行排序（包括单科、总分）" << endl
         << "学生：查询个人成绩信息" << endl;
    cout << "请按回车键继续...";
    cin.get();
    cin.get();
}

void ScoreManagementSystem::showTeacherList()
{
    this->tlist.showAll();
}

void ScoreManagementSystem::showStudentList()
{
    this->slist.showAll();
}

// void ScoreManagementSystem::sort(int subject)
// {
//     cout << "[1] 从小到大排序" << endl;
//     cout << "[2] 从大到小排序" << endl;
//     cout << "[3] 取消" << endl;
//     cout << "请输入你的选择并按回车键继续 (1-3):";
//     char opt;
//     cin >> opt;
//     switch (opt)
//     {
//     case ('1'):
//         quickSort(0, this->studentList.size() - 1, studentList, subject);
//         cout << "请按回车键继续...";
//         cin.get();
//         cin.get();
//         // this->login();
//         break;
//     case ('2'):
//         quickSort(0, this->studentList.size() - 1, studentList, subject);
//         std::reverse(studentList.begin(), studentList.end());
//         cout << "请按回车键继续...";
//         cin.get();
//         cin.get();
//         // this->login();
//         break;
//     case ('3'):
//         // this->login();
//         return;
//         break;
//     default:
//         cout << "未知选项，请按回车键继续...";
//         cin.get();
//         cin.get();
//         break;
//     }
// }

// //快速排序（从小到大）
// void quickSort(int left, int right, vector<Student *> &arr, int subject)
// {
//     if (left >= right)
//         return;
//     int i, j, base;
//     Student *temp = NULL;
//     i = left, j = right;
//     base = arr[left]->getScore(subject); //取最左边的数为基准数
//     while (i < j)
//     {
//         while (arr[j]->getScore(subject) >= base && i < j)
//             j--;
//         while (arr[i]->getScore(subject) <= base && i < j)
//             i++;
//         if (i < j)
//         {
//             temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
//     //基准数归位
//     temp = arr[left];
//     arr[left] = arr[i];
//     arr[i] = temp;
//     quickSort(left, i - 1, arr, subject);  //递归左边
//     quickSort(i + 1, right, arr, subject); //递归右边
// }

void ScoreManagementSystem::edit()
{
    while (true)
    {
        cout << "修改菜单:" << endl;
        cout << "[1] 添加一个学生" << endl;
        cout << "[2] 添加一个老师" << endl;
        cout << "[3] 删除一个学生" << endl;
        cout << "[4] 删除一个老师" << endl;
        cout << "[5] 修改一个学生" << endl;
        cout << "[6] 修改一个老师" << endl;
        cout << "[7] 查看学生列表" << endl;
        cout << "[8] 查看老师列表" << endl;
        cout << "[9] 退出" << endl;
        cout << "请输入你的选择并按回车键继续 (1-9):";
        char opt;
        cin >> opt;
        switch (opt)
        {
        case ('9'):
            return;
            break;
        case ('1'):
        {
            while (true)
            {
                this->slist.add();
                cin.get();
                cout << "是否继续添加学生?[Y/n]";
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
                this->tlist.add();
                cin.get();
                cout << "是否继续添加教师?[Y/n]";
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
            while (true)
            {
                cout << "删除一个学生:" << endl;
                cout << "[1] 通过学生ID删除" << endl;
                cout << "[2] 通过学生姓名删除" << endl;
                cout << "[3] 回到主菜单" << endl;
                cout << "请输入你的选择并按回车键继续 (1-3):";
                char opt;
                cin >> opt;
                switch (opt)
                {
                case ('1'):
                {
                    this->slist.deleteOne(this->slist.findID());
                    break;
                }
                case ('2'):
                {
                    this->slist.deleteOne(this->slist.findName());
                    break;
                }
                case ('3'):
                {
                    return;
                    break;
                }
                default:
                {
                    cout << "未知选项，";
                    jixu();
                    break;
                }
                }
            }
        }
        break;
        case ('4'):
        {
            while (true)
            {
                cout << "删除一个教师:" << endl;
                cout << "[1] 通过ID删除" << endl;
                cout << "[2] 通过姓名删除" << endl;
                cout << "[3] 回到菜单" << endl;
                cout << "请输入你的选择并按回车键继续 (1-3):";
                char opt;
                cin >> opt;
                switch (opt)
                {
                case ('1'):
                {
                    this->tlist.deleteOne(this->tlist.findID());
                    break;
                }
                break;
                case ('2'):
                {
                    this->tlist.deleteOne(this->tlist.findName());
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
                    cout << "未知选项，";
                    jixu();
                    break;
                }
                }
            }
        }
        break;
        case ('8'):
            this->showTeacherList();
            break;
        case ('7'):
            this->showStudentList();
            break;
        case ('5'):
        {
            while (true)
            {
                cout << "编辑一个学生:" << endl;
                cout << "[1] 通过ID编辑" << endl;
                cout << "[2] 通过姓名编辑" << endl;
                cout << "[3] 回到菜单" << endl;
                cout << "请输入你的选择并按回车键继续 (1-3):";
                char opt;
                cin >> opt;
                switch (opt)
                {
                case ('1'):
                {
                    int i = this->slist.findID();
                    this->slist.show(i);
                    cin.get();
                    cout << "是否修改这个学生?[Y/n]";
                    char opt = getchar();
                    if (opt == 'Y' || opt == 'y' || opt == '\n')
                    {
                        this->slist.editID(i);
                        this->slist.editName(i);
                        this->slist.editScore(i);
                    }
                    else
                    {
                        return;
                    }
                    break;
                }
                case ('2'):
                {
                    int i = this->slist.findName();
                    this->slist.show(i);
                    cin.get();
                    cout << "是否修改这个学生?[Y/n]";
                    char opt = getchar();
                    if (opt == 'Y' || opt == 'y' || opt == '\n')
                    {
                        this->slist.editID(i);
                        this->slist.editName(i);
                        this->slist.editScore(i);
                    }
                    else
                    {
                        return;
                    }
                    break;
                }
                case ('3'):
                {
                    return;
                    break;
                }
                default:
                {
                    cout << "未知选项，";
                    jixu();
                    break;
                }
                }
            }
        }
        break;
        case ('6'):
        {
            while (true)
            {
                cout << "修改教师:" << endl;
                cout << "[1] 通过ID编辑" << endl;
                cout << "[2] 通过姓名编辑" << endl;
                cout << "[3] 回到菜单" << endl;
                cout << "请输入你的选择并按回车键继续 (1-3):";
                char opt;
                cin >> opt;
                switch (opt)
                {
                case ('1'):
                {
                    int i = this->tlist.findID();
                    this->tlist.show(i);
                    this->tlist.editID(i);
                    this->tlist.editName(i);
                    this->tlist.editSubject(i);
                    break;
                }
                break;
                case ('2'):
                {
                    int i = this->tlist.findName();
                    this->tlist.show(i);
                    this->tlist.editID(i);
                    this->tlist.editName(i);
                    this->tlist.editSubject(i);
                    break;
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
                    cout << "未知选项，";
                    jixu();
                    break;
                }
                }
            }
        }
        break;
        default:
            cout << "未知选项，";
            jixu();
            break;
        }
    }
}