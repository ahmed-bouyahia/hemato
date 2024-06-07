
#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct
{
    char Last_Name[20],Name[20],Work_email[20],Account_Password[20],Confirm_Password[20],Gender[20],ID_Number[20],Phone_Number[20],Dayb[20],Monthb[20],Yearb[20],daye[20],monthe[20],yeare[20],role[20];
 
} users;
int ajouter_user(char *, users );
int modifier_user( char *, int, users );
int supprimer_user(char *, int );
users chercher_user(char *, int);
void UserRole(char file[],int role);
int pourcentageUSerfemale(char file[],int *nbFemme);
int pourcentageUSermale(char file[],int *nbHomme);
void show_table(GtkWidget *list );
void show_table_role(GtkWidget *list );
void empty_table_role(GtkWidget *listr );
void empty_table(GtkWidget *list );
#endif 

