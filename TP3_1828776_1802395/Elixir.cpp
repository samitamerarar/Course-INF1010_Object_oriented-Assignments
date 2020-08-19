#include "Elixir.h"

Elixir::Elixir() : PotionMagique()
{
}

Elixir::Elixir(const std::string & nom, int bonus) : PotionMagique(nom, bonus)
{
}

Elixir::~Elixir()
{
}

void Elixir::utiliserSur(Creature & creature) const
{
	ObjetMagique::utiliserSur(creature);
	PotionMagique::utiliserSur(creature);
}

std::ostream & operator<<(std::ostream & o, const Elixir & e)
{
	return o << "l'objet " << e.nom_ << " soigne de " << e.bonus_ * 2 <<
		" points de vie et fournit " << e.bonus_ << "point(s) d'énergie" << std::endl;
}
