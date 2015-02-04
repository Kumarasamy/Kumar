#include<iostream>
#include<string>

using namespace std;
//enum color { Red,Green,Yellow,Cyan,Magenta,Blue,NOT_A_COLOR };
enum color { 
	#define DEFINE_COLOR(color) color ,
	#include "stringtocolor.h"
	#undef DEFINE_COLOR
	#define NOT_A_COLOR
};

#define ctos(Green) Green 

/*string ColorToString(string col) {
	switch(col) {
	#define DEFINE_COLOR(#color,color) case #color: return #color;
	#include "stringtocolor.h"
	#undef DEFINE_COLOR
	default:
		return NOT_A_COLOR;

	}
}*/

string ColorToString(color c) {

	switch(c ){
	#define DEFINE_COLOR(color) case color: return #color;
	#include "stringtocolor.h"
	#undef DEFINE_COLOR
	default:
		return "NOT_A_COLOR";	

	}
}

int main() {

 cout<<ColorToString(Green);

return 0;

}
