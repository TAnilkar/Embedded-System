#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#include<stdio_ext.h>
#include<math.h>
extern unsigned int ID[26];
struct DateOfBirth{
        unsigned int date:5;
        unsigned int month:4;
        unsigned int year:23;
};
union HigherEdu{
        float Inter;
        float Diploma;
};
struct Marks{
        float Matric;
        union HigherEdu HE;
        float graduation;
};

typedef struct student{
        char SID[20];
        char name[50];
        struct DateOfBirth DOB;
        struct Marks marks;
        char contact[13];
        char email[20];
        struct student *link;
}STUDENT;

STUDENT* Add_Func(STUDENT*);
void Print_Func(STUDENT*);
STUDENT* Delete_Func(STUDENT*,char *);
void Find_Func(STUDENT* ,char *);
void Reverse_Func(STUDENT*);
void Edit_Func(STUDENT*,char *);
void Save_Func(STUDENT*);
STUDENT* Sync_Func(STUDENT*);
