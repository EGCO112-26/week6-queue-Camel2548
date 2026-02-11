#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
    struct node* next;
    int order_number; // namemenu
    int q;            // quantitu
} OrderNode;


typedef struct {
    OrderNode *head, *tail;
    int size;
} Queue;


void enqueue_struct(Queue* q, int menu_id, int qty) {
    OrderNode *new_node = (OrderNode*) malloc(sizeof(OrderNode));
    if (new_node) { 
        new_node->order_number = menu_id;
        new_node->q = qty;
        new_node->next = NULL;

        if (q->size == 0) {
            q->head = new_node;
        } else {
            q->tail->next = new_node;
        }
        q->tail = new_node;
        q->size++;
        printf("My order is %d\n", menu_id);
    }
}


int dequeue_struct(Queue *q, int customer_count) { //dequeue
    OrderNode *t = q->head;
    if (t) {
        int menu_id = t->order_number;
        int qty = t->q;
        int price = 0;
        char menu_name[50];

        
        switch(menu_id) {
            case 1: strcpy(menu_name, "Kraprow Mookrob"); price = 70 * qty; break;
            case 2: strcpy(menu_name, "Koong Maenam"); price = 2000 * qty; break;
            case 3: strcpy(menu_name, "Kanom Jeen"); price = 40 * qty; break;
            case 4: strcpy(menu_name, "Somtam"); price = 120 * qty; break;
            default: strcpy(menu_name, "Unknown"); price = 0; break;
        }

        printf("Customer no: %d\n", customer_count);
        printf("%s\n", menu_name);
        printf("You have to pay %d\n", price);

        int cash = 0;
        while (cash < price) {
            printf(":Cash:");
            scanf("%d", &cash);
            if (cash < price) printf("Not enough cash!\n");
        }

        printf("Thank you\n");
        if (cash > price) {
            printf("Change is:%d\n", cash - price);
        }

        
        q->head = t->next;
        if (q->head == NULL) q->tail = NULL;
        
        free(t);
        q->size--;
        return menu_id;
    }
    printf("The queue is empty\n");
    return -1;
}

#endif