

#include <gtk/gtk.h>
#include"function.h" //for struct date
typedef struct {
char jour0[50];
char mois0[50];
char annee0[50];
}datee;



typedef struct{
char id[50];
char nbr_conseiller[50];
char municipalite[50];
datee del;
}election;


void ajouter_election(char * ELECTION,election e);
void afficher_election(GtkWidget *liste);
void supprimer_election(election e);
election chercher_election( char id[]);
int modifier_election( char * filename,char id[],election em );
void Chercher_MUL(GtkWidget *liste,char ch[20]);
int verifier_seif(char idv[]);

