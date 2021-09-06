/*******************************************/
/* Initial Version 0.0.1                   */
/* Created by Mauricio Quijada             */
/* Email mauricio.quijada@outlook.com      */
/* Homework 01 Artificial Intelligence     */
/* Universidad Nacional Autonoma de Mexico */
/*                                         */
/* AdjacencyList.c                         */
/* This program represents a Graph G(V,E)  */
/* in a adjacency List                     */
/*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define maxNode 20

void addNode(int s, int d, int w);
void printList();

typedef struct Node
{
    int vertexNum;
    int weight;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
} List;

List *adjlist[maxNode] = {0};

void main()
{
    int i;
    for (i = 0; i < maxNode; i++)
    {
        adjlist[i] = (List *)malloc(sizeof(List));
        adjlist[i]->head = NULL;
    }

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
// getchar();

} // End of main

/**********************************************/
/* Adding new node given the following inputs */
/* s--source                                  */
/* d--destiny                                 */
/* w--weight                                  */
/* Head weight is filled with -1              */
/**********************************************/
void addNode(int s, int d, int w)
{
    Node *dest, *tmp, *src;

    if(adjlist[s]->head == NULL)
    {
        src = (Node *)malloc(sizeof(Node));
        src->vertexNum = s;
        src->weight = -1;
        src->next = NULL;
        adjlist[s]->head = src;
    }

    dest = (Node *)malloc(sizeof(Node));
    dest->vertexNum = d;
    dest->weight = w;
    dest->next = NULL;

    tmp = adjlist[s]->head;
    while (tmp->next != NULL)
    { 
        tmp = tmp->next;
    }
    tmp->next = dest;
} // End of AddNode

void printList()
{
    int i;
    for (i = 0; i < maxNode; i++)
    {
        Node *p = adjlist[i]->head;
        printf("Adjacency list for vertex %d\n", i);
        while(p)
        {
            printf("(%d, %d) ", p->vertexNum, p->weight);
            p = p->next;
        }
        printf("\n");
    }
} // End of printList