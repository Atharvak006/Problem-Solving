#include<stdio.h>
#include<stdlib.h>

struct HNode
{
    int v;
    struct HNode* next;
    struct HNode* prev;
};

struct HList
{
    struct HNode* head;
};

int main(void)
{
    struct HList* list = (struct HList*)malloc(sizeof(struct HList));

    list->head = (struct HNode*)malloc(sizeof(struct HNode));

    list->head->v = -1;
    list->head->next = list->head;
    list->head->prev = list->head;

    printf("Address of list           : %p\n", list); // 200
    printf("Address of HNode          : %p\n", list->head); // 100
 
    printf("\nUsing -> operator\n");
    printf("Inside HList (head)       : %p\n", list->head); // 100
    printf("Inside HNode (v)          : %d\n", list->head->v); // value

    printf("\nUsing * and . operators\n");
    printf("Inside HList (head)       : %p\n", (*list).head); // 100
    printf("Inside HNode (v)          : %d\n", (*((*list).head)).v); // value

    return 0;
}

/*
Memory Layout


Address 200
+-------------------+
| structure HList   |  
|-------------------|
| head = 100 -------+--------------------+
+-------------------+                    |
                                         |
                                         v
                                  Address 100
                           +----------------------+
                           | structure HNode      |
                           |----------------------|
                           | v                    |
                           | next                 |
                           | prev                 |
                           +----------------------+

*/