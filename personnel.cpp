#include "personnel.hpp"
#include <iostream>
#include <string>
using namespace std;

Personnel::Personnel() : nom(""), prenom(""), fonction(ENSEIGNANT) {}
Personnel::Personnel(std::string NOM, std::string PRENOM, Fonction FONCTION)
    : nom(NOM), prenom(PRENOM), fonction(FONCTION) {}

std::string Personnel::getNom() const{
    return nom;
}

std::string Personnel::getPrenom() const{
    return prenom;
}

Fonction Personnel::getFonction() const{
    return fonction;
}

std::ostream& operator<<(std::ostream& os, const Personnel& p){
     os << p.prenom << " " << p.nom << " (";
    if (p.fonction == ENSEIGNANT) {
        os << "Enseignant";
    } else {
        os << "Administratif";
    }
    os << ")";
    return os;
}