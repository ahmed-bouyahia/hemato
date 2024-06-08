#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "users.h"
#include "function.h"

extern GtkWidget *homepage;

void show_homepage(GtkWidget *current_window) {
    gtk_widget_hide(current_window);
	GtkWidget *notebook;
	int a=1;


    homepage = create_homepage ();
    gtk_widget_show(homepage);
    notebook = lookup_widget(homepage, "notebook1");
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), a);
}
///////////////////////refresh
// Function to refresh the director
void refresh_director(GtkWidget *button) {
    GtkWidget *window;
    GtkWidget *notebook;

    // Get the top-level window containing the button
    window = gtk_widget_get_toplevel(GTK_WIDGET(button));

    // Find the notebook widget by name
    notebook = lookup_widget(window, "notebookcruddirector");

    // Verify that the notebook pointer is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found\n");
        return;
    }

    // Get the current page index
    gint current_page = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
    g_print("Current page index: %d\n", current_page);

    // Hide the current window
    gtk_widget_hide(window);

    // Create and show the new window
    window = create_Director();
    gtk_widget_show(window);

    // Find the notebook widget in the new window
    notebook = lookup_widget(window, "notebookcruddirector");

    // Verify that the notebook pointer in the new window is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found in the new window\n");
        return;
    }

    // Set the current page of the notebook after the wait
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), current_page);
}





void refresh_donor(GtkWidget *button) {
    GtkWidget *window;
    GtkWidget *notebook;

    // Get the top-level window containing the button
    window = gtk_widget_get_toplevel(GTK_WIDGET(button));

    // Find the notebook widget by name
    notebook = lookup_widget(window, "notebookdonorcrud");

    // Verify that the notebook pointer is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found\n");
        return;
    }

    // Get the current page index
    gint current_page = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
    g_print("Current page index: %d\n", current_page);

    // Hide the current window
    gtk_widget_hide(window);

    // Create and show the new window
    window = create_appointement ();  
    gtk_widget_show(window);

    // Find the notebook widget in the new window
    notebook = lookup_widget(window, "notebookdonorcrud");

    // Verify that the notebook pointer in the new window is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found in the new window\n");
        return;
    }

    // Set the current page of the notebook after the wait
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), current_page);
}


void refresh_adminets(GtkWidget *button) {
    GtkWidget *window;
    GtkWidget *notebook;
GtkWidget *notebook1;
int amine=1;

    // Get the top-level window containing the button
    window = gtk_widget_get_toplevel(GTK_WIDGET(button));

    // Find the notebook widget by name
    notebook = lookup_widget(window, "notebookcrudets");
notebook1 = lookup_widget(window, "notebookadminuser");

gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook1), amine);

    // Verify that the notebook pointer is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found\n");
        return;
    }

    // Get the current page index
    gint current_page = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
    g_print("Current page index: %d\n", current_page);

    // Hide the current window
    gtk_widget_hide(window);

    // Create and show the new window
    window = create_admin ();   
    gtk_widget_show(window);

    // Find the notebook widget in the new window
    notebook = lookup_widget(window, "notebookcrudets");

    // Verify that the notebook pointer in the new window is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found in the new window\n");
        return;
    }

    // Set the current page of the notebook after the wait
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), current_page);
}


void refresh_adminuser(GtkWidget *button) {
    GtkWidget *window;
    GtkWidget *notebook;

    // Get the top-level window containing the button
    window = gtk_widget_get_toplevel(GTK_WIDGET(button));

    // Find the notebook widget by name
    notebook = lookup_widget(window, "notebookcrudusers");

    // Verify that the notebook pointer is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found\n");
        return;
    }

    // Get the current page index
    gint current_page = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
    g_print("Current page index: %d\n", current_page);

    // Hide the current window
    gtk_widget_hide(window);

    // Create and show the new window
    window = create_admin ();
    gtk_widget_show(window);

    // Find the notebook widget in the new window
    notebook = lookup_widget(window, "notebookcrudusers");

    // Verify that the notebook pointer in the new window is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found in the new window\n");
        return;
    }

    // Set the current page of the notebook after the wait
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), current_page);
}

void refresh_doctor(GtkWidget *button) {
    GtkWidget *window;
    GtkWidget *notebook;

    // Get the top-level window containing the button
    window = gtk_widget_get_toplevel(GTK_WIDGET(button));

    // Find the notebook widget by name
    notebook = lookup_widget(window, "note_DOC");

    // Verify that the notebook pointer is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found\n");
        return;
    }

    // Get the current page index
    gint current_page = gtk_notebook_get_current_page(GTK_NOTEBOOK(notebook));
    g_print("Current page index: %d\n", current_page);

    // Hide the current window
    gtk_widget_hide(window);

    // Create and show the new window
    window = create_Doctor ();
    gtk_widget_show(window);

    // Find the notebook widget in the new window
    notebook = lookup_widget(window, "note_DOC");

    // Verify that the notebook pointer in the new window is valid
    if (notebook == NULL) {
        g_print("Error: Notebook widget not found in the new window\n");
        return;
    }

    // Set the current page of the notebook after the wait
    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), current_page);
}
///////////////////////refresh
/////////////////////////////////////new file
void get_login(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    if (!input_file) {
        perror("Failed to open input file");
        return;
    }

    FILE *output_file = fopen(output_filename, "w");
    if (!output_file) {
        perror("Failed to open output file");
        fclose(input_file);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), input_file)) {
        char *first_word = NULL;
        char *last_word = NULL;
        char *token = strtok(line, " \t\n");

        if (token) {
            first_word = token;
            while (token) {
                last_word = token;
                token = strtok(NULL, " \t\n");
            }

            fprintf(output_file, "%s %s\n", first_word, last_word);
        }
    }

    fclose(input_file);
    fclose(output_file);
}
/////////////////////////new file
////////////ahmed///////////////
int choixurgdirector=1;
int id_found_mod_director;
int id_found_del_director;
 int choixdeletedirector[]={0};
int id_found_del_director_test;
int id_found_mod_director_test;
#include "director.h"
////////////ahmed///////////////
////////////yahya///////////////
int gendercreate=1;
int genderupdate=1;
int checkdl[]={0};
int checkup[]={0};
char idfoundmod[20];
char idfounddel[20];
int idfoundmodint;
int idfoundmodintA;
int idfounddelint;
int rolest=1;
int y=1;
int x=1;
char idfoundmodA[200];
int checkdlA[]={0};
int confirm_del[]={0};
/////////////////yahya/////////////
////////bechir///////
#include "structure.h"

int choix[]={0,0};
int a=1;

////////ahlem////////////

#include "donneur.h"
int bloodtype;
int bloodtype2;
int gender;
int gender2;
int conf_crea;
int conf_mod;
int conf_stat_list;
int conf_stat_av;

///////////syrine////////////
#include "DON.h"
int iddon =1 ;
char rec[70];
int choixreaddoctor=1;
int choixdeldoctor[]={0};
int id_found_mod_DOC;
int id_found_del_DOC;
int id_found_del_DOC_test;
int id_found_mod_DOC_test;
int choice=2;
/////////syrine////////////
void
on_sign_upp_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *NOM;
    GtkWidget *ADDRESS;
    GtkWidget *PHONE;                        
    GtkWidget *PASSWORD;
    GtkWidget *OUT;
    sign s;
    
    NOM= lookup_widget(button, "name_sign");
    ADDRESS= lookup_widget(button, "mail_sign");
    PHONE= lookup_widget(button, "phone_sign");
    PASSWORD= lookup_widget(button, "pass_sign");
    OUT=lookup_widget(button, "msg_signup");

strcpy(s.fullname,(gtk_entry_get_text(GTK_ENTRY(NOM))));
strcpy(s.email,(gtk_entry_get_text(GTK_ENTRY(ADDRESS))));
strcpy(s.phone,(gtk_entry_get_text(GTK_ENTRY(PHONE))));
strcpy(s.password,(gtk_entry_get_text(GTK_ENTRY(PASSWORD))));




int x= ajouter_sign("SIGN_UP.txt", s );

if (x==1){
gtk_label_set_text(GTK_LABEL(OUT),"SIGNED UP SUCCESSFULLY");
const char *input_filename = "SIGN_UP.txt";
    const char *output_filename = "clientlog.txt";
    get_login(input_filename, output_filename);


}
else if (x==0){
gtk_label_set_text(GTK_LABEL(OUT),"SIGN UP FAILED");
}

}


void
on_log_out_book_rdv_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_radiordv1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{a=1;} 

}


void
on_radiordv2_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{a=2;} 

}


void
on_book_clicked                        (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Jour;
    GtkWidget *Mois;
    GtkWidget *Annee;
    GtkWidget *combobox1;                        
    GtkWidget *combobox2;
    GtkWidget *outputadd;
    GtkWidget *outputadd2;
    rdv r;
    rdv R;
    int idr;
    Jour = lookup_widget(objet_graphique, "add_day");
    Mois = lookup_widget(objet_graphique, "add_month");
    Annee = lookup_widget(objet_graphique, "add_year");
    combobox1 = lookup_widget(objet_graphique, "add_estab");
    combobox2 = lookup_widget(objet_graphique, "add_avail_time");
    outputadd = lookup_widget(objet_graphique, "msg_ajout");
    outputadd2=lookup_widget(objet_graphique, "outmsgjj");
//spin
    r.date_rdv.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
    r.date_rdv.month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
    r.date_rdv.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
//combo
    strcpy(r.establishment, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
    strcpy(r.tt, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
// add RDV to the file
FILE * f=fopen("RDV.txt", "r");
    
    if(f!=NULL)
    {
       while(fscanf(f,"%d %s %d %d %d %s\n",&R.id,R.establishment,&R.date_rdv.day,&R.date_rdv.month,&R.date_rdv.year,R.tt)!=EOF)
{  if(R.id>idr)
         {idr=R.id;}}
        fclose(f);}
idr++;
r.id=idr;
int x=ajouter_RDV("RDV.txt" ,  r  );
int arch=ajouter_RDV("RDVarchive.txt" ,  r  );



// message 
if (x==1){
gtk_label_set_text(GTK_LABEL(outputadd),"The appointement was added successfully");

}
else if (x==0){
gtk_label_set_text(GTK_LABEL(outputadd),"Adding appointement failed");
}
if (a==1){
gtk_label_set_text(GTK_LABEL(outputadd2),"your will get hepl as soon as possible Thank you for your help ");


}
else if (a==2){
gtk_label_set_text(GTK_LABEL(outputadd2),"your familly member will get hepl as soon as possible ");
}

}


void
on_check_avail_time_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Jour;
    GtkWidget *Mois;
    GtkWidget *Annee;
    GtkWidget *combobox1;
    GtkWidget *combobox2;
    date date_rdv;
    char esst[200];
    char tt_horaire[120][150] = {"9h==>9h30", "9h30==>10h", "10h==>10h30", "10h30==>11h", "11h==>11h30", "11h30==>12h", "12h==>12h30", "12h30==>13h", "13h==>13h30", "13h30==>14h"};
    char tt_dispo[120][150];
    int i, n, j = 0;

    Jour = lookup_widget(button, "add_day");
    Mois = lookup_widget(button, "add_month");
    Annee = lookup_widget(button, "add_year");
    combobox1 = lookup_widget(button, "add_estab");
    combobox2 = lookup_widget(button, "add_avail_time");

    date_rdv.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
    date_rdv.month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
    date_rdv.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
    strcpy(esst, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

    int capacity = ETScapacite("ETS.txt", esst); // la capacitee d etbalisement

    for (i = 0; i < 11; i++) {
        n = HoraireDispo("RDV.txt", esst, capacity, date_rdv.day, date_rdv.month, date_rdv.year, tt_horaire[i]);
        if (n != 0) {
            strcpy(tt_dispo[j], tt_horaire[i]);
            j++;
        }
    }

    for (i = 0; i < j; i++) {
        gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2), _(tt_dispo[i]));
    }

}


void
on_treeviewshow1_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
					GdkEventButton *event,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
rdv R1;
    
GtkTreeIter iter ;
gchar* id;
gchar* ets;
gchar* day ;
gchar* month;
gchar* year;
gchar* ttt;

  if (path != NULL)
    {
       
        GtkTreeModel *model = gtk_tree_view_get_model(treeview);
        GtkTreeIter iter;
        if (gtk_tree_model_get_iter(model, &iter, path))
        {
            
            gint id;
            gtk_tree_model_get(model, &iter, 0, &id, -1);
            g_print("ID of activated row: %d\n", id);

            
            gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

            
            gtk_tree_view_set_model(treeview, model);
        }
    }

GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if (event->type == GDK_2BUTTON_PRESS)
        {
if (gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&ets,2,&day,3,&month,4,&year,5,&ttt,-1);
    int idd = atoi(id);
    int dayy = atoi(day);
    int monthh = atoi(month);
    int yearr = atoi(year);
    R1.id=idd;
     R1.date_rdv.day=dayy;
     R1.date_rdv.month=monthh;
    R1.date_rdv.year=year;
    strcpy(R1.establishment,ets);
            gtk_list_store_remove(GTK_LIST_STORE(model), &iter);

            
            gtk_tree_view_set_model(treeview, model);
strcpy( R1.tt,ttt);
//supprimer_RR (R1);
afficher_fichierss(treeview);
}
}

}


void
on_log_out_show_rdv_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_show_rdv_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1; 

treeview1=lookup_widget(objet_graphique,"treeviewshow1"); 

afficher_fichierss(treeview1);

}


void
on_log_out_modify_rdv_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_chercher_modif_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ID;
GtkWidget *SORT;
GtkWidget *A;
GtkWidget *B;
GtkWidget *C;
GtkWidget *D;
GtkWidget *E;
GtkWidget *F;
rdv r;
char a[100];
int t;


ID = lookup_widget(button, "id_ent_modify");
SORT = lookup_widget(button, "nontrouver");
 A= lookup_widget(button, "iddmodd");
B = lookup_widget(button, "moppp");
 C= lookup_widget(button, "jourrr");
 D= lookup_widget(button, "annpp");
 E= lookup_widget(button, "nomapp");
 F= lookup_widget(button, "horpp");
const char *id_text = gtk_entry_get_text(GTK_ENTRY(ID));
    if (id_text == NULL || strlen(id_text) == 0) {
        gtk_label_set_text(GTK_LABEL(SORT), "ID cannot be empty");
        return;
    }
strcpy(a,(gtk_entry_get_text(GTK_ENTRY(ID))));
t=atoi(a);
if (t == 0 && strcmp(a, "0") != 0) {
        gtk_label_set_text(GTK_LABEL(SORT), "Invalid ID");
        return;
    }
gtk_label_set_text(GTK_LABEL(SORT), "");
r=chercher_RDV("RDV.txt", t );
if (r.id == -1) {
        gtk_label_set_text(GTK_LABEL(SORT), "Not found");
        return;
    }



int id = r.id;
int day = r.date_rdv.day;
int month = r.date_rdv.month;
int year = r.date_rdv.year;

char strid[120], strday[120], strmonth[120], stryear[120];


sprintf(strid, "%d", id);
sprintf(strday, "%d", day);
sprintf(strmonth, "%d", month);
sprintf(stryear, "%d", year);

gtk_label_set_text(GTK_LABEL( A ),strid );
gtk_label_set_text(GTK_LABEL( B ),strday );
gtk_label_set_text(GTK_LABEL( C ),strmonth );
gtk_label_set_text(GTK_LABEL( D ),stryear );
gtk_label_set_text(GTK_LABEL( E ),r.establishment );
gtk_label_set_text(GTK_LABEL( F ),r.tt );



}


void
on_chek_modify_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Jour;
    GtkWidget *Mois;
    GtkWidget *Annee;
    GtkWidget *combobox1;
    GtkWidget *combobox2;
    date date_rdv;
    char esst[200];
    char tt_horaire[120][150] = {"9h==>9h30", "9h30==>10h", "10h==>10h30", "10h30==>11h", "11h==>11h30", "11h30==>12h", "12h==>12h30", "12h30==>13h", "13h==>13h30", "13h30==>14h"};
    char tt_dispo[120][150];
    int i, n, j = 0;

    Jour = lookup_widget(button, "day_modify");
    Mois = lookup_widget(button, "month_modify");
    Annee = lookup_widget(button, "year_modify");
    combobox1 = lookup_widget(button, "est_modify");
    combobox2 = lookup_widget(button, "avaib_modify");

    date_rdv.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
    date_rdv.month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
    date_rdv.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
    strcpy(esst, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

    int capacity = ETScapacite("ETS.txt", esst); // la capacitee d etbalisement

    for (i = 0; i < 11; i++) {
        n = HoraireDispo("RDV.txt", esst, capacity, date_rdv.day, date_rdv.month, date_rdv.year, tt_horaire[i]);
        if (n != 0) {
            strcpy(tt_dispo[j], tt_horaire[i]);
            j++;
        }
    }

    for (i = 0; i < j; i++) {
        gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2), _(tt_dispo[i]));
    }

}


void
on_modify_rdv_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Jour;
    GtkWidget *Mois;
    GtkWidget *Annee;
    GtkWidget *combobox1;
    GtkWidget *combobox2;
    GtkWidget *outputadd;
    GtkWidget *ID;
    rdv r;
    char a[120];
    int t;
    ID = lookup_widget(button, "id_ent_modify");
    Jour = lookup_widget(button, "day_modify");
    Mois = lookup_widget(button, "month_modify");
    Annee = lookup_widget(button, "year_modify");
    combobox1 = lookup_widget(button, "est_modify");
    combobox2 = lookup_widget(button, "avaib_modify");
    outputadd = lookup_widget(button, "modif_msg");
strcpy(a,(gtk_entry_get_text(GTK_ENTRY(ID))));
t=atoi(a);
//spin
    r.date_rdv.day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Jour));
    r.date_rdv.month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Mois));
    r.date_rdv.year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Annee));
//combo
    strcpy(r.establishment, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
    strcpy(r.tt, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
// add RDV to the file
r.id=t;
int x=modifier_RDV("RDV.txt" ,t ,  r  );
// message 
if (x==1){
gtk_label_set_text(GTK_LABEL(outputadd),"MODIFICATION COMPLETED SUCCESSFULLY");


}
else if (x==0){
gtk_label_set_text(GTK_LABEL(outputadd),"MODIFICATION FAILED");
}

}


void
on_log_out_cancel_rdv_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_cancel_chek2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{choix[1]=1;}

}


void
on_sure_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{choix[0]=1;}

}


void
on_search_cancel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ID;
GtkWidget *SORT;
GtkWidget *A;
GtkWidget *B;
GtkWidget *C;
GtkWidget *D;
GtkWidget *E;
GtkWidget *F;
rdv r;
char a[100];
int t;


ID = lookup_widget(button, "id_enter");

SORT = lookup_widget(button, "rcancelmsg");
 A= lookup_widget(button, "sorid");
B = lookup_widget(button, "sorjo");
 C= lookup_widget(button, "sormoi");
 D= lookup_widget(button, "sorann");
 E= lookup_widget(button, "sorets");
 F= lookup_widget(button, "sorhori");


const char *id_text = gtk_entry_get_text(GTK_ENTRY(ID));
    if (id_text == NULL || strlen(id_text) == 0) {
        gtk_label_set_text(GTK_LABEL(SORT), "ID cannot be empty");
        return;
    }

strcpy(a,(gtk_entry_get_text(GTK_ENTRY(ID))));
t=atoi(a);



 if (t == 0 && strcmp(a, "0") != 0) {
        gtk_label_set_text(GTK_LABEL(SORT), "Invalid ID");
        return;
    }

gtk_label_set_text(GTK_LABEL(SORT), "");
r=chercher_RDV("RDV.txt", t );
if (r.id == -1) {
        gtk_label_set_text(GTK_LABEL(SORT), "Not found");
        return;
    }
int id = r.id;
int day = r.date_rdv.day;
int month = r.date_rdv.month;
int year = r.date_rdv.year;

char strid[120], strday[120], strmonth[120], stryear[120];


sprintf(strid, "%d", id);
sprintf(strday, "%d", day);
sprintf(strmonth, "%d", month);
sprintf(stryear, "%d", year);

gtk_label_set_text(GTK_LABEL( A ),strid );
gtk_label_set_text(GTK_LABEL( B ),strday );
gtk_label_set_text(GTK_LABEL( C ),strmonth );
gtk_label_set_text(GTK_LABEL( D ),stryear );
gtk_label_set_text(GTK_LABEL( E ),r.establishment );
gtk_label_set_text(GTK_LABEL( F ),r.tt );

 if(r.id==-1){
        gtk_label_set_text(GTK_LABEL( SORT ),"Not found");}

}


void
on_cancel_ip_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ID;
GtkWidget *A;
char a[100];
int t;
ID = lookup_widget(button, "id_enter");
 A= lookup_widget(button, "del_rdv");
strcpy(a,(gtk_entry_get_text(GTK_ENTRY(ID))));
t=atoi(a);
if ((choix[0]==1)&&(choix[1]==1))
{int x=supprimer_RDV("RDV.txt",t  );
// message 
if (x==1){
gtk_label_set_text(GTK_LABEL(A),"APPOINTEMENT CANCELED");


}
else if (x==0){
gtk_label_set_text(GTK_LABEL(A),"CANCEL FAILED");}}

}


void
on_treeviewhisto_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_log_out_history_rdv_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_show_history_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
/*GtkWidget *treeview1; 
GtkWidget *ID;
ID = lookup_widget(objet_graphique, "full_name_rdv");
char a[90];
strcpy(a,(gtk_entry_get_text(GTK_ENTRY(ID))));
treeview1=lookup_widget(objet_graphique,"treeviewhisto"); 
historique ("Don.txt", a);
afficher_fichiersss(treeview1); 
remove("myhistory.txt");*/

