#include"myheader.h"
extern unsigned int ID[26];
int main(){
        STUDENT *head=NULL;
        char choice;
        char Id[20];
        head=Sync_Func(head);
        while(1){
                printf("************************************************************************************\n");
                printf("                                 MENU                                               \n");
                printf("************************************************************************************\n");
                printf("\n");
                printf("a/A: Add a new student record\n");
                printf("p/P: Print the records from database\n");
                printf("s/S: Save the database in file\n");
                printf("d/D: Delete a record\n");
                printf("e/E: Edit a record:\n");
                printf("\t1)Name edit\t2)DOB\t3)Percentage\t4)Contact\t5)Email\n");
                printf("f/F: Find a student\n");
                printf("r/R: Reverse the records of current display\n");
                printf("q/Q: Quit from app\n");
                printf("\n");
                printf("Enter choice:");
                __fpurge(stdin);
                scanf("%c",&choice);
                switch(choice){
                        case 'a':
                        case 'A':head=Add_Func(head);
                                break;
                        case 'p':
                        case 'P':Print_Func(head);
                                break;
                        case 's':
                        case 'S':Save_Func(head);
                                 break;
                        case 'd':
                        case 'D':printf("Enter ID:\n");
                                 scanf("%s",Id);
                                 head=Delete_Func(head,Id);
                                 break;
                        case 'e':
                        case 'E':printf("Enter ID:\n");
                                 scanf("%s",Id);
                                 Edit_Func(head,Id);
                                break;
                        case 'f':
                        case 'F':printf("Enter ID:\n");
                                 scanf("%s",Id);
                                 Find_Func(head,Id);
                                 break;
                        case 'r':
                        case 'R':Reverse_Func(head);
                                break;
                        case 'q':
                        case 'Q':
                                exit(0);
                }
        }
}