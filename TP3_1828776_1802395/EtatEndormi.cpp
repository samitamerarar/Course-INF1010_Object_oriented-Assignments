#include "EtatEndormi.h"

EtatEndormi::EtatEndormi(const std::string& nom) : EtatCreature(nom, 0)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const std::string& nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

EtatEndormi::~EtatEndormi()
{
}

void EtatEndormi::appliquerEtat(Creature& creature)
{
	if (duree_ > 0)
		duree_--;
}

bool EtatEndormi::peutAttaquer() const
{
	return false;
}

bool EtatEndormi::estFini() const
{
	return duree_ <= 0;
}

std::ostream & operator<<(std::ostream & o, const EtatEndormi & etat)
{
	return o << " etat " << etat.obtenirNom() << " :endormi durera " << etat.duree_ << std::endl;
}