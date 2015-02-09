#include<iostream>
#include<set>
#include<algorithm>
#include<iterator>

using namespace std;

const int SIZE = 10 ;
void insert_print_set() {
	set<int> randomnumbers;
	for( size_t iter = 0; iter < SIZE ; iter++)
		randomnumbers.insert(rand());
	for(set<int>:: iterator it = randomnumbers.begin() ; it != randomnumbers.end() ; it++)
		cout<<*it<<endl;	
}

int main() {
	srand(static_cast<unsigned>(time(NULL)));
	insert_print_set();
	return 0;
}
