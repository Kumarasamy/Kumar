/* Openfile using ifstream */
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void open_file(){
	string fname;

	while(true) {
		cin>>fname;

		ifstream file;
		file.open(fname.c_str());

		if(file.fail()){
			cerr<<"Cannot open the File"<<endl;
			file.clear();
		}
		else {
			cout<<"Open file success"<<endl;
			break;
		}

	}
}

int main() {
	open_file();
	return 0;

}
