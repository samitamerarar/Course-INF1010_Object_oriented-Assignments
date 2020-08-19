#include "ObjetMagique.h"

ObjetMagique::ObjetMagique()
{
}

ObjetMagique::ObjetMagique(const std::string & nom, int bonus):
	nom_(nom), bonus_(bonus)
{
}


ObjetMagique::~ObjetMagique()
{
}

std::string ObjetMagique::obtenirNom() const
{
	return nom_;
}

int ObjetMagique::obtenirBonus() const
{
	return bonus_;
}

void ObjetMagique::modifierNom(const std::string& nom)
{
	nom_ = nom;
}

void ObjetMagique::modifierBonus(int bonus)
{
	bonus_ = bonus;
}

void ObjetMagique::utiliserSur(Creature & creature) const
{
    if ((creature.obtenirPointDeVieTotal() - creature.obtenirPointDeVie()) >= obtenirBonus()) {
        creature.modifierPointDeVie(creature.obtenirPointDeVie() + obtenirBonus());
    }
    else {
        creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
    }
    if ((creature.obtenirEnergieTotale() - creature.obtenirEnergie()) > obtenirBonus()) {
        creature.modifierEnergie(creature.obtenirEnergie() + obtenirBonus());
    }
    else {
        creature.modifierEnergie(creature.obtenirEnergieTotale());
    }
}

std::ostream& operator<<(std::ostream& os, const ObjetMagique& objet)
{
	return os << "l'objet " << objet.nom_ << "fournit un bonus de " << objet.bonus_ << std::endl;
}