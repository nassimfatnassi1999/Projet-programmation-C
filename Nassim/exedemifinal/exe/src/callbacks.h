#include <gtk/gtk.h>

/////////////////////////////////////////////////////////Nassim Fatnassi Hnifi////////////////////////////////////
void
on_btn_Ajouter_Nassim_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Ajouter_Liste_clicked           (GtkButton       *button,
                                        gpointer         user_data);


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_btn_Afficher_Tree_Liste_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Modifier_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_retour_modifier_nassim_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Retour_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Verifier_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_M_chercher_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobtn_M_G_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobtn_M_C_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobtn_M_D_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_btn_G_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_btn_C_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_btn_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_btn_M_Modifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_stat_Nassim_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_calc_NBV_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewNBRV_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_btn_actualiser_TreeNBRV_clicked     (GtkWidget      *button,
                                        gpointer         user_data);


void
on_btn_QUITTER_A_N_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Connexion_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);



/////////////////////////////////////////// Interface BUreau de Vote -CHAIMA MATOUSSI- /////////////////////////////////////////////////////


void
on_afficherbv_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouterbv_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retourbv_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);






void
on_bt_clicked                          (GtkWidget       *objet,
                                        gpointer         user_data);





void
on_salle3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_salle2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_salle1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewBV_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supprimerbv_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retouraffichebv_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_supprimerfinal_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_quitterbv_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_rechercherBV_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_affTomod_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modToaff_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_trierBVMunic_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_deleg_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_confirmAjout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_check_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_quitterAff_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitterSupp_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_quitterMod_clicked                  (GtkButton       *button,
                                        gpointer         user_data);



void
on_trierElect_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_TrierSalle_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);




void
on_fenetreAjoutBV_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);


///////////////////////////////////////////////////////////////seif fathallah///////////////////////////////////////////////////////:

void
on_nbrmod1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbrmodel2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbrmodel3_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_afficherel_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_quitteraj_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewaffel_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retoureel_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modier_aff_clicked                  (GtkButton       *button,
                                        gpointer         user_data);
void
on_quitteraff_clicked                  (GtkButton       *button,
                                        gpointer         user_data);
void
on_chmedel_clicked                     (GtkButton       *button,
                                        gpointer         user_data);
void
on_model_clicked                       (GtkButton       *button,
                                        gpointer         user_data);
void
on_retoure_aff_clicked                 (GtkButton       *button,
                                        gpointer         user_data);
void
on_quittermod_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_cher____clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_A_N_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbhel1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbrel2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_nbhel3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirmerel_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_ajel_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_Rechajmul_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_CHercherM_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbuttonaj_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_supel_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_quittercherche_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_accher_clicked                      (GtkButton       *button,
                                        gpointer         user_data);
