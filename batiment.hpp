#ifndef BATIMENT_HPP
#define BATIMENT_HPP

#include "bureau.hpp"
#include "salle.hpp"
#include <string>
#include <ostream>

class Batiment {
private:
    std::string nom;
    Salle_enseignement** sallesEnseignement;
    Bureau** bureaux;
    int nbSallesEnseignement;
    int nbBureaux;
    int capaciteSalles;
    int capaciteBureaux;

public:
    Batiment(const std::string& );
    Batiment(const Batiment& );
    ~Batiment();
    
    Batiment& operator=(const Batiment& );
    
    void ajouterSalleEnseignement(const Salle_enseignement& );
    void ajouterBureau(const Bureau& );
    
    Salle_enseignement& getSalleEnseignement(int );
    Bureau& getBureau(int );
    
    std::string getNom() const;
    
    friend std::ostream& operator<<(std::ostream& , const Batiment&);
};

#endif