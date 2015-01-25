#include<iostream>
#include<sstream>
#include<string>

using namespace std;

bool HasHexLetters(int x) {
	string s;
	char ch;
	stringstream sstring;
	sstring<<hex<<x;
	sstring>>s;
	cout<<s<<endl;	
        if(sstring>>ch)
	{
		return true;

	}	
		
	else  return false;
}

int main(){
int number;
	cout<<boolalpha<<HasHexLetters(200)<<endl;
	return 0;
}
