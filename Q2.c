/* CS261- Assignment 1 - Q.2*/
/* Name: Vincent Lee
 * Date: 1/14/17
 * Solution description: This program reflects pass by value vs. pass by reference. Here we demonstrate that a function can only change a parameter if it is passed in as a pointer variable.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = (*a * 2);
    
    /*Set b to half its original value*/
    *b = *b / 2;
    
    /*Assign a+b to c*/
    c = *a + *b;
    
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    
    /*Print the values of x, y and z*/
    printf("x = %i\n", x);
    printf("y = %i\n", y);
    printf("z = %i\n", z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    int fooReturnValue = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    printf("Value Returned by foo = %i\n", fooReturnValue);

    /*Print the values of x, y and z again*/
    printf("x = %i\n", x);
    printf("y = %i\n", y);
    printf("z = %i\n", z);
 
    /*Is the return value different than the value of z?  Why?*/
    printf("The return value is different than the value of z\nbecause C passes arguments by value instead of by reference.\nWhen we passed z into foo() as the third parameter, only a\ncopy of z's value was passed. Therefore the\nvariable z was not actually changed but instead a copy was.\n");
    return 0;
}
    
    
