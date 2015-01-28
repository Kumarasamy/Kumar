#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<iterator>

using namespace std;

void file_read() {
	string str= "in";
	ifstream file("stl_read_file.cc");
	copy(istreambuf_iterator<char>(file),istreambuf_iterator<char>(),ostreambuf_iterator<char>(cout));
}

int main() {

	file_read();

return 0;

}

