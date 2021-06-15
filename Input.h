#ifndef INPUT_H
#define INPUT_H
#include<iostream>
#include<string> 
using namespace std; 

class Input {
	public:

		string requestInput(string hint);
		
		char requestInputChar(string hint);

		void hint(string hint);
	protected:
};

#endif
