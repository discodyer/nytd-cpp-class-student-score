#include "StudentList.h"

StudentList::StudentList()
{
}

void StudentList::deleteOne(int i)
{
    if (i == STUDENT_NOT_FOUND)
        return;
    this->show(i);
    cin.get();
    cout << "�Ƿ�ɾ�����ѧ��?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        if (i < this->list.size() && i > 0)
        {
            auto iter = this->list.erase(this->list.begin() + i);
        }
        else if (this->list.size() == 0 || this->list.size() == 1)
        {
            this->deleteAll();
            return;
        }
    }
    else
    {
        cout << "ȡ��" << endl;
    }
    jixu();
}

void StudentList::deleteAll()
{
    this->list.clear();
    vector<stu>().swap(list);
}

void StudentList::add(string id, string name, int scoreChinese, int scoreEnglish, int scoreMaths)
{
    stu tmp;
    tmp.id = id;
    tmp.name = name;
    tmp.scoreChinese = scoreChinese;
    tmp.scoreEnglish = scoreEnglish;
    tmp.scoreMaths = scoreMaths;
    tmp.scoreTotal = scoreChinese + scoreEnglish + scoreMaths;
    list.push_back(tmp);
}

void StudentList::add()
{
    string id, name;
    int scoreChinese = 0, scoreEnglish = 0, scoreMaths = 0;
    cout << "���һ��ѧ����" << endl;
    cout << "����ѧ��:";
    cin >> id;
    cout << "��������:";
    cin >> name;
    // cout << "�������ĳɼ�:";
    // cin >> scoreChinese;
    // cout << "����Ӣ��ɼ�:";
    // cin >> scoreEnglish;
    // cout << "������ѧ�ɼ�:";
    // cin >> scoreMaths;
    this->add(id, name, scoreChinese, scoreEnglish, scoreMaths);
    cout << "��ӳɹ�" << endl;
    jixu();
    return;
}

void StudentList::editScore(int i)
{
    if (i == STUDENT_NOT_FOUND)
        return;
    int scoreChinese = 0, scoreEnglish = 0, scoreMaths = 0;
    this->show(i);
    cin.get();
    cout << "�Ƿ��޸����ѧ���ĳɼ�?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        cout << "�������ĳɼ�:";
        cin >> scoreChinese;
        cout << "����Ӣ��ɼ�:";
        cin >> scoreEnglish;
        cout << "������ѧ�ɼ�:";
        cin >> scoreMaths;

        this->list[i].scoreChinese = scoreChinese;
        this->list[i].scoreEnglish = scoreEnglish;
        this->list[i].scoreMaths = scoreMaths;
        this->list[i].scoreTotal = scoreChinese + scoreEnglish + scoreMaths;
        cout << "�޸ĺ���" << endl;
        this->show(i);
        jixu();
        return;
    }
    else
    {
        cout << "ȡ��" << endl;
        jixu();
        return;
    }
}

void StudentList::editScore(int i, int subject, int score)
{
    switch (subject)
    {
    case (SUBJECT_CHINESE):
        this->list[i].scoreChinese = score;
        break;
    case (SUBJECT_ENGLISH):
        this->list[i].scoreEnglish = score;
        break;
    case (SUBJECT_MATHS):
        this->list[i].scoreMaths = score;
        break;
    default:
        break;
    }
    this->list[i].scoreTotal = this->list[i].scoreChinese + this->list[i].scoreEnglish + this->list[i].scoreMaths;
}

void StudentList::editID(int i, string id)
{
    if (i == STUDENT_NOT_FOUND)
        return;
    this->list[i].id = id;
}

void StudentList::editID(int i)
{
    if (i == STUDENT_NOT_FOUND)
        return;
    this->show(i);
    cin.get();
    cout << "�Ƿ��޸����ѧ����ѧ��?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        string id;
        cout << "����ѧ��:";
        cin >> id;

        this->editID(i, id);

        cout << "�޸ĺ���" << endl;
        this->show(i);
        jixu();
        return;
    }
    else
    {
        cout << "ȡ��" << endl;
        jixu();
        return;
    }
}

void StudentList::editName(int i, string name)
{
    if (i == STUDENT_NOT_FOUND)
        return;
    this->list[i].name = name;
}

void StudentList::editName(int i)
{
    if (i == STUDENT_NOT_FOUND)
        return;
    this->show(i);
    cin.get();
    cout << "�Ƿ��޸����ѧ��������?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        string name;
        cout << "��������:";
        cin >> name;

        this->editName(i, name);

        cout << "�޸ĺ���" << endl;
        this->show(i);
        jixu();
        return;
    }
    else
    {
        cout << "ȡ��" << endl;
        jixu();
        return;
    }
}

