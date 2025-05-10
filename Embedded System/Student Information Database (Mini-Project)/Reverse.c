#include"myheader.h"
void Reverse_Func(STUDENT* head){
        if(head==NULL){
                printf("list is empty\n");
        }
        else{
                if(head->link!=NULL){
                        Reverse_Func(head->link);
                }
                printf("\n");
                printf("Student ID:%s\n",head->SID);
                printf("Name:%s\n",head->name);
                printf("D.O.B: %d:%d:%d\n",head->DOB.date,head->DOB.month,head->DOB.year);
                printf("Percentage of Matric:%.2f\n",head->marks.Matric);
                printf("Percentage of Inter/Diploma:%.2f\n",head->marks.HE.Inter);
                printf("Percentage of graduation:%.2f\n",head->marks.graduation);
                printf("Contact Number:%s\n",head->contact);
                printf("Email ID:%s\n",head->email);


        }

}
