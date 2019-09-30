#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed {

	private:
		int _value;
		static const int _bits;

	public:

		static Fixed & min(Fixed & fp1, Fixed & fp2);
		static const Fixed & min(Fixed const & fp1, Fixed const & fp2);
		static Fixed & max(Fixed & fp1, Fixed & fp2);
		static const Fixed & max(Fixed const & fp1, Fixed const & fp2);
	
		float toFloat(void) const;
		int toInt(void) const;
		void setRawBits(int const raw);
		int getRawBits(void) const;

		Fixed & operator=(Fixed const & rhs);
		Fixed operator+(Fixed const & rhs) const;
		Fixed operator-(Fixed const & rhs) const;
		Fixed operator*(Fixed const & rhs) const;
		Fixed operator/(Fixed const & rhs) const;

		Fixed & operator++(void);
		Fixed & operator++(int);
		Fixed & operator--(void);
		Fixed & operator--(int);

		bool operator>(Fixed const & rhs) const;
		bool operator<(Fixed const & rhs) const;
		bool operator>=(Fixed const & rhs) const;
		bool operator<=(Fixed const & rhs) const;
		bool operator==(Fixed const & rhs) const;
		bool operator!=(Fixed const & rhs) const;

		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& toCopy);
		Fixed(void);
		~Fixed(void);

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif