#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {

	private:
		int _value;
		static const int _bits;

	public:
		float toFloat(void) const;
		int toInt(void) const;
		void setRawBits(int const raw);
		int getRawBits(void) const;
		Fixed & operator=(Fixed const & rhs);
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& toCopy);
		Fixed(void);
		~Fixed(void);

};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif