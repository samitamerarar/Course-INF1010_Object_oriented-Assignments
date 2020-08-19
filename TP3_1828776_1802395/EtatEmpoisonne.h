/*
Fichier: EtatEmpoisonne.h
Auteur(s): Guy-Frank et Tamer Arar
Date de creation: 11 octobre 2016
Date de modification:  18 octobre 2016
Description: Caractèrise l'état d'une créature empoisonnée
*/
#ifndef ETAT_EMPOISONNE_H
#define ETAT_EMPOISONNE_H

#include "EtatCreature.h"

class EtatEmpoisonne : public EtatCreature
{
public:
	//constructeurs
	EtatEmpoisonne(const std::string& nom);
	EtatEmpoisonne(const std::string& nom, unsigned int duree);
	~EtatEmpoisonne(); //destructeur

	void appliquerEtat(Creature& creature); //à appliquer sur la créature qui possède ce pouvoir
	bool estFini() const; //si vrai, informe la créature qu'elle peut retourner à l'état normal

	friend std::ostream& operator<<(std::ostream& o, const EtatEmpoisonne& etat);
};

#endif // !ETAT_EMPOISONNE_H
