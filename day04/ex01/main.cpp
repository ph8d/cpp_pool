#include <iostream>

#include "Character.class.hpp"
#include "RadScorpion.class.hpp"
#include "SuperMutant.class.hpp"
#include "PlasmaRifle.class.hpp"
#include "PowerFist.class.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	Enemy* sm = new SuperMutant();
	std::cout << sm->getType() + " has " << sm->getHP() << "HP" << std::endl;
	zaz->equip(pf);
	std::cout << *zaz;
	zaz->attack(sm);
	std::cout << *zaz;
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->attack(sm);
	std::cout << *zaz;	
	zaz->attack(sm);
	std::cout << sm->getType() + " has " << sm->getHP() << "HP" << std::endl;
	std::cout << *zaz;
	zaz->attack(sm);
	zaz->recoverAP();
	zaz->recoverAP();
	std::cout << *zaz;
	return 0;
}