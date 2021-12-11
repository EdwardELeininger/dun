#include "stack.h"

stack* stack_init()
{
    stack* newStack;
    newStack = (stack*)malloc(sizeof(stack));
    return newStack;
}
int stack_push(stack** head, void* data)
{
    stack* newItem = stack_init();
    newItem->next = *head;
    newItem->data = data;
    *head = newItem;
    return 0;
}
void* stack_pop(stack** head)
{
    void* retVal = (*head)->data;
    stack* next = (*head)->next;
    free(*head);
    *head = next;
    return retVal;
}
void* stack_peek(stack** head)
{
    return (*head)->data;
}
/*
int main()
{
    stack* head = NULL; 
    head = (stack*)malloc(sizeof(stack));
    static int val=42;
    stack_push(&head, (void*)&val);
    int* newval = stack_peek(&(head));
    printf("val = %d\n", *(int*)(newval));
    static int mval=357;
    stack_push(&head, (void*)&mval);
    printf("popping... %d\n", *(int*)(stack_pop(&(head))));
    printf("popping... %d\n", *(int*)(stack_pop(&(head))));
    return 0;
}
*/
