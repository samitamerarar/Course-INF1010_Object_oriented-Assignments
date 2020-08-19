/*
Fichier: ObjetMagique.cpp
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 20 septembre 2016
Description: les objets magiques sont utilisables sur des créatures du monde de Polyland.
*/

#include "ObjetMagique.h"
#include <iostream>
using namespace std;

ObjetMagique::ObjetMagique()
	:nom_(""), bonus_(0)
{
}

ObjetMagique::ObjetMagique(const string& nom, int bonus)
	:nom_(nom), bonus_(bonus)
{
}

ObjetMagique::~ObjetMagique(){}

std::string ObjetMagique::obtenirNom() const
{
	return nom_;
}

void ObjetMagique::setNom(const std::string& nom)
{
	nom_ = nom;
}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::setBonus(const int bonus)
{
	bonus_ = bonus;
}

void ObjetMagique::affichage()
{
	std::cout << "l'objet " << obtenirNom() << " fournit un bonus de " << obtenirBonus() << endl;
}