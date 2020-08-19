#include "AttaqueMagiquePoison.h"


AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(MIN_DUREE_POISON), generateurAleatoire_(FoncteurGenerateurNombresAlea(1, 6)) // À MODIFIER
{}

AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree), generateurAleatoire_(FoncteurGenerateurNombresAlea(1, 6)) // À MODIFIER
{}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{
}

//Appliquer des dégâts aléatoires à l'énergie de la créature adverse
void AttaqueMagiquePoison::appliquerAttaque(Creature & creature) //A modifier
{
	if (duree_ > 0 && creature.obtenirEnergie() >= 5)
	{
		unsigned int energie = creature.obtenirEnergie();
		if (generateurAleatoire_() == 1)	//si le nombre aléatoire généré = 1 (1 chance sur 6, d'où l'intervalle [1,6]
		{
			creature.modifierEnergie(energie - 2);
		}
		duree_--;
	}
}

bool AttaqueMagiquePoison::estFini() const
{
	return (duree_ <= 0);
}

std::string AttaqueMagiquePoison::obtenirTypeAttaque() const
{
	return (typeid(*this).name());
}
