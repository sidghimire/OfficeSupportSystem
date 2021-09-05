#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<windows.h>
struct wordFileList{
    int id;
    char file_name[50];
    char file_content[2000];
}wordList[50];

struct excelFileList{
    int id;
    char file_name[50];
    char keyList[30][100];
    int valueList[30];
}excelList[50];
int counterForWord=0;
int counterForExcel=0;
//Universally Used Functions START
int getStructArrayLength(struct wordFileList list[20]){
    for(int i=0;i<50;i++){
        printf("%d",list[i].id);
    }
}
//Universally Used Functions END

//Just For Word START

void deleteAWordDocument(){
    system("cls");
    printf("\n\t\t\t\t\t\The list of documents are: \n");
    showListOfWord();
    printf("\n\t\t\t\t\t\Which File Do You Want To Delete: ");
    int choice;
    scanf("%d",&choice);
    system("cls");
    choice--;
    int length=0,count=0;
    char test[50],test2[2000];
    while(count<50){
            if(strlen(wordList[count].file_name)!=0){
                length++;
            }
        count++;
    }
    for(int i=choice;i<length;i++){
        if(i!=length){
            wordList[i].id=wordList[i+1].id;
            strcpy(wordList[i].file_name,wordList[i+1].file_name);
            strcpy(wordList[i].file_content,wordList[i+1].file_content);
        }else{
            wordList[i].id=0;
            strcpy(wordList[i].file_name,test);
            strcpy(wordList[i].file_content,test2);
        }

    }
    counterForWord--;
    openWord();

    }


void openAWordDocument(){
    system("cls");
    printf("\n\t\t\t\t\t\The list of documents are: \n");
    showListOfWord();
    printf("\n\t\t\t\t\t\Which File Do You Want To Open: ");
    int choice;
    scanf("%d",&choice);
    system("cls");
    choice--;
    printf("\n\t\tDocument Name: %s \n",wordList[choice].file_name);
    printf("%s\n\n",wordList[choice].file_content);
    printf("\n\t\t\t\t\t\Press Any Key To Go Back");
    getch();
    system("cls");
    openWord();
}

void editAWordDocument(){
    system("cls");
    printf("The list of documents are: \n");
    showListOfWord();
    printf("Which File Do You Want To Open: ");
    int choice;
    scanf("%d",&choice);
    system("cls");
    choice--;
    char submit;
    printf("####### Edit Document ######\n");
    printf("\nOriginal Name:%s\n",wordList[choice].file_name);
    printf("Edit Your Document Name: ");

    getchar();
    fgets(wordList[choice].file_name,50,stdin);
    printf("\n\t\tEdit The Content Of Your Document:\n");
    fgets(wordList[choice].file_content,2000,stdin);
    printf("\n\t\tEnter Y/y to Submit: ");
    scanf("%s",&submit);
    if(submit=='Y' || submit=='y'){
        system("cls");
        printf("\n\t\t\t\t\t\Word File Was SuccessFully Saved\n");
        printf("\n\t\t\t\t\t\Press Any Key to Continue");
        getch();
        system("cls");
        openWord();
    }else{
        system("cls");
        printf("\n\t\t\t\t\t\Word File Was Not Saved\n");
        printf("\n\t\t\t\t\t\Press Any Key to Continue");
        getch();
        system("cls");
        openWord();

    }
}

void showListOfWord(){
    for(int i=0;i<counterForWord;i++){
        printf("%d. %s\n",i+1,wordList[i].file_name);
    }

}




void openWord(){
    system("cls");
    system("color 0B");
    printf("\n\n\t\t\t\t\t\t\tWord Program\n");
    printf("\n\t\t\t\t\t_____________________________________________");
    int choice;
    printf("\n\n\t\t 1. Create a new document: ");
    printf("\t\t\t\t\t\t 2. Edit document: \n");
    printf("\t\t 3. Delete a document: ");
    printf("\t\t\t\t\t\t\t 4. Open a document: \n");
    printf("\t\t 5. Exit\n");
    printf("\n\t Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        createNewWord();
        break;
    case 2:
        editAWordDocument();
        break;
    case 3:
        deleteAWordDocument();
        break;
    case 4:
        openAWordDocument();
        break;
    }
}

void createNewWord(){
    system("cls");
    char submit;
    printf("\t\t\t\t\t\tCreate A New Word Program \n");
    wordList[counterForWord].id=counterForWord;
    printf("\n\t\t Enter Your Document Name: ");
    getchar();
    fgets(wordList[counterForWord].file_name,50,stdin);
    printf("\n\t\t Enter The Content Of Your Document: ");
    fgets(wordList[counterForWord].file_content,2000,stdin);
    printf("\n\t\tEnter Y/y to Submit: ");
    scanf("%s",&submit);
    if(submit=='Y' || submit=='y'){
        system("cls");
        printf("\n\t\t\t\t\t\tWord File Was SuccessFully Saved\n");
        printf("\n\t\t\t\t\t\tPress Any Key to Continue");
        getch();
        system("cls");
        counterForWord++;
        openWord();
    }else{
        system("cls");
        printf("\n\t\t\t\t\t\t Word File Was Not Saved");
        printf("\n\t\t\t\t\t\t Press Any Key to Continue");
        getch();
        system("cls");
        openWord();
    }
}
//Just For Word END


