// this is a library management system in c programming.
// this program doesnot store data in any file.
// file handling can be used to store data in txt file.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct lib{
    char title[100];
    char author[100];
    char borrowersName[100];
    bool isBorrowed;
}lib;
bool checkBook(lib book[],int* num,char selectedBook[]);
void addBook(lib book[], int* num);
void removeBook(lib book[],int* num);
void viewBook(lib book[], int* num);
void searchBook(lib book[],int* num);
void borrowBook(lib book[],int* num);
void returnBook(lib book[],int* num);

int main(){
    int choice;
    int num = 0;
    lib book[50];

    
    printf("\n<-##  WELCOME TO LIBRARY MANAGEMENT SYSTEM  ##->\n");
    do{
        printf("\n--  Main Menu  --");
        printf("\n1. Add New Book");
        printf("\n2. Remove Book");
        printf("\n3. View All Books");
        printf("\n4. Search Book");
        printf("\n5. Borrow Book");
        printf("\n6. Return Book");
        printf("\n0. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);

        switch (choice){
        case 1:
            addBook(book,&num);
            break;
        case 2:
            removeBook(book,&num);
            break;
        case 3:
            viewBook(book,&num);
            break;
        case 4:
            searchBook(book,&num);
            break;
        case 5:
            borrowBook(book,&num);
            break;
        case 6:
            returnBook(book,&num);
            break;
        case 0:
            printf("<<--|  PROGRAM CLOSED  |-->>");
            break;
        default:
            printf("Invalid Choice");
            break;
        }
    } while (choice!=0);
    
    return 0;
}

bool checkBook(lib book[],int* num,char selectedBook[]){
    bool bookFound=false;
    for (int i = 0; i < *num; i++) {
        if (strcmp(book[i].title,selectedBook)==0) {
            bookFound = true;
            break;
        }
    }
    return bookFound;
}

void addBook(lib book[],int* num){
    char choice;
    char bookName[20];
    printf("\n-- ADD BOOK TO LIBRARY-- \n");
    do {
        printf("\nEnter Book Name : ");
        scanf(" %[^\n]",&bookName);
        
        if (!checkBook(book, num, bookName)) {
            strcpy(book[*num].title,bookName);
            printf("Enter Author Name : ");
            scanf(" %[^\n]",&book[*num].author);
        
            printf("\n!!  %s by %s SUCCESSFULLY ADDED !!\n",book[*num].title,book[*num].author);
            (*num)++;
        }
        else printf("\nBook is already present in library.\n");
        
        printf("\nDo you want to add more bookS? (Y/N) : ");
        scanf(" %c",&choice);
    } while (choice == 'y' || choice == 'Y');
    return ;
}

void removeBook(lib book[],int* num){
    printf("\n-- REMOVE BOOK FROM LIBRARY --\n");
    char remove[100];
    char choice;
    do {
        printf("\nEnter a book to remove: ");
        scanf(" %[^\n]",&remove);
        
        if(checkBook(book, num, remove)) {
            for(int i=0;i<*num;i++){
                if(strcmp(book[i].title,remove)==0){
                    for(int j=i;j<*num;j++){
                        strcpy(book[j].title,book[j+1].title);
                        strcpy(book[j].author,book[j+1].author);
                    }
                    (*num)--;
                    printf("Book Removed successfully :(\n");
                    break;
                }
            }
        }
        else printf("\nBook is not in library\n");
        printf("\nDo you want to remove more books? (Y/N) : ");
        scanf(" %c",&choice);
    } while (choice == 'y' || choice == 'Y');
    return;
}

void viewBook(lib book[],int* num){
    printf("\n-- BOOKS AVAILABLE IN LIBRARY --\n");
    printf("\nS.N\tBOOK\t\tAUTHOR\t\tBURROWED?\n");
    for (int i = 0; i < *num; i++){
        printf("%d\t%s\t%s\t%d\n",i+1,book[i].title,book[i].author,book[i].isBorrowed);
    }
    return;
}

void searchBook(lib book[],int* num){
    printf("\n-- SEARCH BOOK IN LIBRARY --\n");
    char search[50];
    printf("\nEnter a book to search: ");
    scanf(" %[^\n]",&search);
    
    if(checkBook(book, num, search)) {
        for(int i=0;i<*num;i++){
            if(strcmp(search,book[i].title)==0){
                printf("Book Found\n");
                printf("%s by %s\n",book[i].title,book[i].author);
                return;
            }
        }
    }
    else{
        printf("\nBook not found\n");
        return;
    }
}

void borrowBook(lib book[],int* num){
    char borrow[50];
    char name[50];
    printf("\n-- BORROW BOOK FROM LIBRARY  --\n");
    printf("\nEnter book name: ");
    scanf(" %[^\n]",&borrow);
    if(checkBook(book,num,borrow)){
        for(int i=0;i<*num;i++){
            if(strcmp(borrow,book[i].title)==0){
                if(book[i].isBorrowed == false){
                    printf("Enter Borrower's Name : ");
                    scanf(" %[^\n]",&name);
                    book[i].isBorrowed = true;
                    printf("\n%s borrowed by %s\n",book[i].title,name);
                    strcpy(book[i].borrowersName,name);
                    return;
                }
                else{
                    printf("Book is already borrowed by someone else.\n");
                    return;
                }
            }
        }
    }
    else{
        printf("\nBook not available in Library\n");
        return;
    }
}

void returnBook(lib book[],int* num){
    char borrow[50];
    printf("\n--  RETURN BOOK TO LIBRARY  --\n");
    printf("\nEnter book name: ");
    scanf(" %[^\n]",&borrow);

    if(checkBook(book, num, borrow)) {
        for(int i=0;i<*num;i++){
            if(strcmp(borrow,book[i].title)==0 && book[i].isBorrowed){
                book[i].isBorrowed = false;
                printf("\n%s returned by %s\n", book[i].title,book[i].borrowersName);
                strcpy(book[i].borrowersName,"");
                return;
            }
            else{
                printf("\nThis book was not borrowed from here\n");
            }
        }
    }
    else{
        printf("\nThis book is not available library\n");

        return;
    }
}
