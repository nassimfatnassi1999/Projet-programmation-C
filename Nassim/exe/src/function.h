#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct Date
{
    int jour;
    int mois;
    int annee;
} date;
typedef struct DateH
{
    char jour[3];
    char mois[3];
    char annee[3];
} dateH;
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
   char CIN[50];
char Nempreinte[50];
char Ntelephone[50];
char nom[50];
char prenom[50];
char municipalite[50];
char role[50];
char genre[50];
 dateH dh;
char vote[50];
} utilisateur;
//les fonctions

int genererIdListe(char * filename); //fonction pour generer l'id automatiquement

void ajouterListe(Liste L); //fonction pour ajouter une liste

int modifierListe( char * filename,int id,Liste LM ); //fonction pour modifier une liste

void supprimer_Liste(Liste Li); //fonction pour supprimer une liste

int verifier(char cinT[],char cinc1[],char cinc2[],char cinc3[]); //fonction pour verifier cin des candidats

Liste chercher( char id[]); //fonction pour chercher et retourne une liste

int nbv(char idc[]);//fonction pour calculer nbr de vote de liste 

void printTab(Lorder tab[],int *n);//fonction pour print les liste et nbr de vote 

void remplirtab(Lorder tab[],int *n); //les listes selon nbr de votes

int connexion(char login[],char pass[]);

void MiseAjourIdListe(char * filename ,Liste *L);

void afficher_Liste(GtkWidget *liste);

void afficher_Liste_ordre(GtkWidget *liste);

void Chercher_Nassim(GtkWidget *liste,char ch[20]);

int verifier_Length_Cin(char cinT[],char cinc1[],char cinc2[],char cinc3[]);




#endif // FUNCTION_H_INCLUDED

