/*
Fichier: EtatConfus.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Caractérise l'état d'une créature en état de confusion
*/
#ifndef ETAT_CONFUS_H
#define ETAT_CONFUS_H

#include "EtatCreature.h"

class EtatConfus : public EtatCreature
{
public:
	//constructeurs
	EtatConfus(const std::string& nom);
	EtatConfus(const std::string& nom, unsigned int duree);
	~EtatConfus(); //destructeur

	void appliquerEtat(Creature& creature); //à appliquer sur la créature qui possède ce pouvoir
	bool peutAttaquer() const; //détermine si l'état de la créature lui permet d'attaquer (à 50% de probabilité)
	bool estFini() const; //si vrai, informe la créature qu'elle peut retourner à l'état normal

	friend std::ostream& operator<<(std::ostream& o, const EtatConfus& etat);
};

#endif // !ETAT_CONFUS_H