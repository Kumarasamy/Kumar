#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>

using namespace std;

	typedef struct {
		int a;
		char c;
	}st ;
int main() {



	vector<st> v;
	st s;
	s.a = 10;
	s.c = 'c';
	v.push_back(s);
	v.push_back(s);

	//copy(v.begin(),v.end(),ostream_iterator<s>(cout));	
	for(auto it = v.begin(); it != v.end(); it++)
		cout<<*(it.a)<<*(it.c)<<endl;
	return 0;
}
