/* CS261- Assignment 1 - Q.1*/
/* Name: Vincent Lee
 * Date: 1/10/17
 * Solution description: This program creates an array of Struct Students and manipulates score and id values.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* ssArray = (struct student*)malloc(sizeof(struct student) * 10);
    if(ssArray == NULL) {
        printf("Memory Allocation Failed");
        exit(EXIT_FAILURE);
    }
     /*return the pointer*/
    return ssArray;
    
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    for(int i = 0; i < 10; i++) {
    srand((unsigned)0);
    wloop: while(1) {
            int tempID = (rand() % 10) + 1;
            int tempScore = (rand() % 100) + 1;
            for(int j = 0; j < 10; j++) {
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
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    for(int i = 0; i < 10; i++) {
        printf("%i, %i\n", (students + i)->id, (students + i)->score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = -1;
    int max = -1;
    float avg = -1.0f;
    
    for(int i = 0; i < 10; i++) {
        if(min == -1) {
            min = (students + i)->score;
        } else if((students + i)->score < min) {
                min = (students + i)->score;
        }
        
        if(max == -1) {
            max = (students + i)->score;
        } else if ((students + i)->score > max) {
            max = (students + i)->score;
        }
        
        avg += (float)(students + i)->score;
    }
    
    avg = avg / 10.0f;
    
    printf("Minimum Score = %i\n", min);
    printf("Maximum Score = %i\n", max);
    printf("Average Score = %.2f\n", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if(stud != NULL) {
        free(stud);
    }
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
