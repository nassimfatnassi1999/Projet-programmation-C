#ifndef FONCTIONBV_H_INCLUDED
#define FONCTIONBV_H_INCLUDED
typedef struct
{   char gouvernorat[30];
    char delegation[30];
    char centreVote[40];
}identifiant;

typedef struct
{   double nCIN;
    char nom[20];
    char prenom[20];
    int numero;
    double telephone;
}agentBv;

typedef struct
{   int jour;
    int mois;
    int annee;
}date;

typedef struct
{   int id;
    int cap_electeur;
    int cap_observateur;
    int salle;
    identifiant municipalite;
    agentBv agent;
    date d;
}bureauVote;

int ajouterListe(char* filename, bureauVote bv);
int modifierListe( char* filename,int id, bureauVote Nvbv );
int supprimer(char * filename, int id);
bureauVote chercher(char* filename, int id);

#endif // FONCTIONBV_H_INCLUDED


