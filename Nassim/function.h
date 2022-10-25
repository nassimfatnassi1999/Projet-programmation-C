#ifndef FONCTIONS_H_ 
#define FONCTIONS_H_ 
//struct date
struct Date{
int jour;
int mois;
int annee;
};
//struct candidat
struct Candidat{
int c1;
int c2;
int c3;
};
//struct liste electorale
struct liste_electorale{
int Id_Liste;
char Nom_Liste[];
struct Date date_creation;
int orientation[];
char Municipalite[];
int Cin_Liste;
struct Candidat les_candidats;
};
//tableau des struct liste_electorale
struct TabListe[]{
struct liste_electorale;
};
//function ajouterListe
void AjouterListe(liste_electorale e1);

#endif
