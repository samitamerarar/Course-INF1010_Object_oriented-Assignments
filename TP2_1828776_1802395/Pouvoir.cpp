/*
Fichier: Pouvoir.cpp
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Les pouvoirs appartiennent aux créatures et celles-ci peuvent s'en servir pour attaquer
*/

#include "Pouvoir.h"
#include <iostream>


Pouvoir::Pouvoir()
	:nom_(""), nombreDeDegat_(0), energieNecessaire_(0)
{
}

Pouvoir::Pouvoir(const Pouvoir& pouvoir)
	:nom_(pouvoir.nom_), nombreDeDegat_(pouvoir.nombreDeDegat_),
	energieNecessaire_(pouvoir.energieNecessaire_)
{
}

Pouvoir::Pouvoir(const std::string& nom, 
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}

Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

std::string Pouvoir::obtenirNom() const
{
	return nom_;
}

unsigned int Pouvoir::obtenirNombreDeDegat() const
{
	return nombreDeDegat_;
}

void Pouvoir::modifierNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::modifierEnergieNecessarie(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

Pouvoir& Pouvoir::operator=(const Pouvoir& pouvoir)
{
	nom_ = pouvoir.nom_;
	nombreDeDegat_ = pouvoir.nombreDeDegat_;
	energieNecessaire_ = pouvoir.energieNecessaire_;

	return *this;
}

bool Pouvoir::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

std::ostream& operator<<(std::ostream& os, const Pouvoir& pouvoir)
{
	return os << pouvoir.nom_ << " possede un nombre de degat de " << pouvoir.nombreDeDegat_ <<
		" et une energie necessaire de " << pouvoir.energieNecessaire_ << std::endl << std::endl;
}