#pragma once
#include <string>
#include <iostream>
using namespace std;

static string errorMessage(string msg)
{
	string str = "Error: " + msg + "\n";
	//cout << str;
	return str;
}
