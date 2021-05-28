/*
Word Counter by Nikko Gabriel J Hismaña
-asks user to input string
-counts the number of words separated by white spaces
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000 //define maximum size of character array string

int main(){
    char str[MAX_SIZE];
    int wordCount = 1, i=0, stringLen;

    //ask user input, store in str variable using gets() function
    printf("Enter string: ");
    gets(str);
    stringLen = strlen(str);

    //loop until end of string
    for (i = 0; i < stringLen; i++) {

		if ((str[i] == ' ' || //checks for whitespace
            str[i] == '\t') && //checks for tabs
            (str[i+1] != ' ')){ //bugfix: do not count consequtive tabs
            wordCount++;	
        }
    }

    printf("The number of words in '%s' is: %d", str, wordCount);
    
    //prevent window from closing as soon as wordcount results are printed
    getc(stdin);
    return 0;
}