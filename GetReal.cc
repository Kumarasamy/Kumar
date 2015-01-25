#include<iostream>
#include<sstream>
#include<string>

using namespace std;

string GetLine(){
	string result;
	getline(cin,result);
	return result ;
}

float GetReal(){

	while(true) {
		stringstream ss;
		ss<<GetLine();
		float fresult;
		//int fresult;
		if(ss>>fresult)
		{
			char ch;
			if(ss>>ch)
				cout<<"Please enter Real value"<<endl;
			else
				return fresult;	
		}
		else
			cout<<"Try again"<<endl;
	}

}

bool GetBool() {
	while(true) {
	stringstream sstring;
	sstring<<GetLine();
	bool bval;
	if(sstring>>bval)
	{
		char ch;
		if(sstring>>ch)
			cout<<"Please enter bool value"<<endl;
		else
			return bval;
	}
	else 
		cout<<"Try again "<<endl;

	}

}

int main() {

	//float fl;
	//int fl;
	bool bval;
	//fl=GetReal();
	bval=GetBool();
	//cout<<fl;
	cout<<boolalpha<<bval<<endl;

	return 0;
}
