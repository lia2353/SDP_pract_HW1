#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include"Student.h"
#include<fstream>
#include<cstring>

using namespace std;

/*
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
*/

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

    string lineFromFile;
    string currFacNum;
    while (!file.eof())
	{
	    getline(file, lineFromFile);
	    //currFacNum is the faculty number of the student n this line; sequence of chars before first space
	    currFacNum = lineFromFile.substr(0, lineFromFile.find(' '));
		if (currFacNum == facNum)
		{
			cout << lineFromFile << endl;
			file.close();
			return;
		}
	}
	cout << "Record not found!\n";
	file.close();
    return;
}

void update()
{
    fstream file;
    file.open("StudentsGrades.db", ios::in|ios::out);
    if(!file)
    {
        cerr  << "ERROR: can't open this file\n";
        return;
    }

    //asks for the faculty number of the student whom the user wants to update
	string serchFacNum;
	cin >> serchFacNum;
	//asks for the new grade of the student
	char newGrade;
	cin >> newGrade;

	string lineFromFile;
	string currFacNum;
	streampos position = 0;
	while (!file.eof())
	{
	    getline(file, lineFromFile);
	    position += lineFromFile.length() + 2; //length of '\n' = 2
	    //currFacNum is the faculty number of the student n this line; sequence of chars before first space
	    currFacNum = lineFromFile.substr(0, lineFromFile.find(' '));
		if (currFacNum == serchFacNum)
		{
		    file.seekp(position-3, ios::beg); //length of '\n' + one position backward = 3
            file.put(newGrade);
			cout << "Record saved!\n";
			file.close();
			return;
		}
	}
	cout << "Record not found!\n";
	file.close();
	return;
}

void deletest()
{
    ifstream file;
    file.open("StudentsGrades.db", ios::in);
    ofstream tempFile;
    tempFile.open("temp.db", ios::out);
    if(!file && !tempFile)
    {
        cerr  << "ERROR: can't open this files\n";
        return;
    }

    //asks for the faculty number of the student whom the user wants to update
    string serchFacNum;
	cin >> serchFacNum;

	string lineFromFile;
	string currFacNum;
	bool found = false;
	//copies StudentsGrades file line by line to temp file but omits the student with given faculty number
	//than removes the StudentsGrades file and renames temp file to StudentsGrades
	while (!file.eof())
	{
	    getline(file, lineFromFile);
	    currFacNum = lineFromFile.substr(0, lineFromFile.find(' '));
		if (currFacNum == serchFacNum)
		{
			cout << "Record deleted!\n";
			found = true;
			continue;
		}
		tempFile << lineFromFile << '\n';
	}
	if(!found)
        cout << "Record not found!\n";

	tempFile.close();
	file.close();
    remove("StudentsGrades.db");
    rename("temp.db","StudentsGrades.db");
	return;
}

#endif // COMMAND_H_INCLUDED
