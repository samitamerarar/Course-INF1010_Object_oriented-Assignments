#include "PouvoirSoporifique.h"
#include "EtatEndormi.h"

PouvoirSoporifique::PouvoirSoporifique(const std::string& nom,
	unsigned int nombreDeDegat, unsigned int energieNecessaire)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

PouvoirSoporifique::PouvoirSoporifique(const std::string& nom, unsigned int nombreDeDegat,
	unsigned int energieNecessaire, unsigned int duree)
	: Pouvoir(nom, nombreDeDegat, energieNecessaire), duree_(duree)
{
	type_ = TypeEtat::TypeEtat_endormi;
}

PouvoirSoporifique::~PouvoirSoporifique()
{
}

void PouvoirSoporifique::appliquerEffetOffensif(Creature& creatureEnnemie)
{
	creatureEnnemie.modifierEtat(new EtatEndormi("Endormi", duree_));
}

std::ostream & operator<<(std::ostream & o, const PouvoirSoporifique& pouvoir)
{
	return o << (Pouvoir)pouvoir //appel de l'operateur<< de la classe mère
		<< " il peut endormir la cible" << std::endl;
}