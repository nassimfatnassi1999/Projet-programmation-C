#include <gtk/gtk.h>

///////////////////////////////////////////////////////Nassim fatnassi hnifi////////////////////////////////////////////////
void
on_btn_Ajouter_Nassim_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_btn_Ajouter_Liste_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobtn_Gauche_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobtn_Centre_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobtn_Droite_toggled             (GtkToggleButton *togglebutton,
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
on_btn_Retour_Ajouter_clicked          (GtkButton       *button,
                                        gpointer         user_data);
///////////////////////////////////////////////////////chaima mattoussi////////////////////////////////////////////////

void
on_salle1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_salle2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_salle3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewBV_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
void
on_afficherbv_clicked           (GtkButton       *button,
                                        gpointer         user_data);
void
on_ajouterbv_clicked           (GtkButton       *button,
                                        gpointer         user_data);
void
on_bt_clicked           (GtkButton       *button,
                                        gpointer         user_data);
void
on_retourbv_clicked           (GtkButton       *button,
                                        gpointer         user_data);

