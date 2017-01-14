/* CS261- Assignment 1 - Q.5*/
/* Name: Vincent Lee
 * Date: 1/14/17
 * Solution description: This program reads input from the keyboard and converts it to Sticky case
 */
 
#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
    int makeUpper = 1;
    while(*word) {
        if(makeUpper) {
            if(*word >= 'a' && *word <= 'z') {
                char ch = toUpperCase(*word);
                *word = ch;
            }
            makeUpper = 0;
        } else {
            if(*word >= 'A' && *word <= 'Z') {
                char ch = toLowerCase(*word);
                *word = ch;
            }
            makeUpper = 1;
        }
        word++;
    }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[256];
    scanf("%256s", word);
    
    /*Call sticky*/
    sticky(word);
    
    /*Print the new word*/
    printf("%s", word);
    printf("\n");
    
    return 0;
}
