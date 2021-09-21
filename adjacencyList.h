/*******************************************/
/* Initial Version 0.0.1                   */
/* Created by Mauricio Quijada             */
/* Email mauricio.quijada@outlook.com      */
/* Homework 01 Artificial Intelligence     */
/* Universidad Nacional Autonoma de Mexico */
/*                                         */
/* adjacencyList.h                         */
/* This program represents a Graph G(V,E)  */
/* in a adjacency List                     */
/*******************************************/



/**********************************************/
/* Adding new node given the following inputs */
/* s--source                                  */
/* d--destiny                                 */
/* w--weight                                  */
/* Head weight is filled with -1              */
/**********************************************/
void addNode(int s, int d, int w);

/**********************************************/
/* Printing a full filled list                */
/**********************************************/
void printList();

void initAdjacencyList();

int getNext(int node, int visitedNodes[], int goal);

int pathcost(int source, int destiny);

int getNextAstar(int node, int *pathcost, int visitedNodes[]);