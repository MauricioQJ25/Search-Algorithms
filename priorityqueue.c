/*****************************/
/* astar implementation      */
/* based on linked list      */
/* Author: Mauricio Quijada  */
/* version 0.0.1             */
/* priorityqueue.c           */
/*****************************/

#include <stdio.h>
#include <stdlib.h>

#include "priorityqueue.h"

#define MAX_ELEMENTS 20

struct Nodep{
    int data;
    int prevArray[MAX_ELEMENTS];
    int pathcost;
    int sum; // pathcost + heuristics
    struct Nodep* next;
    struct Nodep* previous;
};

static struct Nodep *head = NULL;
static struct Nodep *tail = NULL;
static struct Nodep *tmp = NULL;
static struct Nodep *goal = NULL;
static struct Nodep *seeker = NULL;
static struct Nodep *seekerprev = NULL;

int queue_elements = 0;

void enqueue_p(int element, int previousA[], int path, int sumtotal){
    if(head == NULL){
        head = (struct Nodep *)malloc(sizeof(struct Nodep ));
        head->data = element;
        head->pathcost = path;
        head->sum = sumtotal;
        for (int j = 0; j < MAX_ELEMENTS; j++)
        {
            head->prevArray[j] = previousA[j];
        }
        head->next = NULL;
        head->previous = NULL;
        tail = head;
    } else if(queue_elements == 1){
        tmp = (struct Nodep *)malloc(sizeof(struct Nodep ));
        tmp->data = element;
        tmp->pathcost = path;
        tmp->sum = sumtotal;
        for (int i = 0; i < MAX_ELEMENTS; i++)
        {
            tmp->prevArray[i] = previousA[i];
        }
        tmp->next = NULL;
        tmp->previous = tail;
        tail->next = tmp;
        tail = tmp;
    } 
    else if(queue_elements >= 2){
        tmp = (struct Nodep *)malloc(sizeof(struct Nodep ));
        tmp->data = element;
        tmp->pathcost = path;
        tmp->sum = sumtotal;
        for (int k = 0; k < MAX_ELEMENTS; k++)
        {
            tmp->prevArray[k] = previousA[k];
        }

        seeker = head->next;
        int exit = 1;
        do
        {
            if(seeker->sum >= sumtotal)
            {
                exit = 0;
            }
            else
            {
                seeker = seeker->next;
                if (seeker == NULL)
                {
                    exit = 0;
                }
            }
            
        }while (exit);

        if (seeker == NULL)
        {
            tmp->previous = tail;
            tmp->next = NULL;
            tail->next = tmp;
            tail = tmp;
        }
        else
        {
            seekerprev = seeker->previous;
            seekerprev->next = tmp;
            tmp->previous = seekerprev;
            tmp->next = seeker;
            seeker->previous = tmp;
        }
    }
    queue_elements++;
    printf("Item to be added to the Queue is %d \n", sumtotal);
    displayQueue_p();
} // end of enqueue

void dequeue_p(){
    tmp = head;

    if (head == NULL)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    else
    {
        tmp= tmp->next;
        tmp->previous = NULL;
    }

    printf("Item to be removed to the Queue is %d \n", head->sum);
    free(head);
    head = tmp;
    queue_elements--;
    displayQueue_p();
}

void displayQueue_p(){
    tmp = head;
    if(queue_elements == 0)
    {
        printf("\nQueue is Empty!!!\n");
        return;
    }
    else
    {   
        printf("There are currently %d items: Head-> ", queue_elements);
        while(tmp != NULL)
        {
            printf(" %d ", tmp->sum);
            /*
            printf("data %d \n",tmp->data );
            printf("previous: %d \n", (int)tmp->previous);
            printf("next: %d \n", (int)tmp->next);
            for (int i = 0; i < MAX_ELEMENTS; i++)
            {
                printf("array[%d]: %d \n", i, tmp->prevArray[i]);
            }
            printf("head sum: %d \n", head->sum);
            printf("tail sum: %d \n\n", tail->sum);
            */
            tmp = tmp->next;
        }
        printf(" <-Tail \n");
    }
}