#include <iostream>
#include "info.h"
#include "menu.h"
#include "Operator.h"
#include <vector>

#include "fileHelp.h"

int main(int argc, char** argv) {
//	std::cout << "Hello world!\n";

	Operator operator1;

	Menu menu;
	menu.interface();
	
	operator1.choose();

	return 0;
}

