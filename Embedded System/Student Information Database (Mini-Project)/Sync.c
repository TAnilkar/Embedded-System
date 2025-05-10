#include"myheader.h"
unsigned int ID[26];
STUDENT* Sync_Func(STUDENT *head){
        FILE *fp=NULL,*fp1=NULL;
        int size=sizeof(STUDENT)-sizeof(STUDENT*);
        STUDENT* newnode=NULL,*temp=NULL,var;

        fp1=fopen("Array_of_ID.txt","r");
        if(fp1==NULL){
                printf("file not found\n");
        }
        fread(ID,sizeof(ID),1,fp1);

        fp=fopen("Student.txt","r");
        if(fp==NULL){
                return head;
        }
        while(fread(&var,size,1,fp)==1){
                newnode=calloc(1,sizeof(STUDENT));
                if(newnode==NULL){
                        printf("newnode is not created\n");
                        return head;
                }
                *newnode=var;
                newnode->link=NULL;
                if(head==NULL){
                        head=newnode;
                }
                else{
                        for(temp=head;temp->link;temp=temp->link);
                        temp->link=newnode;
                }
        }
        fclose(fp);
        fclose(fp1);
        return head;

}