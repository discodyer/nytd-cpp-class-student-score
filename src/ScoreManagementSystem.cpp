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
        cout << "============================" << endl;
        cout << "# ��ӭ����ѧ���ɼ�����ϵͳ ! #" << endl;
        cout << "============================" << endl;
        cout << "[1] ��ʾ�����ı�" << endl;
        cout << "[2] ��½ϵͳ" << endl;
        cout << "[3] ���¶�ȡ .csv �ļ�" << endl;
        cout << "[4] �˳�ϵͳ" << endl;
        cout << "���������ѡ�񲢰��س������� (1-4):";
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
            cout << "δ֪ѡ�";
            jixu();
        }
    }
}

void ScoreManagementSystem::login()
{
    while (true)
    {
        cout << "ѡ���½��� :" << endl;
        cout << "[1] ����Ա" << endl;
        cout << "[2] ��ʦ" << endl;
        cout << "[3] ѧ��" << endl;
        cout << "[4] �ص����˵�" << endl;
        cout << "���������ѡ�񲢰��س������� (1-4):";
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
            cout << "δ֪ѡ�";
            jixu();
        }
    }
}

void ScoreManagementSystem::admin()
{
    while (true)
    {
        cout << "����Ա�˵�:" << endl;
        cout << "[1] �鿴��ʦ�б�" << endl;
        cout << "[2] �鿴ѧ���б�" << endl;
        cout << "[3] �༭���" << endl;
        cout << "[4] �������" << endl;
        cout << "[5] �����޸ĵ��ļ�" << endl;
        cout << "[6] �ص����˵�" << endl;
        cout << "���������ѡ�񲢰��س������� (1-6):";
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
            cout << "ѡ���½�Ľ�ʦ:" << endl;
            cout << "[1] ��ID��½" << endl;
            cout << "[2] �Խ�ʦ������½" << endl;
            cout << "[3] �鿴��ʦ�б�" << endl;
            cout << "[4] �ص����˵�" << endl;
            cout << "���������ѡ�񲢰��س������� (1-4):";
            char opt;
            cin >> opt;
            switch (opt)
            {
            case ('1'):
            {
                int i = this->tlist.findID();
                if (i == TEACHER_NOT_FOUND)
                {
                    cout << "û���ҵ�ID !" << endl;
                    *psub = SUBJECT_NULL;
                    jixu();
                    break;
                }
                *psub = this->tlist.getSubject(i);
                cout << "��Ľ�ʦ��Ŀ�� :" << intToSubject(this->tlist.getSubject(i)) << endl;
                jixu();
                break;
            }
            case ('2'):
            {
                int i = this->tlist.findName();
                if (i == TEACHER_NOT_FOUND)
                {
                    cout << "û���ҵ����� !" << endl;
                    *psub = SUBJECT_NULL;
                    jixu();
                    break;
                }
                *psub = this->tlist.getSubject(i);
                cout << "��Ľ�ʦ��Ŀ�� :" << intToSubject(this->tlist.getSubject(i)) << endl;
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
                cout << "δ֪ѡ�";
                jixu();
                break;
            }
        }

        cout << "������ " << intToSubject(subject) << " ��ʦ��ݵ�½:" << endl;
        cout << "[1] �鿴ѧ���б�" << endl;
        cout << "[2] ͨ��ѧ��ID����ɼ�" << endl;
        cout << "[3] ͨ��ѧ����������ɼ�" << endl;
        cout << "[4] ����ѧ���б�" << endl;
        cout << "[5] �����޸ĵ��ļ�" << endl;
        cout << "[6] �ǳ�" << endl;
        cout << "���������ѡ�񲢰��س������� (1-6):";
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
                cout << "����ɼ�:";
                int score;
                cin >> score;
                this->slist.editScore(i, subject, score);
                this->slist.show(i);
                jixu();
                break;
            }
            else
            {
                cout << "�ɼ������޸ģ�" << endl;
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
                cout << "����ɼ�:";
                int score;
                cin >> score;
                this->slist.editScore(i, subject, score);
                this->slist.show(i);
                jixu();
                break;
            }
            else
            {
                cout << "�ɼ������޸ģ�" << endl;
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
            cout << "�ɹ��ǳ���";
            jixu();
            return;
            break;
        }
        default:
        {
            cout << "δ֪ѡ�";
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
        cout << "��ѧ����ݵ�½:" << endl;
        cout << "[1] ͨ��ID���ҳɼ�" << endl;
        cout << "[2] ͨ���������ҳɼ�" << endl;
        cout << "[3] �ص����˵�" << endl;
        cout << "���������ѡ�񲢰��س������� (1-3):";
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
            cout << "δ֪ѡ�";
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
    cout << "�û�����������Ա����ʦ��ѧ����" << endl
         << "����Ա�������Ȩ�ޣ�����¼���ʦ��ѧ����Ϣ��" << endl
         << "��ʦ��¼��ѧ���ɼ���Ϣ������3�ƣ����ɼ��ύ�����޸ģ�" << endl
         << "���Զ�ѧ���ɼ��������򣨰������ơ��ܷ֣�" << endl
         << "ѧ������ѯ���˳ɼ���Ϣ" << endl;
    cout << "�밴�س�������...";
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
//     cout << "[1] ��С��������" << endl;
//     cout << "[2] �Ӵ�С����" << endl;
//     cout << "[3] ȡ��" << endl;
//     cout << "���������ѡ�񲢰��س������� (1-3):";
//     char opt;
//     cin >> opt;
//     switch (opt)
//     {
//     case ('1'):
//         quickSort(0, this->studentList.size() - 1, studentList, subject);
//         cout << "�밴�س�������...";
//         cin.get();
//         cin.get();
//         // this->login();
//         break;
//     case ('2'):
//         quickSort(0, this->studentList.size() - 1, studentList, subject);
//         std::reverse(studentList.begin(), studentList.end());
//         cout << "�밴�س�������...";
//         cin.get();
//         cin.get();
//         // this->login();
//         break;
//     case ('3'):
//         // this->login();
//         return;
//         break;
//     default:
//         cout << "δ֪ѡ��밴�س�������...";
//         cin.get();
//         cin.get();
//         break;
//     }
// }

// //�������򣨴�С����
// void quickSort(int left, int right, vector<Student *> &arr, int subject)
// {
//     if (left >= right)
//         return;
//     int i, j, base;
//     Student *temp = NULL;
//     i = left, j = right;
//     base = arr[left]->getScore(subject); //ȡ����ߵ���Ϊ��׼��
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
//     //��׼����λ
//     temp = arr[left];
//     arr[left] = arr[i];
//     arr[i] = temp;
//     quickSort(left, i - 1, arr, subject);  //�ݹ����
//     quickSort(i + 1, right, arr, subject); //�ݹ��ұ�
// }

void ScoreManagementSystem::edit()
{
    while (true)
    {
        cout << "�޸Ĳ˵�:" << endl;
        cout << "[1] ���һ��ѧ��" << endl;
        cout << "[2] ���һ����ʦ" << endl;
        cout << "[3] ɾ��һ��ѧ��" << endl;
        cout << "[4] ɾ��һ����ʦ" << endl;
        cout << "[5] �޸�һ��ѧ��" << endl;
        cout << "[6] �޸�һ����ʦ" << endl;
        cout << "[7] �鿴ѧ���б�" << endl;
        cout << "[8] �鿴��ʦ�б�" << endl;
        cout << "[9] �˳�" << endl;
        cout << "���������ѡ�񲢰��س������� (1-9):";
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
                cout << "�Ƿ�������ѧ��?[Y/n]";
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
                cout << "�Ƿ������ӽ�ʦ?[Y/n]";
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
                cout << "ɾ��һ��ѧ��:" << endl;
                cout << "[1] ͨ��ѧ��IDɾ��" << endl;
                cout << "[2] ͨ��ѧ������ɾ��" << endl;
                cout << "[3] �ص����˵�" << endl;
                cout << "���������ѡ�񲢰��س������� (1-3):";
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
                    cout << "δ֪ѡ�";
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
                cout << "ɾ��һ����ʦ:" << endl;
                cout << "[1] ͨ��IDɾ��" << endl;
                cout << "[2] ͨ������ɾ��" << endl;
                cout << "[3] �ص��˵�" << endl;
                cout << "���������ѡ�񲢰��س������� (1-3):";
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
                    cout << "δ֪ѡ�";
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
                cout << "�༭һ��ѧ��:" << endl;
                cout << "[1] ͨ��ID�༭" << endl;
                cout << "[2] ͨ�������༭" << endl;
                cout << "[3] �ص��˵�" << endl;
                cout << "���������ѡ�񲢰��س������� (1-3):";
                char opt;
                cin >> opt;
                switch (opt)
                {
                case ('1'):
                {
                    int i = this->slist.findID();
                    this->slist.show(i);
                    cin.get();
                    cout << "�Ƿ��޸����ѧ��?[Y/n]";
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
                    cout << "�Ƿ��޸����ѧ��?[Y/n]";
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
                    cout << "δ֪ѡ�";
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
                cout << "�޸Ľ�ʦ:" << endl;
                cout << "[1] ͨ��ID�༭" << endl;
                cout << "[2] ͨ�������༭" << endl;
                cout << "[3] �ص��˵�" << endl;
                cout << "���������ѡ�񲢰��س������� (1-3):";
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
                    cout << "δ֪ѡ�";
                    jixu();
                    break;
                }
                }
            }
        }
        break;
        default:
            cout << "δ֪ѡ�";
            jixu();
            break;
        }
    }
}