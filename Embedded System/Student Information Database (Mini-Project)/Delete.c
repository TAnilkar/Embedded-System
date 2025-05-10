#include"myheader.h"
STUDENT *Delete_Func(STUDENT*head,char *ID){
        STUDENT *temp=NULL,*prev=NULL;
        if(head==NULL){
                printf("Database is empty\n");
        }
        else if(strcmp(head->SID,ID)==0){
                temp=head;
                head=head->link;
                free(temp);
        }
        else{
                temp=head;
                while(temp && (strcmp(ID,temp->SID)!=0)){
                        prev=temp;
                        temp=temp->link;
                }
                if(temp==NULL){
                        printf("ID not found\n");
                }
                else{
                        prev->link=temp->link;
                        free(temp);
                }

        }
        return head;
}