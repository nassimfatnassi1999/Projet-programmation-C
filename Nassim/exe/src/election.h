#include <gtk/gtk.h>

#include"function.h" //for struct date
/*typedef struct {
char jour[50];
char mois[50];
char annee[50];
}date;*/



typedef struct{
char id[50];
char nbr_conseiller[50];
char municipalite[50];
date del;
}election;


void ajouter_election(election e);
void afficher_election(GtkWidget *liste);
void supprimer_election(election e);
election chercher_election( char id[]);
int modifier_election( char * filename,char id[],election em );
