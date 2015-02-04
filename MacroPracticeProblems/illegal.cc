#include<iostream>

using namespace std;
bool IsPositive(int x) {
	return x<0;
}

int main() {

#if IsPositive 
	#define result trure
#else 
       #define result false
#endif

return  0;
}
