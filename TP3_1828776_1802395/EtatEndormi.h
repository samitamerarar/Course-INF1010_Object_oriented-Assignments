/*
Fichier: EtatEndormi.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Caractèrise l'état d'une créature endormie
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

	void appliquerEtat(Creature& creature); //à appliquer sur la créature qui possède ce pouvoir
	bool peutAttaquer() const; //détermine si l'état de la créature lui permet d'attaquer
	bool estFini() const; //si vrai, informe la créature qu'elle peut retourner à l'état normal

	friend std::ostream& operator<<(std::ostream& o, const EtatEndormi& etat);
};

#endif // !ETAT_ENDORMI_H
