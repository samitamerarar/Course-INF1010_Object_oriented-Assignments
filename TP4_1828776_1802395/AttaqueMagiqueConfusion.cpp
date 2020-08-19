#include "AttaqueMagiqueConfusion.h"

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() : AttaqueMagique(2) {}
AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) : AttaqueMagique(duree) {}
AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion() {}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature& creature)
{
	if (rand() % 3 == 0)	//	1/3 chance de r�duire les points de vie de la cr�ature ennemie de 2 points
	{
		if (creature.obtenirPointDeVie() >= 5 && obtenirDuree() > 0)
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 2);
	}
}

bool AttaqueMagiqueConfusion::estFini() const
{
	if (obtenirDuree() == 0)
		return true;
	return false;
}