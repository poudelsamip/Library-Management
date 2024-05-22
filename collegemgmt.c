#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct students{
    char sname[20];
    int roll;
    int sem;
    char ssub[10];
}students;

typedef struct teachers{
    char tname[20];
    int salary;
}teachers;


void addStudent(students student[], int* snum);
void addTeacher(teachers teacher[], int* tnum);
void removeStudent(students student[], int* snum);
void removeTeacher(teachers teacher[], int* tnum);
void viewStudents(students student[],int* snum);
void viewTeachers(teachers teacher[],int* tnum);
void searchStudents(students student[],int* snum);
void searchTeachers(teachers teacher[],int* tnum);


int main(){
    printf("\n--  WELCOME TO COLLEGE MANAGEMENT SYSTEM  --\n");
    int choice;
    students student[10];
    int snum = 0;
    teachers teacher[10];
    int tnum = 0;
    
    do{
        printf("\nMENU :");
        printf("\n1. Add Student");
        printf("\n2. Add Teacher");
        printf("\n3. Remove Student");
        printf("\n4. Remove Teacher");
        printf("\n5. View All Students");
        printf("\n6. View All Teachers");
        printf("\n7. Search Student");
        printf("\n8. Search Teacher");
        printf("\n0. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        addStudent(student,&snum);
        break;
    case 2:
        addTeacher(teacher,&tnum);
        break;
    case 3:
        removeStudent(student,&snum);
        break;
    case 4:
        removeTeacher(teacher,&tnum);
        break;
    case 5:
        viewStudents(student,&snum);
        break;
    case 6:
        viewTeachers(teacher,&tnum);
        break;
    case 7:
        searchStudents(student,&snum);
        break;
    case 8:
        searchTeachers(teacher,&tnum);
        break;
    case 0:
        printf("Program Exitted\n");
        printf("\n");
        break;
    default:
        printf("Input Invalid");
        break;
    }

    } while (choice!=0);
    
    return 0;
}

void addStudent(students student[], int* snum){
    printf("\n-- ADD STUDENT --\n");
    printf("\nStudent's name: ");
    scanf(" %[^\n]",&student[*snum].sname);
    printf("Student's roll no: ");
    scanf("%d",&student[*snum].roll);
    printf("Semester: ");
    scanf("%d",&student[*snum].sem);
    printf("Course: ");
    scanf(" %[^\n]",&student[*snum].ssub);
    printf("\n!! Student Added Successfully !!\n");
    (*snum)++;
    return;
}

void addTeacher(teachers teacher[], int* tnum){
    printf("\n-- ADD TEACHER --\n");
    printf("\nTeachers's name: ");
    scanf(" %[^\n]",&teacher[*tnum].tname);
    printf("Salary: ");
    scanf("%d",&teacher[*tnum].salary);
    printf("\n!! Teacher Added Successfully !!\n");
    (*tnum)++;
    return;
}

void removeStudent(students student[], int* snum){
    printf("\n-- REMOVE STUDENT --\n");
    char remove[20];
    printf("\nEnter student: ");
    scanf(" %[^\n]",remove);
    for(int i=0;i<*snum;i++){
        if(strcmp(remove,student[i].sname)==0){
            for(int j=i;j<*snum;j++){
                strcpy(student[j].sname,student[j+1].sname);
                student[j].roll=student[j+1].roll;
                student[j].sem=student[j+1].sem;
                strcpy(student[j].ssub,student[j+1].ssub);
            }
        }
    }
    printf("Student Removed Succesfully\n");
    (*snum)--;
    return;
}

void removeTeacher(teachers teacher[], int* tnum){
    printf("\n-- REMOVE TEACHER --\n");
    char remove[20];
    printf("\nEnter teacher: ");
    scanf(" %[^\n]",remove);
    for(int i=0;i<*tnum;i++){
        if(strcmp(remove,teacher[i].tname)==0){
            for(int j=i;j<*tnum;j++){
                strcpy(teacher[j].tname,teacher[j+1].tname);
                teacher[j].salary=teacher[j+1].salary;
            }
        }
    }
    printf("Teacher Removed Succesfully\n");
    (*tnum)--;
    return;
}

void viewStudents(students student[],int* snum){
    printf("\n--  ALL STUDENTS  --\n");
    printf("\nName\tRoll\tSem\tsubject\n");
    for(int i=0;i<*snum;i++){
        printf("%s\t%d\t%d\t%s\n",student[i].sname,student[i].roll,student[i].sem,student[i].ssub);
    }
    return;
}

void viewTeachers(teachers teacher[],int* tnum){
    printf("\n--  ALL TEACHERS  --\n");
    printf("\nName\tSalary\n");
    for(int i=0;i<*tnum;i++){
        printf("%s\t%d\n",teacher[i].tname,teacher[i].salary);
    }
    return;
}

void searchStudents(students student[],int* snum){
    printf("\n-- SEARCH STUDENT --\n");
    char search[20];
    int found = 0;
    printf("\nEnter student name: ");
    scanf(" %[^\n]",search);
    printf("\nName\tRoll\tSem\tsubject\n");
    for(int i=0;i<*snum;i++){
        if(strcmp(search,student[i].sname)==0){
            printf("\n%s\t%d\t%d\t%s\n",student[i].sname,student[i].roll,student[i].sem,student[i].ssub);
            found = 1;
        }
    }
    if(!found) printf("Student Not Found\n");
    return;
}

void searchTeachers(teachers teacher[],int* tnum){
    printf("\n-- SEARCH TEACHER --\n");
    char search[20];
    int found = 0;
    printf("\nEnter teacher name: ");
    scanf(" %[^\n]",search);
    printf("\nName\tSalary\n");
    for(int i=0;i<*tnum;i++){
        if(strcmp(search,teacher[i].tname)==0){
            printf("\n%s\t%d\n",teacher[i].tname,teacher[i].salary);
            found = 1;
        }
    }
    if(!found) printf("Teacher Not Found\n");
    return;
}
