#include "EtatCreature.h"

EtatCreature::EtatCreature(const std::string & nom) : nom_(nom), duree_(0), type_(TypeEtat::TypeEtat_normal)
{
}

EtatCreature::EtatCreature(const std::string & nom, unsigned int duree) : nom_(nom), duree_(duree), type_(TypeEtat::TypeEtat_normal)
{
}

EtatCreature::~EtatCreature()
{
}

void EtatCreature::appliquerEtat(Creature & creature)
{
}

bool EtatCreature::peutAttaquer() const
{
	return true;
}

bool EtatCreature::estFini() const
{
    return false;
}

std::string EtatCreature::obtenirNom() const
{
    return nom_;
}

TypeEtat EtatCreature::obtenirType() const
{
    return type_;
}

std::ostream & operator<<(std::ostream & o, const EtatCreature & etatCreature)
{
    o << "etat" << etatCreature.nom_ << std::endl;

    return o;
}
