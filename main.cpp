#include <iostream>
#include "OperationParser.h"

using namespace std;


int main()
{
    OperationParser parser;

    //asks for operation (create , sequentialSearch , exit)
    cin >> parser;

    //asks the user to enter an operation till entering exit
    while (parser.getOperation() != "exit")
	{
		parser.doOperation();
		//asks for operation (create , sequentialSearch , exit)
		cin >> parser;
	}
    return 0;
}
