#include <stdio.h>
#include <string.h>
#include "fonctionBV.h"
//Ajouter bureau de vote
int ajouterListe(char* filename, bureauVote bv)
{ FILE* fichier;

    fichier=fopen(filename,"a");
    if(fichier!=NULL)
    {
fprintf(fichier,"%d%d%d%d%s%s%s%lf%s%s%d%lf%d%d%d",bv.id,bv.cap_electeur,bv.cap_observateur,bv.salle,bv.municipalite.gouvernorat,bv.municipalite.delegation,bv.municipalite.centreVote,bv.agent.nCIN,bv.agent.nom,bv.agent.prenom,bv.agent.numero,bv.agent.telephone,bv.d.jour,bv.d.mois,bv.d.annee);
        fclose(fichier);
        return 1;
    }
    else
        return 0;
}
//Modifier bureau de vote
int modifierListe( char* filename,int id, bureauVote Nvbv )
{
    int trouve=0;
    bureauVote anBv;
    FILE* fichier;
    FILE* fichierMOD;
    fichier=fopen(filename, "r");
    fichierMOD=fopen("nouv.txt","w");
    if(fichier!=NULL && fichierMOD!=NULL)
    {   while(fscanf(fichier,"%d%d%d%d%s%s%s%lf%s%s%d%lf%d%d%d",&anBv.id,&anBv.cap_electeur,&anBv.cap_observateur,&anBv.salle,anBv.municipalite.gouvernorat,anBv.municipalite.delegation,anBv.municipalite.centreVote,&anBv.agent.nCIN,anBv.agent.nom,anBv.agent.prenom,&anBv.agent.numero,&anBv.agent.telephone,&anBv.d.jour,&anBv.d.mois,&anBv.d.annee)!=EOF)
        {
            if(anBv.id==id)
            {
                fprintf(fichierMOD,"%d%d%d%d%s%s%s%lf%s%s%d%lf%d%d%d",Nvbv.id,Nvbv.cap_electeur,Nvbv.cap_observateur,Nvbv.salle,Nvbv.municipalite.gouvernorat,Nvbv.municipalite.delegation,Nvbv.municipalite.centreVote,Nvbv.agent.nCIN,Nvbv.agent.nom,Nvbv.agent.prenom,Nvbv.agent.numero,Nvbv.agent.telephone,Nvbv.d.jour,Nvbv.d.mois,Nvbv.d.annee);
                trouve=1;
            }
            else
 fprintf(fichier,"%d%d%d%d%s%s%s%lf%s%s%d%lf%d%d%d",anBv.id,anBv.cap_electeur,anBv.cap_observateur,anBv.salle,anBv.municipalite.gouvernorat,anBv.municipalite.delegation,anBv.municipalite.centreVote,anBv.agent.nCIN,anBv.agent.nom,anBv.agent.prenom,anBv.agent.numero,anBv.agent.telephone,anBv.d.jour,anBv.d.mois,anBv.d.annee);

        }
    }
    fclose(fichier);
    fclose(fichierMOD);
    remove(filename);
    rename("nouv.txt",filename);
    return trouve;

}

// supprimer bureau de vote
int supprimer(char * filename, int id)
{
    int trouve=0;
    bureauVote anBv;
    FILE* fichier;
    FILE* fichierMod;
    fichier=fopen(filename, "r");
    fichierMod=fopen("nouv.txt", "w");
    if(fichier!=NULL && fichierMod!=NULL)
    {
  while(fscanf(fichier,"%d%d%d%d%s%s%s%lf%s%s%d%lf%d%d%d",&anBv.id,&anBv.cap_electeur,&anBv.cap_observateur,&anBv.salle,anBv.municipalite.gouvernorat,anBv.municipalite.delegation,anBv.municipalite.centreVote,&anBv.agent.nCIN,anBv.agent.nom,anBv.agent.prenom,&anBv.agent.numero,&anBv.agent.telephone,&anBv.d.jour,&anBv.d.mois,&anBv.d.annee)!=EOF)
        {
            if(anBv.id== id)
                trouve=1;
            else
fprintf(fichier,"%d%d%d%d%s%s%s%lf%s%s%d%lf%d%d%d",anBv.id,anBv.cap_electeur,anBv.cap_observateur,anBv.salle,anBv.municipalite.gouvernorat,anBv.municipalite.delegation,anBv.municipalite.centreVote,anBv.agent.nCIN,anBv.agent.nom,anBv.agent.prenom,anBv.agent.numero,anBv.agent.telephone,anBv.d.jour,anBv.d.mois,anBv.d.annee);
        }
    }
    fclose(fichier);
    fclose(fichierMod);
    remove(filename);
    rename("nouv.txt", filename);
    return trouve;
}
// chercher un bureau de vote
bureauVote chercher(char* filename, int id)
{
    bureauVote anBv;
    int trouve=0;
    FILE* fichier;
 fichier=fopen(filename, "r");
    if(fichier!=NULL)
    {
        while(trouve==0&& fscanf(fichier,"%d%d%d%d%s%s%s%lf%s%s%d%lf%d%d%d",&anBv.id,&anBv.cap_electeur,&anBv.cap_observateur,&anBv.salle,anBv.municipalite.gouvernorat,anBv.municipalite.delegation,anBv.municipalite.centreVote,&anBv.agent.nCIN,anBv.agent.nom,anBv.agent.prenom,&anBv.agent.numero,&anBv.agent.telephone,&anBv.d.jour,&anBv.d.mois,&anBv.d.annee)!=EOF)
        {
            if(anBv.id== id)
                trouve=1;

        }
    }
    fclose(fichier);
    if(trouve==0)
       anBv.id=-1;
    return anBv;

}

