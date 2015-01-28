#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

void Gene_rand(int input) {

vector <int>v;
v.resize(input);
generate(v.begin(),v.end(),rand);
sort(v.begin(),v.end());
copy(v.begin(),v.end(),ostream_iterator<int>(cout,"\n"));

}

int main() {
int input;
cin>>input;
Gene_rand(input);

return 0;
}