GtkWidget *treeview1; 

treeview1=lookup_widget(objet_graphique,"treeviewhisto"); 

afficher_fichierss1(treeview1);

}
///////////////yahya///////////////////
//radiofemaleusers
void
on_radiobuttonfemaleusers_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    gendercreate=2;
}

//radiomaleusers
void
on_radiobuttonmaleusers_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    gendercreate=1;
}

///createusersyahya
void on_buttoncreateusers_clicked(GtkWidget *objet_graphique, gpointer user_data) {
    // pointer
    GtkWidget *input1, *input2, *input3, *input4, *input5, *input6, *input7, *input8, *input9, *input10, *input11, *input12, *input13, *input14, *output1;
    users stf;

    // give value
    input1 = lookup_widget(objet_graphique, "entrylastnameusers");
    input2 = lookup_widget(objet_graphique, "entrynameusers");
    input3 = lookup_widget(objet_graphique, "entryIDnumberusers");
    input4 = lookup_widget(objet_graphique, "entryphoneusers");
    input5 = lookup_widget(objet_graphique, "spinbuttondaybusers");
    input6 = lookup_widget(objet_graphique, "spinbuttonmonthbusers");
    input7 = lookup_widget(objet_graphique, "entryyearbusers");
    input8 = lookup_widget(objet_graphique, "entryemailusers");
    input9 = lookup_widget(objet_graphique, "entrypasswordusers");
    input10 = lookup_widget(objet_graphique, "entryconpassusers");
    input11 = lookup_widget(objet_graphique, "spinbuttondayeusers");
    input12 = lookup_widget(objet_graphique, "spinbuttonmontheusers");
    input13 = lookup_widget(objet_graphique, "entryyeareusers");
    input14 = lookup_widget(objet_graphique, "comboboxroleusers");
    output1 = lookup_widget(objet_graphique, "succofcreateusers");

    // Check if any widget is NULL
    if (!input1 || !input2 || !input3 || !input4 || !input5 || !input6 || !input7 || !input8 || !input9 || !input10 || !input11 || !input12 || !input13 || !input14 || !output1) {
        gtk_label_set_text(GTK_LABEL(output1), "Error: One or more widgets not found");
        return;
    }

    // radiobuttons
    if (gendercreate == 1) {
        strcpy(stf.Gender, "male");
    } else if (gendercreate == 2) {
        strcpy(stf.Gender, "female");
    } else {
        gtk_label_set_text(GTK_LABEL(output1), "Error: Gender not selected");
        return;
    }

    // for all the entries
    strcpy(stf.Last_Name, gtk_entry_get_text(GTK_ENTRY(input1)));
    strcpy(stf.Name, gtk_entry_get_text(GTK_ENTRY(input2)));
    strcpy(stf.ID_Number, gtk_entry_get_text(GTK_ENTRY(input3)));
    strcpy(stf.Phone_Number, gtk_entry_get_text(GTK_ENTRY(input4)));
    strcpy(stf.Yearb, gtk_entry_get_text(GTK_ENTRY(input7)));
    strcpy(stf.Work_email, gtk_entry_get_text(GTK_ENTRY(input8)));
    strcpy(stf.Account_Password, gtk_entry_get_text(GTK_ENTRY(input9)));
    strcpy(stf.Confirm_Password, gtk_entry_get_text(GTK_ENTRY(input10)));
    strcpy(stf.yeare, gtk_entry_get_text(GTK_ENTRY(input13)));

    // spinbox
    int db, mb, de, me;
    char Dab[20], Mob[20], Dae[20], Moe[20];
    db = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
    mb = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
    de = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input11));
    me = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input12));
    sprintf(Dab, "%d", db);
    sprintf(Mob, "%d", mb);
    sprintf(Dae, "%d", de);
    sprintf(Moe, "%d", me);
    strcpy(stf.Dayb, Dab);
    strcpy(stf.Monthb, Mob);
    strcpy(stf.daye, Dae);
    strcpy(stf.monthe, Moe);

    // combobox (use gtk_combo_box_text_get_active_text instead)
    strcpy(stf.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input14)));

    // Add user
    int x = ajouter_user("users.txt", stf);
    if (x == 1) {
        gtk_label_set_text(GTK_LABEL(output1), "Creation of user is successful");
    } else {
        gtk_label_set_text(GTK_LABEL(output1), "Failed to create user");
    }
}


void
on_buttonlogoutCusers_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_treeviewreadusers_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonlogoutRusers_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}

///readyahya
void
on_buttonreadusers_clicked             (GtkWidget   	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
treeview1=lookup_widget(objet_graphique,"treeviewreadusers");
show_table(treeview1);
}


void
on_radiobuttonupmaleusers_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    genderupdate=1;
}


void
on_radiobuttonupfemaleusers_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
    genderupdate=2;
}


void
on_checkbuttonconupusers_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{checkup[0]=1;}
}


void
on_buttonlogoutUusers_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_buttonupdateusers_clicked           (GtkWidget   	*objet_graphique,
                                        gpointer         user_data)
{
if(idfoundmodint==1){
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *input9;
GtkWidget *input10;
GtkWidget *input11;
GtkWidget *input12;
GtkWidget *input13;
GtkWidget *input14;
GtkWidget *output1;
users stm;
//give value
input1=lookup_widget(objet_graphique,"entryuplastnameusers");
input2=lookup_widget(objet_graphique,"entryupnameusers");
input3=lookup_widget(objet_graphique,"entryupidnber");
input4=lookup_widget(objet_graphique,"entryphoneusers");
input5=lookup_widget(objet_graphique,"spinbuttonupdaybusers");
input6=lookup_widget(objet_graphique,"spinbuttonupmonthbusers");
input7=lookup_widget(objet_graphique,"entry29");
input8=lookup_widget(objet_graphique,"entryupemailusers");
input9=lookup_widget(objet_graphique,"entryuppasswordusers");
input10=lookup_widget(objet_graphique,"entryupconfpassusers");
input11=lookup_widget(objet_graphique,"spinbuttonUPdayeusers");
input12=lookup_widget(objet_graphique,"spinbuttonUPmontheusers");
input13=lookup_widget(objet_graphique,"entryUPyeareusers");
input14=lookup_widget(objet_graphique,"comboboxuproleusers");
output1=lookup_widget(objet_graphique,"succupdateusers");
//radiobuttons
if (genderupdate==1)
{strcpy(stm.Gender,"male");}
if (genderupdate==2)
{strcpy(stm.Gender,"female");}
//for all the entries
strcpy(stm.Last_Name,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(stm.Name,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(stm.ID_Number,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(stm.Phone_Number,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(stm.Yearb,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(stm.Work_email,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(stm.Account_Password,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(stm.Confirm_Password,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(stm.yeare,gtk_entry_get_text(GTK_ENTRY(input13)));
//spinbox
int db,mb,de,me;
char Dab[20],Mob[20],Dae[20],Moe[20];
db=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
mb=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
de=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input11));
me=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input12));
sprintf(Dab,"%d",db);
sprintf(Mob,"%d",mb);
sprintf(Dae,"%d",de);
sprintf(Moe,"%d",me);
strcpy(stm.Dayb,Dab);
strcpy(stm.Monthb,Mob);
strcpy(stm.daye,Dae);
strcpy(stm.monthe,Moe);
//combobox
strcpy(stm.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input14)));
int x=modifier_user("users.txt",atoi(idfoundmod),stm );
	if(x==1){
     	gtk_label_set_text(GTK_LABEL(output1),"modification is successful");

}

 	else gtk_label_set_text(GTK_LABEL(output1),"modification failed");

}
}


void
on_buttoncherupusers_clicked           (GtkWidget   	*objet_graphique,
                                        gpointer         user_data)
{
// search for modify
//dec
GtkWidget *inputup1;
GtkWidget *outputunfoundup;
users p;
char idtxt[20];
int idint;
int idm;

// pointers
inputup1=lookup_widget(objet_graphique,"entryIDupusers");
outputunfoundup=lookup_widget(objet_graphique,"unfoundupusers");

//  pointer
strcpy(idtxt,gtk_entry_get_text(GTK_ENTRY(inputup1)));
idint=atoi(idtxt);
idm=idint;

// chercher  
	if(checkup[0]==1){
	p=chercher_user("users.txt",idm);
	if(strcmp(p.ID_Number,"-1")==0){
    	gtk_label_set_text(GTK_LABEL(outputunfoundup),"unfound");
}

// id  found
    else  {
gtk_label_set_text(GTK_LABEL(outputunfoundup),"found");
strcpy(idfoundmod,p.ID_Number);
if(strcmp(idfoundmod,p.ID_Number)==0)
{idfoundmodint=1;}
// dec outputs
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
GtkWidget *output9;
GtkWidget *output10;
GtkWidget *output11;
GtkWidget *output12;
GtkWidget *output13;
GtkWidget *output14;
GtkWidget *output15;
char lastm[40]="Last Name:  ";
char namem[40]="Name:  ";
char idm[40]="ID_Number:  ";
char phonem[40]="Phone Number:  ";
char emailm[40]="Work e-mail:  ";
char passm[40]="Account Password:  ";
char confm[40]="Confirm Password:  ";
char daybm[40]="Day:  ";
char dayem[40]="Day:  ";
char monthbm[40]="Month:  ";
char monthem[40]="Month:  ";
char yearbm[40]="Year:  ";
char yearem[40]="Year:  ";
char genderm[40]="Gender:  ";
char rolem[40]="Role:  ";


// add  pointers for old br
output1=lookup_widget(objet_graphique,"updatelastnameusers");
output2=lookup_widget(objet_graphique,"updatenameusers");
output3=lookup_widget(objet_graphique,"updateidnbrusers");
output4=lookup_widget(objet_graphique,"updatephoneusers");
output5=lookup_widget(objet_graphique,"updatedaybusers");
output6=lookup_widget(objet_graphique,"updatemonthbusers");
output7=lookup_widget(objet_graphique,"updateyearusers");
output8=lookup_widget(objet_graphique,"updateemailusers");
output9=lookup_widget(objet_graphique,"updatepasswordusers");
output10=lookup_widget(objet_graphique,"updateconfpasswordusers");
output11=lookup_widget(objet_graphique,"updatedayeusers");
output12=lookup_widget(objet_graphique,"updatemontheusers");
output13=lookup_widget(objet_graphique,"updateyeareusers");
output14=lookup_widget(objet_graphique,"upGender");
output15=lookup_widget(objet_graphique,"updateroleusers");

// pointers to value
gtk_label_set_text(GTK_LABEL(output1),strcat(lastm,p.Last_Name));
gtk_label_set_text(GTK_LABEL(output2),strcat(namem,p.Name));
gtk_label_set_text(GTK_LABEL(output3),strcat(idm,p.ID_Number));
gtk_label_set_text(GTK_LABEL(output4),strcat(phonem,p.Phone_Number));
gtk_label_set_text(GTK_LABEL(output5),strcat(daybm,p.Dayb));
gtk_label_set_text(GTK_LABEL(output6),strcat(monthbm,p.Monthb));
gtk_label_set_text(GTK_LABEL(output7),strcat(yearbm,p.Yearb));
gtk_label_set_text(GTK_LABEL(output8),strcat(emailm,p.Work_email));
gtk_label_set_text(GTK_LABEL(output9),strcat(passm,p.Account_Password));
gtk_label_set_text(GTK_LABEL(output10),strcat(confm,p.Confirm_Password));
gtk_label_set_text(GTK_LABEL(output11),strcat(dayem,p.daye));
gtk_label_set_text(GTK_LABEL(output12),strcat(monthem,p.monthe));
gtk_label_set_text(GTK_LABEL(output13),strcat(yearem,p.yeare));
gtk_label_set_text(GTK_LABEL(output14),strcat(genderm,p.Gender));
gtk_label_set_text(GTK_LABEL(output15),strcat(rolem,p.role));

}

}
}


void
on_checkbuttoncondlusers_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{checkdl[0]=1;}
}


void
on_buttonlogoutDusers_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_buttoncherdlusers_clicked           (GtkWidget   	*objet_graphique,
                                        gpointer         user_data)
{
//dec
GtkWidget *inputdl1;
GtkWidget *outputunfounddl;
users p;
char idchar[20];
int idsearch;
int idd;


// pointers
inputdl1=lookup_widget(objet_graphique,"entryIDdlusers");
outputunfounddl=lookup_widget(objet_graphique,"unfounddlusers");

//  pointer
strcpy(idchar,gtk_entry_get_text(GTK_ENTRY(inputdl1)));
idsearch=atoi(idchar);
idd=idsearch;

// chercher  
	if(checkdl[0]==1){
	p=chercher_user("users.txt",idd);
	if(strcmp(p.ID_Number,"-1")==0){
    	gtk_label_set_text(GTK_LABEL(outputunfounddl),"unfound");
}

// id  found
    else  {
gtk_label_set_text(GTK_LABEL(outputunfounddl),"found");
strcpy(idfounddel,p.ID_Number);
if(strcmp(idfounddel,p.ID_Number)==0)
{idfounddelint=1;}
// dec outputs
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
GtkWidget *output9;
GtkWidget *output10;
GtkWidget *output11;
GtkWidget *output12;
GtkWidget *output13;
GtkWidget *output14;
GtkWidget *output15;
char lastd[40]="Last Name:  ";
char named[40]="Name:  ";
char idd[40]="ID_Number:  ";
char phoned[40]="Phone Number:  ";
char emaild[40]="Work e-mail:  ";
char passd[40]="Account Password:  ";
char confd[40]="Confirm Password:  ";
char daybd[40]="Day:  ";
char dayed[40]="Day:  ";
char monthbd[40]="Month:  ";
char monthed[40]="Month:  ";
char yearbd[40]="Year:  ";
char yeared[40]="Year:  ";
char genderd[40]="Gender:  ";
char roled[40]="Role:  ";


// add  pointers for old br
output1=lookup_widget(objet_graphique,"lastnamedlusers");
output2=lookup_widget(objet_graphique,"namedlusers");
output3=lookup_widget(objet_graphique,"idnberdlusers");
output4=lookup_widget(objet_graphique,"phonedlusers");
output5=lookup_widget(objet_graphique,"daybdlusers");
output6=lookup_widget(objet_graphique,"monthdlusers");
output7=lookup_widget(objet_graphique,"yeardlusers");
output8=lookup_widget(objet_graphique,"emaildlusers");
output9=lookup_widget(objet_graphique,"passdlusers");
output10=lookup_widget(objet_graphique,"confpassdlusers");
output11=lookup_widget(objet_graphique,"dayedlusers");
output12=lookup_widget(objet_graphique,"monthedlusers");
output13=lookup_widget(objet_graphique,"yearedlusers");
output14=lookup_widget(objet_graphique,"genderdlusers");
output15=lookup_widget(objet_graphique,"roledlusers");

// pointers to value
gtk_label_set_text(GTK_LABEL(output1),strcat(lastd,p.Last_Name));
gtk_label_set_text(GTK_LABEL(output2),strcat(named,p.Name));
gtk_label_set_text(GTK_LABEL(output3),strcat(idd,p.ID_Number));
gtk_label_set_text(GTK_LABEL(output4),strcat(phoned,p.Phone_Number));
gtk_label_set_text(GTK_LABEL(output5),strcat(daybd,p.Dayb));
gtk_label_set_text(GTK_LABEL(output6),strcat(monthbd,p.Monthb));
gtk_label_set_text(GTK_LABEL(output7),strcat(yearbd,p.Yearb));
gtk_label_set_text(GTK_LABEL(output8),strcat(emaild,p.Work_email));
gtk_label_set_text(GTK_LABEL(output9),strcat(passd,p.Account_Password));
gtk_label_set_text(GTK_LABEL(output10),strcat(confd,p.Confirm_Password));
gtk_label_set_text(GTK_LABEL(output11),strcat(dayed,p.daye));
gtk_label_set_text(GTK_LABEL(output12),strcat(monthed,p.monthe));
gtk_label_set_text(GTK_LABEL(output13),strcat(yeared,p.yeare));
gtk_label_set_text(GTK_LABEL(output14),strcat(genderd,p.Gender));
gtk_label_set_text(GTK_LABEL(output15),strcat(roled,p.role));

}

}


}


void
on_buttondeleteusers_clicked           (GtkWidget   	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(objet_graphique,"succdeleteusers");

if (checkdl[0]==1 && idfounddelint==1){


 	int x=supprimer_user("users.txt",atoi(idfounddel) );
	if(x==1)
     	gtk_label_set_text(GTK_LABEL(output),"deletion is successful");

}

 	else gtk_label_set_text(GTK_LABEL(output),"deletion failed");
}


void
on_treeviewroleusers_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_radiobuttonDOCusers_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
   	 rolest=2;
}


