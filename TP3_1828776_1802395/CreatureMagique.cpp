#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie,
	unsigned int bonus)
	: Creature(nom, attaque, defense, pointDeVie, energie), bonus_(bonus)
{
}

CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique)
	: Creature(creatureMagique), bonus_(0)
{
}

void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature)
{
	Creature::attaquer(pouvoir, creature);

	if ((obtenirPointDeVieTotal() - obtenirPointDeVie()) >= bonus_) {
		modifierPointDeVie(obtenirPointDeVie() + bonus_);
	}
	else {
		modifierPointDeVie(obtenirPointDeVieTotal());
	}
}

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creature)
{
	*this = creature;
	return *this;
}