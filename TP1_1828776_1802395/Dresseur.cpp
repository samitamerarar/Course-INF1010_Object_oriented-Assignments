/*
Fichier: Dresseur.cpp
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 31 aout 2016
Date de modification: 4 septembre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/

#include "Dresseur.h"
#include <iostream>
using namespace std;

Dresseur::Dresseur()
	:nom_(""), nombreCreatures_(0), nombreCreaturesMax_(MAX_NOMBRE_CREATURES)
{
	//Initialisation de tableau dynamique
	creatures_ = new Creature*[nombreCreaturesMax_];
	for (size_t i = 0; i < nombreCreaturesMax_; i++)
		creatures_[i] = nullptr;
}

Dresseur::Dresseur(const std::string& nom)
	:nom_(nom), nombreCreatures_(0), nombreCreaturesMax_(MAX_NOMBRE_CREATURES)
{
	//Initialisation de tableau dynamique
	creatures_ = new Creature*[nombreCreaturesMax_];
	for (size_t i = 0; i < nombreCreaturesMax_; i++)
		creatures_[i] = nullptr;
}

Dresseur::~Dresseur()
{
	//Désallocation de tableau dynamique
	for (size_t i = 0; i < nombreCreatures_; i++)
		delete creatures_[i];

	delete[] creatures_;
}

std::string Dresseur::obtenirNom() const
{
	return nom_;
}

void Dresseur::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

ObjetMagique Dresseur::obtenirObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::modifierObjetMagique(const ObjetMagique& objetMagique)
{
	objetMagique_ = objetMagique;
}

unsigned int Dresseur::obtenirNombreCreatures() const
{
	return nombreCreatures_;
}

unsigned int Dresseur::obtenirNombreCreaturesMax() const
{
	return nombreCreaturesMax_;
}

Creature** Dresseur::obtenirCreatures() const
{
	return creatures_;
}

void Dresseur::modifierCreature(Creature** creatures)
{
	creatures_ = creatures;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{
	//Application de l'objet magique à la vie et à l'énergie de la créature
	creature->modifierPointDeVie(creature->obtenirPointDeVie() + objetMagique_.obtenirBonus());
	creature->modifierEnergie(creature->obtenirEnergie() + objetMagique_.obtenirBonus());

	//Ajustement des niveaux de vie et d'énergie si ceux-ci dépassent leur
	//valeur maximale après l'application du bonus
	if (creature->obtenirPointDeVie() > creature->obtenirPointDeVieTotal())
		creature->modifierPointDeVie(creature->obtenirPointDeVieTotal());

	if (creature->obtenirEnergie() > creature->obtenirEnergieTotale())
		creature->modifierEnergie(creature->obtenirEnergieTotale());

	cout << "l'objet " << objetMagique_.obtenirNom() << " fournit un bonus de " << objetMagique_.obtenirBonus() << endl;
}

bool Dresseur::ajouterCreature(const Creature& creature)
{
	bool existe = false;

	//Vérifier si la créature existe
	for (size_t i = 0; i < nombreCreatures_ && !existe; i++)
	{
		if (creatures_[i]->obtenirNom() == creature.obtenirNom())
			existe = true;
	}

	//Ajouter la créature au cas où elle n'existe pas
	if (!existe)
	{
		if (nombreCreatures_ == nombreCreaturesMax_)
		{
			nombreCreaturesMax_ *= 2;

			Creature** temp = new Creature*[nombreCreaturesMax_];

			for (size_t i = 0; i < nombreCreatures_; i++)
				temp[i] = creatures_[i];

			delete[] creatures_;

			creatures_ = temp;

			delete[] temp;
		}		
		creatures_[nombreCreatures_++] = new Creature(creature);
	}
	return !existe;
}

bool Dresseur::retirerCreature(const std::string& nom)
{
	bool retirer = false;
	for (size_t i = 0; i < nombreCreatures_ && !retirer; i++)
	{
		if (creatures_[i]->obtenirNom() == nom) {
			delete creatures_[i];
			creatures_[i] = creatures_[--nombreCreatures_];
			retirer = true;
		}
	}
	return retirer;
}

void Dresseur::affichage() const
{
	std::cout << nom_ << " possede " << nombreCreatures_ << " creature(s)" << std::endl;
}