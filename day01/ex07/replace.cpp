
#include <iostream>
#include <fstream>

bool validate(std::string s1, std::string s2) {
	if (!s1.compare(s2) || s1.empty()) {
		return false;
	}
	return true;
}

std::string get_file_name(std::string og_file_name) {
	std::string new_file_name = og_file_name;
	for(size_t i = 0; i < new_file_name.length(); i++) {
		new_file_name[i] = toupper(new_file_name[i]);
	}
	return new_file_name + ".replace";
}

std::string find_and_replace(std::string str, std::string toFind, std::string toReplace) {
	std::string result = str;
	std::string tmp;

	std::size_t pos = result.find(toFind);
	
	while (pos != std::string::npos) {
		result.replace(pos, toFind.length(), toReplace);
		tmp = result.substr(pos + toReplace.length());

		// Я дико извиняюсь
		pos = tmp.find(toFind) == std::string::npos ? std::string::npos : pos + toReplace.length() + tmp.find(toFind);
	}

	return result;
}

int main(int argc, char **argv) {

	if (argc < 4) {
		std::cout << "Error, not enough arguments" << std::endl;
	} else if (!validate(argv[2], argv[3])) {
		std::cout << "Error, invalid arguments" << std::endl;
	} else {
		std::ifstream source_file(argv[1]);
		if (source_file.is_open()) {
			std::string file_name = get_file_name(argv[1]);
			std::ofstream out_file(file_name);
			std::string buffer;
			while(getline(source_file, buffer)) {
				out_file << find_and_replace(buffer, argv[2], argv[3]) << std::endl;
			}
			out_file.close();
		} else {
			std::cout << "Error, file is invalid" << std::endl;
		}
	}
	return 0;
}