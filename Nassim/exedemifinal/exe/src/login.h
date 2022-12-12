#include <gtk/gtk.h>
/*int verifierLOgin(char cin[], char motdp[]);*/

typedef struct
{
	int idVote;
	char NomListeVote[20];
	int nbreVote;
}calVot;



int tableau_listeElV(char listeElecVote[20][50]);
int getID(char choixVote[20]);
void modifier(int id );
void getCin(char cinConnecter[20]);
int verifierVote(char cinConnecter[20]);
void getNomPrenom(char cinConnecter[20], char NomPrenom[30], char roleREc[20]);
int tableau_listeElecvote(char listeElec[20][50]);
void CalculVotes();
int calculerLeVote(char Lident[10]);
void afficher_VOTE(GtkWidget *liste);
void trierVote();
