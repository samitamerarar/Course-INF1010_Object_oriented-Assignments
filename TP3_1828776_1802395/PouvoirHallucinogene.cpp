#include "PouvoirHallucinogene.h"
#include "EtatConfus.h"

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
	type_ = TypeEtat::TypeEtat_confus;
}

PouvoirHallucinogene::PouvoirHallucinogene(const std::string& nom, unsigned int nombreDeDegat,
	unsigned int energieNecessaire, unsigned int duree)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	type_ = TypeEtat::TypeEtat_confus;
}

PouvoirHallucinogene::~PouvoirHallucinogene()
{
}

void PouvoirHallucinogene::appliquerEffetOffensif(Creature& creatureEnnemie)
{
	creatureEnnemie.modifierEtat(new EtatConfus("Confus", duree_));
}

std::ostream & operator<<(std::ostream & o, const PouvoirHallucinogene& pouvoir)
{
	return o << (Pouvoir)pouvoir //appel de l'operateur<< de la classe mère
		<< " il peut rendre confus la cible" << std::endl;
}