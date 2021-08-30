#include<stdio.h>
#include <stdlib.h>
struct wordFileList{
    int id;
    char file_name[50];
    char file_content[2000];
    char date[20];
}wordList[50];
int counterForWord=0;

//Universally Used Functions START
int getStructArrayLength(struct wordFileList list[20]){
    for(int i=0;i<50;i++){
        printf("%d",list[i].id);
    }
}
//Universally Used Functions END

//Just For Word START

void openAWordDocument(){
    system("cls");
    printf("The list of documents are: \n");
    showListOfWord();
    printf("Which File Do You Want To Open: ");
    int choice;
    scanf("%d",&choice);
    system("cls");
    choice--;
    printf("Document Name: %s \n",wordList[choice].file_name);
    printf("%s\n\n",wordList[choice].file_content);
    printf("Press Any Key To Go Back");
    getch();
    system("cls");
    openWord();

}

void showListOfWord(){
    for(int i=0;i<counterForWord;i++){
        printf("%d. %s\n",i+1,wordList[i].file_name);
    }

}

void openWord(){
    system("cls");
    printf("####### Word Program ######\n");
    int choice;
    printf("1. Create a new document: \n");
    printf("2. Edit opening document: \n");
    printf("3. Delete a document: \n");
    printf("4. Open a document: \n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        createNewWord();
        break;
    case 4:
        openAWordDocument();
        break;
    }

}

void createNewWord(){
    system("cls");
    char submit;
    printf("####### Create A New Word Program ######\n");
    wordList[counterForWord].id=counterForWord;
    printf("Enter Your Document Name: ");
    getchar();
    fgets(wordList[counterForWord].file_name,50,stdin);
    printf("\nEnter The Content Of Your Document: \n");
    fgets(wordList[counterForWord].file_content,2000,stdin);
    printf("Enter Y/y to Submit: ");
    scanf("%s",&submit);
    if(submit=='Y' || submit=='y'){
        system("cls");
        printf("Word File Was SuccessFully Saved\n");
        printf("Press Any Key to Continue");
        getch();
        system("cls");
        counterForWord++;
        openWord();
    }else{
        system("cls");
        printf("Word File Was Not Saved\n");
        printf("Press Any Key to Continue");
        getch();
        system("cls");
        openWord();

    }

}

//Just For Word END

void openExcel(){
    return 0;
}

void openDatabase(){
    return 0;
}
int main() {
    while(1){
        int choice;
        printf("####### Welcome ######\n");
        printf("What program are you looking for:\n");
        printf("1. Word\n");
        printf("2. Excel\n");
        printf("3. Database\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
            printf("########Select Another Option########\n");

        }

    }
}

//Alignment
//Spacing
//UpperCase Lower Case
//Bullets -- *
// Custom function use garne ani while(true){ use # to type, similarly more)

