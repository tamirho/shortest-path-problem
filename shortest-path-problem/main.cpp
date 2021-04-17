#include <iostream>
#include <stdlib.h>
#include "Program.h"

int main(int argc, char* argv[]) {

	try {
		if (argc < 3) {
			throw std::invalid_argument("Error with main program parameters");
		}
		Program::Run(argv[1], argv[2]);
	}
	catch (std::exception& error) {
		std::cout << error.what() << std::endl;
		exit(1);
	}
	
	return 0;
}
