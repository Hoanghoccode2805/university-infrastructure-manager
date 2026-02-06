#ifndef PERSONNEL_HPP
#define PERSONNEL_HPP
#include <ostream>
#include <string>
enum Fonction {
    ENSEIGNANT,
    ADMINISTRATIF
};

class Personnel{
private:
    std::string nom;
    std::string prenom;
    Fonction fonction;
public:
    Personnel();
    Personnel(std::string, std::string, Fonction);
    std::string getNom() const;
    std::string getPrenom() const;
    Fonction getFonction() const;
    friend std::ostream& operator<<(std::ostream&, const Personnel&);
};


#endif