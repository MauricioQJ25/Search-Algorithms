/*****************************/
/* queue implementation      */
/* based on linked list      */
/* Author: Mauricio Quijada  */
/* version 0.0.1             */
/* queue.c                   */
/*****************************/

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

struct Node{
    int data;
    struct Node* next;
};

static struct Node *head = NULL;
static struct Node *tail = NULL;
static struct Node *tmp = NULL;

int counter = 0;

void enqueue(int element){
    if(head == NULL)
    {
        head = (struct Node *)malloc(sizeof(struct Node *));
        head->data = element;
        head->next = NULL;
        tail = head;
    }
    else
    {
        tmp = (struct Node *)malloc(sizeof(struct Node *));
        tmp->data = element;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
    }
    counter++;
    printf("Item to be added to the Queue is %d \n", tail->data);
    displayQueue();
}

void dequeue(){
    tmp = head;

    if (head == NULL)
    {
        printf("\nQueue is empty!\n");
        return;
    }
    else
    {
        tmp= tmp->next;
    }

    printf("Item to be removed to the Queue is %d \n", head->data);
    free(head);
    head = tmp;
    counter--;
    displayQueue();
}

void displayQueue(){
    tmp = head;
    if(counter == 0)
    {
        printf("\nQueue is Empty!!!\n");
        return;
    }
    else
    {   
        printf("There are currently %d items: Head-> ", counter);
        while(tmp != NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf(" <-Tail \n");
    }
}

int getHead(void){
    tmp = head;
    if (tmp != NULL)
    {
        return tmp->data;
    }
    else
    {
        return -3;
    }
}