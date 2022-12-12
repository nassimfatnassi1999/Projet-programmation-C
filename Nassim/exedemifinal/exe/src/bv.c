#ifdef HAVE_CONFIG_H
#include<config.h>
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
#include"bv.h"
  

enum
{
	EIDBV,
	EELC,
	EOBS,
	ESALLE,
	EGOUV,
	EDELG,
	EIDAG,
	COLUMNS,
};


void ajouter_bv(BV bv)
{
	FILE* f=NULL;
	f=fopen("bureauV.txt","a+");
	if(f!=NULL)
	 {
	   fprintf(f,"%s %s %s %s %s %s %s\n",bv.id,bv.capElecteurs,bv.capObservateurs,bv.salle,bv.gouvernorat,bv.delegation,bv.IDagent.idAg);
	   fclose(f);
	 }
}

void filtrerAgentBV()
{int i=0;	
char LCIN[50], LNempreinte[50], LNtelephone[20], Lnom[20], Lprenom[20], Ljour[20], Lmois[20], Lannee[20], Lmunicipalite[20], Lgenre[20], Lrole[50], Lvote[20], chaine[20];
	
	FILE *k=NULL;
	k=fopen("agent.txt","r");
if(k!=NULL)
{while(fscanf(k,"%s \n",chaine)!=EOF)
{i++;}
fclose(k);
}

if(i==0)
{
	FILE *f=NULL;
	FILE *g=NULL;
	f=fopen("utilisateur.txt","r");
	g=fopen("agent.txt","w");

  if(f!=NULL && g!=NULL)
    { 
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",LCIN,LNempreinte,LNtelephone,Lnom,Lprenom,Ljour,Lmois,Lannee,Lmunicipalite,Lgenre,Lrole,Lvote)!=EOF)
	   {
		if(strcmp(Lrole,"agentBureauVote")==0)
		{
		fprintf(g,"%s \n",LCIN);
		}
	   }
fclose(f);
fclose(g);    
    }
}
}



int tableau_agent(char agent[50][50])
{
filtrerAgentBV();
int j=0,filtr=0;
FILE* f=fopen("agent.txt","r");
if(f!=NULL)
   {while(fscanf(f,"%s",agent[j])!=EOF)
      {j++;
      }
   }
fclose(f);
return j;
}



int tableau_delegation(char delegat[50][50],char gouver[30])
{
int d=0;
char gvrn[30];
char delg[30];
FILE* f=fopen("delegation.txt","r");
if(f!=NULL)
   {while(fscanf(f,"%s %s\n",gvrn, delg)!=EOF)
      {if(strcmp(gouver,gvrn)==0)
	{
	strcpy(delegat[d],delg);
        d++;
	}
      }
   }
fclose(f);
return d;
}




void supprimerAgent(char *fichier, char agentbv[])
{   
    char id[50];
    FILE *f=fopen(fichier, "r");
    FILE *f2=fopen("ag.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s\n",id)!=EOF)
        {
            if(strcmp(id,agentbv)!=0)
                fprintf(f2,"%s\n",id);
        }
    }
    fclose(f);
    fclose(f2);
    remove(fichier);
    rename("ag.txt", fichier);
}




void supprimerDelegation(char *fichier, char delegation[])
{   
    char deleg[50],gouver[50];
    FILE *f=fopen(fichier, "r");
    FILE *f2=fopen("del.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s\n",gouver,deleg)!=EOF)
        {
            if(strcmp(deleg,delegation)!=0)
                fprintf(f2,"%s %s\n",gouver,deleg);
        }
    }
    fclose(f);
    fclose(f2);
    remove(fichier);
    rename("del.txt", fichier);
}









