#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef struct STACK{
    void* next;
    void* data;
}stack;

stack* stack_init();
int stack_push(stack** head, void* data);
void* stack_pop(stack** head);
void* stack_peek(stack** head);

#endif
