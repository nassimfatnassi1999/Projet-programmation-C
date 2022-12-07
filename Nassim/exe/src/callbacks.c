#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"function.h" //nassim
#include"election.h" //seif
#include"bv.h"	     //chaima
#include"user.h"   //mohamed
int genre=2;
int genreMODIFIER=2;
char PCIN[50];
int cons=22;
int consm=22;
election em;
Lorder tab[20];
int n=0;
int x=3;
int y=1;
Liste LM; //utilser dans la btn chercher pour passer enn param ala btn modifier

void
on_radiobtn_M_G_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_radiobtn_M_C_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_radiobtn_M_D_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=3;}
}


void
on_radio_btn_G_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radio_btn_C_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radio_btn_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=3;}
}

//button ajouter dans gestion Liste pour passer a la fenetre d'Ajout
void
on_btn_Ajouter_Nassim_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"GestionListeElectorale");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_AjouterListe();
	gtk_widget_show (ajouter);
}

//button pour ajouter une liste electorale 
void
on_btn_Ajouter_Liste_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	GtkWidget* inputNom ;//nom de la liste
	GtkWidget* Jour; //spinbuttun pour le choix du jour.
	GtkWidget* Mois; //spinbuttun pour Le choix du mois.
	GtkWidget* Annee; //spinbuttun pour le choix de l'année.
	GtkWidget* ComboboxM; //comobox pour Le choix de la municipalité.
	GtkWidget* cinTeteListe ;
	GtkWidget* cinC1 ;
	GtkWidget* cinC2 ;
	GtkWidget* cinC3 ;
	GtkWidget* output;
//declarer la struct qui ajouter
        Liste L;
	int verifiA=-1;
// associer les objets avec des variables
	inputNom = lookup_widget(button,"entryNomListe") ;
	Jour = lookup_widget(button,"spinJourListe") ;
	Mois = lookup_widget(button,"spinMoisListe") ;
	Annee = lookup_widget(button,"spinAnneeListe") ;
	ComboboxM = lookup_widget(button,"combobox_nassim") ;
	cinTeteListe = lookup_widget(button,"entryCinTete") ;
	cinC1 = lookup_widget(button,"entryCinC1") ;
	cinC2 = lookup_widget(button,"entryCinC2") ;
	cinC3 = lookup_widget(button,"entryCinC3") ;
	output = lookup_widget(button,"labelVerif") ;
// récupérer les valeurs des spin buttons 
	strcpy(L.nom_liste,gtk_entry_get_text(GTK_ENTRY(inputNom)));
	L.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	L.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
	L.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
//récupérer les valeur de radiobutton
	if(x==1)
	{
	 strcpy(L.orientation,"Gauche");
	}
	else if(x==2)
	{
	 strcpy(L.orientation,"Centre");
	}
	else if(x==3)
	{
	 strcpy(L.orientation,"Droite");
	}
//recupérer lcombo
	strcpy(L.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (ComboboxM)));
// récupérer les valeurs de champ txt 
	strcpy(L.nom_tete_liste,gtk_entry_get_text(GTK_ENTRY(cinTeteListe)));
	strcpy(L.candidat_1,gtk_entry_get_text(GTK_ENTRY(cinC1)));
	strcpy(L.candidat_2,gtk_entry_get_text(GTK_ENTRY(cinC2)));
	strcpy(L.candidat_3,gtk_entry_get_text(GTK_ENTRY(cinC3)));
//appel de la function ajouter
	   verifiA=verifier(L.nom_tete_liste,L.candidat_1,L.candidat_2,L.candidat_3);

	if(verifiA!=1){
		        ajouterListe(L);
			//traja3ni ltree view 
			GtkWidget *ajouter101;
			GtkWidget *destroy101;
			destroy101=lookup_widget(button,"AjouterListe");
			gtk_widget_destroy(destroy101);
			ajouter101=create_GestionListeElectorale();
			gtk_widget_show (ajouter101);

	}
	else{
		GdkColor color;
		gdk_color_parse("red",&color);
		gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(output),"L'un des candidats existe deja dans une Liste !!");
	}
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *id;
gchar *nomliste;
gchar *Jour;
gchar *Mois;
gchar *Annee;
gchar* orienta;
gchar* muni;
gchar* cinT;
gchar* cinc1;
gchar* cinc2;
gchar* cinc3;
Liste L;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path)){
//obtention des valeurs de la ligne selectionnee
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nomliste, 2, &Jour, 3, &Mois, 4, &Annee, 5, &orienta, 6, &muni, 7, &cinT, 8, &cinc1, 9, &cinc2, 10, &cinc3, -1);
// copte des valeurs dans la variable p de type personne pour le passer a la fonction de suppression
	L.id=id;
	strcpy (L.nom_liste,nomliste);
	L.d.jour=Jour;
	L.d.mois=Mois;
	L.d.annee=Annee;
	strcpy (L.orientation,orienta);
	strcpy (L.municipalite,muni);
	strcpy (L.nom_tete_liste,cinT);
	strcpy (L.candidat_1,cinc1);
	strcpy (L.candidat_2,cinc2);
	strcpy (L.candidat_3,cinc3);
	
//appel de la fonction de suppression
	supprimer_Liste(L);
// mise a jour de l'affichage de la treeview
	afficher_Liste(treeview);
}
	//MiseAjourIdListe("liste.txt",&L);
}

//button Afficher dana GL pour afficher les element dans le treeview
void
on_btn_Afficher_Tree_Liste_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_Nassim;
GtkWidget *afficher_u;
afficher_u=lookup_widget(button,"GestionListeElectorale");
treeview_Nassim=lookup_widget(afficher_u,"treeview1");
afficher_Liste(treeview_Nassim);
}

//button Modifier dans gestion Liste pour passer a la fenetre de Modifier
void
on_btn_Modifier_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"GestionListeElectorale");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_windowModifierListe();
	gtk_widget_show (ajouter);
}

//button Retour dana la fenetre modifier pour revenir a la fenetre GL
void
on_btn_retour_modifier_nassim_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"windowModifierListe");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_GestionListeElectorale();
	gtk_widget_show (ajouter);
}

//button Retour dana la fenetre Ajouter pour revenir a la fenetre GL
void
on_btn_Retour_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"AjouterListe");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_GestionListeElectorale();
	gtk_widget_show (ajouter);
}

//button verifier pour verifier l'un des candidats existe dans une autre liste ou nn
void
on_btn_Verifier_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* cinTeteListe ;
	GtkWidget* cinC1 ;
	GtkWidget* cinC2 ;
	GtkWidget* cinC3 ;
	GtkWidget* output;
//declarer la struct qui ajouter
        char CT[10],C1[10],C2[10],C3[10];
	int veri;	
// associer les objets avec des variables
	cinTeteListe = lookup_widget(button,"entryCinTete") ;
	cinC1 = lookup_widget(button,"entryCinC1") ;
	cinC2 = lookup_widget(button,"entryCinC2") ;
	cinC3 = lookup_widget(button,"entryCinC3") ;
	output = lookup_widget(button,"labelVerif") ;
// récupérer les valeurs de champ txt 
	strcpy(CT,gtk_entry_get_text(GTK_ENTRY(cinTeteListe)));
	strcpy(C1,gtk_entry_get_text(GTK_ENTRY(cinC1)));
	strcpy(C2,gtk_entry_get_text(GTK_ENTRY(cinC2)));
	strcpy(C3,gtk_entry_get_text(GTK_ENTRY(cinC3)));
