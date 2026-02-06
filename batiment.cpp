#include "batiment.hpp"
#include <string>
#include <iostream>
using namespace std; 

Batiment::Batiment(const std::string& NOM) 
    : nom(NOM), sallesEnseignement(nullptr), bureaux(nullptr),
      nbSallesEnseignement(0), nbBureaux(0), 
      capaciteSalles(0), capaciteBureaux(0) {}

Batiment::Batiment(const Batiment& other)
    : nom(other.nom), 
      nbSallesEnseignement(other.nbSallesEnseignement),
      nbBureaux(other.nbBureaux),
      capaciteSalles(other.capaciteSalles),
      capaciteBureaux(other.capaciteBureaux) {
    
    if (capaciteSalles > 0) {
        sallesEnseignement = new Salle_enseignement*[capaciteSalles];
        for (int i = 0; i < nbSallesEnseignement; i++) {
            sallesEnseignement[i] = new Salle_enseignement(*other.sallesEnseignement[i]);
        }
    } else {
        sallesEnseignement = nullptr;
    }
    
    if (capaciteBureaux > 0) {
        bureaux = new Bureau*[capaciteBureaux];
        for (int i = 0; i < nbBureaux; i++) {
            bureaux[i] = new Bureau(*other.bureaux[i]);
        }
    } else {
        bureaux = nullptr;
    }
}

Batiment::~Batiment() {
    for (int i = 0; i < nbSallesEnseignement; i++) {
        delete sallesEnseignement[i];
    }
    delete[] sallesEnseignement;
    
    for (int i = 0; i < nbBureaux; i++) {
        delete bureaux[i];
    }
    delete[] bureaux;
}

Batiment& Batiment::operator=(const Batiment& other) {
    if (this != &other) {
        for (int i = 0; i < nbSallesEnseignement; i++) {
            delete sallesEnseignement[i];
        }
        delete[] sallesEnseignement;
        
        for (int i = 0; i < nbBureaux; i++) {
            delete bureaux[i];
        }
        delete[] bureaux;
        
        nom = other.nom;
        nbSallesEnseignement = other.nbSallesEnseignement;
        nbBureaux = other.nbBureaux;
        capaciteSalles = other.capaciteSalles;
        capaciteBureaux = other.capaciteBureaux;
        
        if (capaciteSalles > 0) {
            sallesEnseignement = new Salle_enseignement*[capaciteSalles];
            for (int i = 0; i < nbSallesEnseignement; i++) {
                sallesEnseignement[i] = new Salle_enseignement(*other.sallesEnseignement[i]);
            }
        } else {
            sallesEnseignement = nullptr;
        }
        
        if (capaciteBureaux > 0) {
            bureaux = new Bureau*[capaciteBureaux];
            for (int i = 0; i < nbBureaux; i++) {
                bureaux[i] = new Bureau(*other.bureaux[i]);
            }
        } else {
            bureaux = nullptr;
        }
    }
    return *this;
}

void Batiment::ajouterSalleEnseignement(const Salle_enseignement& salle) {
    if (nbSallesEnseignement >= capaciteSalles) {
        int nouvelleCapacite; 
        if(capaciteSalles == 0){
            nouvelleCapacite = 1;
        }
        else{
            nouvelleCapacite = capaciteSalles*2;
        }

        Salle_enseignement** nouveauTableau = new Salle_enseignement*[nouvelleCapacite];
        
        for (int i = 0; i < nbSallesEnseignement; i++) {
            nouveauTableau[i] = sallesEnseignement[i];
        }
        
        delete[] sallesEnseignement;
        sallesEnseignement = nouveauTableau;
        capaciteSalles = nouvelleCapacite;
    }
    
    sallesEnseignement[nbSallesEnseignement] = new Salle_enseignement(salle);
    nbSallesEnseignement++;
}

void Batiment::ajouterBureau(const Bureau& bureau) {
    if (nbBureaux >= capaciteBureaux) {
        int nouvelleCapacite; 
        if(capaciteBureaux == 0){
            nouvelleCapacite = 1;
        }
        else{
            nouvelleCapacite = capaciteBureaux*2;
        }
        Bureau** nouveauTableau = new Bureau*[nouvelleCapacite];
        
        for (int i = 0; i < nbBureaux; i++) {
            nouveauTableau[i] = bureaux[i];
        }
        
        delete[] bureaux;
        bureaux = nouveauTableau;
        capaciteBureaux = nouvelleCapacite;
    }
    
    bureaux[nbBureaux] = new Bureau(bureau);
    nbBureaux++;
}

Salle_enseignement& Batiment::getSalleEnseignement(int index) {
    return *sallesEnseignement[index];
}

Bureau& Batiment::getBureau(int index) {
    return *bureaux[index];
}

std::ostream& operator<<(std::ostream& os, const Batiment& bat) {
    os << " Batiment " << bat.nom << endl;
    
    os << "Salles d'enseignement: \n";
    for (int i = 0; i < bat.nbSallesEnseignement; i++) {
        os << *bat.sallesEnseignement[i] << endl;
    }
    
    os << "Bureaux: \n";
    for (int i = 0; i < bat.nbBureaux; i++) {
        os << " + " << *bat.bureaux[i];
        if (i < bat.nbBureaux - 1) 
            os << endl;
    }
    
    return os;
}