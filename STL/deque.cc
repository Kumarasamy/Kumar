#include<iostream>
#include<deque>
#include<iterator>
#include<algorithm>

using namespace std;


class CircularBuff{

	private:
		int cursor;
		deque<int> q_int;
		
	public:
		CircularBuff(int size) {
			q_int.resize(size);
			cursor = 0;
		}
		int getCursor() {
			return cursor;	
		}
		
		void ReadCursor() {
			cout<<q_int[cursor]<<endl;
		}

		void WriteCursor(int value) {
			q_int.insert(cursor,value);
		}

		void ClockRotateCursor() {
			cursor = 	
		}

		
};

int main() {
	CircularBuff buff(5);

	return 0;
}
