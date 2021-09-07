/*****************************/
/* stack implementation      */
/* based on linked list      */
/* Author: Mauricio Quijada  */
/* version 0.0.1             */
/* main.c                    */
/*****************************/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "stack.h"
#include "adjacencyList.h"

void testStack();
void createAdjacencyList();

void main(){
    testStack();
    createAdjacencyList();
}

void createAdjacencyList()
{
    initAdjacencyList();

    /*Building Adjacent List*/
    addNode(0, 1, 75);
    addNode(0, 2, 140);
    addNode(0, 3, 118);
    addNode(1, 0, 75);
    addNode(1, 4, 71);
    addNode(2, 4, 151);
    addNode(2, 0, 140);
    addNode(2, 5, 99);
    addNode(2, 6, 80);
    addNode(3, 0, 118);
    addNode(3, 7, 111);
    addNode(4, 1, 71);
    addNode(4, 2, 151);
    addNode(5, 2, 99);
    addNode(5, 8, 211);
    addNode(6, 2, 80);
    addNode(6, 9, 97);
    addNode(6, 10, 146);
    addNode(7, 3, 111);
    addNode(7, 11, 70);
    addNode(8, 5, 211);
    addNode(8, 9, 101);
    addNode(8, 12, 90);
    addNode(8, 13, 85);
    addNode(9, 6, 97);
    addNode(9, 10, 138);
    addNode(9, 8, 101);
    addNode(10, 14, 120);
    addNode(10, 6, 146);
    addNode(10, 9, 138);
    addNode(11, 7, 70 );
    addNode(11, 14, 75);
    addNode(12, 8, 90);
    addNode(13, 8, 85);
    addNode(13, 15, 98);
    addNode(13, 16, 142);
    addNode(14, 11, 70);
    addNode(14, 10, 120);
    addNode(15, 13, 98);
    addNode(15, 17, 86);
    addNode(16, 13, 142);
    addNode(16, 18, 92);
    addNode(17, 15, 86);
    addNode(18, 19, 87);
    addNode(18, 16, 92);
    addNode(19, 18, 87);

    printList();
}

void testStack()
{
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