//appel function verif
	 veri=verifier(CT,C1,C2,C3);
	if(veri==1)
	{
		GdkColor color;
		gdk_color_parse("red",&color);
		gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(output),"L'un des candidats existe deja dans une Liste !!");
	}
	else
	{
		GdkColor color;
		gdk_color_parse("green",&color);
		gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(output),"Vous pouvez maintenant ajouter la Liste");
	}
}


void
on_btn_M_chercher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;//id a chercher
	  GtkWidget* output;
	  GtkWidget* SJ;
	  GtkWidget* SM;
	  GtkWidget* SA;
          GtkWidget* COX;
	  GtkWidget* outputEr;
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"entry_M_id") ;
//declarer 
        char idch[10];
	int idint=atoi(idch);
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//appel function chercher
	LM=chercher(idch);
	if(LM.id!=-1){
         output=lookup_widget(button,"entry_M_nom");
         gtk_entry_set_text(GTK_ENTRY(output),LM.nom_liste);
//*************************************
	 GtkSpinButton *SJ=lookup_widget(button, "spinbtn_M_J");
         gtk_spin_button_set_value(SJ,LM.d.jour);
	 GtkSpinButton *SM=lookup_widget(button, "spinbtn_M_M");
         gtk_spin_button_set_value(SM,LM.d.mois);
	 GtkSpinButton *SA=lookup_widget(button, "spinbtn_M_A");
         gtk_spin_button_set_value(SA,LM.d.annee);
//*************************************
	COX=lookup_widget(button,"cobox_M_muni");
Liste Li;
int i=-1;
int tr=0;
int trouve=0;
char gouv[20];
     	FILE *g=fopen("liste.txt","r");
while(!tr && fscanf(g,"%d %s %d %d %d %s %s %s %s %s %s\n",&Li.id,Li.nom_liste,&Li.d.jour,&Li.d.mois,&Li.d.annee,Li.orientation,Li.municipalite,Li.nom_tete_liste,Li.candidat_1,Li.candidat_2,Li.candidat_3)!=EOF)
	{
	if(idint==Li.id)
	  { tr=1;   //condition d'arret
	  }
	}
	fclose(g);

	/*if(tr==0)
	{gtk_label_set_text(GTK_LABEL(alert),"identifiant non trouvé !");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(alert),"");*/
	
	//traitement gouv
	FILE *f=fopen("gouvernorat.txt","r");
	while(!trouve && fscanf(f,"%s \n",gouv)!=EOF)
	   {i++; 
	    if(strcmp(gouv,Li.municipalite)==0)
	    trouve=1;   //condition d'arret
	   }
	gtk_combo_box_set_active(GTK_COMBO_BOX(COX),i);
//*************************************
	/* 
	 if(strcmp(LM.municipalite,"Tunis")){
         	gtk_combo_box_set_active(COX,2);}
	 else if(strcmp(LM.municipalite,"Beja")){
         	gtk_combo_box_set_active(COX,1);}
	 else if(strcmp(LM.municipalite,"Sousse")){
         	gtk_combo_box_set_active(COX,3);}*/
//*************************************
	 output=lookup_widget(button,"entry_M_cinT");
         gtk_entry_set_text(GTK_ENTRY(output),LM.nom_tete_liste);
	 output=lookup_widget(button,"entry_M_cinc1");
         gtk_entry_set_text(GTK_ENTRY(output),LM.candidat_1);
	 output=lookup_widget(button,"entry_M_cinc2");
         gtk_entry_set_text(GTK_ENTRY(output),LM.candidat_2);
	 output=lookup_widget(button,"entry_M_cinc3");
         gtk_entry_set_text(GTK_ENTRY(output),LM.candidat_3);

}
	else{
	 	
		///
	}
}




void
on_btn_M_Modifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;//id 
	  GtkWidget* output;
	  GtkWidget* SJ;
	  GtkWidget* SM;
	  GtkWidget* SA;
          GtkWidget* COX;
	  GtkWidget* outputEr;
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"entry_M_id") ;
//declarer 
        char idch[10];
	int idIN;
	Liste nouvL;
	int test;
	int xv;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//convert txtentry to int 
	idIN=atoi(idch);
	nouvL.id=idIN;
	GtkWidget* inputNom ;//nom de la liste
	GtkWidget* Jour; //spinbuttun pour le choix du jour.
	GtkWidget* Mois; //spinbuttun pour Le choix du mois.
	GtkWidget* Annee; //spinbuttun pour le choix de l'année.
	GtkWidget* ComboboxM; //comobox pour Le choix de la municipalité.
	GtkWidget* cinTeteListe ;
	GtkWidget* cinC1 ;
	GtkWidget* cinC2 ;
	GtkWidget* cinC3 ;
	GtkWidget* outputEM ;

// associer les objets avec des variables
	inputNom = lookup_widget(button,"entry_M_nom") ;
	Jour = lookup_widget(button,"spinbtn_M_J") ;
	Mois = lookup_widget(button,"spinbtn_M_M") ;
	Annee = lookup_widget(button,"spinbtn_M_A") ;
	ComboboxM = lookup_widget(button,"cobox_M_muni") ;
	cinTeteListe = lookup_widget(button,"entry_M_cinT") ;
	cinC1 = lookup_widget(button,"entry_M_cinc1") ;
	cinC2 = lookup_widget(button,"entry_M_cinc2") ;
	cinC3 = lookup_widget(button,"entry_M_cinc3") ;
	outputEM = lookup_widget(button,"labelER_M") ;
// récupérer les valeurs des spin buttons 
	strcpy(nouvL.nom_liste,gtk_entry_get_text(GTK_ENTRY(inputNom)));
	nouvL.d.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	nouvL.d.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
	nouvL.d.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
//récupérer les valeur de radiobutton
	if(y==1)
	{
	 strcpy(nouvL.orientation,"Gauche");
	}
	if(y==2)
	{
	 strcpy(nouvL.orientation,"Centre");
	}
	if(y==3)
	{
	 strcpy(nouvL.orientation,"Droite");
	}
//recupérer lcombo
	strcpy(nouvL.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (ComboboxM)));
// récupérer les valeurs de champ txt 
	strcpy(nouvL.nom_tete_liste,gtk_entry_get_text(GTK_ENTRY(cinTeteListe)));
	strcpy(nouvL.candidat_1,gtk_entry_get_text(GTK_ENTRY(cinC1)));
	strcpy(nouvL.candidat_2,gtk_entry_get_text(GTK_ENTRY(cinC2)));
	strcpy(nouvL.candidat_3,gtk_entry_get_text(GTK_ENTRY(cinC3)));

		//appel function modifier
	        test=modifierListe("liste.txt",idIN,nouvL);
		if(test==1){
		 //traja3ni ltree view 
			GtkWidget *ajouter;
			GtkWidget *afficher_Nassim;
			afficher_Nassim=lookup_widget(button,"windowModifierListe");
			gtk_widget_destroy(afficher_Nassim);
			ajouter=create_GestionListeElectorale();
			gtk_widget_show (ajouter);	
		}
		else{
			GdkColor color;
		        gdk_color_parse("red",&color);
		        gtk_widget_modify_fg(outputEM,GTK_STATE_NORMAL,&color);
		        gtk_label_set_text(GTK_LABEL(outputEM),"Oups echec modification !!");
			
		    }


}