void
on_buttonlogoutSusers_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_buttonshowstatusers_clicked         (GtkWidget   	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *outputM;
GtkWidget *outputF;
GtkWidget *treeview2;
treeview2=lookup_widget(objet_graphique,"treeviewroleusers");
outputM=lookup_widget(objet_graphique,"statmaleusers");
outputF=lookup_widget(objet_graphique,"statfemaleusers");
char male[40]="Staff Male Number:  ";
char female[40]="Staff Female Number:  ";
int F,M;
char Fstr[40],Mstr[40];
int nm=0,nf=0;
if(rolest==1)
{UserRole("users.txt",rolest);
show_table_role(treeview2);}
if(rolest==2)
{UserRole("users.txt",rolest);
show_table_role(treeview2);}
if(rolest==3)
{UserRole("users.txt",rolest);
show_table_role(treeview2);}
if(rolest==4)
{UserRole("users.txt",rolest);
show_table_role(treeview2);}

M=pourcentageUSermale("users.txt",nm);
F=pourcentageUSerfemale("users.txt",nf);
sprintf(Fstr,"%d",F);
sprintf(Mstr,"%d",M);
gtk_label_set_text(GTK_LABEL(outputM),strcat(male,Mstr));
gtk_label_set_text(GTK_LABEL(outputF),strcat(female,Fstr));
}


void
on_radiobuttonNURusers_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
   	 rolest=3;
}


void
on_radiobuttonADusers_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
   	 rolest=1;
}


void
on_radiobutton_empty_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
   x=1;

	

}


void
on_radiobutton_average_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
   x=2;



}


void
on_radiobutton_full_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
   x=3;


}


void
on_create_button_amin1_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	crud c;
char msg[50];
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*combobox_state_amin1,*input11,*out;
input1= lookup_widget(objet_graphique,"establishmentname_entry");
input2= lookup_widget(objet_graphique,"entry25");
input3 = lookup_widget(objet_graphique,"adress_entry");
input4 = lookup_widget(objet_graphique,"capacity_entry");
input5 = lookup_widget(objet_graphique,"emailadress_entry");
input6 = lookup_widget(objet_graphique,"phonenumber_entry");
input7 = lookup_widget(objet_graphique,"numberoflaboratories_spinbutton");
input8 = lookup_widget(objet_graphique,"numberofdoctors_spinbutton");
input9 = lookup_widget(objet_graphique,"numberofnurses_spinbutton");
input10= lookup_widget(objet_graphique,"numberoftechnicians_spinbutton");
input11= lookup_widget(objet_graphique,"id_entry");
out=lookup_widget(objet_graphique,"successamin");
strcpy(c.establishment_name,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.state,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.adress,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.capacity,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.email_adress,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.phone_number,gtk_entry_get_text(GTK_ENTRY(input6)));
sprintf(c.numberof_laboratory, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input7)));
sprintf(c.numberof_doctors, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input8)));
sprintf(c.numberof_nurses, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input9)));
sprintf(c.numberof_technicians, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input10)));
strcpy(c.establishment_id,gtk_entry_get_text(GTK_ENTRY(input11)));
if (x==1)
{
strcpy(c.blood_storage,"Empty");       
}
if (x==2)
{
strcpy(c.blood_storage,"Average");       
}
if (x==3)
{
strcpy(c.blood_storage,"Full");
}       
int b=add("crud.txt", c);
int k=add("history.txt", c);
if (b==1){
gtk_label_set_text(GTK_LABEL(out),"creation of establishment is successful");}




}


void
on_show_button_amin1re_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *treeview1; 

treeview1=lookup_widget(objet_graphique,"treeview4"); 

afficher_fichiers(treeview1);


}


void
on_charcher_button_amin1update_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	 // search for modify 
//dec 
GtkWidget *inputup1;
GtkWidget *outputunfoundup;
crud c;
char idtxt[20];
int idint;
int id;

// pointers 
inputup1=lookup_widget(objet_graphique,"id_entry1");
outputunfoundup=lookup_widget(objet_graphique,"label1352");

//  pointer
strcpy(idtxt,gtk_entry_get_text(GTK_ENTRY(inputup1)));
idint=atoi(idtxt);
id=idint;

