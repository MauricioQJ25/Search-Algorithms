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
#include "queue.h"

#include "priorityqueue.h"

void createAdjacencyList();
void dfs(int initialNode, int goalNode);
void bfs(int initialNode, int goalNode);
void greedySearch(int initialNode, int goalNode);
void aStar(int initialNode, int goalNode);

int element1 = 1;
int previous1[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
int path1 = 10;
int sumtotal1 = 10;

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
    printf("6.- Greedy Search \n");

    printf("\n Select one of this to obtain a path and path cost\n Option: ");

    do{
        scanf("%d", &select);
        if(select < 1 || select > 6)
        {
            printf("Please select a right version \n");
        }
    }while(select < 1 || select > 6);

    createAdjacencyList();

    switch(select)
    {
        case 1:
            printf("\nYou select DFS algorithm\n");
            printf("Select init node: ");
            scanf("%d", &init);

            printf("Select goal node: ");
            scanf("%d", &goal);
            printf("\n");

            dfs(init,goal);
            break;
        case 2:
            printf("\nYou select BFS algorithm\n");
            printf("Select init node: ");
            scanf("%d", &init);

            printf("Select goal node: ");
            scanf("%d", &goal);
            printf("\n");
            bfs(init, goal);
            break;
        case 3:
            enqueue_p(1, previous1, path1, 9);
            enqueue_p(2, previous1, path1, 15);
            enqueue_p(3, previous1, path1, 10);
            enqueue_p(3, previous1, path1, 11);
            enqueue_p(3, previous1, path1, 17);
            enqueue_p(3, previous1, path1, 18);
            enqueue_p(3, previous1, path1, 12);
            dequeue_p();
            dequeue_p();
            dequeue_p();
            enqueue_p(7, previous1, path1, 7);
            

            printf("\nHello From case 3\n");
            break;
        case 4:
            break;
        case 5:
            printf("\nYou select A Star algorithm\n");
            printf("Goal node is Bucharest: 8 \n");
            goal = 8; /* Harcoded value*/

            printf("Select init node: ");
            scanf("%d", &init);
            printf("\n");
            aStar(init, goal);
            break;
        case 6:
            printf("\nYou select Greedy Search algorithm\n");
            printf("Goal node is Bucharest: 8 \n");
            goal = 8; /* Harcoded value*/

            printf("Select init node: ");
            scanf("%d", &init);
            printf("\n");
            greedySearch(init, goal);
            break;
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

void dfs(int initialNode, int goalNode)
{
    int next = initialNode;
    int visitedNodes[20] = {0};
    int pathsum = 0;
    int source = -2;
    int destiny = -2;
    int steps = 0;


    printf("\n------------DFS Processing-----------------\n");
    push(initialNode);
    steps = steps + 1;
    visitedNodes[initialNode] = 1;

    while(next != goalNode){
        next = getNext(next, visitedNodes, goalNode);
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
    
    printf("\n------------DFS Report-----------------\n");
    printf("Steps in the stack: %d \n", steps);
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

void bfs(int initialNode, int goalNode)
{
    int visitedNodes[20] = {0};
    int previousNodes[20] = {100};
    for (int j = 0; j < 20; j++)
        previousNodes[j] = -5;
    int pathsum = 0;
    int source = -2;
    int destiny = -2;
    int steps = 0;


    printf("\n------------Processing BFS-----------------\n");
    enqueue(initialNode);
    steps = steps + 1;
    visitedNodes[initialNode] = 1;
    previousNodes[initialNode] = -100;

    int next = initialNode;
    int previous = initialNode;
    
    if(initialNode != goalNode)
    {
        
        if(next != -1)
        {
            enqueue(next);
            steps = steps + 1;
            visitedNodes[next] = 1;
            previousNodes[next] = getHead();
        }
    }

    while(next != goalNode){
        while(next != -1 )
        {
            
            if(next != -1)
            {
                enqueue(next);
                steps = steps + 1;
                visitedNodes[next] = 1;
                previousNodes[next] = getHead();
            }
        }

        dequeue();
        steps = steps + 1;
        previous = getHead();
        if (previous != -3)
        {
            
            if(next != -1)
            {
                enqueue(next);
                steps = steps + 1;
                visitedNodes[next] = 1;
                previousNodes[next] = getHead();;
            }
        }
        // display();
    }

    printf("\n--------Printing previous nodes-----------\n");
    printf("(-100) means initial node, (-5) unvisited \n");
    for( int i = 0; i < 20; i++)
    {
        printf("previousnode[%d] = %d\n", i, previousNodes[i]);
    }
    
    
    printf("\n------------BFS Report-----------------\n");
    printf("Steps in the queue: %d \n", steps);
    printf("Getting path... \n");
    
    int head = goalNode;
    do
    {
        push(head);
        head = previousNodes[head];
        
    }while(head != -100);

    printf("Path found: ");
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

} // End of BFS

void greedySearch(int initialNode, int goalNode)
{
    int visitedNodes[20] = {0};
    // for (int j1 = 0; j1 < 20; j1++)
    //    visitedNodes[j1] = -5;

    int previousNodes[20] = {100};
    for (int j = 0; j < 20; j++)
        previousNodes[j] = -5;

    int pathsum = 0;
    int source = -2;
    int destiny = -2;
    int steps = 0;
    int heuristicActual = 0 ;
    int tempnext = 0;
    int watchdog= 0;
    int errorloop = 0;

    int heuristics[20] = {  366, /*0 Arad*/
                            374, /*1 Zerind*/
                            253, /*2 Sibiu*/
                            329, /*3 Timisoara*/
                            380, /*4 Oradea*/
                            176, /*5 Fagaras*/
                            193, /*6 Rimnicu Vilcea*/
                            244, /*7 Lugoj*/
                            0,   /*8 Bucharest*/
                            100, /*9 Pitesti*/
                            160, /*10 Craiova*/
                            241, /*11 Mehadia*/
                            77,  /*12 Giurgiu*/
                            80,  /*13 Urziceni*/
                            242, /*14 Drobeta*/
                            151, /*15 Hirzova*/
                            199, /*16 Vaslui*/
                            161, /*17 Eforie*/
                            226, /*18 Lasi*/
                            234} ; /*19 Neamt*/

    for (int i = 0; i < 20; i++)
    {
        printf("%d \n", heuristics[i]);
    }
    
    printf("\n------------Processing Greedy Search-----------------\n");
    push(initialNode);
    steps = steps + 1;
    visitedNodes[initialNode] = 1;
    previousNodes[initialNode] = -100;
    heuristicActual = heuristics[initialNode];

    int next = initialNode;
    int previous = initialNode;
    
    while(previous != goalNode)
    {   
        while(next != -1)
        {
            next = getNext(previous, visitedNodes, goalNode);
            if (next != -1)
            {
                visitedNodes[next] = 1;
            }

            printf("next: %d \n", next);

            if(heuristics[next] < heuristicActual && next != -1)
            { 
                tempnext = next;
                heuristicActual = heuristics[tempnext];
            }
            if(next == goalNode)
            {
                break;
            }
        }
        
        previous = tempnext;
        //tempnext = -2;
        push(previous);
        next = -2;
        watchdog++;
        if (watchdog > 20)
        {
            errorloop = 1;
            break;
        }

    }
    if (errorloop)
    {
        printf("\nWarning: Greedy Search fails due loop in path!!!\n");
    }
    else
    {
        printf("End Path found: ");
        display();
    }
} // End of greedySearch

void aStar(int initialNode, int goalNode)
{

} // End of a Star


