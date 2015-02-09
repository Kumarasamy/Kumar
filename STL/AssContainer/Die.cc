#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
enum type {
	vect_t,
	set_t
};

int DieRoll() {
	return (rand() % 6) + 1;
}
const size_t kNumIterations = 10000;

size_t RunProcess(type t){

	if(t == vect_t ) {
	vector<int> generated;
	cout<<generated.size()<<endl;
	
	while(true) {
		int nextValue = DieRoll();
		cout<<nextValue<<endl;
		
		for(size_t k = 0; k < generated.size(); k++ )
			if(generated[k] == nextValue )
				return generated.size() + 1;
		generated.push_back(nextValue);
	}
	
	}

	if(t == set_t )
	{
		set<int> generat;
		while(true) {
	        int nextval = DieRoll();
		if(generat.count(nextval)) return generat.size() + 1;		
		generat.insert(nextval);
		
		}

	}
}



int main() {
	srand(static_cast<unsigned> (time(NULL)));
	size_t  total = 0;
	int getval = RunProcess(vect_t);	
		cout<<getval<<endl;
	getval = RunProcess(set_t);	
		cout<<getval<<endl;

return 0;
}
