#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

typedef struct
{
    char establishment_name[20],state[20],adress[200],email_adress[200],blood_storage[20],establishment_id[20],capacity[20],phone_number[20],numberof_laboratory[20],numberof_doctors[20],numberof_nurses[20],numberof_technicians[20];
} crud;

int add(char *, crud );
crud show(char * filename, char id[20]);
void del(char * filename, char id[20]);
int modify( char * filename,char id[20], crud nouv );
void afficher_fichiers(GtkWidget *list);
void ETSParRegion(char *nomFichier, char reg[20]);
void afficher_fichiers_stat(GtkWidget *list);
void afficher_fichiers_capacity(GtkWidget *list);
void ETSTrieCapacite(char *nomFichier);

