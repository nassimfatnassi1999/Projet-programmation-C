#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct Date
{
    int jour;
    int mois;
    int annee;
} date;
//struct liste
typedef struct liste_electorale
{
    int id;
    char nom_liste[30];
    date d;
    char orientation[20];
    char municipalite[20];
    char nom_tete_liste[30];
    char candidat_1[30];
    char candidat_2[30];
    char candidat_3[30];
} Liste;
typedef struct
{
    char nomListe[30];
    int idListe;
    int NbrVote;
}Lorder;
typedef struct infoUtilisateur
{
    int CIN;
    int Nempreinte;
    int Ntelephone;
    char nom[30];
    char prenom[30];
    int municipalite;
    int role;
    int genre;
    date d;
    int vote;
} utilisateur;
//les fonctions

int genererIdListe(char * filename);

void ajouterListe(Liste L);

int modifierListe( char * filename,int id,Liste nouvL );

void supprimerListe(Liste Li);

Liste chercher(char *, int);

int nbv(char * filename,int id);

void afficherTab(int tab,int n);

void printTab(Lorder tab[],int *n);

void remplirtab(char * filename,char * filename2,Lorder tab[],int *n);

int connexion(int login,int pass);

int verifier(char * filename, char nom[]);

void afficher_Liste(GtkWidget *liste);




#endif // FUNCTION_H_INCLUDED

