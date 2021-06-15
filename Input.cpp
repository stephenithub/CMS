#include "Input.h"
#include<iostream>
#include<string>
using namespace std;

string  Input:: requestInput(string hint) {
	cout << hint ;
	string str_input;
	cin >> str_input;
	return str_input;
};

void  Input::	hint(string hint) {
	cout << hint;
}

char Input:: requestInputChar(string hint) {
	cout << hint ;
	char str_input;
	cin >> str_input;
	return str_input;
};




