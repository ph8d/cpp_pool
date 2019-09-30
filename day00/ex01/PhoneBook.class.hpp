#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"

class PhoneBook {

private:
    Contact contacts[8];
    int last_contact_index;
	void display_message(std::string msg);
	int get_last_contact_index(void);
	std::string format_string_for_output(std::string str);

public:
	void init(void);
    void add_new_contact(void);
    void search(void);
	int display_contact_list(void);
	void display_contact_by_index(int index);
	std::string read_input(std::string msg);
	PhoneBook(void);
	~PhoneBook(void);

};

#endif