void
on_btn_stat_Nassim_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ajouter;
	GtkWidget *afficher_Nassim;
	afficher_Nassim=lookup_widget(button,"Statistique");
	gtk_widget_destroy(afficher_Nassim);
	ajouter=create_Stat_Liste_Nassim();
	gtk_widget_show (ajouter);
}


void
on_btn_calc_NBV_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;//id a chercher
	  GtkWidget* output;
//declarer des variables
	int result;
	char idch[10]; 
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"entry_idL_nbr") ;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//appel function nbv
	result=nbv(idch);
	char resch[20];
sprintf(resch,"%d",result);
//*************************************
	/* GdkColor color;
         gdk_color_parse("green",&color);
 	 gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);*/
	 output=lookup_widget(button,"label_R_NBR");
	 gtk_label_set_text(GTK_LABEL(output),resch);


}


void
on_treeviewNBRV_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
GtkWidget *treeview_Nassim;
gchar *nomliste;
gchar *id;
gchar *nbvote;
Liste L;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path)){
//obtention des valeurs de la ligne selectionnee
	gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &nomliste, 1, &id, 2, &nbvote,-1);

// mise a jour de l'affichage de la treeview
	afficher_Liste_ordre(treeview);
}
}


void
on_btn_actualiser_TreeNBRV_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	
	// printTab(tab,&n);//fonction pour print les liste et nbr de vote 

	 //remplirtab(tab,&n);//les listes selon nbr de votes
 //laffichage de etreeview
GtkWidget *treeview_Nassim;
GtkWidget *afficher_u;
afficher_u=lookup_widget(button,"Stat_Liste_Nassim");
treeview_Nassim=lookup_widget(afficher_u,"treeviewNBRV");
afficher_Liste_ordre(treeview_Nassim);
}

void
on_btn_QUITTER_A_N_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}






/////////////////////////////////////////// Interface BUreau de Vote -CHAIMA MATOUSSI- /////////////////////////////////////////////////////





int salle=2;
checkModif=0;
BV bvModif;

void
on_afficherbv_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(objet,"ajoutBV");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(objet,"afficherBV");
	affiche=create_afficherBV();
	
	gtk_widget_show(affiche);
	
	treeview=lookup_widget(affiche,"treeviewBV");
	afficher_bv(treeview);
	
}




void
on_ajouterbv_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	BV bv;
	char sallebv[10];
	char cE[10];
	char cO[10];
	char agentbv[50];
	int a,b,erreur=0;

	sprintf(sallebv,"%d",salle);

	GtkWidget *id, *capElec, *capObserv, *gouv, *deleg, *idAg, *alert;
	GtkWidget *ajoutBV;
	GtkWidget *alertnidbv,*labelngouv,*labelndelg;
	

	ajoutBV=lookup_widget(objet,"ajoutBV");
	id=lookup_widget(objet,"idbv");
	capElec=lookup_widget(objet,"elecbv");
	capObserv=lookup_widget(objet,"obsbv");
	gouv=lookup_widget(objet,"gouvernoratajbv");
	deleg=lookup_widget(objet,"delegation");
	idAg=lookup_widget(objet,"idagentbv");
	alert=lookup_widget(objet,"alertajbv");
	alertnidbv=lookup_widget(objet,"alertnidbv");
	labelngouv=lookup_widget(objet,"labelngouv");
	labelndelg=lookup_widget(objet,"labelndelg");

	strcpy(bv.id,gtk_entry_get_text(GTK_ENTRY(id)));
	a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capElec));
	b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capObserv));
	sprintf(cE,"%d",a);
	sprintf(cO,"%d",b);
	strcpy(bv.capElecteurs,cE);
	strcpy(bv.capObservateurs,cO);
	strcpy(bv.gouvernorat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouv)));
	strcpy(bv.delegation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(deleg)));
	strcpy(bv.IDagent.idAg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idAg)));
	strcpy(bv.salle,sallebv);


	/*if(strlen(bv.IDagent.idAg)!=4)
	{gtk_label_set_text(GTK_LABEL(alertnidbv),"L'identifiant doit contenir 4 caractéres");
	erreur=1;
	}
	else{
	erreur=0;
	}
//
	if(strlen(bv.gouvernorat)==0) 
	{gtk_label_set_text(GTK_LABEL(labelngouv),"Vous devez choisir un gouvernorat");
	erreur=1;	
	}
	else
	{erreur=0;
	}

	 if(strlen(bv.delegation)==0) 
	{gtk_label_set_text(GTK_LABEL(labelndelg),"Vous devez choisir une delegation");
	erreur=1;
	}
	else{
	erreur=0;
	}
*/
	if(erreur==1)
	{
	gtk_label_set_text(GTK_LABEL(alert),"Vous devez remplir tout les champs");
	}
	else
	{
	
	ajouter_bv(bv);
	supprimerAgent("agent.txt", bv.IDagent.idAg);
	supprimerDelegation("delegation.txt", bv.delegation);
	


	gtk_widget_destroy(ajoutBV);

	ajoutBV=create_ajoutBV();
	
	gtk_widget_show(ajoutBV);

	gtk_label_set_text(GTK_LABEL(alert),"Opération Réussie");
}
}






void
on_retourbv_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout, *affiche;
affiche=lookup_widget(objet,"afficherBV");

gtk_widget_destroy(affiche);
ajout=create_ajoutBV();
gtk_widget_show(ajout);
}




void
on_bt_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{int i,n,m;
BV bv;
char agent[50][50],delegat[50][50],gouver[30];
GtkWidget *idagentbv,*delegation,*gouvernorat;
idagentbv=lookup_widget(objet,"idagentbv");
delegation=lookup_widget(objet,"delegation");
gouvernorat=lookup_widget(objet,"gouvernoratajbv");
n=tableau_agent(agent);

for(i=0;i<n;i++)
{gtk_combo_box_append_text(GTK_COMBO_BOX(idagentbv),_(agent[i]));
}

strcpy(gouver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouvernorat)));
m=tableau_delegation(delegat, gouver);
for(i=0;i<m;i++)
{gtk_combo_box_append_text(GTK_COMBO_BOX(delegation),_(delegat[i]));
}
}







void
on_salle3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle=3;
}


void
on_salle2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle=2;
}


void
on_salle1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
salle=1;
}


void
on_treeviewBV_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* capElecteurs;
	gchar* capObservateurs;
	gchar* salle;
	gchar* gouvernorat;
	gchar* delegation;
	gchar* idAg;

	BV bv;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{ 
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &capElecteurs, 2, &capObservateurs, 3, &salle, 4, &gouvernorat, 5, &delegation, 6, &idAg, -1);
	strcpy(bv.id,id);
	strcpy(bv.capElecteurs,capElecteurs);
	strcpy(bv.capObservateurs,capObservateurs);
	strcpy(bv.salle,salle);
	strcpy(bv.gouvernorat,gouvernorat);
	strcpy(bv.delegation,delegation);
	strcpy(bv.IDagent.idAg,idAg);

	supprimer_bv(bv);

	afficher_bv(treeview);

	 
	}
}


void
on_supprimerbv_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *affiche, *supprimer,*treeview;

	affiche=lookup_widget(objet,"afficherBV");
	gtk_widget_destroy(affiche);

	supprimer=lookup_widget(objet,"supprimerbuv");
	supprimer=create_supprimerbuv();
	
	gtk_widget_show(supprimer);
	treeview=lookup_widget(supprimer,"treeview2BV");
	afficher_bv(treeview);
	
}


