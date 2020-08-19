#include "AttaqueMagiquePoison.h"

AttaqueMagiquePoison::AttaqueMagiquePoison(): AttaqueMagique(2){}
AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree): AttaqueMagique(duree){}
AttaqueMagiquePoison::~AttaqueMagiquePoison(){}

void AttaqueMagiquePoison::appliquerAttaque(Creature& creature)
{
	if (rand() % 3 == 0)	//	1/3 chance de réduire l'énergie de la créature ennemie de 2 points
	{
		if (creature.obtenirEnergie() >= 5 && obtenirDuree() > 0)
			creature.modifierEnergie(creature.obtenirEnergie() - 2);
	}
}

bool AttaqueMagiquePoison::estFini() const
{
	if (obtenirDuree() == 0)
		return true;
	return false;
}