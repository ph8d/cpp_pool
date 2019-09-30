#include "ShrubberyCreationForm.class.hpp"
#include <fstream>

void ShrubberyCreationForm::_execute() const {
	std::string tree[] = {
		"   oxoxoo    ooxoo  ",
		" ooxoxo oo  oxoxooo ",
		"oooo xxoxoo ooo ooox",
		"oxo o oxoxo  xoxxoxo",
		" oxo xooxoooo o ooo ",
		"   ooo\\oo\\  /o/o    ",
		"       \\  \\/ /      ",
		"        |   /       ",
		"        |  |        ",
		"        | D|        ",
		"        |  |        ",
		"        |  |        ",
		" ______/____\\____   "
	};

	std::string file_name = this->getTarget() + "_shrubbery";

	std::ofstream target_file(file_name);
	for (int i = 0; i != 13; i++) {
		target_file << tree[i] << std::endl;
	}
	target_file.close();
} 

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	(void)rhs;
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm", 145, 137, "") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137, target) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & toCopy):
Form(toCopy.getName(), toCopy.getGradeToSign(), toCopy.getGradeToExecute(), toCopy.getTarget()) { }