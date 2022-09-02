/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "main.h"

using namespace std;

int main(int argc, char **argv)
{
    int opt;
    opterr = 0;
    string pathToStudents = "", pathToTeachers = "";
    while( (opt = getopt(argc, argv, "hs:t:")) != -1 )
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

    // ScoreManagementSystem S;
    // S.init();
    // S.start();
    return 0;
}

void help()
{
    cout<<"------------------------------------------"<<endl;
    cout<<"-s   [path to Studients.csv]"<<endl;
    cout<<"-t   [path to Teachers.csv]"<<endl;
    cout<<"-h   show help message"<<endl;
    cout<<"     Leave empty to create new .csv files."<<endl;
    cout<<"------------------------------------------"<<endl;
}