#include"myheader.h"
char *new_SID;
extern unsigned int ID[26];
char* create_ID(char *SID){
        char Default_ID[10]="v24he2",ID_Roll_No[5];
        char first_letter_Of_name;
        unsigned int Roll_No,Id_No;
        if(!isalpha(*SID)){
                while(!isalpha(*SID)){
                        SID++;
                }
        }
        first_letter_Of_name=*SID;
        if(isupper(first_letter_Of_name)){
                first_letter_Of_name^=32;
        }
        Default_ID[6]=first_letter_Of_name;

        Id_No=first_letter_Of_name-97;
        Roll_No=++ID[Id_No];

        sprintf(ID_Roll_No,"%d",Roll_No);

        strcat(Default_ID,ID_Roll_No);
        new_SID=Default_ID;
        return new_SID;
}

int* valid_email(char *str){
        int cnt[2]={0,0};
        static int temp[2];
        while(*str){
                if(*str=='@'){
                        cnt[0]++;
                }
                if(*str=='.'){
                        cnt[1]++;
                }
                str++;
        }
        temp[0]=cnt[0];
        temp[1]=cnt[1];
        return temp;
}
int valid_name(char *name){
        while(*name){
                if(!isalpha(*name)){
                        return 0;
                }
                name++;
        }
        return 1;
}
STUDENT *Add_Func(STUDENT *head){
        STUDENT *newnode=NULL,*temp=NULL;
        unsigned int d,m,y,*valid;
        char choice,*temp_ID;
        newnode=calloc(1,sizeof(STUDENT));
        if(newnode==NULL){
                printf("newnode is not created\n");
        }
        else{
                printf("Enter name:\n");
N:              __fpurge(stdin);
                scanf("%[^\n]s",newnode->name);
                if(valid_name(newnode->name)==0){
                        printf("Enter valid Name:\n");
                        goto N;
                }
                printf("Generate ID :\n");
                sleep(1);
                temp_ID=create_ID(newnode->name);
                strcpy(newnode->SID,temp_ID);
                printf("SID:%s\n",newnode->SID);
                printf("Enter D.O.B:(DD/MM/YYYY):(12/12/9999)\n");
Input:          scanf("%d %d %d",&d,&m,&y);
                if(d>31||m>12||y>9999){
                        printf("Enter valid D.O.B:\n");
                        goto Input;
                }
                newnode->DOB.date=d,newnode->DOB.month=m,newnode->DOB.year=y;
                printf("Enter marks:\n");
                printf("Enter percentage of matric:\n");
M:              scanf("%f",&newnode->marks.Matric);
                if((newnode->marks.Matric<0)||(newnode->marks.Matric>100)){
                        puts("Enter valid Percentage:");
                        goto M;
                }
Percentage:     printf("Enter I/D for Inter or Diploma percentage:\n");
                scanf(" %c",&choice);
                switch(choice){
I:                       case 'I':puts("Inter percentage:");
                                 scanf("%f",&newnode->marks.HE.Inter);
                                 if(newnode->marks.HE.Inter<0 || newnode->marks.HE.Inter>100){
                                         puts("Enter valid Percentage:");
                                         goto I;
                                        }
                                 break;
                        case 'D':puts("Diploma percentage:");
D:                                 scanf("%f",&newnode->marks.HE.Diploma);
                                 if(newnode->marks.HE.Diploma<0 || newnode->marks.HE.Diploma>100){
                                        puts("Enter valid Percentage:");
                                         goto D;
                                 }
                                 break;
                        default:
                                goto Percentage;
                }
G:              printf("Enter percentage of graduation:\n");
                scanf("%f",&newnode->marks.graduation);
                 if((newnode->marks.graduation<0)||(newnode->marks.graduation>100)){
                        goto G;
                }
                printf("Enter contact:\n");
cont:           scanf("%s",newnode->contact);
                if(strlen(newnode->contact)<10){
                        puts("Enter valid contact:");
                        goto cont;
                }
Em:             printf("Enter Email:\n");
                __fpurge(stdin);
                scanf("%s",newnode->email);
                valid=valid_email(newnode->email);
                if(valid[0]!=1 || valid[1]!=1){
                        printf("Enter valid Email:\n");
                        goto Em;
                }
                if(head==NULL){
                        head=newnode;
                }
                else{
                        temp=head;
                        while(temp->link){
                                temp=temp->link;
                        }
                        temp->link=newnode;
                }
        }
        return head;
}