#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

int main(int argc, char **argv) {
    Queue q;
    q.headPtr = NULL;
    q.tailPtr = NULL;
    q.size = 0;
    
    int i, x;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "x") == 0) {
            
            if (q.size > 0) { 
                
                x = dequeue_struct(&q);
                printf("dequeing %d\n", x);
            } else {
                
                dequeue_struct(&q);
            }
        } else {
            x = atoi(argv[i]);
            enqueue_struct(&q, x);
          //  printf("enqueing %d\n", x);
        }
    }
    
    return 0;
}