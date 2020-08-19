/*
Fichier: EtatConfus.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Caract�rise l'�tat d'une cr�ature en �tat de confusion
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

	void appliquerEtat(Creature& creature); //� appliquer sur la cr�ature qui poss�de ce pouvoir
	bool peutAttaquer() const; //d�termine si l'�tat de la cr�ature lui permet d'attaquer (� 50% de probabilit�)
	bool estFini() const; //si vrai, informe la cr�ature qu'elle peut retourner � l'�tat normal

	friend std::ostream& operator<<(std::ostream& o, const EtatConfus& etat);
};

#endif // !ETAT_CONFUS_H