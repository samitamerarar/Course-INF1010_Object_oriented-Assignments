/*
Fichier: Professeur.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 5 octobre 2016
Date de modification:  18 octobre 2016
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "Dresseur.h"
#include "OutilScientifique.h"

class Professeur : public Dresseur
{
public:
	//constructeurs
	Professeur(); 
	Professeur(const std::string nom, const std::string equipe);
	Professeur(const Professeur& professeur); //constructeur par copie
	~Professeur(); //destructeur

	//getter
	OutilScientifique obtenirOutilScientifique() const;
	//setter
	void modifierOutil(const OutilScientifique& outilScientifique);
	
	void soigner(Creature& creature); //rétablit pointDeVie et energie au max d'une créature
	void utiliserOutil(Creature& creature);

	Professeur& operator=(const Professeur& professeur);
	//appel de l'operator<< de la classe mère et affiche l'outil utilisé
	friend std::ostream& operator<<(std::ostream& o, const Professeur& professeur);

private:
	OutilScientifique* outilScientifique_;
};

#endif
