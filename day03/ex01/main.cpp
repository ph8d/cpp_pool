#include <iostream>
#include "FragTrap.class.hpp"
#include "ScavTrap.class.hpp"

int main(void) {

	srand(time(NULL));

	FragTrap fragtrap = FragTrap("FragTrap");

	fragtrap.meleeAttack("bandit");

	fragtrap.takeDamage(80);
	fragtrap.rangeAttack("bandit");
	fragtrap.takeDamage(50);
	fragtrap.takeDamage(25);
	fragtrap.beRepaired(20);
	fragtrap.beRepaired(100);
	fragtrap.beRepaired(20);

	std::cout << std::endl;

	fragtrap.vaulthunter_dot_exe("bandit");
	fragtrap.vaulthunter_dot_exe("grandma");
	fragtrap.vaulthunter_dot_exe("zaz");
	fragtrap.vaulthunter_dot_exe("badass");
	fragtrap.vaulthunter_dot_exe("bandit");

	std::cout << std::endl;
	std::cout << std::endl;

	ScavTrap scavtrap = ScavTrap("ScavTrap");

	scavtrap.meleeAttack("bandit");

	scavtrap.takeDamage(80);
	scavtrap.rangeAttack("bandit");
	scavtrap.takeDamage(50);
	scavtrap.takeDamage(25);
	scavtrap.beRepaired(20);
	scavtrap.beRepaired(100);
	scavtrap.beRepaired(20);

	std::cout << std::endl;

	scavtrap.challengeNewcomer();
	scavtrap.challengeNewcomer();
	scavtrap.challengeNewcomer();
	scavtrap.challengeNewcomer();


	ScavTrap scavCopy = ScavTrap(scavtrap);

	return 0;
}