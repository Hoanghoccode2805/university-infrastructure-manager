#include "bureau.hpp"
#include <iostream>
#include <string>
using namespace std;

Bureau::Bureau() : Salle("", 0), membres(nullptr), nbMembres(0), capacite(0) {}

Bureau::Bureau(const std::string& NOM, int SUPERFICIE) 
    : Salle(NOM, SUPERFICIE), membres(nullptr), nbMembres(0), capacite(0) {}

Bureau::Bureau(const Bureau& other) 
    : Salle(other.nom, other.superficie), 
      nbMembres(other.nbMembres), 
      capacite(other.capacite) {
    if (capacite > 0) {
        membres = new Personnel[capacite];
        for (int i = 0; i < nbMembres; i++) {
            membres[i] = other.membres[i];
        }
    } else {
        membres = nullptr;
    }
}

Bureau::~Bureau() {
    delete[] membres;
}

Bureau& Bureau::operator=(const Bureau& other) {
    if (this != &other) {
        delete[] membres;
        
        nbMembres = other.nbMembres;
        capacite = other.capacite;
        
        if (capacite > 0) {
            membres = new Personnel[capacite];
            for (int i = 0; i < nbMembres; i++) {
                membres[i] = other.membres[i];
            }
        } else {
            membres = nullptr;
        }
    }
    return *this;
}

void Bureau::ajouterPersonnel(const Personnel& p) {
    if (nbMembres >= capacite) {
        int nouvelleCapacite;
        if(capacite == 0)
            nouvelleCapacite = 1;
        else
            nouvelleCapacite = capacite*2;

        Personnel* nouveauTableau = new Personnel[nouvelleCapacite];
        
        for (int i = 0; i < nbMembres; i++) {
            nouveauTableau[i] = membres[i];
        }
        
        delete[] membres;
        membres = nouveauTableau;
        capacite = nouvelleCapacite;
    }
    
    membres[nbMembres] = p;
    nbMembres++;
}

Personnel& Bureau::operator[](int index) {
    return membres[index];
}

const Personnel& Bureau::operator[](int index) const {
    return membres[index];
}

std::ostream& operator<<(std::ostream& os, const Bureau& b) {
    os << "Bureau " << b.nom << " de " << b.superficie <<  " (m2) " << endl;
    if (b.nbMembres > 0) {
        os << "Membres du personnel :\n";
        for (int i = 0; i < b.nbMembres; i++) {
            os << "   " << b.membres[i] << "\n";
        }
    } else {
        os << "Aucun membre ";
    }
    return os;
}