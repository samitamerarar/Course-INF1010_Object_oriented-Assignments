#include "OutilScientifique.h"

OutilScientifique::OutilScientifique(const std::string & nom, const std::string & description) :
    nom_(nom), description_(description)
{
}

OutilScientifique::~OutilScientifique()
{
}

std::string OutilScientifique::obtenirNom() const
{
    return nom_;
}

std::string OutilScientifique::obtenirDesciption() const
{
    return description_;
}

void OutilScientifique::utiliser(Creature & creature)
{
    //methode de classe de base
    //ne fait rien
}

std::ostream & operator<<(std::ostream & os, const OutilScientifique & outil)
{
	return os << "l'outil " << outil.nom_ << " Permet de " << outil.description_;
}