void
on_retouraffichebv_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *affiche, *supprimer, *treeview;
supprimer=lookup_widget(objet,"supprimerbuv");

gtk_widget_destroy(supprimer);
affiche=create_afficherBV();
gtk_widget_show(affiche);
	treeview=lookup_widget(affiche,"treeviewBV");
	afficher_bv(treeview);

}


void
on_supprimerfinal_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{char suppI[20],gouvSup[30],delegt[30],idagn[20];
int t;
	GtkWidget *idsupp,*alertsupp,*supprimerbuv;
	GtkWidget *treeview;

	supprimerbuv=lookup_widget(objet,"supprimerbuv");
	idsupp=lookup_widget(objet,"supprimerbvid");
	alertsupp=lookup_widget(objet,"alertsupp");
	strcpy(suppI,gtk_entry_get_text(GTK_ENTRY(idsupp)));


	t=supprimer_idbv(suppI);
if(t==1)
{
	gtk_label_set_text(GTK_LABEL(alertsupp),"Opération Réussie");
	

}
else
{
	gtk_label_set_text(GTK_LABEL(alertsupp),"identifiant non trouvé !");
}


	treeview=lookup_widget(supprimerbuv,"treeview2BV");
	afficher_bv(treeview);

}


void
on_quitterbv_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{gtk_main_quit();

}


void
on_rechercherBV_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
	{ 
	char idrech[20];
	char gouv[20];
	BV bv;
	int i=-1, trouve=0,tr=0 , capE=0, capO=0;
	GtkWidget *idbvv, *gouvernoratv, *delegationv, *idagentbvv, *alert, *elecbvv, *obsbvv, *radio1, *radio2, *radio3;


	idbvv=lookup_widget(objet, "idbvv");
	gouvernoratv=lookup_widget(objet, "gouvernoratv");
	delegationv=lookup_widget(objet, "delegationv");
	idagentbvv=lookup_widget(objet, "idagentbvv");
	alert=lookup_widget(objet, "alertRech");
	elecbvv=lookup_widget(objet, "elecbvv");
	obsbvv=lookup_widget(objet, "obsbvv");
	radio1=lookup_widget(objet, "radio1");
	radio2=lookup_widget(objet, "radio2");
	radio3=lookup_widget(objet, "radio3");

	strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(idbvv)));

	FILE *g=fopen("bureauV.txt","r");
while(!tr && fscanf(g,"%s %s %s %s %s %s %s\n",bv.id,bv.capElecteurs,bv.capObservateurs,bv.salle,bv.gouvernorat,bv.delegation,bv.IDagent.idAg)!=EOF)
	{
	if(strcmp(idrech,bv.id)==0)
	  { tr=1;   //condition d'arret
	  }
	}
	fclose(g);

	if(tr==0)
	{gtk_label_set_text(GTK_LABEL(alert),"identifiant non trouvé !");
	}
	else
	{
	gtk_label_set_text(GTK_LABEL(alert),"");
	bvModif=bv;
	//traitement gouv
	FILE *f=fopen("gouvernorat.txt","r");
	while(!trouve && fscanf(f,"%s \n",gouv)!=EOF)
	   {i++; 
	    if(strcmp(gouv,bv.gouvernorat)==0)
	    trouve=1;   //condition d'arret
	   }
	gtk_combo_box_set_active(GTK_COMBO_BOX(gouvernoratv),i);


	//traitement electeur
	capE=atoi(bv.capElecteurs);
	gtk_spin_button_set_value(elecbvv,capE);


	//traitement observateur
	capO=atoi(bv.capObservateurs);
	gtk_spin_button_set_value(obsbvv,capO);


	//traitement salle
	if(strcmp(bv.salle,"1")==0)
	{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radio1),TRUE);
	}
	else if(strcmp(bv.salle,"2")==0)
	{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radio2),TRUE);
	}
	else if(strcmp(bv.salle,"3")==0)
	{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(radio3),TRUE);
	}


	fclose(f);
	}

	
          

}


void
on_affTomod_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
	{GtkWidget *afficherBV, *modifierBV;
	afficherBV=lookup_widget(objet,"afficherBV");

	gtk_widget_destroy(afficherBV);
	modifierBV=lookup_widget(objet,"modifierBV");
	modifierBV=create_modifierBV();
	
	gtk_widget_show(modifierBV);
	
	}


void
on_modToaff_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
	{GtkWidget *afficherBV, *modifierBV ,*treeview;
	modifierBV=lookup_widget(objet,"modifierBV");

	gtk_widget_destroy(modifierBV);
	afficherBV=lookup_widget(objet,"afficherBV");
	afficherBV=create_afficherBV();
	
	gtk_widget_show(afficherBV);
	treeview=lookup_widget(afficherBV,"treeviewBV");
	afficher_bv(treeview);

	}


void
on_trierBVMunic_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview, *afficherBV;
	trierMunicipalite("bureauV.txt");
	afficherBV=lookup_widget(objet,"afficherBV");
	treeview=lookup_widget(afficherBV,"treeviewBV");
	afficher_bv(treeview);
}


void
on_deleg_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data)
{int i,n,m;
BV bv;
char agent[50][50],delegat[50][50],gouver[30];
GtkWidget *idagentbv,*delegation,*gouvernorat;
idagentbv=lookup_widget(objet,"idagentbvv");
delegation=lookup_widget(objet,"delegationv");
gouvernorat=lookup_widget(objet,"gouvernoratv");
n=tableau_agent(agent);

for(i=0;i<n;i++)
{gtk_combo_box_append_text(GTK_COMBO_BOX(idagentbv),_(agent[i]));
}

strcpy(gouver,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouvernorat)));
m=tableau_delegation(delegat, gouver);
for(i=0;i<m;i++)
{gtk_combo_box_append_text(GTK_COMBO_BOX(delegation),_(delegat[i]));
}
}

void
on_confirmAjout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
BV bv,bv2;
	char sallebv[10];
	char cE[10];
	char cO[10];
	char agentbv[50];
	int a,b,erreur=0;

	sprintf(sallebv,"%d",salle);

	GtkWidget *id, *capElec, *capObserv, *gouv, *deleg, *idAg, *alertCheck;
	GtkWidget *modifierBV;
	GtkWidget *alertnidbv,*labelngouv,*labelndelg;
	

	modifierBV=lookup_widget(objet,"modifierBV");
	id=lookup_widget(objet,"idbvv");
	capElec=lookup_widget(objet,"elecbvv");
	capObserv=lookup_widget(objet,"obsbvv");
	gouv=lookup_widget(objet,"gouvernoratv");
	deleg=lookup_widget(objet,"delegationv");
	idAg=lookup_widget(objet,"idagentbvv");
	alertCheck=lookup_widget(objet,"alertCheck");



	strcpy(bv.id,gtk_entry_get_text(GTK_ENTRY(id)));
	a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capElec));
	b=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(capObserv));
	sprintf(cE,"%d",a);
	sprintf(cO,"%d",b);
	strcpy(bv.capElecteurs,cE);
	strcpy(bv.capObservateurs,cO);
	strcpy(bv.gouvernorat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouv)));
	strcpy(bv.delegation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(deleg)));
	strcpy(bv.IDagent.idAg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(idAg)));
	strcpy(bv.salle,sallebv);


	if(checkModif!=1)
	{	gtk_label_set_text(GTK_LABEL(alertCheck),"Confirmer la modification");
	}
	else{
	gtk_label_set_text(GTK_LABEL(alertCheck),"Opération Réussie");
	supprimer_bv(bvModif);
	ajouter_bv(bv);
	supprimerAgent("agent.txt", bv.IDagent.idAg);
	supprimerDelegation("delegation.txt", bv.delegation);
	}
	gtk_widget_destroy(modifierBV);

	modifierBV=create_modifierBV();
	
	gtk_widget_show(modifierBV);
	

}


