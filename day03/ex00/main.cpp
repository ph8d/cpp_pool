#include <iostream>
#include "FragTrap.class.hpp"

int main(void) {

	srand(time(NULL));

	FragTrap claptrap = FragTrap("Claptrap");

	claptrap.meleeAttack("bandit");

	claptrap.takeDamage(80);
	claptrap.rangeAttack("bandit");
	claptrap.takeDamage(50);
	claptrap.takeDamage(25);
	claptrap.beRepaired(20);
	claptrap.beRepaired(100);
	claptrap.beRepaired(20);

	std::cout << std::endl;

	claptrap.vaulthunter_dot_exe("bandit");
	claptrap.vaulthunter_dot_exe("grandma");
	claptrap.vaulthunter_dot_exe("zaz");
	claptrap.vaulthunter_dot_exe("badass");
	claptrap.vaulthunter_dot_exe("bandit");

	std::cout << std::endl;

	FragTrap clapcopy = FragTrap(claptrap);

	FragTrap onemore = FragTrap("Trapclap");

	clapcopy = onemore;

	return 0;
}