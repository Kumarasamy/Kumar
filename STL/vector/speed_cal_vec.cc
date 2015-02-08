#include<iostream>
#include<vector>
#include<iterator>
#include<string>
#include<ctime>
#include<fstream>

#define MAX_LINE 250
using namespace std;

enum ins_type {
	Normal,
	Reserve
};

void insert_vect(ins_type type,ifstream& input) {
	vector<string> vect_res;
	vector<string> vect_nor;
	time_t t_res_start ;
	time_t t_res_stop ;
	string line;
	t_res_start = clock() / CLOCKS_PER_SEC;
	if( type == Reserve )
	{
		cout<<"Vector Reserve "<<endl;
		vect_res.reserve(MAX_LINE);
		while(getline(input,line))
		{
			cout<<line<<endl;
			vect_res.push_back(line);	
		}
	}

	if(type == Normal ) {
        cout<<"Vector Normal"<<endl;
		while(getline(input,line))
		{
			cout<<line<<endl;
			vect_nor.push_back(line);	
		}
	}

        t_res_stop = double(clock()) / CLOCKS_PER_SEC;	
		
	cout<<"Time in Sec"<< t_res_stop <<endl;
}

int main() {
	ifstream input;
	string file;
	cin>>file;
	input.open(file.c_str(),ifstream::binary);
	cout<<file<<endl;
	if(!input.is_open()){
		cerr<<"Failed to open file"<<file<<endl;
		return 0;
	}
		
	insert_vect(Reserve,input);
	int length = input.tellg();
	cout<<length<<endl;
	input.seekg(0,input.beg);
	insert_vect(Normal,input);

	return 0;	
}
