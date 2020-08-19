#include "Professeur.h"
#include "OutilScientifique.h"


Professeur::Professeur()
	: Dresseur()
{
}

Professeur::Professeur(const std::string nom, const std::string equipe)
	: Dresseur(nom, equipe)
{
}

Professeur::Professeur(const Professeur& professeur)
	:outilScientifique_(professeur.outilScientifique_), Dresseur(professeur)
{
	outilScientifique_ = new OutilScientifique(*(professeur.outilScientifique_));
}

Professeur::~Professeur()
{
	delete outilScientifique_;
}

OutilScientifique Professeur::obtenirOutilScientifique() const
{
	return *outilScientifique_;
}

void Professeur::modifierOutil(const OutilScientifique& outilScientifique)
{	
	outilScientifique_ = nullptr;
	outilScientifique_ = new OutilScientifique(outilScientifique);
}

void Professeur::soigner(Creature& creature)
{
	creature.modifierPointDeVie(creature.obtenirPointDeVieTotal());
	creature.modifierEnergie(creature.obtenirEnergieTotale());
}

Professeur& Professeur::operator=(const Professeur& professeur)
{
	this->Dresseur::operator=(professeur);
	return *this;
}

void Professeur::utiliserOutil(Creature& creature)
{
	outilScientifique_->utiliser(creature);
}

std::ostream & operator<<(std::ostream & o, const Professeur& professeur)
{
	return o << (Dresseur&)professeur
		<< "il utilise un outil : " << professeur.obtenirOutilScientifique();
}
