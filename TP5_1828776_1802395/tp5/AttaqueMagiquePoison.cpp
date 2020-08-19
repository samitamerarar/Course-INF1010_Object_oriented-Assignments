#include "AttaqueMagiquePoison.h"


AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(MIN_DUREE_POISON), generateurAleatoire_(FoncteurGenerateurNombresAlea(1, 6)) // � MODIFIER
{}

AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree), generateurAleatoire_(FoncteurGenerateurNombresAlea(1, 6)) // � MODIFIER
{}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{
}

//Appliquer des d�g�ts al�atoires � l'�nergie de la cr�ature adverse
void AttaqueMagiquePoison::appliquerAttaque(Creature & creature) //A modifier
{
	if (duree_ > 0 && creature.obtenirEnergie() >= 5)
	{
		unsigned int energie = creature.obtenirEnergie();
		if (generateurAleatoire_() == 1)	//si le nombre al�atoire g�n�r� = 1 (1 chance sur 6, d'o� l'intervalle [1,6]
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