void afficher_bv(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


    
    char id[30];
    char capElecteurs[10];
    char capObservateurs[10];
    char salle[10];
    char gouvernorat[30];
    char delegation[30];
    char idAg[50];


	store=NULL;
	FILE* f=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("idbv", renderer, "text", EIDBV , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("elecbv", renderer, "text", EELC, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("obsbv", renderer, "text", EOBS , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("Salle", renderer, "text", ESALLE , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("gouvernorat", renderer, "text", EGOUV , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("delegation", renderer, "text", EDELG , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("idagentbv", renderer, "text", EIDAG , NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("bureauV.txt","r");
	if(f==NULL)
	{return;
	}	
	else 
	{

		f=fopen("bureauV.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s %s \n",id,capElecteurs,capObservateurs,salle,gouvernorat,delegation,idAg)!=EOF)
		{	gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter, EIDBV, id, EELC, capElecteurs, EOBS, capObservateurs,  ESALLE, salle,EGOUV,gouvernorat,EDELG,delegation, EIDAG, idAg,-1);
		}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}



void supprimer_bv(BV bv)
    {   BV bv2;
	FILE *f, *g, *a, *d;
	f=fopen("bureauV.txt","r");
	g=fopen("bureauV2.txt","w");
	if(f==NULL || g==NULL)
	  { return;
	  }
	else
	{ while(fscanf(f,"%s %s %s %s %s %s %s\n",bv2.id,bv2.capElecteurs,bv2.capObservateurs,bv2.salle,bv2.gouvernorat,bv2.delegation,bv2.IDagent.idAg)!=EOF)
	   {
if( strcmp(bv.id,bv2.id)!=0 || strcmp(bv.capElecteurs,bv2.capElecteurs)!=0 || strcmp(bv.capObservateurs,bv2.capObservateurs)!=0 || strcmp(bv.salle,bv2.salle)!=0 ||strcmp(bv.gouvernorat,bv2.gouvernorat)!=0 || strcmp(bv.delegation,bv2.delegation)!=0 ||strcmp(bv.IDagent.idAg,bv2.IDagent.idAg)!=0) 
fprintf(g,"%s %s %s %s %s %s %s\n",bv2.id,bv2.capElecteurs,bv2.capObservateurs,bv2.salle,bv2.gouvernorat,bv2.delegation,bv2.IDagent.idAg);
else {
	a=fopen("agent.txt","a");
	d=fopen("delegation.txt","a");

fprintf(a,"%s\n",bv2.IDagent.idAg);
fprintf(d,"%s %s\n",bv2.gouvernorat,bv2.delegation);
}
	   }
fclose(f);
fclose(g);
fclose(a);
fclose(d);
remove("bureauV.txt");
rename("bureauV2.txt","bureauV.txt");
	}
    }



int supprimer_idbv(char suppI[])
    {   BV bv2;
	FILE *f, *g, *a, *d;
	f=fopen("bureauV.txt","r");
	g=fopen("bureauV2.txt","w");
	a=fopen("agent.txt","a");
	d=fopen("delegation.txt","a");
	int tr=0;
	if(f==NULL || g==NULL)
	  { return;
	  }
	else
	{ while(fscanf(f,"%s %s %s %s %s %s %s\n",bv2.id,bv2.capElecteurs,bv2.capObservateurs,bv2.salle,bv2.gouvernorat,bv2.delegation,bv2.IDagent.idAg)!=EOF)
	   {
if( strcmp(bv2.id,suppI)!=0)
fprintf(g,"%s %s %s %s %s %s %s\n",bv2.id,bv2.capElecteurs,bv2.capObservateurs,bv2.salle,bv2.gouvernorat,bv2.delegation,bv2.IDagent.idAg);
else 
{
fprintf(a,"%s\n",bv2.IDagent.idAg);
fprintf(d,"%s %s\n",bv2.gouvernorat,bv2.delegation);
tr=1;
}
	   }
fclose(f);
fclose(g);
fclose(a);
fclose(d);
remove("bureauV.txt");
rename("bureauV2.txt","bureauV.txt");
	} return tr;
    }




void trierMunicipalite(char *fichier)
{
    int i=0,j,x,permut;
    BV aux;
    BV T[50];
    FILE *f=fopen(fichier, "r");
    FILE *f2=fopen("bv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s\n",T[i].id,T[i].capElecteurs,T[i].capObservateurs,T[i].salle,T[i].gouvernorat,T[i].delegation,T[i].IDagent.idAg)!=EOF)
        {i++;}


       do
	{
	permut=0;
	for(j=0;j<i-1;j++)
	  { x=strcmp(T[j].gouvernorat ,T[j+1].gouvernorat);
	if(x>0)
	   { aux=T[j];
	     T[j]=T[j+1];
	     T[j+1]=aux ;
	     permut=1;
	   }
	  }
	}
       while (permut==1);


    for(j=0; j<i; j++)
    {
      fprintf(f2,"%s %s %s %s %s %s %s\n",T[j].id,T[j].capElecteurs,T[j].capObservateurs,T[j].salle,T[j].gouvernorat,T[j].delegation,T[j].IDagent.idAg);
    }

    fclose(f);
    fclose(f2);
    remove(fichier);
    rename("bv.txt", fichier);
}
}



void trierElecteurs(char *fichier)
{
    int i=0,j,x,permut,elec1,elec2;
    BV aux;
    BV T[50];
    FILE *f=fopen(fichier, "r");
    FILE *f2=fopen("bv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s\n",T[i].id,T[i].capElecteurs,T[i].capObservateurs,T[i].salle,T[i].gouvernorat,T[i].delegation,T[i].IDagent.idAg)!=EOF)
        {i++;}


       do
	{
	permut=0;
	for(j=0;j<i-1;j++)

	  { elec1=atoi(T[j].capElecteurs);
	    elec2=atoi(T[j+1].capElecteurs);
	if(elec1>elec2)
	   { aux=T[j];
	     T[j]=T[j+1];
	     T[j+1]=aux ;
	     permut=1;
	   }
	  }
	}
       while (permut==1);


    for(j=0; j<i; j++)
    {
      fprintf(f2,"%s %s %s %s %s %s %s\n",T[j].id,T[j].capElecteurs,T[j].capObservateurs,T[j].salle,T[j].gouvernorat,T[j].delegation,T[j].IDagent.idAg);
    }

    fclose(f);
    fclose(f2);
    remove(fichier);
    rename("bv.txt", fichier);
}
}



void trierSalle(char *fichier)
{
    int i=0,j,x,permut,elec1,elec2;
    BV aux;
    BV T[50];
    FILE *f=fopen(fichier, "r");
    FILE *f2=fopen("bv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s\n",T[i].id,T[i].capElecteurs,T[i].capObservateurs,T[i].salle,T[i].gouvernorat,T[i].delegation,T[i].IDagent.idAg)!=EOF)
        {i++;}


       do
	{
	permut=0;
	for(j=0;j<i-1;j++)

	  { elec1=atoi(T[j].salle);
	    elec2=atoi(T[j+1].salle);
	if(elec1>elec2)
	   { aux=T[j];
	     T[j]=T[j+1];
	     T[j+1]=aux ;
	     permut=1;
	   }
	  }
	}
       while (permut==1);


    for(j=0; j<i; j++)
    {
      fprintf(f2,"%s %s %s %s %s %s %s\n",T[j].id,T[j].capElecteurs,T[j].capObservateurs,T[j].salle,T[j].gouvernorat,T[j].delegation,T[j].IDagent.idAg);
    }

    fclose(f);
    fclose(f2);
    remove(fichier);
    rename("bv.txt", fichier);
}
}























