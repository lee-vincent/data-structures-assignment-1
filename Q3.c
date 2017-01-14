/* CS261- Assignment 1 - Q.3*/
/* Name: Vincent Lee
 * Date: 1/14/17
 * Solution description: This program sorts an array of integers in ascending order
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    int currentIndex = 0;
    
    while(currentIndex < n) {
        int min = *(number + currentIndex);
        int indexToSwitch = currentIndex;
        for(int i = currentIndex + 1; i < n; i++) {
            if(*(number + i) < min) {
                min = *(number + i);
                indexToSwitch = i;
            }
        }
        
        if(min < *(number + currentIndex)) {
            int temp = *(number + currentIndex);
            *(number + currentIndex) = min;
            *(number + indexToSwitch) = temp;
        }
        currentIndex++;
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int* array = (int*)malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
    srand((unsigned)0);
    for(int i = 0; i < 20; i++) {
        *(array +i) = rand();
    }
    
    /*Print the contents of the array.*/
    for(int i = 0; i < 20; i++) {
        printf("%i\n", *(array + i));
    }

    printf("\n\n");
    
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    
    /*Print the contents of the array.*/
    for(int i = 0; i < 20; i++) {
        printf("%i\n", *(array + i));
    }
    
    return 0;
}
