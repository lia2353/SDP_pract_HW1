#ifndef OPERATIONPARSER_H_INCLUDED
#define OPERATIONPARSER_H_INCLUDED

#include"Command.h"
#include<fstream>
#include<string>

using namespace std;

class OperationParser
{
private:
	string operation;
public:
	OperationParser();
	string getOperation() const;
	void doOperation();
	friend istream& operator>>(istream&, OperationParser&);
};

//the default operation for the parser is create
OperationParser::OperationParser()
{
	operation = "create";
}

inline string OperationParser::getOperation() const
{
	return operation;
}

//receives a string with an operation and parses it to its respective function
//if "exit" program will end in main's while clause
inline void OperationParser::doOperation()
{
    if (operation == "create")
    {
	create();
    }
    else if (operation == "sequentialSearch")
    {
	sequentialSearch();
    }
    else if (operation == "update")
    {
        update();
    }
    else if (operation == "delete")
    {
        deletest();
    }
    else
    {
	operation = "exit";
    }
}

istream& operator>>(istream& is, OperationParser& parcer)
{
	is >> parcer.operation;
	return is;
}

#endif // OPERATIONPARSER_H_INCLUDED