void
on_check_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{checkModif=1;}
}


void
on_quitterAff_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_quitterSupp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_quitterMod_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}





void
on_trierElect_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview, *afficherBV;
	trierElecteurs("bureauV.txt");
	afficherBV=lookup_widget(objet,"afficherBV");
	treeview=lookup_widget(afficherBV,"treeviewBV");
	afficher_bv(treeview);
}



void
on_TrierSalle_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview, *afficherBV;
	trierSalle("bureauV.txt");
	afficherBV=lookup_widget(objet,"afficherBV");
	treeview=lookup_widget(afficherBV,"treeviewBV");
	afficher_bv(treeview);
}

///////////////////////////////////////////FIN Interface BUreau de Vote -CHAIMA MATOUSSI-/////////////////////////////////////////////////////



















void
on_btn_Connexion_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{	
	GtkWidget *WindowLogin;
	GtkWidget *entryLogin;
	GtkWidget *entryPass;
	GtkWidget *output;
	char login[20];
	char Motdepasse[20];
	int cnx=0;
	WindowLogin=lookup_widget(objet,"WindowLogin");
	entryLogin=lookup_widget(objet,"entryLogin");
	entryPass=lookup_widget(objet,"entryPass");
	entryPass=lookup_widget(objet,"labelErreurConnexion");
//************************************************************************
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(entryLogin)));
	strcpy(Motdepasse,gtk_entry_get_text(GTK_ENTRY(Motdepasse)));
//************************************************************************
	cnx=connexion(login,Motdepasse);
	if(cnx==1)
	{
			//admin y7el kol chy
	}
	else if(cnx==3)
	{
		GtkWidget *ajouter;
		GtkWidget *afficher_Nassim;
		afficher_Nassim=lookup_widget(objet,"WindowLogin");
		gtk_widget_destroy(afficher_Nassim);
		ajouter=create_GestionListeElectorale();
		gtk_widget_show (ajouter);
	}
	else{
	  	 GdkColor color;
		gdk_color_parse("red",&color);
		gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
		gtk_label_set_text(GTK_LABEL(output),"Login ou Mot de passe incorrect !");
	}



}


void
on_fenetreAjoutBV_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *AjouterListe, *ajoutBV;
	AjouterListe=lookup_widget(objet,"AjouterListe");
	ajoutBV=lookup_widget(objet,"ajoutBV");
	gtk_widget_destroy(AjouterListe);
	ajoutBV=create_ajoutBV();
	gtk_widget_show(ajoutBV);
}




////////////////////////////////////////////////////////Seif fathallah///////////////////////////////////////////////////////////
void
on_nbrmod1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{consm==22;}
}


void
on_nbrmodel2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{consm==40;}
}


void
on_nbrmodel3_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{consm==60;}
}


void
on_confirmerel_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
election e;
char conseiller[50];
char joure[50];
char moise[50];
char an[50];
int j,m,a;
GtkWidget *id , *municipalite ,*jour, *mois, *annee, *alert ,*alert1;
GtkWidget *window;
window=lookup_widget(objet,"windowel");

id=lookup_widget(objet,"idel");
municipalite=lookup_widget(objet,"municipaliteel");
jour=lookup_widget(objet,"jourel");
mois=lookup_widget(objet,"moisel");
annee=lookup_widget(objet,"enneeel");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
alert=lookup_widget(objet,"alertel");
alert1=lookup_widget(objet,"labelconseilleraj");


sprintf(conseiller,"%d",cons);
sprintf(joure,"%d",j);
sprintf(moise,"%d",m);
sprintf(an,"%d",a);


strcpy(e.nbr_conseiller,conseiller);
strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(e.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));
gtk_label_set_text(GTK_LABEL(alert),"ajout avec succés");
gtk_label_set_text(GTK_LABEL(alert1),e.nbr_conseiller);

strcpy(e.del.jour,joure);
strcpy(e.del.mois,moise);
strcpy(e.del.annee,an);


//supprimerelection("election.txt", e.id);

ajouter_election(e);
}


void
on_afficherel_clicked                  (GtkButton       *objet,
                                        gpointer         user_data)
{
   GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(objet,"windowel");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(objet,"windowafficherel");
	affiche=create_windowafficherel();
	
	gtk_widget_show(affiche);

	treeview=lookup_widget(affiche,"treeviewaffel");
	afficher_election(treeview);
}


void
on_quitteraj_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_treeviewaffel_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* id;
        gchar* nbr_conseiller;
        gchar* municipalite;
	gchar* jour;
	gchar* mois;
	gchar* annee;

	election e;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{ 
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &id, 1, &nbr_conseiller, 2, &municipalite, 3, &jour, 4, &mois, 5, &annee, -1);
	strcpy(e.id,id);
	strcpy(e.nbr_conseiller,nbr_conseiller);
	strcpy(e.municipalite,municipalite);
	strcpy(e.del.jour,jour);
	strcpy(e.del.mois,mois);
	strcpy(e.del.annee,annee);
	

	supprimer_election(e);

	afficher_election(treeview);

	 
	}
}


void
on_retoureel_clicked                   (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajout, *affiche;
affiche=lookup_widget(objet,"windowafficherel");

gtk_widget_destroy(affiche);
ajout=create_windowel();
gtk_widget_show(ajout);
}


void
on_modier_aff_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
	GtkWidget *afficher_m;
	afficher_m=lookup_widget(button,"windowafficherel");
	gtk_widget_destroy(afficher_m);
	ajouter=create_modifeel();
	gtk_widget_show (ajouter);
}


void
on_quitteraff_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_chmedel_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;//id a chercher
	  GtkWidget* output;
	  GtkWidget* SJ;
	  GtkWidget* SM;
	  GtkWidget* SA;
          GtkWidget* COX;
	  GtkWidget* outputEr;
	  GtkWidget *ra1,*ra2,*ra3;
	  GtkWidget *compt;
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"idmodel") ;
	ra1=lookup_widget(button, "nbrmod1");
	ra2=lookup_widget(button, "nbrmodel2");
	ra3=lookup_widget(button, "nbrmodel3");
	compt=lookup_widget(button, "nbrmodcons");
//declarer 
        char idch[50];
	int  j1, m1, a1;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//appel function chercher_election
	em=chercher_election(idch);
	if(strcmp(em.id,"-1")!=0)

	{
	GtkWidget *erreurModification;
erreurModification= lookup_widget (button ,"labelch_erreurmod");

gtk_label_set_text(GTK_LABEL(erreurModification),"Cette election existe !");
gtk_widget_show (erreurModification);

	j1 = atoi (em.del.jour);
	 m1 = atoi (em.del.mois);
	 a1 = atoi (em.del.annee);
         

	 SJ=lookup_widget(button, "jourmodel");
         gtk_spin_button_set_value(SJ,j1);
	 SM=lookup_widget(button, "moismodel");
         gtk_spin_button_set_value(SM,m1);
	 SA=lookup_widget(button, "enneemodel");
         gtk_spin_button_set_value(SA,a1);
	output=lookup_widget(button,"conseilermodel");
     if(strcmp(em.nbr_conseiller,"22")==0)
       {
        
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra1),TRUE);
	
        // gtk_entry_set_text(GTK_ENTRY(compt),em.nbr_conseiller);
       }
     else if(strcmp(em.nbr_conseiller,"40")==0)
       {
        
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra2),TRUE);
       //  gtk_entry_set_text(GTK_ENTRY(compt),em.nbr_conseiller);
       }
      //if (strcmp(em.nbr_conseiller,"60")==0)
           else {
             
             gtk_toggle_button_set_active(GTK_RADIO_BUTTON(ra3),TRUE);
	
        // gtk_entry_set_text(GTK_ENTRY(compt),em.nbr_conseiller);
            }
