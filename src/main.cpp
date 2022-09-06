#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
    int opt;
    opterr = 0;
    string pathToStudents = "students.csv", pathToTeachers = "teachers.csv"; // the path to .csv list files
    while( (opt = getopt(argc, argv, "hs:t:")) != -1 ) // 读取命令行参数
    {
        switch (opt)
        {
            case 's':
                pathToStudents = optarg;
                cout<<"path to students.csv : "<<pathToStudents<<endl;
                break;
            case 't':
                pathToTeachers = optarg;
                cout<<"path to teachers.csv : "<<pathToTeachers<<endl;
                break;
            case 'h':
                cout<<"help message"<<endl;
                help();
                exit(1);
                break;
            case '?':
                if (optopt == 's' || optopt == 't' )
                {
                    fprintf(stderr,"Option -%c requires an argument.", optopt);
                }
                else if (isprint(optopt))
                {
                    fprintf(stderr,"Unknown option `-%c'.\n", optopt);
                    help();
                }
                else
                {
                    fprintf(stderr,"Unknown option character `\\x%x'.\n",optopt);
                    help();
                }
                return 1;
            default:
                abort();
                break;
        }
    }
    if( argc == 1 ) // if no cmd options
    {
        cout<<"using default location."<<endl;
    }

    ScoreManagementSystem S(pathToStudents, pathToTeachers);  // 实例化管理系统
    S.start();  // 入口函数
    return 0;
}

void help() // 命令行帮助文本
{
    cout<<"------------------------------------------"<<endl;
    cout<<"-s   [path to Studients.csv]"<<endl;
    cout<<"-t   [path to Teachers.csv]"<<endl;
    cout<<"-h   show help message"<<endl;
    cout<<"     Leave empty to create new .csv files."<<endl;
    cout<<"------------------------------------------"<<endl;
}

