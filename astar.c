/*****************************/
/* astar implementation      */
/* based on linked list      */
/* Author: Mauricio Quijada  */
/* version 0.0.1             */
/* astar.c                   */
/*****************************/

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "astar.h"

#define MAX_ELEMENTS 20

struct Node{
    int data;
    //int prevArray[MAX_ELEMENTS];
    int pathcost;
    int sum; // pathcost + heuristics
    struct Node* next;
    struct Node* previous;
};

static struct Node *head = NULL;
static struct Node *tail = NULL;
static struct Node *tmp = NULL;
static struct Node *goal = NULL;
static struct Node *seeker = NULL;
static struct Node *seekerprev = NULL;

int queue_elements = 0;

void enqueue_p(int element, int previousA[], int path, int sumtotal){
    if(head == NULL){
        head = (struct Node *)malloc(sizeof(struct Node *));
        head->data = element;
        //for (int i = 0; i < MAX_ELEMENTS; i++)
        //{
        //    tmp->prevArray[i] = 1;//previousA[i];
        //}
        head->pathcost = path;
        head->sum = sumtotal;

        head->next = NULL;
        head->previous = NULL;
        tail = head;
    } else if(queue_elements == 1){
        tmp = (struct Node *)malloc(sizeof(struct Node *));
        tmp->data = element;
        //for (int j = 0; j < MAX_ELEMENTS; j++)
        //{
        //    tmp->prevArray[j] = 2;//previousA[i];
        //}
        tmp->pathcost = path;
        tmp->sum = sumtotal;

        tmp->next = NULL;
        tmp->previous = tail;
        tail->next = tmp;
        tail = tmp;
    } 
    else if(queue_elements >= 2){
        tmp = (struct Node *)malloc(sizeof(struct Node *));
        tmp->data = element;
        //for (int k = 0; k < MAX_ELEMENTS; k++)
        //{
        //    tmp->prevArray[k] = 3;//previousA[i];
        //}
        tmp->pathcost = path;
        tmp->sum = sumtotal;

        seeker = head->next;

        do
        {
            if(seeker->sum >= sumtotal)
            {
                break;
            }
            else
            {
                seeker = seeker->next;
            }
            if (seeker == NULL)
                break;
        }while (1);

        printf("\nSeeker is the following: %d\n", seeker->sum);

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
            printf("**sum %d **\n", tmp->sum);
            printf("data %d \n",tmp->data );
            printf("previous: %d \n", (int)tmp->previous);
            printf("next: %d \n", (int)tmp->next);

            //for (int l = 0; l < MAX_ELEMENTS; l++)
            //{
            //    printf("prevArray[%d]: %d \n", l, tmp->prevArray[l] );
            //}

            printf("head sum: %d \n", head->sum);
            printf("tail sum: %d \n\n", tail->sum);
            tmp = tmp->next;
        }
        printf(" <-Tail \n");
    }
}