//*************************************
	 COX=lookup_widget(button,"municipalitemodel");
	 if(strcmp(em.municipalite,"Ariana")==0){
         	gtk_combo_box_set_active(COX,1);}
	 else if(strcmp(em.municipalite,"Beja")==0){
         	gtk_combo_box_set_active(COX,2);}
	else if(strcmp(em.municipalite,"Jendouba")==0){
         	gtk_combo_box_set_active(COX,3);}
	 else if(strcmp(em.municipalite,"Mahdia")==0){
         	gtk_combo_box_set_active(COX,4);}
	 else if(strcmp(em.municipalite,"Sousse")==0){
         	gtk_combo_box_set_active(COX,5);}
         
//*************************************
	

	}
	else{
	 	
		//outputEr=lookup_widget(button,"labelch_erreurmod");
               // gtk_entry_set_text(GTK_ENTRY(outputEr),"Cette election n'existe pas !");
	GtkWidget *erreurModification;
erreurModification= lookup_widget (button ,"labelch_erreurmod");
gtk_label_set_text(GTK_LABEL(erreurModification),"Cette election n'existe pas ");
gtk_widget_show (erreurModification);

	}

}


void
on_model_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
char conseiller[50];
char joure[50];
char moise[50];
char an[50];
int j,m,a;
/*//declarer les GTKwidget.
	  GtkWidget* inputIDchercher ;
	  GtkWidget* output;
	  GtkWidget* SJ;
	  GtkWidget* SM;
	  GtkWidget* SA;
          GtkWidget* COX;
	  GtkWidget* outputEr;
// associer les objets avec des variables
	inputIDchercher = lookup_widget(button,"idmodel") ;
//declarer 
       char idch[10];
	//int idIN;
	election emod;
	int test;
	strcpy(idch,gtk_entry_get_text(GTK_ENTRY(inputIDchercher)));
//convert txtentry to int 
	//idIN=atoi(idch);
	//nouvL.id=idIN;
	//GtkWidget* inputNom ;nom de la liste
	GtkWidget* Jour; //spinbuttun pour le choix du jour.
	GtkWidget* Mois; //spinbuttun pour Le choix du mois.
	GtkWidget* Annee; //spinbuttun pour le choix de l'année.
	GtkWidget* Comboboxmod; //comobox pour Le choix de la municipalité.
	GtkWidget* conseillermod ;
	
// associer les objets avec des variables
	
	Jour = lookup_widget(button,"jourmodel") ;
	Mois = lookup_widget(button,"moisdmodel") ;
	Annee = lookup_widget(button,"enneemodel") ;
	Comboboxmod = lookup_widget(button,"municipalitemodel") ;
	conseillermod = lookup_widget(button,"conseillermodel") ;
	
// récupérer les valeurs des spin buttons 
	sprintf(jourem,"%d",jm);
	sprintf(moisem,"%d",mm);
	sprintf(anm,"%d",am);
	//strcpy(nouvL.nom_liste,gtk_entry_get_text(GTK_ENTRY(inputNom)));
	jm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	mm=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
	am=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
	strcpy(emod.del.jour,jourem);
	strcpy(emod.del.mois,moisem);
	strcpy(emod.del.annee,anm);
//récupérer les valeur de radiobutton
	if(consm==22)
	{
	 
         strcpy(emod.nbr_conseiller,gtk_entry_get_text(GTK_ENTRY(conseillermod)));
	}
	if(consm==40)
	{
	 strcpy(emod.nbr_conseiller,gtk_entry_get_text(GTK_ENTRY(conseillermod)));
	}
	if(consm==60)
	{
	 strcpy(emod.nbr_conseiller,gtk_entry_get_text(GTK_ENTRY(conseillermod)));
	}
//recupérer lcombo
	strcpy(emod.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (Comboboxmod)));
//appel function modifier

	test=modifier_election("election.txt",idch,emod);
/traja3ni lajouter 
	GtkWidget *ajouter;
	GtkWidget *afficher_m;
	afficher_m=lookup_widget(button,"modifeel");
	gtk_widget_destroy(afficher_m);
	ajouter=create_windowafficherel();
	gtk_widget_show (ajouter);
*/
election em1;
GtkWidget *id , *municipalite ,*jour, *mois, *annee , *alert, *alert1;
GtkWidget *window;
window=lookup_widget(button,"modifeel");

id=lookup_widget(button,"idmodel");
municipalite=lookup_widget(button,"municipalitemodel");
jour=lookup_widget(button,"jourmodel");
mois=lookup_widget(button,"moismodel");
annee=lookup_widget(button,"enneemodel");
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
alert=lookup_widget(button,"nbrmodcons");
alert1=lookup_widget(button,"labelajoutermodel");




sprintf(conseiller,"%d",cons);
sprintf(joure,"%d",j);
sprintf(moise,"%d",m);
sprintf(an,"%d",a);


strcpy(em1.nbr_conseiller,conseiller);
strcpy(em1.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(em1.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(municipalite)));

gtk_label_set_text(GTK_LABEL(alert),em1.nbr_conseiller);
gtk_label_set_text(GTK_LABEL(alert1),"modification avec succés");
strcpy(em1.del.jour,joure);
strcpy(em1.del.mois,moise);
strcpy(em1.del.annee,an);
supprimer_election(em);

ajouter_election(em1);




}


void
on_retoure_aff_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajout;
	GtkWidget *affiche;
	GtkWidget *treeview;

	ajout=lookup_widget(button,"modifeel");

	gtk_widget_destroy(ajout);
	affiche=lookup_widget(button,"windowafficherel");
	affiche=create_windowafficherel();
	
	gtk_widget_show(affiche);

	treeview=lookup_widget(affiche,"treeviewaffel");
	afficher_election(treeview);
}


void
on_quittermod_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}
////////////////////////////////////////////////mohamed rebai///////////////////////////////////////////////////////////////

void
on_button__quitterUserAJOUT_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button_quitter_affichageUSER_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button_quitterModifierUSER_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_radiobutton_FemmeUSER_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
genre=2;
}


void
on_radiobutton_HommeUSER_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
genre=3;
}


