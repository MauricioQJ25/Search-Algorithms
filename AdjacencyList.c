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

#define maxNode 2

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

addNode(0, 1, 666);
addNode(0, 3, 777);
addNode(1, 2, 888);
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