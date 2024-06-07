#include "DON.h"
#include <stdio.h>
#include <string.h>


int ajouter(char *filename, Don d)
{
    FILE *f = fopen(filename, "a");
    if (f != NULL)
    {
        fprintf(f, " %d %s %s %d %d %d %d",  d.id_don, d.blood_type, d.center, d.quantity, d.month, d.day, d.year);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

int modifier(char *filename, int id_don, Don nouv)
{
    int tr = 0;
    Don d;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    while (fscanf(f, " %d %s %s %d %d %d %d\n",  &d.id_don, d.blood_type, d.center, &d.quantity, &d.day, &d.month, &d.year) != EOF)
    {
        if (d.id_don== id_don)
        {
            fprintf(f2, " %d %s %s %d %d %d %d\n", nouv.id_don, nouv.blood_type, nouv.center, nouv.quantity, nouv.day, nouv.month, nouv.year);
            tr = 1;
        }
        else
            fprintf(f2, " %d %s %s %d %d %d %d\n", d.id_don, d.blood_type, d.center, d.quantity, d.day, d.month, d.year);
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int supprimer(char *filename, int id_don)
{
    int tr = 0;
    Don d;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {

        while (fscanf(f, " %d %s %s %d %d %d %d\n",&d.id_don, d.blood_type, d.center, &d.quantity, &d.day, &d.month, &d.year) != EOF)
        {
            if (d.id_don== id_don)
                tr = 1;
            else
                fprintf(f2, " %d %s %s %d %d %d %d\n", d.id_don, d.blood_type, d.center, d.quantity, d.day, d.month, d.year);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

Don chercher(char *filename, int id_don)
{
    Don d;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (tr == 0 && fscanf(f, "%d  %s %s %d %d %d %d\n", &d.id_don, d.blood_type, d.center, &d.quantity, &d.day, &d.month, &d.year) != EOF)
        {
            if (d.id_don == id_don)
            {
                tr = 1;
            }
        }
        fclose(f);
    }
    return d;
}

void statistique(char *filename)
{
    int totalDons = 0;
    int totalQuantite = 0;
    Don d;

    FILE *f = fopen(filename, "r");

    if (f != NULL)
    {
        while (fscanf(f, "%d  %s %s %d %d %d %d\n",&d.id_don, d.blood_type, d.center, &d.quantity, &d.day, &d.month, &d.year) != EOF)
        {
            totalDons++;
            totalQuantite += d.quantity;
        }

        fclose(f);

        printf("Statistiques :\n");
        printf("Nombre total de dons : %d\n", totalDons);
        printf("Quantité totale de sang collectée : %d\n", totalQuantite);
        printf("Quantité moyenne par don : %f\n", (float)totalQuantite / totalDons);
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier\n");
    }
}
//affichage
enum{
	Eid_don,
	Eblood_type,
	Ecenter,
	Equantity,
	Eday,
	Emonth,
	Eyear,
	COLUMNS
}; 
void afficher(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char id_don[20];
char blood_type[20];
char center[20];
char quantity[20];
char day[20];
char month[20];
char year[20]; 
store =NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id_don",renderer,"text",Eid_don,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("center",renderer,"text",Ecenter,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("blood_type",renderer,"text",Eblood_type,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer= gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("quantity",renderer,"text",Equantity,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("day",renderer,"text",Eday,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("month",renderer,"text",Emonth,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("year",renderer,"text",Eyear,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("don.txt", "r");
if (f==NULL){
return;
}
else {f=fopen("don.txt", "a+");
while(fscanf(f," %s %s %s %s %s %s %s\n",&id_don,blood_type,center,&quantity,&day,&month,&year)!=EOF){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,Eid_don,id_don,Eblood_type,blood_type,Ecenter,center,Equantity,quantity,Eday,day,Emonth,month,Eyear,year,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}






    	
	
	















