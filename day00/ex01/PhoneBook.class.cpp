#include "PhoneBook.class.hpp"

void PhoneBook::display_message(std::string msg) {
    if (!msg.empty())
        std::cout << std::endl << "[phonebook]: " << msg << std::endl;
}

std::string PhoneBook::read_input(std::string msg) {
    std::string user_input;

    std::cout << msg << " > ";
    getline(std::cin, user_input);
    if (std::cin.eof())
        exit(0);
    return user_input;
}

int PhoneBook::get_last_contact_index(void) {
    return this->last_contact_index;
}

std::string PhoneBook::format_string_for_output(std::string str) {
    std::string result;

    if (str.length() >= 10)
        result = str.substr(0, 9) += "."; 
    else if (str.length() < 10) {
        result = str;
        result = std::string(10 - result.length(), ' ') + result;
    }
    return result;
}

int PhoneBook::display_contact_list(void) {
    int displayed_contacts = 0;

    this->display_message("List of contacts:");
    std::cout << std::endl;
    for (int i = 0; i != 8; i++) {
        if (this->contacts[i].is_empty == false) {
            std::string index = this->format_string_for_output(std::to_string(i));
            std::string first_name = this->format_string_for_output(this->contacts[i].first_name);
            std::string last_name = this->format_string_for_output(this->contacts[i].last_name);
            std::string nickname = this->format_string_for_output(this->contacts[i].nickname);

            std::cout << "|" + index + "|" + first_name + "|" + last_name + "|" + nickname + "|" << std::endl;
            displayed_contacts++;
        }
    }
    return displayed_contacts;
}

void PhoneBook::display_contact_by_index(int index) {
    std::cout << "First name: " << this->contacts[index].first_name << std::endl;
    std::cout << "Last name: " << this->contacts[index].last_name << std::endl;
    std::cout << "Nickname: " << this->contacts[index].nickname << std::endl;
    std::cout << "Login: " << this->contacts[index].login << std::endl;
    std::cout << "Postal adress: " << this->contacts[index].postal_adress << std::endl;
    std::cout << "Email: " << this->contacts[index].email << std::endl;
    std::cout << "Phone number: " << this->contacts[index].phone_number << std::endl;
    std::cout << "Birthday date: " << this->contacts[index].birthday_date << std::endl;
    std::cout << "Favorite meal: " << this->contacts[index].favorite_meal << std::endl;
    std::cout << "Underwear color: " << this->contacts[index].underwear_color << std::endl;
    std::cout << "Darkest secret: " << this->contacts[index].darkest_secret << std::endl;
}

void PhoneBook::add_new_contact(void) {    
    std::string value;
    int last_contact_index = this->last_contact_index;

    if (last_contact_index == 0 && this->contacts[0].is_empty == false) {
        this->display_message("Phonebook is full, adding a new contact will override existing contacts. Continue? [y/n]");
        do {
            value = this->read_input("");
            if (value == "n" || value == "N")
                return;
            else if (value != "y" && value != "Y")
                this->display_message("Please, enter [y] to continue or [n] to return");
        } while (value != "y" && value != "Y");
    }

    this->display_message("Adding new contact:");

    value = this->read_input("Enter first name");
    this->contacts[last_contact_index].first_name = value;
    value = this->read_input("Enter last name");
    this->contacts[last_contact_index].last_name = value;
    value = this->read_input("Enter nickname");
    this->contacts[last_contact_index].nickname = value;
    value = this->read_input("Enter login");
    this->contacts[last_contact_index].login = value;
    value = this->read_input("Enter postal adress");
    this->contacts[last_contact_index].postal_adress = value;
    value = this->read_input("Enter email");
    this->contacts[last_contact_index].email = value;
    value = this->read_input("Enter phone number");
    this->contacts[last_contact_index].phone_number = value;
    value = this->read_input("Enter birthday date");
    this->contacts[last_contact_index].birthday_date = value;
    value = this->read_input("Enter favorite meal");
    this->contacts[last_contact_index].favorite_meal = value;
    value = this->read_input("Enter underwear color");
    this->contacts[last_contact_index].underwear_color = value;
    value = this->read_input("Enter darkest secret");
    this->contacts[last_contact_index].darkest_secret = value;

    this->contacts[last_contact_index].is_empty = false;
    this->display_message("New contact was successfully added to the phonebook!");

    last_contact_index = (last_contact_index + 1) % 8;
    this->last_contact_index = last_contact_index;
}

void PhoneBook::search(void) {
    int displayed_contacts = this->display_contact_list();
    if (displayed_contacts != 0) {
        int index;
        std::cout << std::endl;
        std::string input = this->read_input("Enter contact index");
        if (input.length() == 1 && (input.at(0) >= '0' && input.at(0) <= '8')) {
            index = atoi(input.data());
            this->display_contact_by_index(index);
        }
    }
}

PhoneBook::PhoneBook(void) {
    this->last_contact_index = 0;
    return;
}

PhoneBook::~PhoneBook(void) {
    return;
}