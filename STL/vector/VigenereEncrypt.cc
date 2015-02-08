#include<iostream>
#include<vector>

using namespace std;

string Encrypt(string input , vector<int> key ) {
	string en_string;
	cout<<input<<endl;
	int length = 0;
	int key_iter = 0;
	while( input[length] != '\0' && key_iter <key.size()) {
		en_string[length] = input[length] + key[key_iter]; 
		length++;
		key_iter++;
		if( key_iter == key.size() )
			key_iter = 0;
	}
	en_string[length] = '\0';
	cout<<en_string<<endl;
	return en_string;
}

void Decrypt(string en_input,vector<int> key ){
	string de_string ;
	int length = 0;
	int key_iter = 0;
	while( en_input[length] != '\0' && key_iter < key.size()) {
		de_string[length] = en_input[length] - key[key_iter]; 
		length++;
		key_iter++;
		if( key_iter == key.size())
			key_iter = 0;
	}
	de_string[length] = '\0';
	cout<<de_string<<endl;
}

int main() {
	vector<int> key;
	string de_string;
	const int SIZE = 3;
	for(int iter = 0;iter < SIZE; iter++)
		key.push_back(iter);
	de_string = Encrypt("Kumarasamy" ,key);
	cout<<de_string<<endl;
	Decrypt(de_string,key);
	return 0;
}
