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
    cout << "是否删除这位教师?[Y/n]";
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
        cout << "取消" << endl;
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
    cout << "添加一位教师：" << endl;
    cout << "输入教师编号:";
    cin >> id;
    cout << "输入姓名:";
    cin >> name;
    cout << "输入学科:";
    cin >> subject;
    this->add(id, name, subjectToInt(subject));
    cout << "添加成功" << endl;
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
    cout << "是否修改这位老师的学科?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        string subject;
        cout << "输入学科:";
        cin >> subject;

        this->editSubject(i, subjectToInt(subject));

        cout << "修改好了" << endl;
        this->show(i);
        jixu();
        return;
    }
    else
    {
        cout << "取消" << endl;
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
    cout << "是否修改这位教师的编号?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        string id;
        cout << "输入编号:";
        cin >> id;

        this->editID(i, id);

        cout << "修改好了" << endl;
        this->show(i);
        jixu();
        return;
    }
    else
    {
        cout << "取消" << endl;
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
    cout << "是否修改这位教师的姓名?[Y/n]";
    char opt = getchar();
    if (opt == 'Y' || opt == 'y' || opt == '\n')
    {
        string name;
        cout << "输入姓名:";
        cin >> name;

        this->editName(i, name);

        cout << "修改好了" << endl;
        this->show(i);
        jixu();
        return;
    }
    else
    {
        cout << "取消" << endl;
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
    cout << "输入ID:";
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
    cout << "没有找到ID !" << endl;
    jixu();
    return TEACHER_NOT_FOUND;
}

int TeacherList::findName()
{
    cout << "输入名字:";
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
    cout << "没有找到名字 !" << endl;
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