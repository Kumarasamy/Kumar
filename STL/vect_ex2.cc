#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

size_t Insert_Index(vector<int> &v,int to_insert) {

for(int i = 0;i<v.size();i++)
	if(to_insert < v[i])
		return i;

	return v.size();
}

int main() {

	vector<int> v(10);
	vector<int> s(10);
	generate(v.begin(),v.end(),rand);
	int pos = Insert_Index(v,10);
	v.insert(v.begin() + pos,10);
	copy(v.begin(),v.end(),ostream_iterator<int>(s));

	return 0;
}
