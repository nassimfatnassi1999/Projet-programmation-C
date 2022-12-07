#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct Date{
char jour[5];
char mois[5];
char annee[5];
} dateh;
//struct Utilisteur
typedef struct infoUtilisateur{
char CIN[50];
char Nempreinte[50];
char Ntelephone[50];
char nom[50];
char prenom[50];
char municipalite[50];
char role[50];
char genre[50];
 dateh d;
char vote[50];
}utilisateur;
//les fonctions

int ajouterUtilisateur(char * filename, utilisateur L);
int verifUtilisateur(char * filename, char nom[], char prenom[]);
void afficher_USERtreeview(GtkWidget *liste);
void supprimer_USERtreev(utilisateur L);
utilisateur chercherUtilisateur(char * filename, char CIN[]);
int modifierUtilisateur( char * filename,char CIN[],utilisateur nouvL );
#endif // FUNCTION_H_INCLUDE
