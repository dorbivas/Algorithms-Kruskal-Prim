#include <string>
#include <iostream>
using namespace std;

static const string errorMessage(string msg)
{
	string str = "Invalid Input. error: " + msg + "\n";
	cout << str;
	return str;

}
