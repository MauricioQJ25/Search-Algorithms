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
void dfs(int initialNode, int goalNode);

void main(){

    int select = 0;
    int init, goal;
    
    printf("\n------------ Menu -----------------------------------------\n");
    printf("Graph taken from IA book related to Rumanian cities\n");
    printf("This program resolve a path using different algorithms like: \n");
    printf("1.- dfs \n");
    printf("2.- bfs \n");
    printf("3.- iterativa \n");
    printf("4.- costo uniforme \n");
    printf("5.- A* \n");
    printf("6.- Busqueda Voraz \n");

    printf("\n Select one of this to obtain a path and path cost\n Option: ");
    scanf("%d", &select);

    switch(select)
    {
        case 1:
            createAdjacencyList();

            printf("\nYou select DFS algorithm\n");
            printf("Select init node: ");
            scanf("%d", &init);

            printf("Select goal node: ");
            scanf("%d", &goal);
            printf("\n");

            dfs(init,goal);
            break;
        case 0:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        default:
            break;
    }

    // printList();
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
    addNode(14, 11, 75);
    addNode(14, 10, 120);
    addNode(15, 13, 98);
    addNode(15, 17, 86);
    addNode(16, 13, 142);
    addNode(16, 18, 92);
    addNode(17, 15, 86);
    addNode(18, 19, 87);
    addNode(18, 16, 92);
    addNode(19, 18, 87);
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

void dfs(int initialNode, int goalNode)
{
    int next = initialNode;
    int visitedNodes[20] = {0};
    int pathsum = 0;
    int source = -2;
    int destiny = -2;
    int steps = 0;


    printf("\n------------Processing-----------------\n");
    push(initialNode);
    steps = steps + 1;
    visitedNodes[initialNode] = 1;

    while(next != goalNode){
        next = getNext(next, visitedNodes);
        if(next == -1)
        {
            pop();
            next = getTop();
            display();
        }
        else
        {
            push(next);
            visitedNodes[next] = 1;
            display();
        }
        steps = steps + 1;
    }
    
    printf("\n------------Report-----------------\n");
    printf("Nodes visited: %d \n", steps);
    printf("Path found... ");
    display();
    printf("Calculating path cost...\n");
    source = getTop();
    pop();
    destiny = getTop();

    while( destiny != -1)
    {
        pathsum = pathsum + pathcost(source, destiny);
        source = destiny;
        pop();
        destiny = getTop();
    }
    printf("The path cost is the following: %d\n", pathsum);
}

