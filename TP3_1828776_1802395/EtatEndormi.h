/*
Fichier: EtatEndormi.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Caract�rise l'�tat d'une cr�ature endormie
*/
#ifndef ETAT_ENDORMI_H
#define ETAT_ENDORMI_H

#include "EtatCreature.h"

class EtatEndormi : public EtatCreature
{
public:
	//constructeurs
	EtatEndormi(const std::string& nom);
	EtatEndormi(const std::string& nom, unsigned int duree);
	~EtatEndormi(); //destructeurs

	void appliquerEtat(Creature& creature); //� appliquer sur la cr�ature qui poss�de ce pouvoir
	bool peutAttaquer() const; //d�termine si l'�tat de la cr�ature lui permet d'attaquer
	bool estFini() const; //si vrai, informe la cr�ature qu'elle peut retourner � l'�tat normal

	friend std::ostream& operator<<(std::ostream& o, const EtatEndormi& etat);
};

#endif // !ETAT_ENDORMI_H
