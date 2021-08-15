#include<stdio.h>

int main() {

}

void howToInputNewLine(){
char inputString[128];

   printf("Enter a multi line string\n");
   scanf("%[^;]s  ", inputString);

   printf("\n%s", inputString);

   return 0;
}
