#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"function.h"
Lorder tab[20];
int n=0;
int x=1;
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
//declarer la struct qui ajouter
        Liste L;
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
	if(x==2)
	{
	 strcpy(L.orientation,"Centre");
	}
	if(x==3)
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
	
	ajouterListe(L);
//traja3ni ltree view 
	GtkWidget *ajouter101;
	GtkWidget *destroy101;
	destroy101=lookup_widget(button,"AjouterListe");
	gtk_widget_destroy(destroy101);
	ajouter101=create_GestionListeElectorale();
	gtk_widget_show (ajouter101);
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
	 x=verifier(CT,C1,C2,C3);
	if(x==1)
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
     if(strcmp(LM.orientation,"Gauche")==0)
       {
        output=lookup_widget(button,"radiobtn_M_G");
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
       }
     if(strcmp(LM.orientation,"Centre")==0)
       {
        output=lookup_widget(button,"radiobtn_M_C");
        gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
       }
     else if (strcmp(LM.orientation,"Droite")==0)
            {
             output=lookup_widget(button,"radiobtn_M_D");
             gtk_toggle_button_set_active(GTK_RADIO_BUTTON(output),TRUE);
            }
//*************************************
	 COX=lookup_widget(button,"cobox_M_muni");
	 if(strcmp(LM.municipalite,"Tunis")){
         	gtk_combo_box_set_active(COX,"Tunis");}
	 else if(strcmp(LM.municipalite,"Beja")){
         	gtk_combo_box_set_active(COX,"Beja");}
	 else if(strcmp(LM.municipalite,"Sousse")){
         	gtk_combo_box_set_active(COX,"Sousse");}
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
		        gtk_label_set_text(GTK_LABEL(outputEM),"Oups echec modification l'un des Candidats existe deja!!");
			
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
	result=nbv("utilisater.txt",idch);
//*************************************
	 GdkColor color;
         gdk_color_parse("yellow",&color);
 	 gtk_widget_modify_fg(output,GTK_STATE_NORMAL,&color);
	 output=lookup_widget(button,"label_R_NBR");
         gtk_entry_set_text(GTK_ENTRY(output),result);


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

		remplirtab(tab,&n); 

		printTab(tab,&n);

 //laffichage de etreeview
GtkWidget *treeview_Nassim;
GtkWidget *afficher_u;
afficher_u=lookup_widget(button,"Stat_Liste_Nassim");
treeview_Nassim=lookup_widget(afficher_u,"treeviewNBRV");
afficher_Liste_ordre(treeview_Nassim);
}

















/////////////////////////////////////////// Interface BUreau de Vote -CHAIMA MATOUSSI- /////////////////////////////////////////////////////


#include"bv.h"


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
gouvernorat=lookup_widget(objet,"gouvernorat");
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
{	GtkWidget *AjouterListe, *ajoutBV, *WindowLogin, *entryLogin, *entryPass;
	char login[20];
	char Motdepasse[20];

	WindowLogin=lookup_widget(objet,"WindowLogin");
	entryLogin=lookup_widget(objet,"entryLogin");
	entryPass=lookup_widget(objet,"entryPass");
	AjouterListe=lookup_widget(objet,"AjouterListe");
	ajoutBV=lookup_widget(objet,"ajoutBV");
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(entryLogin)));
	strcpy(Motdepasse,gtk_entry_get_text(GTK_ENTRY(Motdepasse)));
	if((strcmp(login,"2")==0) && (strcmp(Motdepasse,"22")==0))
	{gtk_widget_destroy(WindowLogin);
	ajoutBV=create_ajoutBV();
	gtk_widget_show(ajoutBV);
	}
	else if((strcmp(login,"3")==0) && (strcmp(Motdepasse,"33")==0))
	{gtk_widget_destroy(WindowLogin);
	AjouterListe=create_AjouterListe();
	gtk_widget_show(AjouterListe);
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

