#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(MIN_DUREE_CONFUSION), generateurAleatoire_(FoncteurGenerateurNombresAlea(1, 6)) // À MODIFIER
{}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) : AttaqueMagique(duree), generateurAleatoire_(FoncteurGenerateurNombresAlea(1, 6)) // À MODIFIER
{}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

//Appliquer des dégâts aléatoires aux points de vie de la créature adverse
void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) //A modifier
{
	if (duree_ > 0 && creature.obtenirPointDeVie() >= 5)
	{
		unsigned int pointDeVie = creature.obtenirPointDeVie();
		if (generateurAleatoire_() == 1)	//si le nombre aléatoire généré = 1 (1 chance sur 6, d'où l'intervalle [1,6]
		{
			creature.modifierPointDeVie(pointDeVie - 2);
		}
		duree_--;
	}
}

bool AttaqueMagiqueConfusion::estFini() const
{
	return (duree_ <= 0);
}

std::string AttaqueMagiqueConfusion::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}