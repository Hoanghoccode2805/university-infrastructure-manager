#include <iostream>
#include "bureau.hpp"
#include "batiment.hpp"
#include "personnel.hpp"
#include "salle.hpp"

using namespace std;

int main()
{
	Salle_enseignement salle("S01", 35, 30, true, SALLE_MANIP);
	cout<<"Une salle : "<<salle<<endl;

	Bureau bur1("S02", 16);
	
	Personnel pers("Dubois","Jean",ENSEIGNANT);
	bur1.ajouterPersonnel(pers);
	bur1.ajouterPersonnel(Personnel("Dugland","Louise",ENSEIGNANT));
	bur1.ajouterPersonnel(Personnel("Duchene","Robert",ADMINISTRATIF));
		
	cout<<"Un membre : "<<bur1[1]<<endl; // Doit afficher Louise Dugland
	cout<<"Un bureau : "<<bur1<<endl;
	
	Bureau bur2(bur1);
	Bureau bur3;
	bur3 = bur1;
	cout<<bur2<<endl<<bur3<<endl;



	// Avec Batiment
	Batiment bat("Darwin");
	
	Personnel jean("Dubois","Jean",ENSEIGNANT);
	bat.ajouterBureau(Bureau("D01",16));
	bat.getBureau(0).ajouterPersonnel(jean);
	bat.getBureau(0).ajouterPersonnel(Personnel("Dugland","Louise",ENSEIGNANT));
	bat.getBureau(0).ajouterPersonnel(Personnel("Duchene","Robert",ADMINISTRATIF));
	
	bat.ajouterBureau(Bureau("D02",9));
	bat.getBureau(1).ajouterPersonnel(Personnel("Latour","Gerard",ADMINISTRATIF));
	bat.getBureau(1).ajouterPersonnel(Personnel("Larue","Evelyne",ADMINISTRATIF));
	
	Salle_enseignement manip("D11", 35, 30, true, SALLE_STANDARD);
	
	bat.ajouterSalleEnseignement(manip);
	bat.ajouterSalleEnseignement(Salle_enseignement("D12", 25, 15, false, SALLE_INFO));
	
	cout<<"Un membre : "<<bat.getBureau(0)[1]<<endl; // Doit afficher Louise Dugland
	cout<<"Un bureau : "<<bat.getBureau(0)<<endl;
	cout<<"Un batiment : "<<bat<<endl;
	
	return 0;
}