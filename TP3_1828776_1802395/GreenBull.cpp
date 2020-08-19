#include "GreenBull.h"

GreenBull::GreenBull() : ObjetMagique()
{
}

GreenBull::GreenBull(const std::string & nom, int bonus): ObjetMagique(nom, bonus)
{
}

GreenBull::~GreenBull()
{
}

void GreenBull::utiliserSur(Creature & creature) const
{
	if ((creature.obtenirEnergieTotale() - creature.obtenirEnergie()) > bonus_) //bonus correspond a l'energie rendue
		creature.modifierEnergie(creature.obtenirEnergie() + bonus_);	
	else 
		creature.modifierEnergie(creature.obtenirEnergieTotale());
}

std::ostream & operator<<(std::ostream & o, const GreenBull & g)
{
	return o << "l'objet " << g.nom_ << " fournit " << g.bonus_ << " point(s) d'énergie" << std::endl;
}
