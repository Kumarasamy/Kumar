/* Find the integer hex notation having letters or not */ 

#include<iostream>
#include<sstream>
#include<string>

using namespace std;

bool HasHexLetters(int x) {
	string s;
	char ch;
	stringstream sstring;
	sstring<<hex<<x;
	return sstring.str().find_first_of("abcdefABCDEF") != string::npos;
}

int main(){
int number;
	cout<<boolalpha<<HasHexLetters(100)<<endl;
	return 0;
}
