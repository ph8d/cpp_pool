#include <iostream>

void megaphone(std::string s) {
	for(size_t i = 0; i < s.length(); i++) {
		s[i] = toupper(s[i]);
	}
	std::cout << s;
}

int		main(int argc, char **argv) {

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		for(int i = 1; i < argc; i++) {
			megaphone(argv[i]);
		}
	}
	std::cout << std::endl;
	return (0);
}