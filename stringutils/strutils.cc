#include "strutils.h"
#include<iostream>
#include<sstream>
#include<cctype>

using namespace std;

string ToUpperCase(string input) {
	for(int i= 0;i<input.size();i++)
	{
		input[i] = toupper(input[i]);
	}
return input;
}

string ToLower(string input) {
	for(int i= 0;i<input.size();i++)
	{
		input[i] = tolower(input[i]);
	}
return input;
}
string IntToString(int input) {
	stringstream sstring;
	sstring>>input;
	return sstring.str();
}
string DoubleToString(int input) {
	stringstream sstring;
	sstring>>input;
	return sstring.str();
}
