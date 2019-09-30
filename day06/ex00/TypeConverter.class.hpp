#ifndef TYPECONVERTER_CLASS_HPP
# define TYPECONVERTER_CLASS_HPP

# include <iostream>
# include "Literal.class.hpp"

class TypeConverter {

	Literal & _literal;
	void _printChar(void) const;
	void _printInt(void) const;
	void _printFloat(void) const;
	void _printDouble(void) const;

public:
	void execute(void);

	TypeConverter & operator=(TypeConverter const & rhs);

	TypeConverter(Literal & literal);
	TypeConverter(const TypeConverter & toCopy);
	~TypeConverter(void);

};

#endif
