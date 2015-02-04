#include<iostream>

using namespace std;

 
enum Color { Red,Green,Blue,Cyan,Magenta,Yellow,NOT_A_COLOR };


Color GetOppsiteColor(Color c) {
	switch(c) {
	#define DEFINE_COLOR(color,opposite) case color:return opposite;
	#include "color.h"
	#undef DEFINE_COLOR
	default:
		return c;
	}
}

int main() {

	Color c = GetOppsiteColor(Red);
	return 0;
}
