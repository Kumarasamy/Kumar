#include<iostream>

#define MAX(a,b) (((a)>(b))?(a):(b))

inline int max(int one,int two) {

return one>two?one:two;
}

using namespace std;

int main() {

int x = MAX(100,200);
x=max(100,200);
cout<<x<<endl;
return 0;

}
