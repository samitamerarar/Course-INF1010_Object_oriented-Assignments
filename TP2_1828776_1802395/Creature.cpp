/*
Fichier: Creature.cpp
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 3 octobre 2016
Description: (classe) Les creatures sont des etres combattantes de polyland
*/

#include "Creature.h"
#include "Pouvoir.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

Creature::Creature()
	:nom_("inconnu"), attaque_(0), defense_(0), pointDeVie_(0),
	energie_(0), experience_(0), niveau_(1) // A MODIFIER... (si necessaire)
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

Creature::Creature(const std::string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie):
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1) // A MODIFIER... (si necessaire)
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}

Creature::Creature(const Creature & c)
	:nom_(c.nom_), attaque_(c.attaque_), defense_(c.defense_), pointDeVie_(c.pointDeVie_),
	energie_(c.energie_), experience_(c.experience_), niveau_(c.niveau_),
	pointDeVieTotal_(c.pointDeVieTotal_), energieTotal_(c.energieTotal_),
	experienceNecessaire_(c.experienceNecessaire_)
{
}

Creature::~Creature() // A MODIFIER... (si necessaire)
{
	while (!pouvoirs_.empty())
	{
		delete pouvoirs_.back();
		pouvoirs_.back() = nullptr;
		pouvoirs_.pop_back();
	}
}

std::string Creature::obtenirNom() const
{
	return nom_;
}

unsigned int Creature::obtenirAttaque() const
{
	return attaque_;
}

unsigned int Creature::obtenirDefense() const
{
	return defense_;
}

unsigned int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::obtenirEnergie() const
{
	return energie_;
}

unsigned int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::obtenirExperience() const
{
	return experience_;
}

unsigned int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::obtenirNiveau() const
{
	return niveau_;
}

std::vector<Pouvoir*> Creature::obtenirPouvoirs() const
{
	return pouvoirs_;
}

void Creature::attaquer(const Pouvoir pouvoir_, Creature & creature)// A MODIFIER... (si necessaire)
{
	if (energie_ >= pouvoir_.obtenirEnergieNecessaire()) 
    {
		if (creature.obtenirPointDeVie() >= 0) 
        {
			//Calcul du nombre de degat selon une formule 
			unsigned int degat = (pouvoir_.obtenirNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				std::cout << nom_ << " lance " << pouvoir_.obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << std::endl;
				if (degat > creature.obtenirPointDeVie()) {
					creature.modifierPointDeVie(0);
					int xp = experienceGagnee(creature);
					std::cout << nom_ << " a gagné " << xp << " XP" << std::endl;
				}
				else
					creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
				std::cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << std::endl;
				energie_ -= pouvoir_.obtenirEnergieNecessaire();
			}
			else {
				std::cout << "Attaque " << pouvoir_.obtenirNom() << " a échouée" << std::endl;
			}
		}
		else
			std::cout << "Vous deja avez vaincu " << creature.obtenirNom() << std::endl;
	}

}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) 
    {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) * (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) 
        {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else 
        {
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::modifierNom(const std::string & nom)
{
	nom_ = nom;
}

void Creature::modifierAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::modifierDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::modifierPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::modifierEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::modifierExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::modifierNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::modifierPouvoirs(std::vector<Pouvoir*> pouvoirs) // A MODIFIER... (si necessaire)
{
	pouvoirs_ = pouvoirs;
}

// _______TP2________

void Creature::apprendrePouvoir(Pouvoir* pouvoir)
{
	pouvoirs_.push_back(new Pouvoir());
	*pouvoirs_.back() = *pouvoir;
}

void Creature::oublierPouvoir(Pouvoir* pouvoir)
{
	bool retire = false;
	for (int i = 0; i < pouvoirs_.size(); i++) {
		if (*pouvoirs_[i] == pouvoir->obtenirNom()) {
			delete pouvoirs_[i];
			pouvoirs_[i] = pouvoirs_.back();
			pouvoirs_.pop_back();
			retire = true;
		}
	}
	if (retire){
		std::cout << "Le pouvoir " << pouvoir->obtenirNom() << " a bien ete retire." << std::endl;
	}
	else {
		std::cout << "Le pouvoir " << pouvoir->obtenirNom() << " n'a pas ete retire." << std::endl;
	}
}

Creature & Creature::operator=(const Creature & creature)
{
	nom_ = creature.nom_;
	attaque_ = creature.attaque_;
	defense_ = creature.defense_;
	pointDeVie_ = creature.pointDeVie_;
	pointDeVieTotal_ = creature.pointDeVieTotal_;
	energie_ = creature.energie_;
	experience_ = creature.experience_;
	experienceNecessaire_ = creature.experienceNecessaire_;
	niveau_ = creature.niveau_;
	pouvoirs_ = creature.pouvoirs_;

	return *this;
}

bool Creature::operator==(const Creature& creature) const
{
	return (nom_ == creature.nom_ && attaque_ == creature.attaque_ && defense_ == creature.defense_ && pointDeVie_ == creature.pointDeVie_
		&& pointDeVieTotal_ == creature.pointDeVieTotal_ && energie_ == creature.energie_ && energieTotal_ == creature.energieTotal_ 
		&& experience_ == creature.experience_ && experienceNecessaire_ == creature.experienceNecessaire_ && niveau_ == creature.niveau_);
}

bool Creature::operator==(const std::string nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string nom, Creature& creature)
{
	return (creature == nom);
}

std::ostream& operator<<(std::ostream& os, const Creature& creature)
{
	os << creature.nom_ << " a " << creature.attaque_ << " en attaque et " << creature.defense_ << " en defense," << std::endl
		<< "Il a " << creature.pointDeVie_ << "/" << creature.pointDeVieTotal_ << " PV et " << creature.energie_ << "/" << creature.energieTotal_ << " Energie" << std::endl
		<< "Il lui manque " << creature.experienceNecessaire_ << " jusqu'au prochain niveau" << std::endl
		<< "Pouvoirs :" << std::endl;

	if (!creature.pouvoirs_.empty()) {
		for (int i = 0; i < creature.pouvoirs_.size(); i++) 
			os << *creature.pouvoirs_[i];
	}
	else
		os << creature.nom_ << " ne connait aucun pouvoir" << std::endl;
	return os;
}