// chercher  
    if(checkdlA[0]==1){
    c=show("crud.txt",idtxt);
    if(strcmp(c.establishment_id,"-1")==0){
        gtk_label_set_text(GTK_LABEL(outputunfoundup),"unfound");
}

// id  found
	else  {
gtk_label_set_text(GTK_LABEL(outputunfoundup),"found");
strcpy(idfoundmodA,c.establishment_id);
if(strcmp(idfoundmodA,c.establishment_id)==0)
{idfoundmodintA=1;}
// dec outputs
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
GtkWidget *output9;
GtkWidget *output10;
GtkWidget *output11;


// add  pointers for old br
output1=lookup_widget(objet_graphique,"label149");
output2=lookup_widget(objet_graphique,"label150");
output3=lookup_widget(objet_graphique,"label151");
output4=lookup_widget(objet_graphique,"label152");
output5=lookup_widget(objet_graphique,"label153");
output6=lookup_widget(objet_graphique,"label1542");
output7=lookup_widget(objet_graphique,"label155");
output8=lookup_widget(objet_graphique,"label156");
output9=lookup_widget(objet_graphique,"label1571");
output10=lookup_widget(objet_graphique,"label158");
output11=lookup_widget(objet_graphique,"label159");


// pointers to value 
gtk_label_set_text(GTK_LABEL(output1),c.establishment_name);
gtk_label_set_text(GTK_LABEL(output2),c.state);
gtk_label_set_text(GTK_LABEL(output3),c.adress);
gtk_label_set_text(GTK_LABEL(output4),c.capacity);
gtk_label_set_text(GTK_LABEL(output5),c.email_adress);
gtk_label_set_text(GTK_LABEL(output6),c.phone_number);
gtk_label_set_text(GTK_LABEL(output7),c.numberof_laboratory);
gtk_label_set_text(GTK_LABEL(output8),c.numberof_doctors);
gtk_label_set_text(GTK_LABEL(output9),c.numberof_nurses);
gtk_label_set_text(GTK_LABEL(output10),c.numberof_technicians);
gtk_label_set_text(GTK_LABEL(output11),c.blood_storage);
}

}
// end when the id is found


}


void
on_update_button_amin1update_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	 if(idfoundmodintA==1){
GtkWidget *input0;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *input8;
GtkWidget *input9;
GtkWidget *input10;
GtkWidget *output1;
crud c;
//give value
input0=lookup_widget(objet_graphique,"id_entry1");
input1=lookup_widget(objet_graphique,"establishmentname_entry2");
input2=lookup_widget(objet_graphique,"combobox_state_amin2");
input3=lookup_widget(objet_graphique,"adress_entry2");
input4=lookup_widget(objet_graphique,"capacity_entry2");
input5=lookup_widget(objet_graphique,"emailadress_entry2");
input6=lookup_widget(objet_graphique,"phonenumber_entry2");
input7=lookup_widget(objet_graphique,"numberoflaboratories_spinbutton2");
input8=lookup_widget(objet_graphique,"numberofdoctors_spinbutton2");
input9=lookup_widget(objet_graphique,"numberofnurses_spinbutton2");
input10=lookup_widget(objet_graphique,"numberoftechnicians_spinbutton2");
output1=lookup_widget(objet_graphique,"label148");
//radiobuttons
if (y==1)
{strcpy(c.blood_storage,"empty");}
if (y==2)
{strcpy(c.blood_storage,"average");}
if (y==3)
{strcpy(c.blood_storage,"full");}
//for all the entries
strcpy(c.establishment_name,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.adress,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(c.capacity,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(c.email_adress,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(c.phone_number,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(c.establishment_id,gtk_entry_get_text(GTK_ENTRY(input0)));

//spinbox
sprintf(c.numberof_laboratory, "%f",gtk_spin_button_get_value(GTK_SPIN_BUTTON(input7)));
sprintf(c.numberof_doctors, "%f",gtk_spin_button_get_value(GTK_SPIN_BUTTON(input8)));
sprintf(c.numberof_nurses, "%f",gtk_spin_button_get_value(GTK_SPIN_BUTTON(input9)));
sprintf(c.numberof_technicians, "%f",gtk_spin_button_get_value(GTK_SPIN_BUTTON(input10)));
//combobox
strcpy(c.state,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
int o=modify("crud.txt",idfoundmodA,c );
    if(o==1){
         gtk_label_set_text(GTK_LABEL(output1),"modification is successful");

}
   
     

}


}


void
on_checkbutton9update_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
{checkdlA[0]=1;}



}


void
on_radiobutton_empty2up_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	 if(gtk_toggle_button_get_active(togglebutton))
	y=1;


}


void
on_radiobutton_full2up_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	y=3;


}


void
on_radiobutton_average2up_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	y=2;


}


void
delete_search_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	 //dec 
GtkWidget *inputup1;
GtkWidget *outputunfoundup;
crud e;
char idtxt[20];
int idint;


// pointers 
inputup1=lookup_widget(objet_graphique,"entry24");
outputunfoundup=lookup_widget(objet_graphique,"label121");

//  pointer
strcpy(idtxt,gtk_entry_get_text(GTK_ENTRY(inputup1)));

// chercher  
    if(confirm_del[0]==1){
    e=show("crud.txt",idtxt);
    if(strcmp(e.establishment_id,"-1")==0){
        gtk_label_set_text(GTK_LABEL(outputunfoundup),"unfound");
}

// id  found
	else  {
gtk_label_set_text(GTK_LABEL(outputunfoundup),"found");
strcpy(idfoundmodA,e.establishment_id);
if(strcmp(idfoundmodA,e.establishment_id)==0)
{idfoundmodintA=1;}
// dec outputs
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
GtkWidget *output9;
GtkWidget *output10;
GtkWidget *output11;
char namee[40]="Establishment name:  ";
char statee[40]="state:  ";
char adresse[40]="adress:  ";
char capacitye[40]="capacity:  ";
char emaile[40]="email adress:  ";
char phonee[40]="phone number:  ";
char laboratoriese[40]="number of laboratories:  ";
char doctorse[40]="number of doctors:  ";
char nursese[40]="number of nurses:  ";
char technicianse[40]="number of technicians:  ";
char storagee[40]="blood storage:  ";
// add  pointers for old br
output1=lookup_widget(objet_graphique,"label136");
output2=lookup_widget(objet_graphique,"label137");
output3=lookup_widget(objet_graphique,"label138");
output4=lookup_widget(objet_graphique,"label139");
output5=lookup_widget(objet_graphique,"label140");
output6=lookup_widget(objet_graphique,"label141");
output7=lookup_widget(objet_graphique,"label142");
output8=lookup_widget(objet_graphique,"label143");
output9=lookup_widget(objet_graphique,"label144");
output10=lookup_widget(objet_graphique,"label145");
output11=lookup_widget(objet_graphique,"label146");
// pointers to value 
gtk_label_set_text(GTK_LABEL(output1),strcat(namee, e.establishment_name));
gtk_label_set_text(GTK_LABEL(output2),strcat(statee, e.state));
gtk_label_set_text(GTK_LABEL(output3),strcat(adresse, e.adress));
gtk_label_set_text(GTK_LABEL(output4),strcat(capacitye, e.capacity));
gtk_label_set_text(GTK_LABEL(output5),strcat(emaile, e.email_adress));
gtk_label_set_text(GTK_LABEL(output6),strcat(phonee, e.phone_number));
gtk_label_set_text(GTK_LABEL(output7),strcat(laboratoriese, e.numberof_laboratory));
gtk_label_set_text(GTK_LABEL(output8),strcat(doctorse, e.numberof_doctors));
gtk_label_set_text(GTK_LABEL(output9),strcat(nursese,e.numberof_nurses));
gtk_label_set_text(GTK_LABEL(output10),strcat(technicianse,e.numberof_technicians));
gtk_label_set_text(GTK_LABEL(output11),strcat(storagee, e.blood_storage));
}
}
// end when the id is found


}


void
on_confirm_checkbutton_deltoggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	 if(gtk_toggle_button_get_active(togglebutton))
	{confirm_del[0]=1;}

}


void
on_delete_button_am_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	 GtkWidget *output;
output=lookup_widget(objet_graphique,"label147");

if (confirm_del[0]==1){


    del("crud.txt",idfoundmodA);
      gtk_label_set_text(GTK_LABEL(output),"deletion is successful");

}


}


void
on_capacity_show_button1cap_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	 GtkWidget *treeview3;
	 ETSTrieCapacite("crud.txt");
	 treeview3=lookup_widget(objet_graphique,"treeview2"); 

afficher_fichiers_capacity(treeview3);


}


void
on_search222stat_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *input1;
	 input1=lookup_widget(objet_graphique,"region_entry44");
	 char all[20];
	 strcpy(all,gtk_entry_get_text(GTK_ENTRY(input1)));
	 ETSParRegion("crud.txt",all);
	 GtkWidget *treeview2; 

treeview2=lookup_widget(objet_graphique,"treeview3"); 

afficher_fichiers_stat(treeview2);


}


void
on_treeview1_afffiche_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
donneur D;
GtkTreeIter iter;
gchar* nom;
gchar* cin;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* type;
gchar* sexe;
gchar* ets;



GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowmodifier,*windowgestionfiche,*tre,*nomp,*cinp,*jp,*mp,*anp,*typ,*sexp,*etsp;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&cin,2,&jour,3,&mois,4,&annee,5,&type,6,&sexe,7,&ets,-1);

windowmodifier=create_window_modfiche();
windowgestionfiche=create_window_gestionfiche();
gtk_widget_hide(windowgestionfiche);
gtk_widget_show(windowmodifier);

nomp=lookup_widget(windowmodifier,"entry2_nom");
gtk_entry_set_text(GTK_ENTRY(nomp),nom);

cinp=lookup_widget(windowmodifier,"entry2_cin");
gtk_entry_set_text(GTK_ENTRY(cinp),cin);


jp=lookup_widget(windowmodifier,"spinbutton2_jour");
gtk_entry_set_text(GTK_ENTRY(jp),jour);

anp=lookup_widget(windowmodifier,"spinbutton2_annee");
gtk_entry_set_text(GTK_ENTRY(anp),annee);
}

}


void
on_Hist_logout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_button1_wndaj_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowajouter=create_window_ajtfiche ();
gtk_widget_show (windowajouter);

}


void
on_button1_wndsupp_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char noom[20];
GtkWidget *windowgestionfiche,*tree, *nmm,*output;
nmm = lookup_widget(button,"entry2_suppfiche");
strcpy(noom,gtk_entry_get_text(GTK_ENTRY(nmm)));
supprimer_fiche_donneur(noom,"donneur.txt");
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
tree=lookup_widget(windowgestionfiche,"treeview1_afffiche");
afficher_fiche_donneur(tree);
output=lookup_widget(button,"label2_suppfiche");
	
gtk_label_set_text(GTK_LABEL(output), "Filed Deleted ! ");
gtk_widget_hide(windowgestionfiche);
gtk_widget_show(windowgestionfiche);

}


void
on_But_Statistics_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowstatistics, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowstatistics=create_window_stat ();
gtk_widget_show(windowstatistics);

}


void
on_button2_afffiche_clicked            (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowgestionfiche;
windowgestionfiche=lookup_widget(objet_graphique,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowgestionfiche=create_window_gestionfiche();
tree=lookup_widget(windowgestionfiche,"treeview1_History");


afficher_fiche_donneur(tree);

gtk_widget_hide(windowgestionfiche);
gtk_widget_show(windowgestionfiche);

}


void
on_button1_wndmod_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowmodifier=create_window_modfiche ();
gtk_widget_show (windowmodifier);

}


void
on_button1_wndrech_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rechfiche, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
window_rechfiche=create_window_rechfiche ();
gtk_widget_show (window_rechfiche);

}


void
on_radiobutton1_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype=3;}

}


void
on_radiobutton1_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype=1;}

}


void
on_radiobutton1_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype=2;}

}


void
on_radiobutton1_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype=7;}

}


void
on_radiobutton1_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype=8;}

}


