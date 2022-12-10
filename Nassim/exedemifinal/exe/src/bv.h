#include <gtk/gtk.h>


typedef struct
{
    char idAg[50];
}agentBV;


typedef struct
{   
    char id[30];
    char capElecteurs[10];
    char capObservateurs[10];
    char salle[10];
    char gouvernorat[30];
    char delegation[30];
    agentBV IDagent;
}BV;




void ajouter_bv(BV bv);
int tableau_agent(char agent[50][50]);
void supprimerAgent(char *fichier, char agentbv[]);
int tableau_delegation(char delegat[50][50],char gouver[30]);
void afficher_bv(GtkWidget *liste);
void supprimer_bv(BV bv);
int supprimer_idbv(char suppI[]);
void supprimerDelegation(char *fichier, char delegation[]);
void trierMunicipalite(char *fichier);
void trierElecteurs(char *fichier);
void trierSalle(char *fichier);


