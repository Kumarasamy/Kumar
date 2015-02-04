#include<iostream>
#include<vector>
#include<iterator>
#include<fstream>
#include<algorithm>

using namespace std;

vector<string> Read_Line_File(ifstream& input) {
	string line;	
	vector<string> v_str;
	while(getline(input,line)) {
	v_str.push_back(line);
	}

return v_str;
}


int main() {
	vector<string> it;
	string file;
	ifstream input;
	cout<<"Enter the File name:";
	cin>>file;
	input.open(file.c_str());	
	it = Read_Line_File(input);
	sort(it.begin(),it.end(),less<string>());
	for(auto it_str = it.begin(); it_str != it.end(); it_str++)
		cout<<*it_str<<endl;
	return 0;
}
