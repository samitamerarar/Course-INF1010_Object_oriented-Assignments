#include "EtatEmpoisonne.h"

EtatEmpoisonne::EtatEmpoisonne(const std::string& nom) : EtatCreature(nom, 0)
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}

EtatEmpoisonne::EtatEmpoisonne(const std::string& nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat::TypeEtat_empoisonne;
}

EtatEmpoisonne::~EtatEmpoisonne()
{
}

void EtatEmpoisonne::appliquerEtat(Creature& creature)
{
	creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);
	duree_--;
}

bool EtatEmpoisonne::estFini() const
{
	return duree_ <= 0;
}

std::ostream & operator<<(std::ostream & o, const EtatEmpoisonne & etat)
{
	return o << " etat " << etat.obtenirNom() << " :Empoisonne durera " << etat.duree_ << std::endl;
}