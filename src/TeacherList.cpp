#include "TeacherList.h"

TeacherList::TeacherList()
{
}

void TeacherList::deleteOne(int i)
{
    if (i == TEACHER_NOT_FOUND)
        return;
    this->show(i);
    cin.get();
    cout << "�Ƿ�ɾ����λ��ʦ?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        if (i < this->list.size() && i > 0)
        {
            this->list.erase(this->list.begin() + i);
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

void TeacherList::deleteAll()
{
    this->list.clear();
    vector<tch>().swap(list);
}

void TeacherList::add()
{
    string id, name, subject;
    cout << "���һλ��ʦ��" << endl;
    cout << "�����ʦ���:";
    cin >> id;
    cout << "��������:";
    cin >> name;
    cout << "����ѧ��:";
    cin >> subject;
    this->add(id, name, subjectToInt(subject));
    cout << "��ӳɹ�" << endl;
    jixu();
    return;
}

void TeacherList::add(string id, string name, int subject)
{
    tch tmp;
    tmp.id = id;
    tmp.name = name;
    tmp.subject = subject;
    this->list.push_back(tmp);
}

void TeacherList::editSubject(int i)
{
    if (i == TEACHER_NOT_FOUND)
        return;
    this->show(i);
    cin.get();
    cout << "�Ƿ��޸���λ��ʦ��ѧ��?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        string subject;
        cout << "����ѧ��:";
        cin >> subject;

        this->editSubject(i, subjectToInt(subject));

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

void TeacherList::editSubject(int i, int subject)
{
    this->list[i].subject = subject;
}

void TeacherList::editID(int i, string id)
{
    if (i == TEACHER_NOT_FOUND)
        return;
    this->list[i].id = id;
}

void TeacherList::editID(int i)
{
    if (i == TEACHER_NOT_FOUND)
        return;
    this->show(i);
    cin.get();
    cout << "�Ƿ��޸���λ��ʦ�ı��?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        string id;
        cout << "������:";
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

void TeacherList::editName(int i, string name)
{
    if (i == TEACHER_NOT_FOUND)
        return;
    this->list[i].name = name;
}

void TeacherList::editName(int i)
{
    if (i == TEACHER_NOT_FOUND)
        return;
    this->show(i);
    cin.get();
    cout << "�Ƿ��޸���λ��ʦ������?[Y/n]";
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

string TeacherList::getID(int i)
{
    if (i == TEACHER_NOT_FOUND)
        return "NULL";
    return this->list[i].id;
}

string TeacherList::getName(int i)
{
    if (i == TEACHER_NOT_FOUND)
        return "NULL";
    return this->list[i].name;
}

int TeacherList::getSubject(int i)
{
    return this->list[i].subject;
}

void TeacherList::show(int i)
{
    cout << "id\t|name\t|subject" << endl;
    cout << getID(i) << "\t|"
         << getName(i) << "\t|"
         << intToSubject(getSubject(i)) << endl;
    jixu();
}

void TeacherList::showAll()
{
    cout << "id\t|name\t|subject" << endl;
    int i = 0;
    for (i = 0; i < this->list.size(); i++)
    {
        cout << getID(i) << "\t|"
             << getName(i) << "\t|"
             << intToSubject(getSubject(i)) << endl;
    }
    cout << endl;
    jixu();
    return;
}

int TeacherList::findID()
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
    return TEACHER_NOT_FOUND;
}

int TeacherList::findName()
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
    return TEACHER_NOT_FOUND;
}

TeacherList::~TeacherList()
{
}

int TeacherList::getSize()
{
    return this->list.size();
}