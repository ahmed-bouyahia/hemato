#include "structure.h"
#include <string.h>
enum {
    ID,
    ESTABLISHMENT,
    DAY,
    MONTH,
    YEAR,
    TT,
    COLUMNS
};
enum {
   
    ID_DON,
    BLOOD_TYPE,
    CENTER,
    QUANTITY,
    MONTHH,
    DAYH,
    YEARH,
    COLUMNS_DONN,
};
int ETScapacite(char* nomFichier,char establishment_name[]){
    int tr;
    crude c;
    FILE * f=fopen(nomFichier, "r");

    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %d %d %d %d %d %s %d\n",c.establishment_name,c.state,c.adress,&c.capacity,c.email_adress,&c.phone_number,&c.numberof_laboratory,&c.numberof_doctors,&c.numberof_nurses,&c.numberof_technicians,c.blood_storage,&c.establishment_id)!=EOF)
        {
            if(strcmp (c.establishment_name,establishment_name)==0)
            {
              tr=c.capacity       ;    }

        }
    }
    fclose(f);


    return tr;

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void historique (char *nomFichier, char CIN[]){
    
    donn d;
    FILE * f=fopen(nomFichier, "r");
    FILE * f2=fopen("myhistory.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
          while(fscanf(f,"%s %s %s %s %d %d %d %d\n",d.id_donor,d.id_don, d.blood_type,d.center,&d.quantity,&d.day,&d.month,&d.year)!=EOF)
           {

if(strcmp(CIN, d.id_donor) == 0)

            {
                fprintf(f2,"%s %s %s %s %d %d %d %d\n",d.id_donor,d.id_don, d.blood_type,d.center,d.quantity,d.day,d.month,d.year);
            }
    }
    fclose(f);
    fclose(f2);
}}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
int HoraireDispo(char *nomFichier, char ETS[],int capacity, int jour, int mois , int annee, char  horaire[]){
int dispo;
char tab [20][20];
int test=0;
    rdv R;
    FILE * f=fopen(nomFichier, "r");

    if(f!=NULL )
    {
        while(fscanf(f,"%d %s %d %d %d %s\n",&R.id,R.establishment,&R.date_rdv.day,&R.date_rdv.month,&R.date_rdv.year,R.tt)!=EOF)// fichier n'a pas atteint la fin
        {
            if((strcmp(ETS,R.establishment)==0) && (R.date_rdv.day==jour )&& (R.date_rdv.month==mois )&& (R.date_rdv.year==annee )&& (strcmp(horaire,R.tt)==0))
            {
                test++;
            }
        }
    }
    fclose(f);
    dispo=capacity - test;
    if (dispo<capacity)
    return (dispo);
    else
    return capacity ;
}
int ajouter_sign(char * filename,sign s )
{

    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s\n",s.fullname,s.email,s.phone,s.password);
        fclose(f);
        return 1;
    }
    else return 0;
}




int ajouter_RDV(char * filename,rdv R )
{

    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %s %d %d %d %s\n",R.id,R.establishment,R.date_rdv.day,R.date_rdv.month,R.date_rdv.year,R.tt);
        fclose(f);
        return 1;
    }
    else return 0;
}
int modifier_RDV( char * filename, int id ,rdv NR )
{
int test=0;
    rdv R;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("NRDV.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %s\n",&R.id,R.establishment,&R.date_rdv.day,&R.date_rdv.month,&R.date_rdv.year,R.tt)!=EOF)// fichier n'a pas atteint la fin
        {
            if(R.id== id)
            {
                fprintf(f2,"%d %s %d %d %d %s\n",NR.id,NR.establishment,NR.date_rdv.day,NR.date_rdv.month,NR.date_rdv.year,NR.tt);
                test=1;
            }
            else
                 fprintf(f2,"%d %s %d %d %d %s\n",R.id,R.establishment,R.date_rdv.day,R.date_rdv.month,R.date_rdv.year,R.tt);


        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("NRDV.txt", filename);
    return test;
}
int supprimer_RDV(char *filename , int id  ){
int test=0;
    rdv R;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("NRDV.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %d %d %d %s\n",&R.id,R.establishment,&R.date_rdv.day,&R.date_rdv.month,&R.date_rdv.year,R.tt  )!=EOF)
        {
            if(R.id== id)
                test=1;
            else
               fprintf(f2,"%d %s %d %d %d %s\n",R.id,R.establishment,R.date_rdv.day,R.date_rdv.month,R.date_rdv.year,R.tt);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("NRDV.txt", filename);
    return test;

}
rdv chercher_RDV(char * filename, int id){


    int test=0;
    rdv R;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(test==0&& (fscanf(f,"%d %s %d %d %d %s \n",&R.id,R.establishment,&R.date_rdv.day,&R.date_rdv.month,&R.date_rdv.year,R.tt)!=EOF))
        {
            if(R.id== id)
                test=1;
        }
    }
    fclose(f);
    if(test==0)
        R.id=-1;
    return R;

}


