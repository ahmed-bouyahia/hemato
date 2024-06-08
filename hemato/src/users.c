
#include "users.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <gtk/gtk.h>

int ajouter_user(char * file, users p)
{
    FILE * f=fopen(file, "a");
    if(f!=NULL)
    {  
        fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare);
        fclose(f);
        return 1;
        }
    else return 0;
}
//////////////////////////////////////////////////////////////
int modifier_user( char * file, int ID_Numberr, users nouv )
{
    int tr=0;
    users p;
    FILE * f=fopen(file, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare)!=EOF)
        {
            if(atoi(p.ID_Number)==ID_Numberr)
            {
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",nouv.Name,nouv.Last_Name,nouv.Work_email,nouv.Account_Password,nouv.Confirm_Password,nouv.Gender,nouv.role,nouv.ID_Number,nouv.Phone_Number,nouv.Dayb,nouv.Monthb,nouv.Yearb,nouv.daye,nouv.monthe,nouv.yeare);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare);

        }
    }
    fclose(f);
    fclose(f2);
    remove(file);
    rename("nouv.txt", file);
    return tr;

}
//////////////////////////////////////////////////////////////
int supprimer_user(char * file, int ID_Number)
{
    int tr=0;
    users p;
    FILE * f=fopen(file, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare)!=EOF)
        {
            if(atoi(p.ID_Number)== ID_Number)
                tr=1;
            else
                fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare);
        }
    }
    fclose(f);
    fclose(f2);
    remove(file);
    rename("nouv.txt", file);
    return tr;
}
////////////////////////////////////////////////////////////
users chercher_user(char * file, int ID_Number)
{
    users p;
    int tr=0;
    FILE * f=fopen(file, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare)!=EOF)
        {
            if(atoi(p.ID_Number)== ID_Number)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(p.ID_Number,"-1");
    return p;

}
/////////////////////////////////////////////////
void UserRole(char file[],int role)
{ users p;
  int comp;
  FILE* f=fopen(file, "r");
    FILE* f2=fopen("Role.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
      while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare)!=EOF){
	if(strcmp(p.role,"Admin")==0)
	   {comp=1;}
	if(strcmp(p.role,"Doctor")==0)
	   {comp=2;}
	if(strcmp(p.role,"Nurse")==0)
	   {comp=3;}
	if(strcmp(p.role,"Director")==0)
	   {comp=4;}
      if (role==comp)
        {  fprintf(f2,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare);
        }
  }
}
fclose(f);
    fclose(f2);
}
/////////////////////////////////////////////////////////
enum 
{ 
LASTNAME,
NAME, 
EMAIL, 
PASS, 
CONPASS, 
GENDER, 
ID, 
PHONE, 
DB, 
MB,
YB,
DE,
ME,
YE,
ROLE,
COLUMNS
}; 
void show_table(GtkWidget *list )
 {
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter; 
GtkListStore *store; 
char Last_Name[20]; 
char Name[20]; 
char Work_email[20]; 
char Account_Password[20]; 
char Confirm_Password[20]; 
char Gender[20]; 
char ID_Number[20]; 
char Phone_Number[20]; 
char Dayb[20]; 
char Monthb[20];
char Yearb[20];
char daye[20];
char monthe[20];
char yeare[20];
char role[20];
store =NULL; 
FILE *f; store=gtk_tree_view_get_model(list); 
if(store==NULL){ 
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Last_Name",renderer,"text",LASTNAME,NULL); gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("Name",renderer,"text",NAME,NULL); gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("Work_email",renderer,"text",EMAIL,NULL); gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("Account_Password",renderer,"text",PASS,NULL); gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("Confirm_Password",renderer,"text",CONPASS,NULL); gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("Gender",renderer,"text",GENDER,NULL); gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("ID_Number",renderer,"text",ID,NULL); gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("Phone_Number",renderer,"text",PHONE,NULL); gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("Dayb",renderer,"text",DB,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("Monthb",renderer,"text",MB,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("Yearb",renderer,"text",YB,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("daye",renderer,"text",DE,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("monthe",renderer,"text",ME,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("yeare",renderer,"text",YE,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
renderer=gtk_cell_renderer_text_new(); 
column=gtk_tree_view_column_new_with_attributes("role",renderer,"text",ROLE,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);} store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING); f=fopen("users.txt","r"); 
if(f==NULL)
{ return;} 
else{ f=fopen("users.txt","a+"); 
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",Name,Last_Name,Work_email,Account_Password,Confirm_Password,Gender,role,ID_Number,Phone_Number,Dayb,Monthb,Yearb,daye,monthe,yeare)!=EOF)
{ gtk_list_store_append(store,&iter); 
gtk_list_store_set(store,&iter,LASTNAME,Last_Name,NAME,Name,EMAIL,Work_email,PASS,Account_Password,CONPASS,Confirm_Password,GENDER,Gender,ID,ID_Number,PHONE,Phone_Number,DB,Dayb,MB,Monthb,YB,Yearb,DE,daye,ME,monthe,YE,yeare,ROLE,role,-1);} 
f= fclose(f); 
gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store)); 
g_object_unref(store);}}
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
enum 
{ 
LASTNAMER,
NAMER, 
EMAILR, 
PASSR, 
CONPASSR, 
GENDERR, 
IDR, 
PHONER, 
DBR, 
MBR,
YBR,
DER,
MER,
YER,
ROLER,
COLUMNSR
}; 
void show_table_role(GtkWidget *listr )
 {
 GtkCellRenderer *rendererr;
 GtkTreeViewColumn *columnr;
 GtkTreeIter iterr; 
GtkListStore *storer; 
char Last_Name[20]; 
char Name[20]; 
char Work_email[20]; 
char Account_Password[20]; 
char Confirm_Password[20]; 
char Gender[20]; 
char ID_Number[20]; 
char Phone_Number[20]; 
char Dayb[20]; 
char Monthb[20];
char Yearb[20];
char daye[20];
char monthe[20];
char yeare[20];
char role[20];
storer =NULL; 
FILE *f; storer=gtk_tree_view_get_model(listr); 
if(storer==NULL){ 
rendererr=gtk_cell_renderer_text_new();
columnr=gtk_tree_view_column_new_with_attributes("Last_Name",rendererr,"text",LASTNAMER,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr); 
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("Name",rendererr,"text",NAMER,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr); 
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("Work_email",rendererr,"text",EMAILR,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr); 
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("Account_Password",rendererr,"text",PASSR,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr); 
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("Confirm_Password",rendererr,"text",CONPASSR,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr); 
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("Gender",rendererr,"text",GENDERR,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr); 
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("ID_Number",rendererr,"text",IDR,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr); 
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("Phone_Number",rendererr,"text",PHONER,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr); 
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("Dayb",rendererr,"text",DBR,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr);
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("Monthb",rendererr,"text",MBR,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr);
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("Yearb",rendererr,"text",YBR,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr);
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("daye",rendererr,"text",DER,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr);
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("monthe",rendererr,"text",MER,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr);
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("yeare",rendererr,"text",YER,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr);
rendererr=gtk_cell_renderer_text_new(); 
columnr=gtk_tree_view_column_new_with_attributes("role",rendererr,"text",ROLER,NULL); 
gtk_tree_view_append_column(GTK_TREE_VIEW(listr),columnr);} storer=gtk_list_store_new(COLUMNSR,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING); f=fopen("Role.txt","r"); 
if(f==NULL)
{ return;} 
else{ f=fopen("Role.txt","a+"); 
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",Name,Last_Name,Work_email,Account_Password,Confirm_Password,Gender,role,ID_Number,Phone_Number,Dayb,Monthb,Yearb,daye,monthe,yeare)!=EOF)
{ gtk_list_store_append(storer,&iterr); 
gtk_list_store_set(storer,&iterr,LASTNAMER,Last_Name,NAMER,Name,EMAILR,Work_email,PASSR,Account_Password,CONPASSR,Confirm_Password,GENDERR,Gender,IDR,ID_Number,PHONER,Phone_Number,DBR,Dayb,MBR,Monthb,YBR,Yearb,DER,daye,MER,monthe,YER,yeare,ROLER,role,-1);} 
f= fclose(f); 
gtk_tree_view_set_model(GTK_TREE_VIEW(listr),GTK_TREE_MODEL(storer)); 
g_object_unref(storer);}}
///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
int pourcentageUSermale(char file[],int *nbHomme)
{ users p;
 int y1,numb=0;
  FILE * f=fopen(file, "r");
   if(f!=NULL)
{ while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare)!=EOF){
  y1=strcmp(p.Gender,"male");
  if(y1==0)
   {numb++;}
  
}
}
fclose(f);
return numb;
}
/////////////////////////////////////////////////////
int pourcentageUSerfemale(char file[],int *nbFemme)
{ users p;
 int x1,numr=0;
  FILE * f=fopen(file, "r");
   if(f!=NULL)
{ while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",p.Name,p.Last_Name,p.Work_email,p.Account_Password,p.Confirm_Password,p.Gender,p.role,p.ID_Number,p.Phone_Number,p.Dayb,p.Monthb,p.Yearb,p.daye,p.monthe,p.yeare)!=EOF){
 x1=strcmp(p.Gender,"female");
  if(x1==0)
   {numr++;}
}
}
fclose(f);
return numr;
}


