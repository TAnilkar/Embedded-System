#include"myheader.h"
void Edit_Func(STUDENT *head,char *ID){
        char choice,ch;
        int d,m,y;
        if(head==NULL){
                printf("Database is empty\n");
        }
        else{
                while(head && (strcmp(head->SID,ID)!=0)){
                        head=head->link;
                }
                if(head==NULL){
                        printf("ID not Found\n");
                }
                else{
                        printf("                         Sub-Menu                      \n");
                        printf("1.Name Edit\t2.DOB\t3.Percentage\t4.Contact\t5.EmailID\n");
                        printf("Enter choice:");
Input1:                 scanf(" %c",&choice);
                        switch(choice){
                                case '1':printf("Enter Name:\n");
                                         scanf("%s",head->name);
                                         break;
                                case '2':printf("Enter DOB:\n");
                                         scanf("%d %d %d",&d,&m,&y);
                                         head->DOB.date=d,head->DOB.month=m,head->DOB.year=y;
                                         break;
                                case '3':
input:                                    printf("M.Matric I.Inter D.Diploma G.graduation\n");
                                          scanf(" %c",&ch);
                                          switch(ch){
                                                  case 'M': printf("Enter percentage of Matric:\n");
                                                            scanf("%f",&head->marks.Matric);
                                                            break;
                                                  case 'I': puts("Inter percentage:");
                                                            scanf("%f",&head->marks.HE.Inter);
                                                            break;
                                                  case 'D':puts("Diploma percentage:");
                                                           scanf("%f",&head->marks.HE.Diploma);
                                                           break;
                                                  case 'G': printf("Enter percentage of graduation:\n");
                                                            scanf("%f",&head->marks.graduation);

                                                            break;
                                                  default:
                                                            printf("Invalid choice Enter again:\n");
                                                            goto input;
                                          }
                                          break;
                                case '4':printf("Enter Contact:\n");
                                         scanf("%s",head->contact);
                                         break;
                                case '5':printf("Enter EmailID:\n");
                                         scanf("%s",head->email);
                                         break;
                                default :printf("invalid choice Enter again:\n");
                                         goto Input1;
                        }
                }
        }
}