#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
typedef struct Date{
int jour;
int mois;
int annee;
} date;
//struct liste
typedef struct liste_electorale{
int id;
char nom_liste[30];
 date d;
int orientation;
int municipalite;
char nom_tete_liste[30];
char candidat_1[30];
char candidat_2[30];
char candidat_3[30];
}Liste;
//les fonctions
void saisir(Liste *L);
int ajouterListe(char * filename, Liste L);
int modifierListe( char * filename,int id,Liste nouvL );
int supprimerListe(char * filename, int id);
Liste chercher(char * , int);


#endif // FUNCTION_H_INCLUDED

