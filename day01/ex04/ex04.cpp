#include <iostream>

int main(void) {

	std::string s = "HI THIS IS BRAIN";

	std::string* sPtr = &s;
	std::string& sRef = s;

	std::cout << *sPtr << std::endl << sRef << std::endl;

	return 0;
}