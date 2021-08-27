#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
void openWord(){
    system("cls");
    system("color 0B");
    printf("\t\t\t\t\t\t Word Program \n\n");
    int choice;
    printf("1. Create a new document: \n");
    printf("2. Edit opening document: \n");
    printf("3. Delete a document: \n");
    printf("4. Open a document: \n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

}

void openExcel(){
    return 0;
}

void openDatabase(){
    return 0;
}
int main() {
    while(1){
        int choice;
        system("color 0C");
        printf("\t\t\t\t\t\t\tWelcome\n\n");
        printf("What program are you looking for:\n");
        printf("1. Word\n");
        printf("2. Excel\n");
        printf("3. Database\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            openWord();
            break;
        case 2:
            openExcel();
            break;
        case 3:
            openDatabase();
            break;
        case 4:
            exit(1);
            break;
        default:
            system("cls");
            system("color 0B");
            printf("ERROR!!!");
            printf("\n\nSelect Another Option:");

        }

    }
}

void howToInputNewLine(){

}
//Alignment
//Spacing
//UpperCase Lower Case
//Bullets -- *
// Custom function use garne ani while(true){ use # to type, similarly more)

