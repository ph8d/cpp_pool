#include <iostream>

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

int main(void) {
	std::string command;
	PhoneBook phonebook;

	do {
		command = phonebook.read_input("");
		if (command == "ADD")
			phonebook.add_new_contact();
		else if (command == "SEARCH")
			phonebook.search();
	} while (command != "EXIT");
	return 0;
}