#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class Student
{
private:
    unsigned long long FN;
    string FirstName, LastName;
    int Grade;
public:
    Student(unsigned long long =0, string = "", string = "", int = 0);

    unsigned long long getFN() const;
    string getFirstName() const;
    string getLastName() const;
	int getGrade() const;

	friend ostream& operator<<(ostream&, Student&);
	friend istream& operator>>(istream&, Student&);
};

Student::Student(unsigned long long fn, string fname, string lname, int grade)
{
	FN = fn;
	FirstName = fname;
	LastName = lname;
	Grade = grade;
}

unsigned long long Student::getFN() const
{
    return FN;
}

string Student::getFirstName() const
{
	return FirstName;
}

string Student::getLastName() const
{
	return LastName;
}

int Student::getGrade() const
{
	return Grade;
}


ostream & operator<<(ostream & os, Student & obj)
{
	os << obj.FN << ' ' << obj.FirstName << ' ' << obj.LastName << ' ' << obj.Grade << '\n';
	return os;
}


istream& operator>>(istream& is, Student& obj)
{
	is >> obj.FN >> obj.FirstName >> obj.LastName >> obj.Grade;
	return is;
}

#endif // STUDENT_H_INCLUDED
