#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "function.h"
#include <gtk/gtk.h>



enum
{
ECIN,
EPASSWORD,
ENUMTELEPHONE,
ENOM,
EPRENOM,
EMUNICIPALITE,
EROLE,
ESEXE,
EVOTE,
EJOUR,
EMOIS,
EANNEE,
COLUMNS,
};



//function pour ajouter utilisateur
int ajouterUtilisateur(char * filename, utilisateur L)
{

    FILE * f=fopen(filename,"a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role,"-1");
        fclose(f);
        return 1;
    }
    else
        return 0;
}
           
// controle de saisir sur cin len== 8 && composer de 8 chiffre



//function pour chercher personne 
int verifUtilisateur(char * filename, char nom[], char prenom[])
{
    utilisateur L;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 &&fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d
.annee,L.municipalite,L.genre,L.role,L.vote)!=EOF)
        {
            if((strcmp(L.CIN,nom)==0)&&(strcmp(L.Nempreinte,prenom)==0))
		{tr=1;}	// login et psw vraie
            else if((strcmp(L.CIN,nom)==0)&&(strcmp(L.Nempreinte,prenom)!=0))
		{tr=2;}	// login vraie et psw faux 
           /* else if((strcmp(L.CIN,nom)!=0)&&(strcmp(L.Nempreinte,prenom)==0))
		{tr=3;} // login faux et psw vraie
	    else if((strcmp(L.CIN,nom)!=0)&&(strcmp(L.Nempreinte,prenom)!=0))
		{tr=4;} // login faux et psw faux */      

        }
    }
    fclose(f);
    
    return tr;

}










void afficher_USERtreeview(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;



char CIN[50];
char Nempreinte[50];
char Ntelephone[50];
char nom[50];
char prenom[50];
char municipalite[50];
char role[50];
char genre[50];
char vote[50];
char jour[5];
char mois[5];
char annee[5];
 


store=NULL;
FILE* f=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cin", renderer, "text", ECIN , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("password", renderer, "text", EPASSWORD, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("numeroTelephone", renderer, "text", ENUMTELEPHONE , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nom", renderer, "text", ENOM , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", EPRENOM , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("municipalite", renderer, "text", EMUNICIPALITE , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("role", renderer, "text", EROLE , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe", renderer, "text", ESEXE , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("vote", renderer, "text", EVOTE , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE , NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("utilisateur.txt","r");
if(f==NULL)
{return;
}
else
{

f=fopen("utilisateur.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",CIN,Nempreinte,Ntelephone,nom,prenom,jour,mois,annee,municipalite,genre,role,vote)!=EOF)
{ gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,ECIN,CIN,EPASSWORD,Nempreinte,ENUMTELEPHONE,Ntelephone,ENOM,nom,EPRENOM,prenom,EMUNICIPALITE,municipalite,EROLE,role,ESEXE,genre,EVOTE,vote,EJOUR,jour,EMOIS,mois,EANNEE,annee,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}








//////////////////////////////////////
void supprimer_USERtreev(utilisateur L)
{
	utilisateur L2;
	FILE *f, *g;
	f=fopen("utilisateur.txt","r");
	g=fopen("utilisateur2.txt","w");
	if(f==NULL || g==NULL){ return;}
	else{ while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L2.CIN,L2.Nempreinte,L2.Ntelephone,L2.nom,L2.prenom,L2.d.jour,L2.d.mois,L2.d
.annee,L2.municipalite,L2.genre,L2.role,L2.vote)!=EOF)
  	{
	if(strcmp(L2.CIN,L.CIN)!=0 || strcmp(L2.Nempreinte,L.Nempreinte)!=0 || strcmp(L2.Ntelephone,L.Ntelephone)!=0 || strcmp(L2.nom,L.nom)!=0 || strcmp(L2.prenom,L.prenom)!=0 || strcmp(L2.d.jour,L.d.jour)!=0 || strcmp(L2.d.mois,L.d.mois)!=0 || strcmp(L2.d.annee,L.d.annee)!=0 || strcmp(L2.municipalite,L.municipalite)!=0 || strcmp(L2.genre,L.genre)!=0 || strcmp(L2.role,L.role)!=0 || strcmp(L2.vote,L.vote)!=0 )
		fprintf(g,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L2.CIN,L2.Nempreinte,L2.Ntelephone,L2.nom,L2.prenom,L2.d.jour,L2.d.mois,L2.d
.annee,L2.municipalite,L2.genre,L2.role,L2.vote);

	  }

	fclose(f);
	fclose(g);

	remove("utilisateur.txt");
	rename("utilisateur2.txt","utilisateur.txt");
	}
}







//function pour chercher utilisateur
utilisateur chercherUtilisateur(char * filename, char CIN[])
{
    utilisateur L;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role,L.vote)!=EOF)
        {
            if(strcmp(L.CIN,CIN)==0)
                tr=1;

        }
    }
    fclose(f);
    if(tr==0){strcpy(L.CIN,"-1");}
    return L;

}






//function pour modifier utilisateur
int modifierUtilisateur( char * filename,char CIN[],utilisateur nouvL )
{
    int tr=0;
    utilisateur L;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt","w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role,L.vote)!=EOF)
        {
            if(strcmp(L.CIN,CIN)==0)
            {
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",nouvL.CIN,nouvL.Nempreinte,nouvL.Ntelephone,nouvL.nom,nouvL.prenom,nouvL.d.jour,nouvL.d.mois,nouvL.d.annee,nouvL.municipalite,nouvL.genre,nouvL.role,L.vote);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s\n",L.CIN,L.Nempreinte,L.Ntelephone,L.nom,L.prenom,L.d.jour,L.d.mois,L.d.annee,L.municipalite,L.genre,L.role,L.vote);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt",filename);
    return tr;

}



