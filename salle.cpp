#include <iostream>
#include <string>
#include "salle.hpp"
using namespace std;

Salle::Salle(): nom(" "), superficie(0) {}
Salle::Salle(std::string NOM, int SUPERFICIE)
    : nom(NOM),superficie(SUPERFICIE) {}

std::string Salle::getNom() const{
    return nom;
}
int Salle::getSuperficie() const{
    return superficie;
}


Salle_enseignement::Salle_enseignement(std::string NOM , int SUPERFICIE, int NB_PLACES , bool VIDEO_PROJECTEUR, TypeSalle TYPE )
    : Salle(NOM,SUPERFICIE), nb_places(NB_PLACES), video_projecteur(VIDEO_PROJECTEUR), type(TYPE) {}

int Salle_enseignement::getNb_Places() const{
    return nb_places;
}

bool Salle_enseignement::hasVideo_projecteur() const{
    return video_projecteur;
}
    
TypeSalle Salle_enseignement::getTypedeSalle() const{
    return type;
}

std::ostream& operator<< (std::ostream& os, const Salle_enseignement& s){
    os << " + Salle d'enseignement " << s.nom << " de " << s.superficie <<  " (m2) " << endl;
    if (s.video_projecteur == 1)
        os << "  Cette salle presente video projecteur " << endl;
    else
        os << "  Cette salle ne presente pas video projecteur " << endl;

    os << "  Type: " ;
    if (s.type == SALLE_STANDARD ) {
        os << "Salle de classe standard ";
    } else if (s.type == SALLE_INFO ) {
        os << "Salle informatique ";
    } else if (s.type == SALLE_MANIP ){
        os << "Salle de manip";
    }
    return os;
}