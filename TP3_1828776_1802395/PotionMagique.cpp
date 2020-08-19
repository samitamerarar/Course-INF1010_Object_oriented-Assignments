#include "PotionMagique.h"

PotionMagique::PotionMagique(): ObjetMagique()
{
}

PotionMagique::PotionMagique(const std::string& nom, int bonus): ObjetMagique(nom, bonus)
{
}

PotionMagique::~PotionMagique()
{
}

void PotionMagique::utiliserSur(Creature& creature) const
{
	if ((creature.obtenirPointDeVieTotal() - creature.obtenirPointDeVie()) >= bonus_) //bonus correspond aux points de vie rendus
		creature.modifierPointDeVie(creature.obtenirPointDeVie() + bonus_);
	else
		creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
}

std::ostream & operator<<(std::ostream & o, const PotionMagique & p)
{
	return o << "l'objet " << p.nom_ << " soigne de " << p.bonus_ << " points de vie" << std::endl;
}
