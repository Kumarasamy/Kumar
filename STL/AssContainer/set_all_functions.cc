#include<iostream>
#include<set>
#include<iterator>
#include<algorithm>

using namespace std ;

const int SIZE =  10;
void _set_all() {
	set<int> set_int ;
	for( int it = 0; it < SIZE ; it++)
		set_int.insert(it);
	set<int>set_int_next(set_int.begin() ,set_int.end());
	//set<int>set_int_next_one = set_int;
	set_int.erase(0);
	set<int>::iterator it_min = set_int.lower_bound(5);
	set<int>::iterator it_max = set_int.upper_bound(6);
	cout<<"Lower Bound "<<*it_min<<endl;
	cout<<"Upper Bound "<<*it_max<<endl;
	//cout<<set_int_next.find(0)<<endl;
	cout<<set_int_next.count(1)<<endl;

}

int main() {

	_set_all();
	return 0;
}
