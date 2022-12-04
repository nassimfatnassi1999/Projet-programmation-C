#include <stdio.h>
#include <string.h>
#include "function.h"
#include <gtk/gtk.h>

enum{
	NAME_LISTE,
	IDL,
	NBR_VOTE,
	COLUMNS

};
//aficher les liste ordre par nbr de vote
void afficher_Liste_ordre(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	int idliste;
	char nomListe[30];
	int nbr_vote;
	store=NULL;
	FILE *f;
	Lorder L;
	store=gtk_tree_view_get_model(liste);

	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("nom_liste", renderer, "text", NAME_LISTE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", IDL, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


	renderer = gtk_cell_renderer_text_new (); 
	column = gtk_tree_view_column_new_with_attributes("nbr_vote", renderer, "text", NBR_VOTE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

 store=gtk_list_store_new (COLUMNS,      G_TYPE_STRING,
	 				 G_TYPE_UINT,
					 G_TYPE_UINT);

	f=fopen("printTab.txt", "r");
	if(f==NULL)
	{
		return;
	}
	else{
	
	while(fscanf(f,"%s %d %d\n",L.nomListe,L.idListe,L.NbrVote)!=EOF)
	{
	gtk_list_store_append (store, &iter); 
	gtk_list_store_set (store,&iter,NAME_LISTE,L.nomListe,IDL,L.idListe,NBR_VOTE,L.NbrVote);
	}
	fclose(f);

	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store)); 
	g_object_unref (store);
	}
	
}
}
//statistique nombre de vote de chaque liste
int nbv(char * filename,char *idc[])
{
    int id=atoi(idc);
    int nbr_vote=0;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %d %d %s %s %d %d %d %d %d %d %d\n",&L.CIN,&L.Nempreinte,&L.Ntelephone,L.nom,L.prenom,&L.d.jour,&L.d.mois,&L.d.annee,&L.municipalite,&L.genre,&L.role,&L.vote)!=EOF)
        {
            if(L.vote==id)
                nbr_vote++;
        }
    }
    fclose(f);
    return nbr_vote;
}
//remplir tab nbr de vote et id liste
void remplirtab(Lorder tab[],int *n)
{
    int i,j,k,p;
    Liste Li;
    utilisateur L;
    FILE * f=fopen("utilisateur.txt", "r");
    FILE * f2=fopen("liste.txt", "r");
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
            tab[i].NbrVote=nbv("liste.txt",tab[i].idListe);
        }
        //pour ajouter ne nom de la liste
        while(fscanf(f2,"%d %s %d %d %d %s %s %s %s %s %s\n",&Li.id,Li.nom_liste,&Li.d.jour,&Li.d.mois,&Li.d.annee,Li.orientation,Li.municipalite,Li.nom_tete_liste,Li.candidat_1,Li.candidat_2,Li.candidat_3)!=EOF)
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