string StudentList::getID(int i)
{
    if (i == STUDENT_NOT_FOUND)
        return "NULL";
    return this->list[i].id;
}

string StudentList::getName(int i)
{
    if (i == STUDENT_NOT_FOUND)
        return "NULL";
    return this->list[i].name;
}

int StudentList::getScore(int i, int subject)
{
    if (i == STUDENT_NOT_FOUND)
        return STUDENT_NOT_FOUND;
    switch (subject)
    {
    case SUBJECT_CHINESE:
        return this->list[i].scoreChinese;
        break;
    case SUBJECT_ENGLISH:
        return this->list[i].scoreEnglish;
        break;
    case SUBJECT_MATHS:
        return this->list[i].scoreMaths;
        break;
    default:
        return this->list[i].scoreTotal;
        break;
    }
}

void StudentList::showAll()
{
    cout << "id\t|name\t|Chinese|English|Maths\t|Total" << endl;
    for (int i = 0; i < this->list.size(); i++)
    {
        cout << this->list[i].id << '\t'
             << this->list[i].name << '\t'
             << this->list[i].scoreChinese << '\t'
             << this->list[i].scoreEnglish << '\t'
             << this->list[i].scoreMaths << '\t'
             << this->list[i].scoreTotal << endl;
    }
    jixu();
    return;
}

int StudentList::findID()
{
    cout << "����ID:";
    string id;
    cin >> id;
    int i;
    for (i = 0; i < this->list.size(); i++)
    {
        if (getID(i) == id)
        {
            return i;
        }
    }
    cout << "û���ҵ�ID !" << endl;
    jixu();
    return STUDENT_NOT_FOUND;
}

int StudentList::findName()
{
    cout << "��������:";
    string name;
    cin >> name;
    int i;
    for (i = 0; i < this->list.size(); i++)
    {
        if (this->list[i].name == name)
        {
            return i;
        }
    }
    cout << "û���ҵ����� !" << endl;
    jixu();
    return STUDENT_NOT_FOUND;
}

void StudentList::sort()
{
    cout << "ѡ�������Ŀ:" << endl;
    cout << "[1] ����" << endl;
    cout << "[2] Ӣ��" << endl;
    cout << "[3] ��ѧ" << endl;
    cout << "[4] �ܷ�" << endl;
    cout << "[5] ȡ��" << endl;
    cout << "���������ѡ�񲢰��س������� (1-6):";
    char opt;
    cin >> opt;
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
        cout << "δ֪ѡ�";
        jixu();
        break;
    }
}

void StudentList::sort(int subject)
{
    cout << "��ѡ�����򷽷�" << endl;
    cout << "[1] ��С��������" << endl;
    cout << "[2] �Ӵ�С����" << endl;
    cout << "[3] ȡ��" << endl;
    cout << "���������ѡ�񲢰��س������� (1-3):";
    char opt;
    cin >> opt;
    switch (opt)
    {
    case ('1'):
        this->sortSubject(subject);
        jixu();
        break;
    case ('2'):
        this->sortSubject(subject);
        std::reverse(list.begin(), list.end());
        jixu();
        break;
    case ('3'):
        return;
        break;
    default:
        cout << "δ֪ѡ�";
        jixu();
        break;
    }
}

StudentList::~StudentList()
{
}

void StudentList::show(int i)
{
    if (i == STUDENT_NOT_FOUND)
        return;
    cout << "id\t|name\t|Chinese|English|Maths\t|Total" << endl;
    cout << this->list[i].id << '\t'
         << this->list[i].name << '\t'
         << this->list[i].scoreChinese << '\t'
         << this->list[i].scoreEnglish << '\t'
         << this->list[i].scoreMaths << '\t'
         << this->list[i].scoreTotal << endl;
}

void StudentList::sortSubject(int subject)
{
    if (subject == subjectToInt("Chinese"))
    {
        std::sort(this->list.begin(), this->list.end(), [](stu a, stu b)
                  { return a.scoreChinese < b.scoreChinese; });
    }
    else if (subject == subjectToInt("English"))
    {
        std::sort(this->list.begin(), this->list.end(), [](stu a, stu b)
                  { return a.scoreEnglish < b.scoreEnglish; });
    }
    else if (subject == subjectToInt("Maths"))
    {
        std::sort(this->list.begin(), this->list.end(), [](stu a, stu b)
                  { return a.scoreMaths < b.scoreMaths; });
    }
    else
    {
        std::sort(this->list.begin(), this->list.end(), [](stu a, stu b)
                  { return a.scoreTotal < b.scoreTotal; });
    }
}

int StudentList::getSize()
{
    return this->list.size();
}