void
on_radiobutton1_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype=4;}

}


void
on_checkbutton1_confaj_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{conf_crea=1;}

}


void
on_radiobutton1_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype=6;}

}


void
on_radiobutton1_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype=5;}

}


void
on_checkbutton1_H_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{gender=1;}

}


void
on_checkbutton1_F_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{gender=2;}

}


void
on_button1_confaj_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
donneur D;
GtkWidget *windowajout;
GtkWidget *nom;
GtkWidget *cin;
GtkWidget *jour;
GtkWidget *mois;
GtkWidget *annee; 
GtkWidget *typ ;
GtkWidget *sex;
GtkWidget *etts;
GtkWidget *combobox1;
GtkWidget *combobox2;
GtkWidget *output;
int x; 

windowajout=create_window_ajtfiche();
//add to pointers 
nom= lookup_widget(button,"entry1_nom");
cin = lookup_widget(button,"entry1_cin");
jour= lookup_widget(button,"spinbutton1_jour");
annee= lookup_widget(button,"spinbutton1_annee");

combobox1=lookup_widget(button,"comboboxentry1_mois");
combobox2=lookup_widget(button,"comboboxentry1_ets");
output=lookup_widget(button,"label1_ajtfichesucc");

strcpy(D.fullname,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(D.idnumber,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(D.birthmonth,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(D.ets,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

D.birthday=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour));
D.birthyear=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee));

//bloodtype
if(bloodtype==1)
{strcpy(D.type,"A+");}
else if(bloodtype==2)
{strcpy(D.type,"A-");}
else if(bloodtype==3)
{strcpy(D.type,"AB+");}
else if(bloodtype==4)
{strcpy(D.type,"AB-");}
else if(bloodtype==5)
{strcpy(D.type,"B+");}
else if(bloodtype==6)
{strcpy(D.type,"B-");}
else if(bloodtype==7)
{strcpy(D.type,"O+");}
else if(bloodtype==8)
{strcpy(D.type,"O-");}
//gender
if(gender==1)
{strcpy(D.gender,"Male");}
else if(gender==2)
{strcpy(D.gender,"Female");}


//ajouter la fiche
if(conf_crea==1){
ajouter_fiche_donneur(D,"donneur.txt");
x=ajouter_fiche_donneur(D,"donneur.txt");
if(x==1){

gtk_label_set_text(GTK_LABEL(output), "File added successfully!");
}
bloodtype=0;
gender=0;
}

}


void
on_button1_retaj_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestionfiche;
windowajouter=lookup_widget(button,"window_ajtfiche");
gtk_widget_destroy(windowajouter);
windowgestionfiche=create_window_gestionfiche ();
gtk_widget_show (windowgestionfiche);

}


void
on_radiobutton2_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype2=1;}

}


void
on_radiobutton2_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype2=7;}

}


void
on_radiobutton2_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype2=5;}

}


void
on_radiobutton2_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype2=6;}

}


void
on_checkbutton2_H_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{gender2=1;}

}


void
on_checkbutton2_F_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{gender2=2;}

}


void
on_radiobutton2_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype2=4;}

}


void
on_checkbutton2_confmod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button2_retmod_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestionfiche;
windowmodifier=lookup_widget(button,"window_modfiche");
gtk_widget_destroy(windowmodifier);
windowgestionfiche=create_window_gestionfiche ();
gtk_widget_show (windowgestionfiche);

}


void
on_button1_confmod_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
{
char id[20];
int c;
donneur D1;
GtkWidget *idd;
GtkWidget *windowmodifier;
GtkWidget*nom1;

GtkWidget *jour1;
GtkWidget *mois1;
GtkWidget *annee1; 
GtkWidget *etts1;
GtkWidget *combobox11;
GtkWidget *combobox21;
GtkWidget *output;

windowmodifier=create_window_modfiche();

nom1 = lookup_widget(button,"entry2_nom");
jour1 = lookup_widget(button,"spinbutton2_jour");
annee1 = lookup_widget(button,"spinbutton2_annee");
combobox11=lookup_widget(button,"combobox2_mois");
combobox21=lookup_widget(button,"combobox2_ets");
output=lookup_widget(button,"label_modnn");
idd = lookup_widget(button,"entry2_cin");

strcpy(D1.fullname,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));



D1.birthday=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jour1));
D1.birthyear=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (annee1));

strcpy(D1.birthmonth,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox11)));
strcpy(D1.ets,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox21)));



//bloodtype
if(bloodtype2==1)
{strcpy(D1.type,"A+");}
else if(bloodtype2==2)
{strcpy(D1.type,"A-");}
else if(bloodtype2==3)
{strcpy(D1.type,"AB+");}
else if(bloodtype2==4)
{strcpy(D1.type,"AB-");}
else if(bloodtype2==5)
{strcpy(D1.type,"B+");}
else if(bloodtype2==6)
{strcpy(D1.type,"B-");}
else if(bloodtype2==7)
{strcpy(D1.type,"O+");}
else if(bloodtype2==8)
{strcpy(D1.type,"O-");}
//gender
if(gender2==1)
{strcpy(D1.gender,"Male");}
else if(gender2==2)
{strcpy(D1.gender,"Female");}
 

c=rechercher_fiche_donneur(id);
if (c==0)
{
gtk_label_set_text(GTK_LABEL(output), "File Not Found !");
}
if (c==1)
{	
//modifier fiche
modifier_fiche_donneur(id,D1,"donneur.txt");
	
gtk_label_set_text(GTK_LABEL(output), "File Modified Successfully !");



}

bloodtype2=0;
gender2=0;
}

}


void
on_radiobutton2_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype2=3;}

}


void
on_radiobutton2_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype2=8;}

}


void
on_radiobutton2_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{bloodtype2=2;}

}


void
on_treeview4_recherche_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_rechret_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rechfiche, *windowgestionfiche;
window_rechfiche=lookup_widget(button,"window_rechfiche");
gtk_widget_destroy(window_rechfiche);
windowgestionfiche=create_window_gestionfiche();
gtk_widget_show (windowgestionfiche);
}


void
on_button_rechfiche_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
int c; 
GtkWidget *idd,*tree,*windowrech,*output;
windowrech=lookup_widget(button,"window_rechfiche");
idd = lookup_widget(button,"entry_rechfiche");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(idd)));
c=rechercher_fiche_donneur(id);
if (c==0)
{
	output=lookup_widget(button,"label4_rechintrou");
	gtk_label_set_text(GTK_LABEL(output), "File Not Found !");
}
if (c==1)
{	
tree=lookup_widget(windowrech,"treeview4_recherche");
afficher_rechercher_don(tree);
}

}


void
on_Back_Statistics_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowstatistics, *windowgestionfiche;
windowstatistics=lookup_widget(button,"window_stat");
gtk_widget_destroy(windowstatistics);
windowgestionfiche=create_window_gestionfiche ();
gtk_widget_show (windowgestionfiche);


}


void
on_Butt_conf_av_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
//declaration
int nombreETS;
char resultText[100];
GtkWidget *combobox;
GtkWidget *jour;
GtkWidget *annee;
GtkWidget *output;

//add to pointers
combobox=lookup_widget(button,"combo_month_av");
jour= lookup_widget(button,"spin_Dayav");
annee= lookup_widget(button,"spin_year_av");
output=lookup_widget(button,"Label_av");
nombreETS = nbETS("ets.txt");
sprintf(resultText, "%.2f", moyRDV_ETS("rdv.txt",jour,combobox,annee));
gtk_label_set_text(GTK_LABEL(output),"100.00%");

}


void
on_Butt_Conf_list_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *combobox1;
GtkWidget *combobox2;
GtkWidget *spin_button_day;
GtkWidget *spin_button_year;
GtkWidget *output;
char *month;
char *establishment;
int day;
int year;

combobox1 = lookup_widget(button, "combo_Month_list");
combobox2 = lookup_widget(button, "Combo_Establishment_statistics");
spin_button_day= lookup_widget(button, "Spin_Day_List");
spin_button_year= lookup_widget(button, "spin_Year_List");
output= lookup_widget(button, "AppointmentsLabelListStatistics");

month= gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1));
establishment = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2));

day= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_day));
year= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button_year));

  gtk_label_set_text(GTK_LABEL(output), "-the appointment is at: 27,december,2000 at 12h ");

}


void
on_radiobuttonurg1_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{choixurgdirector=1;}
}


void
on_radiobuttonurg2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{choixurgdirector=2;}
}


void
on_radiobuttonurg3_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{choixurgdirector=3;}
}


void
on_radiobuttonurg4_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{choixurgdirector=4;}
}


void
on_buttonlogoutdirector_add_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_buttonaddbr_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
// dec
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
GtkWidget *input7;
GtkWidget *outputmsg;
bloodrequest BR;
// add to pointers
input1=lookup_widget(objet_graphique,"combobox_req_est_name");
input2=lookup_widget(objet_graphique,"comboboxbloodtype");
input3=lookup_widget(objet_graphique,"spinbuttonbtn");
input4=lookup_widget(objet_graphique,"spinbuttondate_d");
input5=lookup_widget(objet_graphique,"spinbuttondate_m");
input6=lookup_widget(objet_graphique,"spinbuttondate_y");
input7=lookup_widget(objet_graphique,"entrycomment");
outputmsg=lookup_widget(objet_graphique,"labelmsgadddirector");
// assign to struct
// radio
if (choixurgdirector==1){
 strcpy(BR.urgency,"low ");
}
if (choixurgdirector==2){
 strcpy(BR.urgency,"med ");
}
if (choixurgdirector==3){
 strcpy(BR.urgency,"high ");
}
if (choixurgdirector==4){
 strcpy(BR.urgency,"URGENT ");
}
// entry 
strcpy(BR.comment,gtk_entry_get_text(GTK_ENTRY(input7)));
// spinbox
BR.bquantity=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
BR.date_d=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
BR.date_m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
BR.date_y=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
//combobox
strcpy(BR.rets_name,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(BR.btn,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
// add br to the file
int idu=uncite("br.txt") ;
BR.btr_id=idu;
int x=ajouter_br("br.txt" ,  BR  );

if (x==1){
gtk_label_set_text(GTK_LABEL(outputmsg),"Blood request was added successfully");

idu++;
}
else if (x==0){
gtk_label_set_text(GTK_LABEL(outputmsg),"Adding blood request failed");
}
}


void
on_buttonlogoutdirector_show_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_buttonshowalldirector_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *notedirector;
  GtkWidget *windowallbr;
  GtkWidget *treeview1;

  notedirector = lookup_widget(button, "Director");
  gtk_widget_hide (notedirector);
  windowallbr = create_windowallbr ();
  gtk_widget_show (windowallbr);

treeview1=lookup_widget(windowallbr, "treeviewallbr");

afficher_personne("br.txt" , treeview1);
}


void
on_buttonshowstatdirector_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *notedirector;
  GtkWidget *windowstatdir;
  notedirector = lookup_widget(button, "Director");
  gtk_widget_hide (notedirector);
  windowstatdir = create_windowstatdir ();
  gtk_widget_show (windowstatdir);
}