//Just For Excel START
void showListOfExcel(){
    for(int i=0;i<counterForExcel;i++){
        printf("%d. %s\n",i+1,excelList[i].file_name);
    }

}
void createNewRecord(){
    system("cls");
    char submit;
    int keys=0;
    printf("\n\t\t\t\t\t\Create A New Excel Program");
    excelList[counterForExcel].id=counterForExcel;
    printf("\n\t\t\t\t\t\Enter Your Excel Document Name: ");
    getchar();
    fgets(excelList[counterForExcel].file_name,50,stdin);
    printf("\n\t\t\t\t\t\How many keys do you want to enter:");
    scanf("%d",&keys);
    for(int i=0;i<keys;i++){
        printf("\n\t\t\t\t\t\Enter the Key At Position %d: ",i+1);
        scanf("%s",&excelList[counterForExcel].keyList[i]);

    }
    printf("\n");
    for(int j=0;j<keys;j++)
    {
        printf("\n\t\t\t\t\t\Enter Value of %s:",excelList[counterForExcel].keyList[j]);
        scanf("%d",&excelList[counterForExcel].valueList[j]);
    }
    printf("\n\t\t\t\t\t\Enter Y/y to Submit: ");
    scanf("%s",&submit);
    if(submit=='Y' || submit=='y'){
        system("cls");
        printf("\n\t\t\t\t\t\Word File Was SuccessFully Saved\n");
        printf("\n\t\t\t\t\t\Press Any Key to Continue");
        getch();
        system("cls");
        counterForExcel++;
        openExcel();
    }else{
        system("cls");
        printf("\n\t\t\t\t\t\Word File Was Not Saved\n");
        printf("\n\t\t\t\t\t\Press Any Key to Continue");
        getch();
        system("cls");
        openExcel();
    }
}

void openRecord(){
    system("cls");
    printf("The list of record are: \n");
    showListOfExcel();
    printf("Which Record Do You Want To Open: ");
    int choice;
    scanf("%d",&choice);
    system("cls");
    choice--;
    int length=0;
    int count=0,x=0;

    while(count<30){

            if(strlen(excelList[choice].keyList[x])!=0){
                length++;
            }
            count++;
            x++;
    }
    printf("Document Name: %s \n",excelList[choice].file_name);
   for(int i=0;i<length;i++){
        printf("%s : %d",excelList[choice].keyList[i],excelList[choice].valueList[i]);
        printf("\n\n");
    }
    printf("Press Any Key To Go Back");
    getch();
    system("cls");
    openExcel();
}
void deleteRecord(){

    system("cls");
    printf("The list of record are: \n");
    showListOfExcel();
    printf("Which Record Do You Want To Open: ");
    int choice;
    scanf("%d",&choice);
    system("cls");
    choice--;
    int length=0,count=0;
    char test[50],test2[30];
    while(count<50){
            if(strlen(excelList[count].file_name)!=0){
                length++;
            }
        count++;
    }

    for(int i=choice;i<length;i++){
        if(i!=length){
            excelList[i].id=excelList[i+1].id;
            strcpy(excelList[i].file_name,excelList[i+1].file_name);
            memcpy(excelList[i].keyList, excelList[i+1].keyList, sizeof excelList[i].keyList);
            memcpy(excelList[i].valueList, excelList[i+1].valueList, sizeof excelList[i].valueList);

        }else{
            excelList[i].id=0;
            strcpy(wordList[i].file_name,test);
            memcpy(excelList[i].keyList, test2, sizeof excelList[i].keyList);
            memcpy(excelList[i].valueList, test2, sizeof excelList[i].valueList);
        }

    }
    counterForExcel--;
    openExcel();
}

void editRecord(){
    char submit;

    system("cls");
    printf("The list of record are: \n");
    showListOfExcel();
    printf("Which Record Do You Want To Open: ");
    int choice,x=0;
    scanf("%d",&choice);
    system("cls");
    choice--;
    printf("####### Edit Excel File ########\n");
    printf("File Name: %s",excelList[choice].file_name);
    int length=0,count=0;
    while(count<30){

            if(strlen(excelList[choice].keyList[x])!=0){
                length++;
            }
            count++;
            x++;
    }
    printf("\n");
    for(int j=0;j<length;j++)
    {
        printf("Enter Value of %s:",excelList[choice].keyList[j]);
        scanf("%d",&excelList[choice].valueList[j]);
    }
    printf("Enter Y/y to Submit: ");
    scanf("%s",&submit);
    if(submit=='Y' || submit=='y'){
        system("cls");
        printf("Word File Was SuccessFully Saved\n");
        printf("Press Any Key to Continue");
        getch();
        system("cls");
        openExcel();
    }else{
        system("cls");
        printf("Word File Was Not Saved\n");
        printf("Press Any Key to Continue");
        getch();
        system("cls");
        openExcel();
    }
}
//Just For Excel STOP

void openExcel(){
    system("cls");
    system("color 0A");
    printf("\n\n\t\t\t\t\t\t\tExcel Program \n");
    printf("\n\t\t\t\t\t_____________________________________________");
    int choice;
    printf("\n\n\t\t 1. Create a new Record: ");
    printf("\t\t\t\t\t\t 2. Edit record: ");
    printf("\n\t\t\ 3. Delete a record: ");
    printf("\t\t\t\t\t\t\t 4. Open a record: ");
    printf("\n\t\t 5. Exit");
    printf("\n\t\t Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        createNewRecord();
        break;
    case 2:
        editRecord();
        break;
    case 3:
        deleteRecord();
        break;
    case 4:
        openRecord();
        break;
    }

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