void
on_button_Ajouter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[20];
	utilisateur L;
	int x;
	int AA,MM,JJ;
	GtkWidget *id;
	id=lookup_widget(button,"entry_CIN_ajUSER");
	strcpy(L.CIN,gtk_entry_get_text(GTK_ENTRY(id)));
	
	GtkWidget *nom;
	nom=lookup_widget(button,"entry_nom_ajUSER");
	strcpy(L.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

	GtkWidget *prenom;
	prenom=lookup_widget(button,"entry_prenom_ajUSER");
	strcpy(L.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
/*
	GtkWidget *sexe;
	sexe=lookup_widget(button,"entry_sexe");
	strcpy(,gtk_entry_get_text(GTK_ENTRY(sexe)));
*/
	if(genre==2)
	{strcpy(L.genre,"Homme");}
	else if(genre==3){strcpy(L.genre,"Femme");}

	GtkWidget *municipalite;
	municipalite=lookup_widget(button,"combobox_municipalit___ajUSER");
	strcpy(L.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (municipalite)));

	GtkWidget *role;
	role=lookup_widget(button,"combobox_role_ajUSER");
	strcpy(L.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX (role)));

	GtkWidget *password;
	password=lookup_widget(button,"entry_password_ajUSER");
	strcpy(L.Nempreinte,gtk_entry_get_text(GTK_ENTRY(password)));	

	GtkWidget *Ntelephone;
	Ntelephone=lookup_widget(button,"entry_Ntelephone_ajUSER");
	strcpy(L.Ntelephone,gtk_entry_get_text(GTK_ENTRY(Ntelephone)));	


	GtkWidget *Jour; //spinbuttun pour le choix du jour
	GtkWidget *Mois; //spinbuttun pour Le choix du mois.
	GtkWidget *Annee; //spinbuttun pour le choix de l'année
	Jour=lookup_widget (button, "spinbutton_jour_ajUSER");
	Mois=lookup_widget(button, "spinbutton_mois_ajUSER"); 
	Annee=lookup_widget(button, "spinbutton_annee_ajUSER"); 
	/* récupérer les valeurs des spin buttons en utilisant la fonction gtk spin_button_get_value as int qui retourne l'entier choisi par l'utilisateur */ 
	JJ=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	MM=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
	AA=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
	sprintf(L.d.jour,"%d",JJ);
	sprintf(L.d.mois,"%d",MM);
	sprintf(L.d.annee,"%d",AA);
	

	GtkWidget *erreurAjouter;
	erreurAjouter=lookup_widget(button,"label_erreur_ajouter");
	
	GtkWidget *AjouterAvecSucces;
	AjouterAvecSucces=lookup_widget(button,"label_ajouter_avec_succes");


	x=ajouterUtilisateur("utilisateur.txt",L);
	if (x==1){ gtk_widget_show (AjouterAvecSucces);}
	else { gtk_widget_show (erreurAjouter);}


/*
GtkWidget *afficher_user;
	afficher_user =create_window_ajouter_utilisateur ();// create_window_ajouter_utilisateur 
	gtk_widget_show (afficher_user);
*/
}


void
on_button_TOafficherUSER_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_user;
	ajouter_user=lookup_widget(button,"window_ajouter_utilisateur");
	gtk_widget_destroy(ajouter_user);

	GtkWidget *afficher_user;
	afficher_user =create_window_Affichage ();//create_window_Affichage 
	gtk_widget_show (afficher_user);

	GtkWidget *treeview;
	treeview=lookup_widget(afficher_user,"treeview_affichageUSER");
	afficher_USERtreeview(treeview);
}


void
on_treeview_affichageUSER_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	GtkTreeIter iter;
	gchar* CIN;
	gchar* Nempreinte;
	gchar* Ntelephone;
	gchar* nom;
	gchar* prenom;
	gchar* municipalite;
	gchar* role;
	gchar* genre;
	gchar* vote;
	gchar* jour;
	gchar* mois;
	gchar* annee;

	utilisateur L;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if(gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &CIN, 1, &Nempreinte, 2, &Ntelephone, 3, &nom, 4, &prenom, 5, &municipalite, 6, &role, 7, &genre, 8, &vote, 9, &jour, 10, &mois, 11, &annee, -1);

strcpy(L.CIN,CIN);
strcpy(L.Nempreinte,Nempreinte);
strcpy(L.Ntelephone,Ntelephone);
strcpy(L.nom,nom);
strcpy(L.prenom,prenom);
strcpy(L.d.jour,jour);
strcpy(L.d.mois,mois);
strcpy(L.d.annee,annee);
strcpy(L.municipalite,municipalite);
strcpy(L.genre,genre);
strcpy(L.role,role);
strcpy(L.vote,vote);



supprimer_USERtreev(L);
afficher_USERtreeview(treeview);


}
}


void
on_button_refresh_affichageUSER_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_user;
	ajouter_user=lookup_widget(button,"window_Affichage");
	gtk_widget_destroy(ajouter_user);

	

	GtkWidget *afficher_user;
	afficher_user =create_window_Affichage ();//create_window_Affichage 
	gtk_widget_show (afficher_user);

	GtkWidget *treeview;
	treeview=lookup_widget(afficher_user,"treeview_affichageUSER");
	afficher_USERtreeview(treeview);
}


void
on_button_TOmodifierUSER_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_user;
	ajouter_user=lookup_widget(button,"window_Affichage");
	gtk_widget_destroy(ajouter_user);

	GtkWidget *afficher_user;
	afficher_user =create_window_modifierUtilisateur ();// create_window_ajouter_utilisateur create_window_Affichage 
	gtk_widget_show (afficher_user);
}


void
on_button_TOajouterUSER_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_user;
	ajouter_user=lookup_widget(button,"window_Affichage");
	gtk_widget_destroy(ajouter_user);

	GtkWidget *afficher_user;
	afficher_user =create_window_ajouter_utilisateur ();// create_window_ajouter_utilisateur create_window_Affichage 
	gtk_widget_show (afficher_user);
}


