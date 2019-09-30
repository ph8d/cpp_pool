
#include <cmath>
#include <iostream>

#include "TypeConverter.class.hpp"
#include "Literal.class.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return 0;
	}
	Literal literal = Literal(argv[1]);
	TypeConverter converter = TypeConverter(literal);

	converter.execute();

	return 0;
}
