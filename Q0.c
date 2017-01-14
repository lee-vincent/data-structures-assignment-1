/* CS261- Assignment 1 - Q. 0*/
/* Name: Vincent Lee
 * Date: 1/10/17
 * Solution description: This program defines an integer and uses pointers to print the address of the variables and also the value pointed to.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("%d\n", *iptr);
    
     /*Print the address pointed to by iptr*/
    printf("%p\n", iptr);
     
     /*Print the address of iptr itself*/
    printf("%p\n", &iptr);

}

int main(){
    
    /*declare an integer x*/
    int x = 10;
    
    /*print the address of x*/
    printf("%p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("%d\n", x);
    
    return 0;
}
