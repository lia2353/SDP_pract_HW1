#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include"Student.h"
#include<fstream>

using namespace std;

void create()
{
    ofstream file;
    file.open("StudentsGrades.db", ios::app);
    if(!file)
    {
        cerr  << "ERROR: can't open this file\n";
        return;
    }
    Student st;
    //asks for the student's faculty number, first name,  last name and grade
    cin >> st;
    file << st;
    cout << "Record saved!\n";
    file.close();
    return;
}

void sequentialSearch()
{
    ifstream file;
    file.open("StudentsGrades.db", ios::in);
    if(!file)
    {
        cerr  << "ERROR: can't open this file\n";
        return;
    }

    //asks for the faculty number of the student whom the user wants to find
    string facNum;
    cin >> facNum;
    int position = 0;
    string lineFromFile;
    while (!file.eof())
	{
	    getline(file, lineFromFile);
	    //function of class string that searches for facNum and returns its position
        position = lineFromFile.find(facNum);
        //returns string::npos if string is not found
		if (position != string::npos)
		{
			cout << lineFromFile << endl;
			return;
		}
	}
	cout << "Record not found!\n";
	file.close();
    return;
}

#endif // COMMAND_H_INCLUDED