void
on_button_chercherModifierUSER_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
char ch[20];
	char CIN[20];
	utilisateur L,U;
	int x,n=0;
	int AA,MM,JJ;
	GtkWidget *id;
	id=lookup_widget(button,"entry_CIN_modifier_USER");
	strcpy(U.CIN,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(PCIN,CIN);
	
	L=chercherUtilisateur("utilisateur.txt",U.CIN);
	 if(strcmp(L.CIN,"-1")==0){
	
	char vide[10]=" ";	
	GtkWidget *nom;
	nom=lookup_widget(button,"entry_nom_modifier_USER");
	gtk_entry_set_text(GTK_ENTRY(nom),vide);

	GtkWidget *prenom;
	prenom=lookup_widget(button,"entry_prenom_Modifier_USER");
	gtk_entry_set_text(GTK_ENTRY(prenom),vide);
	
	GtkWidget *password;
	password=lookup_widget(button,"entry_password_rModifierUSER");
	gtk_entry_set_text(GTK_ENTRY(password),vide);
	
	GtkWidget *Ntelephone;
	Ntelephone=lookup_widget(button,"entry_NumTelephoneModifierUSER");
	gtk_entry_set_text(GTK_ENTRY(Ntelephone),vide);
	
	int J= 1;
	GtkSpinButton *SJ=lookup_widget(button, "spinbutton_jour_ModifierUSER");
        gtk_spin_button_set_value(SJ,J);
	
	GtkSpinButton *SM=lookup_widget(button, "spinbutton_mois_ModifierUSER");
        gtk_spin_button_set_value(SM,J);
	double A=1999;
	GtkSpinButton *SA=lookup_widget(button, "spinbutton_annee_ModifierUSER");
        gtk_spin_button_set_value(SA,A);

	GtkWidget *erreurModification;
	erreurModification= lookup_widget (button ,"label_erreurModifiationUSER");
	gtk_widget_show (erreurModification);

	

	}
	
	else{
	GtkWidget *nom;
	nom=lookup_widget(button,"entry_nom_modifier_USER");
	gtk_entry_set_text(GTK_ENTRY(nom),L.nom);

	GtkWidget *prenom;
	prenom=lookup_widget(button,"entry_prenom_Modifier_USER");
	gtk_entry_set_text(GTK_ENTRY(prenom),L.prenom);
	
	GtkWidget *password;
	password=lookup_widget(button,"entry_password_rModifierUSER");
	gtk_entry_set_text(GTK_ENTRY(password),L.Nempreinte);
	
	GtkWidget *Ntelephone;
	Ntelephone=lookup_widget(button,"entry_NumTelephoneModifierUSER");
	gtk_entry_set_text(GTK_ENTRY(Ntelephone),L.Ntelephone);
	
	int J= atoi(L.d.jour);
	GtkSpinButton *SJ=lookup_widget(button, "spinbutton_jour_ModifierUSER");
        gtk_spin_button_set_value(SJ,J);
	int M= atoi(L.d.mois);
	GtkSpinButton *SM=lookup_widget(button, "spinbutton_mois_ModifierUSER");
        gtk_spin_button_set_value(SM,M);
	int A= atoi(L.d.annee);
	GtkSpinButton *SA=lookup_widget(button, "spinbutton_annee_ModifierUSER");
        gtk_spin_button_set_value(SA,A);


	 GtkWidget* COX;
	 COX=lookup_widget(button,"combobox_role_ModifierUSER");
	 
 
	 GtkWidget* COX11;
	 COX11=lookup_widget(button,"combobox_municipalite_ModifierUSER");





int trouve=0;
int i=-1;


char gouv[20];
//traitement gouv
FILE *f=fopen("gouvernorat.txt","r");
while(!trouve && fscanf(f,"%s \n",gouv)!=EOF)
  {i++;
   if(strcmp(gouv,L.municipalite)==0)
   trouve=1;   //condition d'arret
  }
gtk_combo_box_set_active(GTK_COMBO_BOX(COX11),i);

int trouveR=0;
int iR=-1;


char gouvR[20];
//traitement gouv
FILE *fR=fopen("role.txt","r");
while(!trouveR && fscanf(fR,"%s \n",gouvR)!=EOF)
  {iR++;
   if(strcmp(gouvR,L.role)==0)
   trouveR=1;   //condition d'arret
  }
gtk_combo_box_set_active(GTK_COMBO_BOX(COX),iR);




	  
	GtkWidget *output,*output2;
        output=lookup_widget(button,"radiobutton_HommeModifierUSER");	
             output2=lookup_widget(button,"radiobutton_femmeModifierUSER");
	if(strcmp(L.genre,"Homme")==0)
	{

        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
	}
	else if (strcmp(L.genre,"Femme")==0)
	    {

             gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output2),TRUE);
            }


	  }
}


void
on_button_ModifierUSER_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

	char ch[20];
	char CIN[20];
	utilisateur L;
	int x;
	int AA,MM,JJ;
	GtkWidget *id;
	id=lookup_widget(button,"entry_CIN_modifier_USER");
	strcpy(L.CIN,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(CIN,PCIN);
	
	GtkWidget *nom;
	nom=lookup_widget(button,"entry_nom_modifier_USER");
	strcpy(L.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

	GtkWidget *prenom;
	prenom=lookup_widget(button,"entry_prenom_Modifier_USER");
	strcpy(L.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

	if(genreMODIFIER==2)
	{strcpy(L.genre,"Homme");}
	else if(genreMODIFIER==3){strcpy(L.genre,"Femme");}

	GtkWidget *municipalite;
	municipalite=lookup_widget(button,"combobox_municipalite_ModifierUSER");
	strcpy(L.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX (municipalite)));

	GtkWidget *role;
	role=lookup_widget(button,"combobox_role_ModifierUSER");
	strcpy(L.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX (role)));

	GtkWidget *password;
	password=lookup_widget(button,"entry_password_rModifierUSER");
	strcpy(L.Nempreinte,gtk_entry_get_text(GTK_ENTRY(password)));	

	GtkWidget *Ntelephone;
	Ntelephone=lookup_widget(button,"entry_NumTelephoneModifierUSER");
	strcpy(L.Ntelephone,gtk_entry_get_text(GTK_ENTRY(Ntelephone)));	


	GtkWidget *Jour; //spinbuttun pour le choix du jour
	GtkWidget *Mois; //spinbuttun pour Le choix du mois.
	GtkWidget *Annee; //spinbuttun pour le choix de l'année
	Jour=lookup_widget (button, "spinbutton_jour_ModifierUSER");
	Mois=lookup_widget(button, "spinbutton_mois_ModifierUSER"); 
	Annee=lookup_widget(button, "spinbutton_annee_ModifierUSER"); 
	//récupérer les valeurs des spin buttons en utilisant la fonction gtk spin_button_get_value as int qui retourne l'entier choisi par l'utilisateur
	JJ=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Jour));
	MM=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Mois));
	AA=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (Annee));
	sprintf(L.d.jour,"%d",JJ);
	sprintf(L.d.mois,"%d",MM);
	sprintf(L.d.annee,"%d",AA);
	

	GtkWidget *erreurModification;
	erreurModification=lookup_widget(button,"label_erreurModifiationUSERr");
	
	GtkWidget *ModificationAvecSucces;
	ModificationAvecSucces=lookup_widget(button,"label_modifierAvecSuccesUSER");
	
	x=modifierUtilisateur("utilisateur.txt",CIN,L);
	
	if (x==1){ gtk_widget_show (ModificationAvecSucces);}
	else { gtk_widget_show (erreurModification);}



}


void
on_button_annulerModifierUSER_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
char vide[10]=" ";	
	GtkWidget *nom;
	nom=lookup_widget(button,"entry_nom_modifier_USER");
	gtk_entry_set_text(GTK_ENTRY(nom),vide);

	GtkWidget *prenom;
	prenom=lookup_widget(button,"entry_prenom_Modifier_USER");
	gtk_entry_set_text(GTK_ENTRY(prenom),vide);
	
	GtkWidget *password;
	password=lookup_widget(button,"entry_password_rModifierUSER");
	gtk_entry_set_text(GTK_ENTRY(password),vide);
	
	GtkWidget *Ntelephone;
	Ntelephone=lookup_widget(button,"entry_NumTelephoneModifierUSER");
	gtk_entry_set_text(GTK_ENTRY(Ntelephone),vide);
	
	int J= 1;
	GtkSpinButton *SJ=lookup_widget(button, "spinbutton_jour_ModifierUSER");
        gtk_spin_button_set_value(SJ,J);
	
	GtkSpinButton *SM=lookup_widget(button, "spinbutton_mois_ModifierUSER");
        gtk_spin_button_set_value(SM,J);
	double A=1950;
	GtkSpinButton *SA=lookup_widget(button, "spinbutton_annee_ModifierUSER");
        gtk_spin_button_set_value(SA,A);

	
}

void
on_button2_FROMmodifierTOafficherUSER_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouter_user;
	ajouter_user=lookup_widget(button,"window_modifierUtilisateur");
	gtk_widget_destroy(ajouter_user);

	GtkWidget *afficher_user;
	afficher_user =create_window_Affichage ();//create_window_Affichage 
	gtk_widget_show (afficher_user);

	GtkWidget *treeview;
	treeview=lookup_widget(afficher_user,"treeview_affichageUSER");
	afficher_USERtreeview(treeview);
}




