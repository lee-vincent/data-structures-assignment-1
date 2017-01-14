/* CS261- Assignment 1 - Q.4*/
/* Name: Vincent Lee
 * Date: 1/14/17
 * Solution description: This program sorts an array of students based on their scores in ascending order
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int currentIndex = 0;
    
    while(currentIndex < n) {
        int min = (students + currentIndex)->score;
        int indexToSwitch = currentIndex;
        for(int i = currentIndex + 1; i < n; i++) {
            if((students + i)->score < min) {
                min = (students + i)->score;
                indexToSwitch = i;
            }
        }
        
        if(min < (students + currentIndex)->score) {
            int temp = (students + currentIndex)->score;
            (students + currentIndex)->score = min;
            (students + indexToSwitch)->score = temp;
        }
        currentIndex++;
    }

}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;
    
    /*Allocate memory for n students using malloc.*/
    struct student* students = (struct student*)malloc(n * sizeof(struct student));
    
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    for(int i = 0; i < n; i++) {
        srand((unsigned)1240);
        wloop: while(1) {
            int tempID = (rand() % n) + 1;
            int tempScore = (rand() % 100) + 1;
            for(int j = 0; j < n; j++) {
                if((students + j)->id == tempID || (students +j)->score == tempScore) {
                    goto wloop;
                }
            }
            //here we know no other existing id or score matches so we can assign it
            (students + i)->id = tempID;
            (students + i)->score = tempScore;
            break;
        }
    }
    
    /*Print the contents of the array of n students.*/
    for(int i = 0; i < n; i++) {
        printf("%i, %i\n", (students + i)->id, (students + i)->score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    printf("\n\n");
    /*Print the contents of the array of n students.*/
    for(int i = 0; i < n; i++) {
        printf("%i, %i\n", (students + i)->id, (students + i)->score);
    }
    
    return 0;
}
