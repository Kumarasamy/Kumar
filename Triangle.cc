/* Triangle using setw and setfill manipulators */

#include<iostream>
#include<iomanip>

using namespace std;

void Print_Triangle(int hieght,char ch) {
	
	for(int i=0;i<hieght;i++)
	{

		for(int j=0; j<=hieght-i;j++)
		{
			cout<<setfill(' ')<<setw(10);
		}

		for( int k =0;k< 2*i-1;k++)
		{

			cout<<ch;

		}
		
		cout<<endl;
	}
	
}

int main(){
	int hi;
	char ch;
	cin>>hi>>ch;
	Print_Triangle(hi,ch);	
	return 0;
}
