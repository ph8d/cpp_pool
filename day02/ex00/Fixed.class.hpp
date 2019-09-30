#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {

	private:
		int _value;
		static const int _bits;

	public:
		void setRawBits(int const raw);
		int getRawBits(void) const;
		Fixed & operator=(Fixed const & rhs);
		Fixed(const Fixed& toCopy);
		Fixed(void);
		~Fixed(void);

};

#endif