/*
Fichier: Pouvoir.cpp
Auteur(s): Tamer Arar, Guy-Frank Essome Penda
Date de creation: 14 septembre 2016
Date de modification: 26 septembre 2016
Description: Une classe des pouvoirs des créatures qui demandent une certaine quantité d'energie pour infliger des dégâts sur une autre créature.
*/

#include "Pouvoir.h"
#include <iostream>
using namespace std;

Pouvoir::Pouvoir()
	:nom_(""), nombreDeDegats_(0), energieNecessaire_(0)
{}

Pouvoir::Pouvoir(const std::string& nom, int nbDegats, int energieNecessaire)
	:nom_(nom), nombreDeDegats_(nbDegats), energieNecessaire_(energieNecessaire)
{}

Pouvoir::~Pouvoir() {}

std::string Pouvoir::obtenirNom() const
{
	return nom_;
}

void Pouvoir::setNom(const std::string& nom)
{
	nom_ = nom;
}

int Pouvoir::obtenirNombreDeDegats() const
{
	return nombreDeDegats_;
}

void Pouvoir::setNombreDeDegats(const int nombreDeDegats)
{
	nombreDeDegats_ = nombreDeDegats;
}

int Pouvoir::obtenirEnergieNecessaire() const
{
	return energieNecessaire_;
}

void Pouvoir::setEnergieNecessaire(const int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::description()
{
	cout << "Son pouvoir est : " << nom_ << " necessite " << energieNecessaire_ << " d'energie et inflige " << nombreDeDegats_ << " degats" << endl << endl;
}
