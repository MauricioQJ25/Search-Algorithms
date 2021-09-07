/*****************************/
/* stack implementation      */
/* based on linked list      */
/* Author: Mauricio Quijada  */
/* version 0.0.1             */
/* main.c                    */
/*****************************/

#include "stack.h"

void main(){
    // empty
    // 5
    // 5 6
    // 5 6 7
    // 5 6 7 8
    // 5 6 7
    // 5 6 7 10
    // 5 6 7
    // 5 6 
    // 5 
    // empty
    pop();
    pop();
    push(5);
    push(6);
    push(7);
    push(8);
    pop();
    push(10);
    pop();
    pop();
    pop();
    pop();
    pop();
}