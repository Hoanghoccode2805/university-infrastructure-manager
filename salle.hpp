#ifndef SALLE_HPP
#define SALLE_HPP
#include <string>
class Salle{
protected:
    std::string nom;
    int superficie;

public:
    Salle();
    Salle(std::string , int);
    std::string getNom() const;
    int getSuperficie() const;
};

enum TypeSalle {
    SALLE_STANDARD,
    SALLE_INFO,
    SALLE_MANIP
};

class Salle_enseignement : public Salle {
private:
    int nb_places;
    bool video_projecteur;
    TypeSalle type;
public:
    Salle_enseignement(std::string , int, int, bool, TypeSalle );
    int getNb_Places() const;
    bool hasVideo_projecteur() const;
    TypeSalle getTypedeSalle() const;
    friend std::ostream& operator<< (std::ostream&, const Salle_enseignement&);
};


#endif