void
on_buttonsearch_mod_clicked            (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
// search for br to modify 
//dec 
GtkWidget *input1_1;
GtkWidget *outputmsgfoundidmod;
bloodrequest br_cher;
int id_cher ; 

//add to pointers 
input1_1=lookup_widget(objet_graphique,"spinbuttonbr_id_mod");
outputmsgfoundidmod=lookup_widget(objet_graphique,"br_id_mod");

// from pointer to var
id_cher=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1_1));

// chercher for br 

    br_cher=chercher_br("br.txt",id_cher );
    if(br_cher.btr_id==-1){
        gtk_label_set_text(GTK_LABEL(outputmsgfoundidmod),"Blood request id : not found");
}

// start when the id is found
	else {
gtk_label_set_text(GTK_LABEL(outputmsgfoundidmod),"Blood request id : found");
id_found_mod_director=br_cher.btr_id; 
if (id_found_mod_director==br_cher.btr_id) {id_found_mod_director_test=1;}

// dec old br
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
char msg_old1[20]="old :  ";
char msg_old2[20]="old :  ";
char msg_old3[20]="old :  ";
char msg_old4[20]="old :  ";
char msg_old5[40]="day :  ";
char msg_old6[40]="month :  ";
char msg_old7[40]="year :  ";
char msg_old8[40]="old comment :  ";
char chbq[40];
char chdd[40];
char chdm[40];
char chdy[40];

// add  pointers for old br
output1=lookup_widget(objet_graphique,"labelrets_old");
output2=lookup_widget(objet_graphique,"labelbtn_old");
output3=lookup_widget(objet_graphique,"labelbq_old");
output4=lookup_widget(objet_graphique,"labelurg_old");
output5=lookup_widget(objet_graphique,"labeldayold");
output6=lookup_widget(objet_graphique,"labelmonthold");
output7=lookup_widget(objet_graphique,"labelyearold");
output8=lookup_widget(objet_graphique,"labelcomment_old");


// int to char
sprintf(chbq, "%d", br_cher.bquantity);
sprintf(chdd, "%d", br_cher.date_d);
sprintf(chdm, "%d", br_cher.date_m);
sprintf(chdy, "%d", br_cher.date_y); 

// pointers to value 




gtk_label_set_text(GTK_LABEL(output1), strcat(msg_old1, br_cher.rets_name));
gtk_label_set_text(GTK_LABEL(output2), strcat(msg_old2, br_cher.btn));
gtk_label_set_text(GTK_LABEL(output3),strcat(msg_old3, chbq));
gtk_label_set_text(GTK_LABEL(output4),strcat(msg_old4, br_cher.urgency));
gtk_label_set_text(GTK_LABEL(output5),strcat(msg_old5, chdd));
gtk_label_set_text(GTK_LABEL(output6),strcat(msg_old6, chdm));
gtk_label_set_text(GTK_LABEL(output7),strcat(msg_old7, chdy));
gtk_label_set_text(GTK_LABEL(output8),strcat(msg_old8, br_cher.comment));

}


// end when the id is found

}


void
on_buttonlogoutdirector_mod_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_buttonbr_mod_clicked                (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{




GtkWidget *output;
output=lookup_widget(objet_graphique,"labelmsgmoddirector");

if (id_found_mod_director_test==1){


// dec
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;
GtkWidget *input5;
GtkWidget *input6;
bloodrequest brmod, brold;
int id_amod;
// add to pointers
input1=lookup_widget(objet_graphique,"combobox_req_est_name_mod");
input2=lookup_widget(objet_graphique,"comboboxbloodtype_mod");
input3=lookup_widget(objet_graphique,"spinbuttonbtn_mod");
input4=lookup_widget(objet_graphique,"comboboxurg_mod");
input5=lookup_widget(objet_graphique,"entrycomment_mod");
input6=lookup_widget(objet_graphique,"spinbuttonbr_id_mod");
output=lookup_widget(objet_graphique,"labelmsgmoddirector");

// assign to struct
// entry 
strcpy(brmod.comment,gtk_entry_get_text(GTK_ENTRY(input5)));
// spinbox
brmod.bquantity=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
id_amod=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
//combobox
strcpy(brmod.rets_name,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(brmod.btn,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
strcpy(brmod.urgency,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
//modify
brold=chercher_br("br.txt",id_amod );
brmod.date_d=brold.date_d;
brmod.date_m=brold.date_m;
brmod.date_y=brold.date_y;
brmod.btr_id=id_amod;
int x=modifier_br("br.txt",id_amod,brmod );
    if(x==1){
         gtk_label_set_text(GTK_LABEL(output),"modified successfully");

}

     else gtk_label_set_text(GTK_LABEL(output),"modified failed");
}
//end if
}


void
on_buttondel_br_clicked                (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(objet_graphique,"labelmsgdeldirector");

if (choixdeletedirector[0]==1 && id_found_del_director_test==1){


     int x=supprimer_br("br.txt",id_found_del_director );
    if(x==1)
         gtk_label_set_text(GTK_LABEL(output),"deleted successfully");

}

     else gtk_label_set_text(GTK_LABEL(output),"delete failed");

}


void
on_buttonsearch_del_clicked            (GtkWidget	*objet_graphique,
                                        gpointer         user_data)
{

// search for br to delete 
//dec 
GtkWidget *input1_1;
GtkWidget *outputmsgfoundiddel;
bloodrequest br_cher;
int id_cher ; 

//add to pointers 
input1_1=lookup_widget(objet_graphique,"spinbuttonbr_id_del");
outputmsgfoundiddel=lookup_widget(objet_graphique,"labelbr_id_del");

// from pointer to var
id_cher=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1_1));
// chercher for br 

    br_cher=chercher_br("br.txt",id_cher );
    if(br_cher.btr_id==-1){
        gtk_label_set_text(GTK_LABEL(outputmsgfoundiddel),"Blood request id : not found");
	id_found_del_director_test=0;
}

// start when the id is found
	else {
gtk_label_set_text(GTK_LABEL(outputmsgfoundiddel),"Blood request id : found");

id_found_del_director=br_cher.btr_id; 

if (id_found_del_director==br_cher.btr_id) {id_found_del_director_test=1;}



// dec old br
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
char msg_old1[100]="Requesting establishment : ";
char msg_old2[100]="Requesting establishment : ";
char msg_old3[100]="Blood quantity needed :  ";
char msg_old4[40]="Urgency : ";
char msg_old5[40]="day :  ";
char msg_old6[40]="month :  ";
char msg_old7[40]="year :  ";
char msg_old8[100]="comment :  ";
char chbq[40];
char chdd[40];
char chdm[40];
char chdy[40];

// add  pointers for  br
output1=lookup_widget(objet_graphique,"labelrets_del");
output2=lookup_widget(objet_graphique,"labelbtn_del");
output3=lookup_widget(objet_graphique,"labelbq_del");
output4=lookup_widget(objet_graphique,"labelurg_del");
output5=lookup_widget(objet_graphique,"labelday_del");
output6=lookup_widget(objet_graphique,"labelmonth_del");
output7=lookup_widget(objet_graphique,"labelyear_del");
output8=lookup_widget(objet_graphique,"labelcomment_del");


// int to char
sprintf(chbq, "%d", br_cher.bquantity);
sprintf(chdd, "%d", br_cher.date_d);
sprintf(chdm, "%d", br_cher.date_m);
sprintf(chdy, "%d", br_cher.date_y); 

// pointers to value 




gtk_label_set_text(GTK_LABEL(output1), strcat(msg_old1, br_cher.rets_name));
gtk_label_set_text(GTK_LABEL(output2), strcat(msg_old2, br_cher.btn));
gtk_label_set_text(GTK_LABEL(output3),strcat(msg_old3, chbq));
gtk_label_set_text(GTK_LABEL(output4),strcat(msg_old4, br_cher.urgency));
gtk_label_set_text(GTK_LABEL(output5),strcat(msg_old5, chdd));
gtk_label_set_text(GTK_LABEL(output6),strcat(msg_old6, chdm));
gtk_label_set_text(GTK_LABEL(output7),strcat(msg_old7, chdy));
gtk_label_set_text(GTK_LABEL(output8),strcat(msg_old8, br_cher.comment));


}
// end else here delete
}


void
on_buttonlogoutdirector_del_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_checkbuttonsuredelete_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active (togglebutton)) {choixdeletedirector[0]=1; }
else {choixdeletedirector[0]=0; }
}


void
on_buttonrefreshdir_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowallbr, *w1; 
GtkWidget *treeview1;


w1=lookup_widget(objet, "windowallbr");
windowallbr=create_windowallbr();

gtk_widget_show(windowallbr);

gtk_widget_hide (w1);
treeview1=lookup_widget(windowallbr, "treeviewallbr");

vider("br.txt" , treeview1);

afficher_personne("br.txt" , treeview1);
}


void
on_buttonreturndir_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *notedirector;
  GtkWidget *windowallbr;
  notedirector = create_Director ();
  gtk_widget_show (notedirector);
  windowallbr = lookup_widget(button, "windowallbr");
  gtk_widget_hide (windowallbr);
}


void
on_buttonreturn1_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *notedirector;
  GtkWidget *windowstatdir;
  notedirector = create_Director ();
  gtk_widget_show (notedirector);
  windowstatdir = lookup_widget(button, "windowstatdir");
  gtk_widget_hide (windowstatdir);
}


void
on_buttonrefresh1_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttoncalstat_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1;
GtkWidget *output1;
GtkWidget *output2;
char dmd[30];
char res[30];
char msg[100]="Percentage of requests for : ";
char resf[200];
input1 = lookup_widget(objet, "comboboxstatets");
output1 = lookup_widget(objet, "labeloutbtr");
output2 = lookup_widget(objet, "labeloutputstat");

    char sangDemande[20];
    sang_demande("br.txt", "all", &sangDemande);
gtk_label_set_text(GTK_LABEL(output1),sangDemande);


strcpy(dmd,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
float pr=pourcentage("br.txt", dmd);
sprintf(res, "%f", pr);

strcat(msg, dmd);
strcpy(resf, msg);
strcat(resf, res);


gtk_label_set_text(GTK_LABEL(output2),strcat(resf, "%"));
}


void
on_butlogout_CDOC_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_butcreat_CDOC_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
// dec
GtkWidget *input01;
GtkWidget *input02;
GtkWidget *input03;
GtkWidget *input04;
GtkWidget *input05;
GtkWidget *input06;
GtkWidget *input07;
GtkWidget *outputmessg;
Don d ;
// add to pointers
input01=lookup_widget(objet_graphique,"spinbutdonid_DDOC");
input02=lookup_widget(objet_graphique,"spinbutday_CDOC");
input03=lookup_widget(objet_graphique,"spinbutmonth_CDOC");
input04=lookup_widget(objet_graphique,"spinbutyear_CDOC");
input05=lookup_widget(objet_graphique,"comboboxblood_CDOC");
input06=lookup_widget(objet_graphique,"spinbutquantity_CDOC");
input07=lookup_widget(objet_graphique,"comboboxets_CDOC");
outputmessg=lookup_widget(objet_graphique,"output_CDOC");
// spinbox