void afficher_fichierss(GtkWidget *list) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
     char str_id[50], str_day[50], str_month[50], str_year[50];
    rdv R;

    store = NULL;

    FILE *f;

    store = gtk_tree_view_get_model(list);
    if (store == NULL) {

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("appointement id", renderer, "text", ID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("establishment name", renderer, "text", ESTABLISHMENT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("day", renderer, "text", DAY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("month", renderer, "text", MONTH, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("year", renderer, "text", YEAR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("time", renderer, "text", TT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);}

        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        f = fopen("RDV.txt", "r");
        if (f == NULL) {
            perror("Erreur lors de l'ouverture du fichier");
            return;
        } else {
            while (fscanf(f, "%d %s %d %d %d %s\n", &R.id, R.establishment, &R.date_rdv.day, &R.date_rdv.month, &R.date_rdv.year, R.tt) != EOF) {
                gtk_list_store_append(store, &iter);
                sprintf(str_id, "%d", R.id);
                sprintf(str_day, "%d", R.date_rdv.day);
                sprintf(str_month, "%d", R.date_rdv.month);
                sprintf(str_year, "%d", R.date_rdv.year);

                gtk_list_store_set(store, &iter,
                                   ID, str_id,
                                   ESTABLISHMENT, R.establishment,
                                   DAY, str_day,
                                   MONTH, str_month,
                                   YEAR, str_year,
                                   TT, R.tt,
                                   -1);
            }

            fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
            g_object_unref(store);
        }
    }




/////////////////////////////////////////////////////////////////////////
void afficher_fichiersss(GtkWidget *list) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
   
    donn don;

    store = NULL;
    char quantity_str[200], month_str[200], day_str[200], year_str[200];
    FILE *f;

   store = gtk_tree_view_get_model(list);
    if (store == NULL) {
       

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("donation id", renderer, "text", ID_DON, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("blood type", renderer, "text", BLOOD_TYPE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);
        
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("establishment name", renderer, "text", CENTER, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("boold quantity in ML", renderer, "text", QUANTITY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("day", renderer, "text", DAYH, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("month", renderer, "text", MONTHH, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("year", renderer, "text", YEARH, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);}

       

     

        store = gtk_list_store_new(COLUMNS_DONN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        f = fopen("myhistory.txt", "r");
        if (f == NULL) {
            perror("Erreur lors de l'ouverture du fichier");
            return;
        } else {
             while(fscanf(f,"%s %s %s %s %d %d %d %d\n",don.id_donor,don.id_don, don.blood_type,don.center,&don.quantity,&don.day,&don.month,&don.year)!=EOF) {
        gtk_list_store_append(store, &iter);

      
        sprintf(quantity_str, "%d", don.quantity);
        sprintf(month_str, "%d", don.month);
        sprintf(day_str, "%d", don.day);
        sprintf(year_str, "%d", don.year);

        gtk_list_store_set(store, &iter,
                           
                           ID_DON, don.id_don,
                           BLOOD_TYPE, don.blood_type,
                           CENTER, don.center,
                           QUANTITY, quantity_str,
                           DAYH, day_str,
                           MONTHH, month_str,
                           
                           YEARH, year_str,
                           -1);
            }

            fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
            
            g_object_unref(store);
        }
    }


void supprimer_RR (rdv r)
{rdv R;

FILE *f,*g;
f=fopen("RDV.txt", "r");
g= fopen("dump.txt", "w");
if(f==NULL | g==NULL)
{
return;
}
else{
{ 
        while(fscanf(f,"%d %s %d %d %d %s\n",&R.id,R.establishment,&R.date_rdv.day,&R.date_rdv.month,&R.date_rdv.year,R.tt  )!=EOF)
       
              
if((R.id!=r.id) || strcmp(R.establishment,r.establishment)!=0 ||(R.date_rdv.day!=r.date_rdv.day) ||(R.date_rdv.month!=r.date_rdv.month) ||(R.date_rdv.year!=r.date_rdv.year) || strcmp(r.tt,R.tt)!=0) 
            {  fprintf(g,"%d %s %d %d %d %s\n",R.id,R.establishment,R.date_rdv.day,R.date_rdv.month,R.date_rdv.year,R.tt);}
}
fclose(f);
fclose (g);
remove("RDV.txt");
rename("dump.txt", "RDV.txt");
}}

void afficher_fichierss1(GtkWidget *list) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
     char str_id[50], str_day[50], str_month[50], str_year[50];
    rdv R;

    store = NULL;

    FILE *f;

    store = gtk_tree_view_get_model(list);
    if (store == NULL) {

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("appointement id", renderer, "text", ID, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("establishment name", renderer, "text", ESTABLISHMENT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("day", renderer, "text", DAY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("month", renderer, "text", MONTH, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("year", renderer, "text", YEAR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("time", renderer, "text", TT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(list), column);}

        store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

        f = fopen("RDVarchive.txt", "r");
        if (f == NULL) {
            perror("Erreur lors de l'ouverture du fichier");
            return;
        } else {
            while (fscanf(f, "%d %s %d %d %d %s\n", &R.id, R.establishment, &R.date_rdv.day, &R.date_rdv.month, &R.date_rdv.year, R.tt) != EOF) {
                gtk_list_store_append(store, &iter);
                sprintf(str_id, "%d", R.id);
                sprintf(str_day, "%d", R.date_rdv.day);
                sprintf(str_month, "%d", R.date_rdv.month);
                sprintf(str_year, "%d", R.date_rdv.year);

                gtk_list_store_set(store, &iter,
                                   ID, str_id,
                                   ESTABLISHMENT, R.establishment,
                                   DAY, str_day,
                                   MONTH, str_month,
                                   YEAR, str_year,
                                   TT, R.tt,
                                   -1);
            }

            fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(list), GTK_TREE_MODEL(store));
            g_object_unref(store);
        }
    }


