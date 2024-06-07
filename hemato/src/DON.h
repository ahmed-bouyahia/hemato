#ifndef DON_H_INCLUDED
#define DON_H_INCLUDED
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>


typedef struct 
{
    char  blood_type[20],center[20];
    int   id_don,quantity,month,day,year;
}Don ;
int ajouter(char*,Don);
int modifier(char*,int,Don);
int supprimer(char *,int);
Don chercher(char* ,int);
void statistics(char *);
void afficher(GtkWidget *liste);
#endif // DON_H_INCLUDED
 