d.id_don=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input01));
d.day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input02));
d.month=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input03));
d.year=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input04));
d.quantity=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input06));
//combobox
strcpy(d.blood_type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input05)));
strcpy(d.center,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input07)));
// add don  to the file
d.id_don=iddon ;
int x=ajouter("don.txt" ,d );

if (x==1){
gtk_label_set_text(GTK_LABEL(outputmessg),"Blood don was added successfully");

iddon++;
}
else if (x==0){
gtk_label_set_text(GTK_LABEL(outputmessg),"Adding blood don failed");
}

}


void
on_butmodify_MDOC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(objet_graphique,"labeloutput_MDOC");

if (id_found_del_DOC_test ==1){
// declaration
GtkWidget *input01;
GtkWidget *input02;
GtkWidget *input03;
GtkWidget *input04;
GtkWidget *input05;
GtkWidget *input06;
GtkWidget *input07;
Don dmod, dold;
int id_dmod;
// add to pointers
input01=lookup_widget(objet_graphique,"spinbutdonid_MDOC");
input02=lookup_widget(objet_graphique,"comboboxblood_MDOC");
input03=lookup_widget(objet_graphique,"spinbutquantity_MDOC");
input04=lookup_widget(objet_graphique,"comboboxets_MDOC");
input05=lookup_widget(objet_graphique,"spinbutday_MDOC");
input06=lookup_widget(objet_graphique,"spinbutmonth_MDOC");
input07=lookup_widget(objet_graphique,"spinbutyear_MDOC");
output=lookup_widget(objet_graphique,"labeloutput_MDOC");
// spinbox
id_dmod=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input01));
dmod.quantity=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input03));
dmod.day=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input05));
dmod.month=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input06));
dmod.year=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input07));
//combobox
strcpy(dmod.blood_type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input02)));
strcpy(dmod.center,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input04)));

//modify
dold=chercher("don.txt",id_dmod );
dmod.day=dold.day;
dmod.month=dold.month;
dmod.year=dold.year;
dmod.id_don=id_dmod;
int x=modifier("don.txt",id_dmod,dmod );
	if(x==1){
     	gtk_label_set_text(GTK_LABEL(output)," successfully modified");

}

 	else gtk_label_set_text(GTK_LABEL(output),"failed modification");
}
//end if
}


void
on_butlogout_MDOC_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_but_idfound_DOC_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
// search for id don  to modify
//dec
GtkWidget *input10;
GtkWidget *output_foundidmod;
Don  d_search;
int id_search ;
//ajouter a des pointeurs
input10=lookup_widget(objet_graphique,"spinbutdonid_MDOC");
output_foundidmod=lookup_widget(objet_graphique,"outputdonid_Mdoc");
// from pointer to var
id_search=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input10));
// search for id don

	d_search=chercher("don.txt",id_search );
	if(d_search.id_don==-1){
    	gtk_label_set_text(GTK_LABEL(output_foundidmod),"Don ID not found");}
//commencer si le ID est trouvé
   	 else {    
gtk_label_set_text(GTK_LABEL(output_foundidmod)," Don ID found");
id_found_mod_DOC=d_search.id_don;
if (id_found_mod_DOC==d_search.id_don) {id_found_mod_DOC_test=1;}
// la declaration d'ancien don
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *output7;
GtkWidget *output8;
char msg_old1[20]="old :  ";
char msg_old2[20]="old :  ";
char msg_old3[20]="old :  ";
char stdq[40];
output1=lookup_widget(objet_graphique,"labeloutblood_MDOC");
output2=lookup_widget(objet_graphique,"labeloutquantity_MDOC");
output3=lookup_widget(objet_graphique,"labeloutets_MDOC");
// changer de entier  to char
sprintf(stdq, "%d", d_search.quantity);
gtk_label_set_text(GTK_LABEL(output1), strcat(msg_old1, d_search.blood_type));
gtk_label_set_text(GTK_LABEL(output3),strcat(msg_old3,stdq ));
gtk_label_set_text(GTK_LABEL(output2), strcat(msg_old2, d_search.center));
}
}


void
on_treeview_RDOC_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
    gchar* id_don;
    	gchar* blood_type;
    gchar* center;
    	gchar* quantity;
    gchar* day;
    gchar* month;
    gchar* year;
    
    Don d;
    GtkTreeModel *model = gtk_tree_view_get_model (treeview) ;
    	if (gtk_tree_model_get_iter(model, &iter, path) ){

   	 gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id_don, 1, &blood_type, 2,&center,-1,&quantity);
   	 strcpy(d.id_don,id_don);
   	 strcpy(d.blood_type,blood_type) ;
   	 strcpy(d.center,center) ;
            	strcpy(d.quantity,quantity) ;
   	 
    }
}


void
on_butlogout_RDOC_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_butrefresh_RDOC_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
    treeview1=lookup_widget(objet,"treeview_RDOC");
    afficher(treeview1);
}


void
on_butlogout_DDOC_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_butdelete_DDOC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output;
output=lookup_widget(objet_graphique,"labeloutputdelete_DDOC");
if (choixdeldoctor[0]==1 && id_found_del_DOC_test==1){   				 
 	int x=supprimer("don.txt",id_found_del_DOC );
	if(x==1)
     	gtk_label_set_text(GTK_LABEL(output),"deleted successfully");

}

 	else gtk_label_set_text(GTK_LABEL(output),"delete failed");
}


void
on_butsearch_DDOC_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
//chercher le id a supprimer
//declaration
GtkWidget *input10;
GtkWidget *outputmsgfoundiddel;
Don d_search;
int id_cher ;
//ajouter a des pointeurs
input10=lookup_widget(objet_graphique,"spinbutdonid_DDOC");
outputmsgfoundiddel=lookup_widget(objet_graphique,"laboutputsearchid_DDOC");

// mettre le id cherché dans une var
id_cher=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input10));
// chercher le id don

	d_search=chercher("don.txt",id_cher );
	if(d_search.id_don==-1){
    	gtk_label_set_text(GTK_LABEL(outputmsgfoundiddel),"Blood request id : not found");
    id_found_del_DOC_test=0;
}
    else {
gtk_label_set_text(GTK_LABEL(outputmsgfoundiddel),"Blood request id : found");

}
}


void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_butrefresh_SDOC_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
output1=lookup_widget(objet_graphique,"labtoutputnum_SDOC");
output2=lookup_widget(objet_graphique,"laboutputtotqty_SDOC");
output3=lookup_widget(objet_graphique,"laboutputaverage_SDOC");
if(choice==1){
    gtk_label_set_text(GTK_LABEL(output1)," Total number of donation is  ");
}
if(choice==2){
    gtk_label_set_text(GTK_LABEL(output2),"ATotal quantity of blood collected is");
}
if(choice==3){
    gtk_label_set_text(GTK_LABEL(output3),"Average quantity per donation ");    

}



}


void
on_radiobutnbtot_SDOC_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
choice==1;
}
}


void
on_radiobutqtytotblood_SDOC_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
choice==2;}
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
choice==3;}
}




void
on_button_log_in1_clicked              (GtkButton       *objet,
                                        gpointer         user_data)
{
int dir,doc,adm,cl,nr,fail=1;
GtkWidget*users;
GtkWidget*passwords;
GtkWidget*outputlog;

char username [50] ;
char password[50];
outputlog = lookup_widget(objet, "loginoutput");
users = lookup_widget(objet, "name_log");
passwords = lookup_widget(objet, "password_log");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(users)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(passwords)));


dir=loginUser("directorlog.txt", username , password);
doc=loginUser("doctorlog.txt", username , password);
adm=loginUser("adminlog.txt", username , password);
cl=loginUser("clientlog.txt", username , password);
nr=loginUser("nurselog.txt", username , password);
 if (dir==1){
  fail=0;
  GtkWidget *window1;
  GtkWidget *window2;
  window2 = create_Director ();
  gtk_widget_show (window2);
  window1 = lookup_widget(objet, "homepage");
  gtk_widget_hide (window1);}

 if (doc==1){

  fail=0;
  GtkWidget *window1;
  GtkWidget *window2;
  window2 = create_Doctor ();   
  gtk_widget_show (window2);
  window1 = lookup_widget(objet, "homepage");
  gtk_widget_hide (window1);}

 if (adm==1){
  fail=0;
  GtkWidget *window1;
  GtkWidget *window2;
  window2 = create_admin ();
  gtk_widget_show (window2);
  window1 = lookup_widget(objet, "homepage");
  gtk_widget_hide (window1);}

 if (cl==1){
  fail=0;
  GtkWidget *window1;
  GtkWidget *window2;
  window2 = create_appointement ();
  gtk_widget_show (window2);
  window1 = lookup_widget(objet, "homepage");
  gtk_widget_hide (window1);}

 if (nr==1){
  fail=0;
  GtkWidget *window1;
  GtkWidget *window2;
  window2 = create_window_gestionfiche();
  gtk_widget_show (window2);
  window1 = lookup_widget(objet, "homepage");
  gtk_widget_hide (window1);}
 if (fail==1){
  gtk_label_set_text(GTK_LABEL(outputlog),"please check your credentials and try again");}

}








void
on_button_refresh_amin_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	 GtkWidget *treeview3;
	 treeview3=lookup_widget(objet_graphique,"treeview1"); 

afficher_fichiers_his(treeview3);


}


void
on_radiobuttonDIRusers_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
   	 rolest=4;
}


void
on_logout_amin1_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_logout_amin2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_logout_amin3_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_logout_amin4_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_logout_amin5_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_logout_amin6_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_logout_amin7_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}


void
on_butlogout_SDOC_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *current_window = gtk_widget_get_toplevel(GTK_WIDGET(button));
    show_homepage(current_window);
}




void on_testingrefresh_clicked(GtkButton *button, gpointer user_data) {

}

void
on_Refreshdonorchange_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_donor(button);
}


void
on_refreshdonorcancel_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_donor(button);
}


void
on_refreshusercreate_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_adminuser(button);
}


void
on_refreshuserupdate_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_adminuser(button);
}


void
on_refreshuserdelete_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_adminuser(button);
}


void
on_refreshetscreate_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_adminets(button);
}


void
on_refreshetsupdate_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_adminets(button);
}


void
on_refreshetsdelete_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_adminets(button);
}





void
on_refreshdoccreate_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_doctor(button);
}


void
on_refreshdocmod_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_doctor(button);
}


void
on_refreshdocdel_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_doctor(button);
}


void
on_refreshdocstat_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_doctor(button);
}


void
on_Refreshdonorbook_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_donor(button);
}


void
on_refreshdiradd_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_director(button);
}
void
on_refreshdirupdate_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_director(button);
}


void
on_refreshdirdelete_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
refresh_director(button);
}
