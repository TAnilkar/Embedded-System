/********************************************************************************************************************************
                                           myheader.h
********************************************************************************************************************************\

1) In myheader.h file I write all the headerfile names which are needed for an predefined functions used to build student database.
2) In myheader.h file ,I declare an structure called student which contains structure members like StudentId,name of student, D.O.B,marks(Matric,Inter/Diploma,graduation),contact number,email id.
3) I also added the userdefined functions declarations which are required for student database(add_func(),print_func(),save_func(),Delete_Func(),Edit_Func(),Find_Func(),Reverse_Func()).


/********************************************************************************************************************************
                                           menu.c
***********************************************************************************************************************************\

1)All needed header files and function declarations are present in the myheader.h file.For every function the seperate files are created.
2)In this file,I use one structure pointer head which is passed as a argument to do the specific operation based on data.
3)Here one Sync_Func is present which sync the previous add record with new added records.
4)In this file I take a menu printing until we enter q/Q to exit from app, it has number of functionalities like add,delete,print,reverse print,edit and so on.
5)Base on our choice using switch statement we can use any function.



/********************************************************************************************************************************
                                          makefile
********************************************************************************************************************************\

1)In this file we use make utility to reduce the recompilation time.
2)In this file I add target file(a.out) and subtarget files(menu.o,Add.o,Print.o,Del.o,Edit.o,Save.o,Sync.o,RevPrint.o).


/*******************************************************************************************************************************
                                           Add.c
*******************************************************************************************************************************\

1)This file is used for adding new record.
2)I declare structure pointer named as newnode for adding new data and temp for traversing.
3)I allocate memmory dynamically using calloc() function.
4)Then I am checking if newnode is allocated or not,if not allocate print msg newnode not created.
5)The memory if allocated then add data into the newnode record,here I use create_Id function for automatically generate the Student ID's based on name of Student,then add other data like DOB,marks,contact,email,I additionally write functions or conditional statements to find if given data is valid or not if not valid re-enter the data.
6)After that check is record is empty or not,if empty pass newnode to head.
7)Else use temp to tranverse upto get link NULL ,when we find link as NULL pass it newnode.
8)At last return first node address.


/********************************************************************************************************************************
                                           Print.c
*********************************************************************************************************************************\

1)This file is used for Print the record.
2)First we check if the head is NULL or not ,if NULL print empty msg.
3)Else traverse and print every node until we not getting link as NULL.


/********************************************************************************************************************************
                                            Delete.c
********************************************************************************************************************************\

1)This file is used to delete an record based on SID.
2)I take an two structure pointers for traversing and storing prev node address.
3)Then I check if a head is equal to NULL the print msg Database is empty.
4)Else if the first nodes SID is matched with the ID,then take the head to temp , give heads link to head and free the temp.
5)Else traverse until we reached the firstnode again or data matched.
        if reached to NULL means data not found.
        else link previous link node with next node & delete current node.
6)return first node address.


/********************************************************************************************************************************
                                             Reverse.c
********************************************************************************************************************************\

1)This file is used for printing the student records in the reverse order,without actually changing its order.
2)I use recursive function to to print the records.
3)If head is NULL then print list is empty.
4)Else
        if head link is not equal to NULL then call Reverse_func() and after that print the records data in reverse order.


/********************************************************************************************************************************
                                             Edit.c
********************************************************************************************************************************\

1)This file is used to edit a particular data based on the student id (name,DOB,email,contact,percentage).
2)If the head is NULL then print the Database is empty msg.
3)Else traverse the head and check until its SID is not equal to ID.
4)After that check if head becomes NULL or not ,if becomes NULL means ID not found.
5)else print the sub-menu and using switch case ask choice of edit any member of structure.


/********************************************************************************************************************************
                                             Save.c
********************************************************************************************************************************\

1)This file is used for an saving the entered records of the students to the File.
2)I take one file pointer fp for doing open the file and other operations, also i take size variable for the taking data as per the required to store data other than link of structure.Hence that's the reason I minus the sizeof(STUDENT) with sizeof(STUDENT*).
3)If head is NULL, print msg as Database is empty.
4)Else first open the file in an write mode("w"),then check fp ,if fp is NULL then print file not found msg,else in the while loop check head and write the data into the file using fwrite userdefined function and move the head with head link.
5)At last close the file(fp).


/********************************************************************************************************************************
                                             Sync.c
********************************************************************************************************************************\

1)This file is used to sync the previous data to current records.
2)I take one file pointer fp for doing open the file and other operations, also i take size variable for the taking data as per the required to store data other than link of structure.Hence that's the reason I minus the sizeof(STUDENT) with sizeof(STUDENT*).
3)I take newnode variable for adding newnodes to it and temp variable for traversing the nodes.
4)then open the file in read only mode("r");
5)Check if the fp is NULL, if yes then return head.
6)Then use while loop for taking the number of records presented in the file.After that create newnode using calloc and intialised it .
7)Check if the head is NULL ,if yes the give newnode to it.
8)Else  give head to temp,and used for loop for the traversing upto the temp link becomes the NULL;
9)When temp link becomes NULL give it newnode.
10)close the fp and return the head.

