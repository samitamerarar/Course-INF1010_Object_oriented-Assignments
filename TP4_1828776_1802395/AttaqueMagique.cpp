#include "AttaqueMagique.h"

AttaqueMagique::AttaqueMagique(unsigned int duree): duree_(duree){}
AttaqueMagique::~AttaqueMagique(){}

void AttaqueMagique::modifierDuree(unsigned int duree)
{
	duree_ = duree;
}

unsigned int AttaqueMagique::obtenirDuree() const
{
	return duree_;
}

std::string AttaqueMagique::obtenirTypeAttaque() const
{
	return typeid(*this).name();	//retourne type de l'attaque magique
}

bool AttaqueMagique::estFini() const
{
	return true;
}

std::ostream& operator<<(std::ostream& o, AttaqueMagique* attaqueMagique)
{
	return o << attaqueMagique->obtenirDuree();		//affiche la durée de l'attaque magique
}