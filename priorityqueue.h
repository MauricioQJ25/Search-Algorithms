/*****************************/
/* astar implementation      */
/* based on linked list      */
/* Author: Mauricio Quijada  */
/* version 0.0.1             */
/* priorityqueue.h           */
/*****************************/

#define MAX_ELEMENTS 20

void enqueue_p(int element, int previousA[], int path, int sumtotal);
void dequeue_p();
void displayQueue_p();
void getHead_p(int *previouscities, int *pcost, int *city);
// int getHead_p();
// int getGoal_p();
// int getTail_p();