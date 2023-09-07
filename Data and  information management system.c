#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

struct studentInfo
{
    char id[8];
    char name[20];
    char email[30];
    char phone[20];
    char dept[20];
    int  numberOfCourse;
};
//Global variable
struct studentInfo students[100];
int count=0;
char studentId[10];
int i,j;

int main()
{

    home:
    menu();
    int choice;
    printf("\tWe are here to help you.");
    printf(".....Enter your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 0:
        {
            exit1();
            break;
            return 0;
        }
    case 1:
        {
          system("cls");
          addStudents();
         goBackOrExit();
         goto home;
          break;
        }
    case 2:
        {
            system("cls");
            showAllStudents();
            goBackOrExit();
            goto home;
            break;

        }
    case 3:
        {


            system("cls");
            printf("\n\t Search Students^\n\n");
            printf(" Enter The last six digit of your ID: ");
            scanf("%s",studentId);
            int isFound = searchStudent(studentId);
            if(isFound<0)
            {
                printf(" No Student Found\n\n");
            }
            printf("\n");
            goBackOrExit();
            goto home;
            break;
        }
    case 4:
        {
             char sure = 'N';
            getchar();
            system("cls");


            printf("\nAre you sure want to delete all the students? (y/n): ");
            scanf("%c",&sure);
            if(sure == 'y' || sure == 'Y')
            {
                deleteAllStudents();
                goto home;
            }
            else
            {
                printf("\n\nYour Data is Safe.\n\n");
                goBackOrExit();
                goto home;
            }
            break;
        }
    case 5:
        {
            system("cls");
            break;
        }
    case 6:
        {
            system("cls");
            userGuideline();
            goBackOrExit();
            goto home;
            break;
        }
    case 7:
        {
            system("cls");
            about();
            goBackOrExit();
            goto home;
            break;
        }
    default:
        exit1();
    }
    getch();
}
void menu()
{

    printf("\n\t--Data and information Management--\n\n");
    printf("\tHome\n");
    printf("\t----\n");
    printf("\t1. Add A New Student.\n");
    printf("\t2. Display All Students.\n");
    printf("\t3. Search For A Student.\n");
    printf("\t4. Remove All Students.\n");
    printf("\t5. Clear The Screen.\n");
    printf("\t6. Instructions For User.\n");
    printf("\t7. About IUBAT.\n");
    printf("\t0. Quit the Program.\n");
    printf("\n\n");
}
void addStudents()
{
    char studentid[400];
    char name[300];
    char phone[300];
    char email[300];
    char dept[300];
    int numberOfCourses;
    printf("Enter last six digit of your Id: ");
    scanf("%s",&studentid);
    printf("Enter Name: ");
    scanf("%s",&name);
    printf("Enter Phone number: ");
    scanf("%s",&phone);
    printf("Enter Email: ");
    scanf("%s",&email);
    printf("Enter Department: ");
    scanf("%s",&dept);
    printf("Enter no of course that student taken: ");
    scanf("%d",&numberOfCourses);
    strcpy(students[count].id,studentid);
    strcpy(students[count].name,name);
    strcpy(students[count].phone,phone);
    strcpy(students[count].email,email);
    strcpy(students[count].dept,dept);
    students[count].numberOfCourse = numberOfCourses;
    count++;
    printf("\n Student Added Successfully....\n\n");



}
void exit1()
{
    system("cls");
     printf("\n\n\tThank You For Your Query.");
    printf("\n\tBest Wishes.");
    return 0;
}
void userGuideline()
{
    printf("\n\t Instructions:\n\n");
    printf("\t1. You will only able to store the Student's ID, Name, Email, Phone,department, Number of Courses.\n");
    printf("\t2. A student can have maximum 4 courses and minimum 1 course.\n");
    printf("\t3. Student ID can be maximum 6 characters long and unique for every students.\n");
    printf("\t4. Student Name can be maximum 20 characters long.\n");
    printf("\t5. Student Email can be maximum 20 characters long and unique for every students.\n");
    printf("\t6. Student Phone can be maximum 11 characters long and unique for every students.\n");
    printf("\t7. Department name can be maximum 10 characters long.\n\n");

}
void showAllStudents()
{

    printf("\n\n");
    printf("|   ID       |        Name        |        Email       |    Phone    | NO.Course|   Dept.  |\n");
    printf("|------------|--------------------|--------------------|-------------|----------|----------|\n");

    for(i=0; i<count; i++)
    {
        printf("|");
        printf("%s",students[i].id);
        for(j=0; j < (12-strlen(students[i].id)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",students[i].name);
        for(j=0; j < (20-strlen(students[i].name)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",students[i].email);
        for(j=0; j < (20-strlen(students[i].email)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",students[i].phone);
        for(j=0; j < (13-strlen(students[i].phone)); j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%d",students[i].numberOfCourse);
        for(j=0; j < 9; j++)
        {
            printf(" ");
        }
        printf("|");
        printf("%s",students[i].dept);
        for(j=0; j < (10-strlen(students[i].dept)); j++)
        {
            printf(" ");
        }

        printf("|\n");
        printf("|------------|--------------------|--------------------|-------------|----------|----------|\n");

    }
    printf("\n");
}
int searchStudent(char studentId[10])
{
    system("cls");
    int studentFoundIndex = -1;

    int i;
    for(i=0; i<count; i++)
    {
        if(strcmp(studentId,students[i].id) == 0)
        {
            studentFoundIndex = i;
            printf("\n One Student Found for ID: %s\n\n",studentId);
            printf(" Student Informations:\n");
            printf("\n");

            printf(" ID:    %s\n",students[i].id);
            printf(" Name:  %s\n",students[i].name);
            printf(" Email: %s\n",students[i].email);
            printf(" Phone: %s\n",students[i].phone);
            printf(" Department: %s\n",students[i].dept);
            printf("\n Total Number of Courses: %d\n",students[i].numberOfCourse);
        }
    }

    return studentFoundIndex;
}
void deleteAllStudents()
{
    count = 0;
    printf("\n\nAll Students Deleted Successfully.\n\n");
    goBackOrExit();
}


void goBackOrExit()
{
    getchar();
    char option;
    printf(" Want to Go back?? press (b): ");
    scanf("%c",&option);

    if(option=='b')
    {
        system("cls");
    }
    else
        printf("Invalid");
}
void about()
{
    printf("\n\t** Iubat is the first non-government university in Bangladesh.\n");
    printf("\n\t** The university was established in 1991. \n");
    printf("\n\t** In this university, there are about 300 teachers to teach students\n");
    printf("\n\t** In this university,there are 10 several departments to study\n");
    printf("\n\t** To know about the unversity more, you can visit our website");
    printf("\n\t   www.iubat.edu\n\n");

}

