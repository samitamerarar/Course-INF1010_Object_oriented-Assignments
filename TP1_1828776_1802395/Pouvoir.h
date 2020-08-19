/*
Fichier: Pouvoir.h
Auteur(s): Tamer Arar, Guy-Frank Essome Penda
Date de creation: 14 septembre 2016
Date de modification: 26 septembre 2016
Description: Une classe des pouvoirs des cr�atures qui demandent une certaine quantit� d'energie pour infliger des d�g�ts sur une autre cr�ature.
*/

#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>

class Pouvoir
{
public:
	
	//constructeur par defaut et par parametres
	Pouvoir();

	Pouvoir(const std::string& nom, int nombreDeDegats, int energieNecessaire);

	~Pouvoir();		//destructeur

	//methodes d'acces et modifications
	std::string obtenirNom() const;
	void setNom(const std::string& nom);

	int obtenirNombreDeDegats() const;
	void setNombreDeDegats(const int nombreDeDegats);

	int obtenirEnergieNecessaire() const;
	void setEnergieNecessaire(const int energieNecessaire);
	
	void description();

private: 

	//Attributs
	std::string nom_;
	int nombreDeDegats_;
	int energieNecessaire_;

};

#endif