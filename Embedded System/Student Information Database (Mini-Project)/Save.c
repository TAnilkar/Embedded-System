#include"myheader.h"
extern unsigned int ID[26];
void Save_Func(STUDENT* head){
        FILE *fp=NULL,*fp1=NULL;
        int size=sizeof(STUDENT)-sizeof(STUDENT*);
        fp1=fopen("Array_of_ID.txt","w");
        fwrite(ID,sizeof(ID),1,fp1);
        if(head==NULL){
                printf("Database is empty\n");
                fp=fopen("Student.txt","w");
                fclose(fp);
        }
        else{
                fp=fopen("Student.txt","w");
                if(fp==NULL){
                        printf("File not Found\n");
                        return;
                }
                while(head){
                        fwrite(head,size,1,fp);
                        head=head->link;
                }
                fclose(fp);
        }
        //fclose(fp);
        fclose(fp1);

}