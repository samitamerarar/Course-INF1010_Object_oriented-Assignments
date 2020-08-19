/*
Fichier: ObjetMagique.cpp
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Les objets magiques sont utilisés sur des creatures pour augmenter leurs attributs.
*/

#include "ObjetMagique.h"
#include <iostream>

ObjetMagique::ObjetMagique()
{
}

ObjetMagique::ObjetMagique(const std::string & nom, int bonus):
	nom_(nom), bonus_(bonus)
{
}


ObjetMagique::~ObjetMagique()
{
}

std::string ObjetMagique::obtenirNom() const
{
	return nom_;
}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;
}

std::ostream& operator<<(std::ostream& o, const ObjetMagique& om)
{
	return o << "l'objet " << om.nom_ << "fournit un bonus de " << om.bonus_ << std::endl;
}