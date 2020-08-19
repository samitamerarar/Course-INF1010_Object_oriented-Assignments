#include "EtatConfus.h"

EtatConfus::EtatConfus(const std::string& nom) : EtatCreature(nom, 0)
{
	type_ = TypeEtat::TypeEtat_confus;
}

EtatConfus::EtatConfus(const std::string& nom, unsigned int duree) : EtatCreature(nom, duree)
{
	type_ = TypeEtat::TypeEtat_confus;
}

EtatConfus::~EtatConfus()
{
}

void EtatConfus::appliquerEtat(Creature& creature)
{
	if (rand() % 3) //probabilité de 33%
	{
		if (creature.obtenirPointDeVie() <= 0) {
			creature.modifierPointDeVie(0);
		}
		else if (creature.obtenirPointDeVie() / 20 < 5) { //si 5% des points de vie est inférieur à 5 point de vie
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - 5);	
		}
		else { //creature perd 5% de ses points de vie
			creature.modifierPointDeVie(creature.obtenirPointDeVie() - (creature.obtenirPointDeVie() / 20));
		}
	}
	duree_--;
}

bool EtatConfus::peutAttaquer() const
{
	//50% de chance d'attaquer
	return rand() % 2;
}

bool EtatConfus::estFini() const
{
	//État est fini si la durée <=0 ou avoir une chance de 33.33% qu'il soit fini.
	return duree_ <= 0 || rand() % 3;
}

std::ostream & operator<<(std::ostream & o, const EtatConfus & etat)
{
	return o << " etat " << etat.obtenirNom() << " :folie durera " << etat.duree_ << std::endl;
}
