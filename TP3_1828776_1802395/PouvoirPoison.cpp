#include "PouvoirPoison.h"
#include "EtatEmpoisonne.h"

PouvoirPoison::PouvoirPoison(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}

PouvoirPoison::PouvoirPoison(const std::string& nom, unsigned int nombreDeDegat,
	unsigned int energieNecessaire, unsigned int duree)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}

PouvoirPoison::~PouvoirPoison()
{
}

void PouvoirPoison::appliquerEffetOffensif(Creature& creatureEnnemie)
{
	creatureEnnemie.modifierEtat(new EtatEmpoisonne("Empoisonne", duree_));
}

std::ostream & operator<<(std::ostream & o, const PouvoirPoison& pouvoir)
{
	return o << (Pouvoir)pouvoir //appel de l'operateur<< de la classe mère
		<< " il peut empoisonner la cible" << std::endl;
}