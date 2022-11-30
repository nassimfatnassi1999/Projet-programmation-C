#include <stdio.h>
#include <string.h>
#include "function.h"
#include <gtk/gtk.h>

enum{

	ID,
	NOM_LISTE,
	JOUR,
	MOIS,
	ANNEE,
	ORIENTA,
	MUNI,
	CINT,
	CINC1,
	CINC2,
	CINC3,
	COLUMNS

};
//function pour generer lid auto
int genererIdListe(char * filename)
{

Liste L;
L.id=0;
FILE * f=fopen(filename, "r");
while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF);
fclose(f);

	return (L.id+1);

}

void ajouterListe(Liste L)
{
    L.id=genererIdListe("liste.txt");
    FILE * f=fopen("liste.txt", "a+");

    if(f!=NULL)
    {
        fprintf(f,"%d %s %d %d %d %s %s %s %s %s %s\n",L.id,L.nom_liste,L.d.jour,L.d.mois,L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);

    }
    fclose(f);
}
void afficher_Liste(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	int idliste;
	char nomListe[30];
	char orienta[30];
	char muni[30];
	int Jour;
	int Mois;
	int Annee;
	char cinT[30];
	char cinC1[30];
	char cinC2[30];
	char cinC3[30];
	store=NULL;
	FILE *f;
	Liste L;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("nom_liste", renderer, "text",NOM_LISTE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text",JOUR, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text",MOIS, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text",ANNEE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("orientation", renderer, "text",ORIENTA, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text",MUNI, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("nom_tete_liste", renderer, "text",CINT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("candidat_1", renderer, "text",CINC1, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("candidat_2", renderer, "text",CINC2, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("candidat_3", renderer, "text",CINC3, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
	 store=gtk_list_store_new (COLUMNS,
	 				 G_TYPE_UINT,
					 G_TYPE_STRING,
					 G_TYPE_UINT,
					 G_TYPE_UINT,
					 G_TYPE_UINT,
					 G_TYPE_STRING, 
					 G_TYPE_STRING,
					 G_TYPE_STRING,
					 G_TYPE_STRING,
					 G_TYPE_STRING,
					 G_TYPE_STRING);

	f=fopen("liste.txt", "r");
	if(f==NULL)
	{
		return;
	}
	else{
	
	while(fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
	{
	gtk_list_store_append (store, &iter); 
	gtk_list_store_set (store,&iter,ID,L.id,NOM_LISTE,L.nom_liste,JOUR,L.d.jour,MOIS,L.d.mois,ANNEE,L.d.annee,ORIENTA,L.orientation,MUNI,L.municipalite,CINT,L.nom_tete_liste,CINC1,L.candidat_1,CINC2,L.candidat_2,CINC3,L.candidat_3);
	}
	fclose(f);

	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
	g_object_unref (store);
	}

	
}
//function pour supprimer liste
void supprimerListe(Liste Li)
{
    int tr=0;
    Liste L;
    FILE * f=fopen("liste.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(tr!=0&&fscanf(f,"%d %s %d %d %d %s %s %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
        {
            if((Li.id==L.id )||(strcmp(Li.nom_liste,L.nom_liste)!=0)||(Li.d.jour==L.d.jour)||(Li.d.mois==L.d.mois)||(Li.d.annee==L.d.annee)||(strcmp(Li.orientation,L.orientation)!=0)||(strcmp(Li.municipalite,L.municipalite)!=0)||(strcmp(Li.nom_tete_liste,L.nom_tete_liste)!=0)||(strcmp(Li.candidat_1,L.candidat_1)!=0)||(strcmp(Li.candidat_2,L.candidat_2)!=0)||(strcmp(Li.candidat_3,L.candidat_3)!=0))
            {
                fprintf(f2,"%d %s %d %d %d %s %s %s %s %s %s\n",L.id,L.nom_liste,L.d.jour,L.d.mois,L.d.annee,L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);
            }

        }
    }
    fclose(f);
    fclose(f2);
    remove("liste.txt");
    rename("nouv.txt", "liste.txt");
}
/*
//function pour modifier liste
int modifierListe( char * filename,int id,Liste nouvL )
{
    int tr=0;
    Liste L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %d %s %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF)
        {
            if(L.id== id)
            {
                fprintf(f2,"%d %s %d %d %d %d %s %s %s %s %s\n",nouvL.id,nouvL.nom_liste,nouvL.d.jour,nouvL.d.mois,nouvL.d.annee,nouvL.orientation,nouvL.municipalite,nouvL.nom_tete_liste,nouvL.candidat_1,nouvL.candidat_2,nouvL.candidat_3);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %d %d %d %d %s %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}

//function pour chercher liste
Liste chercher(char * filename, int id)
{
    Liste L;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf(f,"%d %s %d %d %d %d %s %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF )
        {
            if(L.id==id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
    {
       L.id=-5;
    }
    return L;

}
//function pour verifier
int verifier(char * filename, char nom[])
{
    Liste L;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&&fscanf(f,"%d %s %d %d %d %d %s %s %s %s %s\n",&L.id,L.nom_liste,&L.d.jour,&L.d.mois,&L.d.annee,&L.orientation,L.municipalite,L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3)!=EOF )
        {
            if(strcmp(L.nom_liste,nom)==0)
                tr=1;
        }
    }
    fclose(f);
    return tr;
}
//statistique nombre de vote de chaque liste
int nbv(char * filename,int id)
{
    int nbr_vote=0;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            if(L.vote==id&&L.vote!=0&&L.vote!=-1)
                nbr_vote++;
        }
    }
    fclose(f);
    return nbr_vote;
}

//remplir tab nbr de vote et id liste
void remplirtab(char * filename,char * filename2,Lorder tab[],int *n)
{
    int i,j,k,p;
    Liste Li;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen(filename2, "r");
    if(f!=NULL&&f2!=NULL)
    {
        //ajouter les id dans un tableau
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            //ajouter dans le tableau les id de liste et eliminer le vote blanc
            if(L.vote!=0&&L.vote!=-1)
            {
                tab[*n].idListe=L.vote;
                (*n)++;
            }
        }
        //pour simplifier le tableau est supp l'occurence de lid liste
        for (i=0; i<(*n); i++)
        {
            for (j=i+1; j<(*n);)
            {
                if (tab[j].idListe==tab[i].idListe)
                {
                    for (k=j; k<(*n); k++)
                    {
                        tab[k].idListe=tab[k+1].idListe;
                    }
                    (*n)--;
                }
                else
                    j++;
            }
            //ajouter les nbr de vote dans un tableau
            tab[i].NbrVote=nbv("user.txt",tab[i].idListe);
        }
        //pour ajouter ne nom de la liste
        while(fscanf(f2,"%d %s %d %d %d %d %s %s %s %s %s\n",&Li.id,Li.nom_liste,&Li.d.jour,&Li.d.mois,&Li.d.annee,&Li.orientation,Li.municipalite,Li.nom_tete_liste,Li.candidat_1,Li.candidat_2,Li.candidat_3)!=EOF)
        {
            for(i=0; i<(*n); i++)
            {
                if(tab[i].idListe==Li.id)
                {
                    strcpy(tab[i].nomListe,Li.nom_liste);
                }
            }
        }
    }
    fclose(f);
    fclose(f2);
}

//function pour print and trier le tableau dans un fichier
void printTab(Lorder tab[],int *n)
{
    int i,j,min;
    Lorder tompon;
    utilisateur L;
    FILE * f2=fopen("printTab.txt", "w");
    //tri par selection comparer
    for(i=0; i<(*n); i++)
    {
        min=i;
        for(j=i+1; j<(*n); j++)
        {
            if(tab[j].NbrVote>tab[min].NbrVote)
            {
                min=j;
            }
        }
        tompon=tab[i];
        tab[i]=tab[min];
        tab[min]=tompon;
    }
    if(f2!=NULL)
    {
        //print tab dans un fichier printtab
        for(i=0; i<(*n); i++)
        {
            fprintf(f2,"%s %d %d\n",tab[i].nomListe,tab[i].idListe,tab[i].NbrVote);
        }

        fclose(f2);
    }
}

//function connexion
int connexion(int login,int pass)
{
    utilisateur L;
    int role =-1;
    FILE * f=fopen("user.txt", "r");
     FILE * f2=fopen("connected.txt", "w");


    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            if(L.CIN==login && L.Nempreinte==pass)
            {
                role=L.role;
            }
        }
        if(role!=-1){
             fprintf(f2,"%d\n",login);
        }
    }

    fclose(f);
    fclose(f2);
    return role;
}

*/




