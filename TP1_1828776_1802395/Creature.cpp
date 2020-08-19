/*
Fichier: Creature.cpp
Auteur(s): Guy-Frank, Tamer Arar
Date de creation: 14 septembre 2016
Date de modification: 26 septembre 2016
Description: Représente des créatures combattantes dans PolyLand
*/

#include "Creature.h"
#include <iostream>
using namespace std;

Creature::Creature()
	:nom_(""), attaque_(0), defense_(0), pointDeVieTotal_(0),
	pointDeVie_(0), energieTotal_(0), energie_(0),
	experience_(0), experienceNecessaire_(0), niveau_(0)
{
}

Creature::Creature(const std::string& nom, int attaque, int defense,
	int pointDeVie, int energie, const Pouvoir& pouvoir)
	:nom_(nom), attaque_(attaque), defense_(defense),
	pointDeVie_(pointDeVie), pointDeVieTotal_(pointDeVie),
	energie_(energie), energieTotal_(energie), niveau_(1),
	experience_(0),	experienceNecessaire_(100), pouvoir_(pouvoir)
{
}

Creature::~Creature()
{
}

std::string Creature::obtenirNom() const
{
	return nom_;
}

void Creature::setNom(const std::string& nom)
{
	nom_ = nom;
}

int Creature::obtenirAttaque() const
{
	return attaque_;
}

void Creature::setAttaque(int attaque)
{
	attaque_ = attaque;
}

int Creature::obtenirDefense() const
{
	return defense_;
}

void Creature::setDefense(int defense)
{
	defense_ = defense;
}

int Creature::obtenirPointDeVie() const
{
	return pointDeVie_;
}

void Creature::modifierPointDeVie(int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

int Creature::obtenirPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

void Creature::setPointDeVieTotal(int pointDeVie)
{
	pointDeVieTotal_ = pointDeVie;
}

int Creature::obtenirEnergie() const
{
	return energie_;
}

void Creature::modifierEnergie(int energie)
{
	energie_ = energie;
}

int Creature::obtenirEnergieTotale() const
{
	return energieTotal_;
}

void Creature::setEnergieTotal(int energie)
{
	energieTotal_ = energie;
}

int Creature::obtenirExperience() const
{
	return experience_;
}

void Creature::setExperience(int experience)
{
	experience_ = experience;
}

int Creature::obtenirExperienceNecessaire() const
{
	return experienceNecessaire_;
}

void Creature::setExperienceNecessaire(int experienceNecessaire)
{
	experienceNecessaire_ = experienceNecessaire;
}

int Creature::obtenirNiveau() const
{
	return niveau_;
}

void Creature::setNiveau(int niveau)
{
	niveau_ = niveau;
}

Pouvoir Creature::obtenirPouvoir() const
{
	return pouvoir_;
}

void Creature::setPouvoir(const Pouvoir& pouvoir)
{
	pouvoir_ = pouvoir;
}


int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.obtenirPointDeVie() <= 0) {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.obtenirNiveau() + 1 - niveau_) * ((creature.obtenirAttaque() + 5 - attaque_) *
		 (creature.obtenirDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_)) {
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
		else {
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}


void Creature::attaquer(Creature & creature)
{
	//L'attaque est possible si votre créature a assez d'energie
	//Et que la creature adverse a encore des points de vie
	//Si la creature adverse n'a plus de vie, afficher un message en conséquent

	if (energie_ > pouvoir_.obtenirEnergieNecessaire()
		&& creature.obtenirPointDeVie() > 0)
	{
		//Calcul du nombre de degat selon une formule
		unsigned int degat = (pouvoir_.obtenirNombreDeDegats())* (attaque_ / 2 - creature.defense_);
		//On choisit un nombre aléatoire entre 1 et 6
		int tentative = (rand() % 6) + 1;
		//l'attaque rate une fois sur 6
		if (tentative != 3) {
			//Afficher le nom de la créature qui lance l'attaque, le nom de l'attaque,
			//le nombre de dégat infligé, et la créature qui est attaquée

			std::cout << nom_ << " lance " << pouvoir_.obtenirNom() << " qui inflige " << degat << " degat a " << creature.obtenirNom() << endl;
			
			//Afficher le nombre d'XP gagné si c'est approprié, n'oubliez pas de faire
			//les modifications adéquates

			creature.modifierPointDeVie(creature.obtenirPointDeVie() - degat);
			energie_ -= pouvoir_.obtenirEnergieNecessaire();

			if (experienceGagnee(creature) != 0) {
				std::cout << nom_ << " a gagne " << experienceGagnee(creature) << " XP" << endl;
				creature.modifierPointDeVie(0);
			}

			//Afficher le nombre de point de vie restant de la créature attaquée
			//Faites attention aux requis d'une attaque
			std::cout << creature.obtenirNom() << " a encore " << creature.obtenirPointDeVie() << " PV" << endl;
		}
		else {
			// L'attaque a raté
			std::cout << "Attaque " << pouvoir_.obtenirNom() << " a echoue" << endl;
		}
	}
	else
		cout << "Votre créature n'a pas assez d'ernergie pour utiliser le pouvoir" << endl;
}


void Creature::information()
{
	cout << nom_ << " a " << attaque_ << " en attaque et " << defense_ << " en defense," << endl;
	cout << "Il a " << pointDeVie_ << "/" << pointDeVieTotal_ << " PV et " << energie_ << "/" << energieTotal_ << " Energie" << endl;
	cout << "Il est au niveau " << niveau_ << " avec " << experience_ << " de XP" << endl;
	cout << "Il lui manque " << experienceNecessaire_ - experience_ << " jusqu'au prochain niveau" << endl;
	pouvoir_.description();
}
