#ifndef BUREAU_HPP
#define BUREAU_HPP

#include "salle.hpp"
#include "personnel.hpp"
#include <ostream>
#include <string>

class Bureau : public Salle {
private:
    Personnel* membres;
    int nbMembres;
    int capacite;

public:
    Bureau();
    Bureau(const std::string& , int );
    Bureau(const Bureau& );
    ~Bureau();
    
    Bureau& operator=(const Bureau& );
    
    void ajouterPersonnel(const Personnel& );
    Personnel& operator[](int );
    const Personnel& operator[](int ) const;
    
    int getNbMembres() const;
    
    friend std::ostream& operator<<(std::ostream& , const Bureau& );
};

#endif