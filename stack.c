/*****************************/
/* stack implementation      */
/* based on linked list      */
/* Author: Mauricio Quijada  */
/* version 0.0.1             */
/* stack.c                   */
/*****************************/

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;
struct Node* tmp;
int count = 0;


void push(int element){
    if(top == NULL)
    {
        top = (struct Node *)malloc(sizeof(struct Node *));
        top->data = element;
        top->next = NULL;
    }
    else
    {
        tmp = (struct Node *)malloc(sizeof(struct Node *));
        tmp->data = element;
        tmp->next = top;
        top = tmp;
    }
    count++;
    printf("Item to be added is %d \n", top->data);
    // display();
}

void pop(){
    tmp = top;

    if (top == NULL)
    {
        printf("\nStack is empty!\n");
        return;
    }
    else
    {
        tmp= tmp->next;
    }

    printf("Item to be removed is %d \n", top->data);
    free(top);
    top = tmp;
    count--;
    // display();
}

void display(){
    tmp = top;
    if(count == 0)
    {
        printf("\nStack is Empty!!!\n");
        return;
    }
    else
    {   
        printf("There are currently %d items: Top->", count);
        while(tmp != NULL)
        {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int getTop(void){
    tmp = top;
    if (tmp != NULL)
    {
        return tmp->data;
    }
    else
    {
        return -1;
    }
}


