#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "foodqueue.h"

int main(int argc, char **argv) {
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;
    
    int customer_count = 1;

    if (argc < 2) {
        printf("Usage: %s [menu_id and quantity] or [x to start]\n", argv[0]);
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "x") == 0) {
            // ระบบชำระเงินเมื่อเจอ "x"
            if (q.size > 0) {
                dequeue_struct(&q, customer_count);
                customer_count++;
            } else {
                printf("No customer in queue.\n");
            }
        } else {
            // รับค่า menu_id และ quantity (สมมติให้ quantity เป็นตัวถัดไป หรือถ้าไม่มีให้เป็น 1)
            int menu_id = atoi(argv[i]);
            int qty = 1;
            
            // ตรวจสอบว่ามี parameter จำนวน (quantity) ถัดจาก id ไหม
            if (i + 1 < argc && strcmp(argv[i+1], "x") != 0) {
                qty = atoi(argv[i+1]);
                i++; // เลื่อน index ข้ามตัว quantity ไป
            }
            
            enqueue_struct(&q, menu_id, qty);
        }
    }

    printf("==========================================\n");
    printf("There are %d ppl left in the queue\n", q.size);

    // 5. เคลียร์คิวก่อนจบโปรแกรม (Free memory)
    while (q.size > 0) {
        OrderNode *temp = q.head;
        q.head = q.head->next;
        free(temp);
        q.size--;
    }

    return 0;
}